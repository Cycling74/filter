/// @file	
///	@copyright	Copyright (c) 2017, Cycling '74
/// @author		Timothy Place
///	@license	Usage of this file and its contents is governed by the MIT License

#include "c74_min.h"
#include "DspFilters/Elliptic.h"

using namespace c74::min;

class elliptic : public object<elliptic> {
private:
	std::unique_ptr<Dsp::Filter>	m_filter;
	bool							m_is_bandpass_or_bandstop { false };

public:

	MIN_DESCRIPTION { "Nth-order elliptic lowpass filter" };
	MIN_TAGS		{ "filters" };
	MIN_AUTHOR		{ "Cycling '74" };
	MIN_RELATED		{ "filterdesign, filterdetail, slide, filter.elliptic" };

	inlet<>		in	{ this, "(number) input to be filtered" };
	outlet<>	out	{ this, "(number) filtered output" };


	elliptic(const atoms& args = {}) {
		if (args.empty() || args[0] == "lowpass")
			m_filter = std::make_unique<Dsp::FilterDesign<Dsp::Elliptic::Design::LowPass<200>,1>>();
		else if (args[0] == "highpass")
			m_filter = std::make_unique<Dsp::FilterDesign<Dsp::Elliptic::Design::HighPass<200>,1>>();
		else if (args[0] == "bandpass")
			m_filter = std::make_unique<Dsp::FilterDesign<Dsp::Elliptic::Design::BandPass<200>,1>>();
		else if (args[0] == "bandstop")
			m_filter = std::make_unique<Dsp::FilterDesign<Dsp::Elliptic::Design::BandStop<200>,1>>();
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
		description { "Cutoff/center frequency of the filter." },
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


	attribute<double> samplerate { this, "samplerate", 44100.0,
		description { "Sampling frequency of the filter." },
	};


	message<> number { this, "number", "Stream of numbers to be filtered.",
		MIN_FUNCTION {
			double x[1] { args[0] };
			double* y = x;
			m_filter->process(1, &y);
			out.send(*y);
			return {};
		}
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

	
private:
	void do_update() {
		double order = (int)this->order;

		if (m_is_bandpass_or_bandstop) {
			m_filter->setParams({{
				samplerate,
				order,
				frequency,
				bandwidth,
				ripple,
				rolloff,
			}});
		}
		else {
			m_filter->setParams({{
				samplerate,
				order,
				frequency,
				ripple,
				rolloff,
			}});
		}
	}

};


MIN_EXTERNAL(elliptic);
