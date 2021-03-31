/// @file
/// @copyright	Copyright (c) 2017, Cycling '74
/// @author		Timothy Place
/// @license	Usage of this file and its contents is governed by the MIT License

#include "DspFilters/ChebyshevI.h"
using namespace Dsp::ChebyshevI::Design;
#include "../filter.h"


class chebyshev : public filter<chebyshev,true,false>, public vector_operator<> {
public:

	MIN_DESCRIPTION { "Nth-order Chebyshev Type-I filter. The Chebyshev Type-1 filter has a faster rolloff than any of the monotonic filters "
					  "(Bessel, Butterworth, and Legendre). The tradeoff is that it introduces ripples in the passbands of the frequency and phase responses. "
					  "It is possible to configure the amount of ripple (at the expense of steepness of the rolloff.)" };
	MIN_TAGS		{ "audio, filters" };
	MIN_AUTHOR		{ "Cycling '74" };
	MIN_RELATED		{ "filterdesign, filterdetail, biquad~, cascade~" };

	inlet<>		m_inlet		{ this, "(signal) input" };
	outlet<>	m_outlet	{ this, "(signal) output", "signal" };


	chebyshev(const atoms& args = {})
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


MIN_EXTERNAL(chebyshev);
