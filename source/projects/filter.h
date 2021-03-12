/// @file
/// @copyright	Copyright (c) 2017, Cycling '74
/// @author		Timothy Place
/// @license	Usage of this file and its contents is governed by the MIT License

#include "c74_min.h"
#include "DspFilters/Filter.h"

using namespace c74::min;


template<class T, bool has_ripple = true, bool has_rolloff = true>
class filter : public object<T> {
public:

	filter(const atoms& args) {
		update.set();
	}


	queue<> update { this, MIN_FUNCTION {
		do_update();
		return {};
	}};


	attribute<int, threadsafe::no, limit::clamp> order { this, "order", 8,
		description { "Order of the filter." },
		range { 4, 24 }
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
		visibility { has_rolloff ? visibility::show : visibility::disable }
	};


	message<> bang { this, "bang", "Clear the filter history.",
		MIN_FUNCTION {
			m_filter->reset();
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


	virtual double samplerate() = 0;


protected:

	std::unique_ptr<Dsp::Filter>	m_filter;
	std::unique_ptr<Dsp::Filter>	m_filter_pending;
	bool							m_is_bandpass_or_bandstop { false };
	std::atomic<bool>				m_update_pending { false };
	

private:
	
	void create_pending_filter() {
		if (response == symbol("lowpass"))			m_filter_pending = std::make_unique<Dsp::FilterDesign<LowPass<24>,1>>();
		else if (response == symbol("highpass"))	m_filter_pending = std::make_unique<Dsp::FilterDesign<HighPass<24>,1>>();
		else if (response == symbol("bandpass"))	m_filter_pending = std::make_unique<Dsp::FilterDesign<BandPass<24>,1>>();
		else if (response == symbol("bandstop"))	m_filter_pending = std::make_unique<Dsp::FilterDesign<BandStop<24>,1>>();
		else error("invalid response");

		if (response == symbol("bandpass") || response == symbol("bandstop"))
			m_is_bandpass_or_bandstop = true;
	}


	template<bool update_ripple = has_ripple>
	typename enable_if<update_ripple>::type
	do_update() {

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


	template<bool update_ripple = has_ripple>
	typename enable_if<!update_ripple>::type
	do_update() {

		// if an update is already pending then we wait to try again in a moment
		// we can't update the request at this point because the audio thread might be accessing it

		if (m_update_pending)
			update.set();
		else {
			double order = (int)this->order;

			create_pending_filter();

			auto rolloff = (double)this->rolloff;
			if (rolloff < 1.0)
				rolloff = 1.0;

			if (m_is_bandpass_or_bandstop) {
				m_filter_pending->setParams({{
					samplerate(),
					order,
					frequency,
					bandwidth,
					rolloff,
				}});
			}
			else {
				m_filter_pending->setParams({{
					samplerate(),
					order,
					frequency,
					rolloff,
				}});
			}
			m_update_pending = true;
		}
	}

};



template<class T, bool has_ripple = true, bool has_rolloff = true>
class filter_mop : public object<T>, public matrix_operator<> {
public:

	filter_mop(const atoms& args)
	: matrix_operator(false)		// disable the parallel processing matrix breakup
	{
		m_update.set();
	}


	queue<> m_update { this, MIN_FUNCTION {
		do_update();
		return {};
	}};


	attribute<int> m_maxplanecount { this, "maxplanecount", 4,
		description { "Maximum number planes in the matrix to process." },
		setter { MIN_FUNCTION {	m_update.set(); return args; }}
		//		range { 1, 32 }
	};



	attribute<matrix_operator::iteration_direction> m_direction {
		this,
		"direction",
		matrix_operator::iteration_direction::forward,
		matrix_operator::iteration_direction_info,
		setter { MIN_FUNCTION {
			direction(args[0]);
			return args;
		}}
	};



	attribute<int> m_order { this, "order", 8,
		description { "Order of the filter." },
		setter { MIN_FUNCTION {	m_update.set(); return args; }}
		//		range { 4, 24 }
	};


	attribute<symbol> m_response { this, "response", "lowpass",
		description { "Response or shape of the filter." },
		range { "lowpass", "highpass", "bandpass", "bandstop" },
		setter { MIN_FUNCTION {	m_update.set(); return args; }}
	};


	attribute<double> m_frequency { this, "frequency", 0.25,
		description { "Cutoff/center frequency of the filter." },
		setter { MIN_FUNCTION {	m_update.set(); return args; }}
	};


	attribute<double> m_bandwidth { this, "bandwidth", 0.1,
		description { "Width of the band in Hz for bandpass and bandstop filters." },
		setter { MIN_FUNCTION {	m_update.set(); return args; }}
	};


	attribute<double> m_ripple { this, "ripple", 3.0,
		description { "Acceptable passband ripple in magnitude response." },
		visibility { has_ripple ? visibility::show : visibility::disable },
		setter { MIN_FUNCTION {	m_update.set(); return args; }}
	};


	attribute<double> m_rolloff { this, "rolloff", 0.1,
		description { "Order of the filter." },
		visibility { has_rolloff ? visibility::show : visibility::disable },
		setter { MIN_FUNCTION {	m_update.set(); return args; }}
	};


	message<> m_clear { this, "clear", "Clear the filter history.",
		MIN_FUNCTION {
			for (auto& filter : m_filters)
				filter->reset();
			return {};
		}
	};


	template<class matrix_type, size_t planecount>
	cell<matrix_type,planecount> calc_cell(cell<matrix_type,planecount> input, const matrix_info& info, matrix_coord& position) {
		cell<matrix_type,planecount> output;

		if (position.y() != m_y) {
			m_y = position.y();
			for (auto& filter : m_filters)
				filter->reset();
		}

		for (auto plane=0; plane<info.plane_count(); ++plane) {
			double x[1];

			if (is_same<matrix_type, unsigned char>::value)
				x[0] = input[plane] / 255.0;
			else
				x[0] = input[plane];

			double* y = x;
			m_filters[plane]->process(1, &y);

			if (is_same<matrix_type, unsigned char>::value)
				output[plane] = *y * 255.0;
			else
				output[plane] = *y;
		}
		return output;
	}


protected:
	vector<unique_ptr<Dsp::Filter>>	m_filters;
	bool							m_is_bandpass_or_bandstop { false };
	int								m_y {};


private:

	void create_filters() {
		m_filters.clear();

		for (auto i=0; i<m_maxplanecount; ++i) {
			if (m_response == symbol("lowpass"))		m_filters.push_back(std::make_unique<Dsp::FilterDesign<LowPass<24>, 1>>());
			else if (m_response == symbol("highpass"))	m_filters.push_back(std::make_unique<Dsp::FilterDesign<HighPass<24>,1>>());
			else if (m_response == symbol("bandpass"))	m_filters.push_back(std::make_unique<Dsp::FilterDesign<BandPass<24>,1>>());
			else if (m_response == symbol("bandstop"))	m_filters.push_back(std::make_unique<Dsp::FilterDesign<BandStop<24>,1>>());
			else error("invalid response");
		}
		if (m_response == symbol("bandpass") || m_response == symbol("bandstop"))
			m_is_bandpass_or_bandstop = true;
	}


	template<bool update_ripple = has_ripple>
	typename enable_if<update_ripple>::type
	do_update() {
		double order = (int)m_order;

		create_filters();

		for (auto& filter : m_filters) {
			if (m_is_bandpass_or_bandstop) {
				filter->setParams({{
					1.0,
					order,
					m_frequency, // normalized freq (half-band = 0.25)
					m_bandwidth,
					m_ripple,
					m_rolloff,
				}});
			}
			else {
				filter->setParams({{
					1.0,
					order,
					m_frequency, // normalized freq (half-band = 0.25)
					m_ripple,
					m_rolloff,
				}});
			}
		}
	}


	template<bool update_ripple = has_ripple>
	typename enable_if<!update_ripple>::type
	do_update() {
		double order = (int)this->order;

		create_filters();

		auto rolloff = (double)this->rolloff;
		if (rolloff < 1.0)
			rolloff = 1.0;

		for (auto& filter : m_filters) {
			if (m_is_bandpass_or_bandstop) {
				filter->setParams({{
					1.0,
					order,
					m_frequency,
					m_bandwidth,
					rolloff,
				}});
			}
			else {
				filter->setParams({{
					1.0,
					order,
					m_frequency,
					rolloff,
				}});
			}
		}
	}

};
