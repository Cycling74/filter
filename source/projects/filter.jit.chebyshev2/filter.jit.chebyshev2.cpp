/// @file
/// @copyright	Copyright (c) 2017, Cycling '74
/// @author		Timothy Place
/// @license	Usage of this file and its contents is governed by the MIT License

#include "DspFilters/ChebyshevII.h"
using namespace Dsp::ChebyshevII::Design;
#include "../filter.h"


class jit_chebyshev2 : public filter_mop<jit_chebyshev2> {
public:

	MIN_DESCRIPTION { "Nth-order Chebyshev Type-II filter. "
					  "The Chebyshev Type-II filter is similar to its Type-1 counterpart except ripples "
					  "are introduced in the stopband. It also has " 
					  "a slightly slower rolloff than Type-I." };
	MIN_TAGS		{ "filters" };
	MIN_AUTHOR		{ "Cycling '74" };
	MIN_RELATED		{ "filterdesign, filterdetail, slide, filter.chebyshev2~" };

	inlet<>		in	{ this, "(matrix) input to be filtered", "matrix" };
	outlet<>	out	{ this, "(matrix) filtered output", "matrix" };

	jit_chebyshev2(const atoms& args = {})
	: filter_mop(args)
	{}
};


MIN_EXTERNAL(jit_chebyshev2);
