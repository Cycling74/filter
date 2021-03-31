/// @file
/// @copyright	Copyright (c) 2017, Cycling '74
/// @author		Timothy Place
/// @license	Usage of this file and its contents is governed by the MIT License

#include "DspFilters/ChebyshevI.h"
using namespace Dsp::ChebyshevI::Design;
#include "../filter.h"


class jit_chebyshev1 : public filter_mop<jit_chebyshev1> {
public:

	MIN_DESCRIPTION { "Nth-order Chebyshev Type-I filter. The Chebyshev Type-1 filter has a faster rolloff than any of the monotonic filters "
					  "(Bessel, Butterworth, and Legendre). The tradeoff is that it introduces ripples in the passbands of the frequency and phase responses. "
					  "It is possible to configure the amount of ripple (at the expense of steepness of the rolloff.)" };
	MIN_TAGS		{ "filters" };
	MIN_AUTHOR		{ "Cycling '74" };
	MIN_RELATED		{ "filterdesign, filterdetail, slide, filter.chebyshev1~" };

	inlet<>		in	{ this, "(matrix) input to be filtered", "matrix" };
	outlet<>	out	{ this, "(matrix) filtered output", "matrix" };

	jit_chebyshev1(const atoms& args = {})
	: filter_mop(args)
	{}
};


MIN_EXTERNAL(jit_chebyshev1);
