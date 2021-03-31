/// @file
/// @copyright	Copyright (c) 2017, Cycling '74
/// @author		Timothy Place
/// @license	Usage of this file and its contents is governed by the MIT License

#include "DspFilters/Elliptic.h"
using namespace Dsp::Elliptic::Design;
#include "../filter.h"


class elliptic : public filter<elliptic>, public vector_operator<> {
public:

	MIN_DESCRIPTION { "Nth-order elliptic filter. "
					  "The Elliptic filter combines elements of both Chebyshev filters to produce a maximally-steep rolloff. "
					  "It is possible to configure the trade-off of the ripple in stop- and passbands." };
	MIN_TAGS		{ "audio, filters" };
	MIN_AUTHOR		{ "Cycling '74" };
	MIN_RELATED		{ "filterdesign, filterdetail, biquad~, cascade~" };

	inlet<>		m_inlet		{ this, "(signal) input" };
	outlet<>	m_outlet	{ this, "(signal) output", "signal" };


	elliptic(const atoms& args = {})
	: filter(args)
	{}


	void operator()(audio_bundle input, audio_bundle output) {
		output = input;
		if (m_update_pending) {
			m_filter = std::move(m_filter_pending);
			m_update_pending = false;
		}
		m_filter->process(output.frame_count(), output.samples());
	}


	double samplerate() {
		return vector_operator::samplerate();
	}
    
    void samplerate(double a_samplerate) {
        vector_operator::samplerate(a_samplerate);
    }

};


MIN_EXTERNAL(elliptic);
