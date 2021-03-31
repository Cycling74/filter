/// @file
/// @copyright	Copyright (c) 2017, Cycling '74
/// @author		Timothy Place
/// @license	Usage of this file and its contents is governed by the MIT License

#include "DspFilters/Legendre.h"
using namespace Dsp::Legendre::Design;
#include "../filter.h"


class jit_legendre : public filter_mop<jit_legendre> {
public:

	MIN_DESCRIPTION { "Nth-order Legendre filter. "
					  "The Legendre filter has a steeper slope than the Butterworth, but it is not truly flat in the passband. "
					  "However, it does have the benefit of having a monotonic frequency response which means it doesn't introduce ripples." };
	MIN_TAGS		{ "filters" };
	MIN_AUTHOR		{ "Cycling '74" };
	MIN_RELATED		{ "filterdesign, filterdetail, slide, filter.legendre~" };

	inlet<>		in	{ this, "(matrix) input to be filtered", "matrix" };
	outlet<>	out	{ this, "(matrix) filtered output", "matrix" };

	jit_legendre(const atoms& args = {})
	: filter_mop(args)
	{}
};


MIN_EXTERNAL(jit_legendre);
