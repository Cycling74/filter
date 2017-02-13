/// @file
/// @copyright	Copyright (c) 2017, Cycling '74
/// @author		Timothy Place
/// @license	Usage of this file and its contents is governed by the MIT License

#include "c74_min.h"
#include "DspFilters/Filter.h"

using namespace c74::min;


template<class T, int channel_count, bool has_ripple = true, bool has_rolloff = true>
class filter : public object<T> {
public:

	filter(const atoms& args) {
		update.set();
	}


	attribute<int> order { this, "order", 8,
		description { "Order of the filter." },
//		range { 4, 24 }
	};


	attribute<symbol> response { this, "response", "lowpass",
		description { "Response or shape of the filter." },
		range { "lowpass", "highpass", "bandpass", "bandstop" },
	};


	attribute<double> frequency { this, "frequency", 4000.0,
		description { "Cutoff/center frequency of the filter." },
	};


	attribute<double> bandwidth { this, "bandwidth", 2000.0,
		description { "Width of the band in Hz for bandpass and bandstop filters." }
	};


	attribute<double> ripple { this, "ripple", 3.0,
		description { "Acceptable passband ripple in magnitude response." },
		visibility { has_ripple ? visibility::show : visibility::disable }
	};


	attribute<double> rolloff { this, "rolloff", 0.1,
		description { "Order of the filter." },
		visibility { has_ripple ? visibility::show : visibility::disable }
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

			if (sender == this->maxobj() && msg == "attr_modified")
				update.set();
			return { 0 };
		}
	};


	queue update { this, MIN_FUNCTION {
		do_update();
		return {};
	}};


	virtual double samplerate() = 0;


protected:

	std::unique_ptr<Dsp::Filter>	m_filter;
	std::unique_ptr<Dsp::Filter>	m_filter_pending;
	bool							m_is_bandpass_or_bandstop { false };
	std::atomic<bool>				m_update_pending { false };
	

private:
	
	void create_pending_filter() {
		if (response == symbol("lowpass"))			m_filter_pending = std::make_unique<Dsp::FilterDesign<LowPass<24>,channel_count>>();
		else if (response == symbol("highpass"))	m_filter_pending = std::make_unique<Dsp::FilterDesign<HighPass<24>,channel_count>>();
		else if (response == symbol("bandpass"))	m_filter_pending = std::make_unique<Dsp::FilterDesign<BandPass<24>,channel_count>>();
		else if (response == symbol("bandstop"))	m_filter_pending = std::make_unique<Dsp::FilterDesign<BandStop<24>,channel_count>>();
		else error("invalid response");

		if (response == symbol("bandpass") || response == symbol("bandstop"))
			m_is_bandpass_or_bandstop = true;
	}


	void do_update() {

		// if an update is already pending then we wait to try again in a moment
		// we can't update the request at this point because the audio thread might be accessing it

		if (m_update_pending)
			update.set();
		else {
			double order = (int)this->order;

			create_pending_filter();

			if (m_is_bandpass_or_bandstop) {
				m_filter_pending->setParams({{
					samplerate(),
					order,
					frequency,
					bandwidth,
					ripple,
					rolloff,
				}});
			}
			else {
				m_filter_pending->setParams({{
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
