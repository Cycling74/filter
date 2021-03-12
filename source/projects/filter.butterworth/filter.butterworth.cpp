/// @file
/// @copyright	Copyright (c) 2017, Cycling '74
/// @author		Timothy Place
/// @license	Usage of this file and its contents is governed by the MIT License

#include "DspFilters/Butterworth.h"
using namespace Dsp::Butterworth::Design;
#include "../filter.h"


class butterworth : public filter<butterworth,false,false> {
public:

	MIN_DESCRIPTION { "Nth-order Butterworth filter" };
	MIN_TAGS		{ "filters" };
	MIN_AUTHOR		{ "Cycling '74" };
	MIN_RELATED		{ "filterdesign, filterdetail, slide, filter.butterworth" };

	inlet<>		m_inlet		{ this, "(number) input" };
	outlet<>	m_outlet	{ this, "(number) output" };

	
	butterworth(const atoms& args = {})
	: filter(args)
	{}


	attribute<double> m_samplerate { this, "samplerate", 44100.0,
		description { "Sampling frequency of the filter." },
	};


	double samplerate() override {
		return m_samplerate;
	}


	message<> number { this, "number", "Stream of numbers to be filtered.",
		MIN_FUNCTION {
			double x[1] { args[0] };
			double* y = x;

			// we use the pending filter because this object is threadsafe using a copy
			if (m_update_pending) {
				m_filter = std::move(m_filter_pending);
				m_update_pending = false;
			}
			m_filter->process(1, &y);

			m_outlet.send(*y);
			return {};
		}
	};
};


MIN_EXTERNAL(butterworth);
