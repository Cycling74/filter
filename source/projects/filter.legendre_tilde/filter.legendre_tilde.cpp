/// @file
/// @copyright	Copyright (c) 2017, Cycling '74
/// @author		Timothy Place
/// @license	Usage of this file and its contents is governed by the MIT License

#include "DspFilters/Legendre.h"
using namespace Dsp::Legendre::Design;
#include "../filter.h"


class legendre : public filter<legendre>, public vector_operator<> {
public:

	MIN_DESCRIPTION { "Nth-order Legendre filter. "
					  "The Legendre filter has a steeper slope than the Butterworth, but it is not truly flat in the passband. "
					  "However, it does have the benefit of having a monotonic frequency response which means it doesn't introduce ripples." };
	MIN_TAGS		{ "audio, filters" };
	MIN_AUTHOR		{ "Cycling '74" };
	MIN_RELATED		{ "filterdesign, filterdetail, biquad~, cascade~" };

	inlet<>		m_inlet		{ this, "(signal) input" };
	outlet<>	m_outlet	{ this, "(signal) output", "signal" };


	legendre(const atoms& args = {})
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


MIN_EXTERNAL(legendre);
