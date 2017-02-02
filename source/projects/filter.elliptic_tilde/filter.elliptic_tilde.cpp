/// @file	
///	@copyright	Copyright (c) 2017, Cycling '74
/// @author		Timothy Place
///	@license	Usage of this file and its contents is governed by the MIT License

#include "c74_min.h"
#include "DspFilters/Elliptic.h"

using namespace c74::min;

class elliptic : public object<elliptic>, public vector_operator {
private:
	std::unique_ptr<Dsp::Filter>	m_filter;
	std::unique_ptr<Dsp::Filter>	m_filter_pending;
	bool							m_is_bandpass_or_bandstop { false };
	std::atomic<bool>				m_update_pending = { false };

public:

	MIN_DESCRIPTION { "Nth-order elliptic lowpass filter" };
	MIN_TAGS		{ "audio, filters" };
	MIN_AUTHOR		{ "Cycling '74" };
	MIN_RELATED		{ "filterdesign, filterdetail, biquad~, cascade~, filter.elliptic" };
	
	inlet<>		in_left		{ this, "(signal) left channel input" };
	inlet<>		in_right	{ this, "(signal) right channel input" };
	outlet<>	out_left	{ this, "(signal) left channel output", "signal" };
	outlet<>	out_right	{ this, "(signal) right channel output", "signal" };


	elliptic(const atoms& args = {}) {
		if (args.empty() || args[0] == "lowpass") {
			m_filter = std::make_unique<Dsp::FilterDesign<Dsp::Elliptic::Design::LowPass<200>,2>>();
			m_filter_pending = std::make_unique<Dsp::FilterDesign<Dsp::Elliptic::Design::LowPass<200>,1>>();
		}
		else if (args[0] == "highpass") {
			m_filter = std::make_unique<Dsp::FilterDesign<Dsp::Elliptic::Design::HighPass<200>,2>>();
			m_filter_pending = std::make_unique<Dsp::FilterDesign<Dsp::Elliptic::Design::HighPass<200>,1>>();
		}
		else if (args[0] == "bandpass") {
			m_filter = std::make_unique<Dsp::FilterDesign<Dsp::Elliptic::Design::BandPass<200>,2>>();
			m_filter_pending = std::make_unique<Dsp::FilterDesign<Dsp::Elliptic::Design::BandPass<200>,1>>();
		}
		else if (args[0] == "bandstop") {
			m_filter = std::make_unique<Dsp::FilterDesign<Dsp::Elliptic::Design::BandStop<200>,2>>();
			m_filter_pending = std::make_unique<Dsp::FilterDesign<Dsp::Elliptic::Design::BandStop<200>,1>>();
		}
		else
			error("invalid argument");

		if (args[0] == "bandpass" || args[0] == "bandstop")
			m_is_bandpass_or_bandstop = true;

		update.set();
	}


	attribute<int> order { this, "order", 8,
		description { "Order of the filter." },
		range { 4, 200 }
	};


	attribute<double> frequency { this, "frequency", 4000.0,
		description { "Cutoff frequency of the filter." },
	};


	attribute<double> bandwidth { this, "bandwidth", 2000.0,
		description { "Width of the band in Hz for bandpass and bandstop filters." }
	};

	
	attribute<double> ripple { this, "ripple", 3.0,
		description { "Acceptable passband ripple in magnitude response." },
	};


	attribute<double> rolloff { this, "rolloff", 0.1,
		description { "Order of the filter." },
	};


	message<> bang { this, "bang", "Clear the filter history.",
		MIN_FUNCTION {
			m_filter.reset();
			return {};
		}
	};


	message<> notify { this, "notify",
		MIN_FUNCTION {
			symbol	msg = args[2];
			void*	sender = args[3];

			if (sender == maxobj() && msg == "attr_modified")
				update.set();
			return { 0 };
		}
	};


	queue update { this, MIN_FUNCTION {
		do_update();
		return {};
	}};


	void operator()(audio_bundle input, audio_bundle output) {
		output = input;
		if (m_update_pending) {
			(*m_filter) = (*m_filter_pending);
			m_update_pending = false;
		}
		m_filter->process(output.framecount(), output.samples());
	}


private:
	void do_update() {

		// if an update is already pending then we wait to try again in a moment
		// we can't update the request at this point because the audio thread might be accessing it

		if (m_update_pending)
			update.set();
		else {
			double order = (int)this->order;

			if (m_is_bandpass_or_bandstop) {
				m_filter->setParams({{
					samplerate(),
					order,
					frequency,
					bandwidth,
					ripple,
					rolloff,
				}});
			}
			else {
				m_filter->setParams({{
					samplerate(),
					order,
					frequency,
					ripple,
					rolloff,
				}});
			}
			m_update_pending = true;
		}
	}

};


MIN_EXTERNAL(elliptic);
