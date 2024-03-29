/// @file
/// @copyright	Copyright (c) 2017, Cycling '74
/// @author		Timothy Place
/// @license	Usage of this file and its contents is governed by the MIT License

#include "DspFilters/Elliptic.h"
using namespace Dsp::Elliptic::Design;
#include "../filter.h"


class jit_elliptic : public filter_mop<jit_elliptic> {
public:

	MIN_DESCRIPTION { "Nth-order elliptic filter. "
					  "The Elliptic filter combines elements of both Chebyshev filters to produce a maximally-steep rolloff. "
					  "It is possible to configure the trade-off of the ripple in stop- and passbands." };
	MIN_TAGS		{ "filters" };
	MIN_AUTHOR		{ "Cycling '74" };
	MIN_RELATED		{ "filterdesign, filterdetail, slide, filter.elliptic~" };

	inlet<>		in	{ this, "(matrix) input to be filtered", "matrix" };
	outlet<>	out	{ this, "(matrix) filtered output", "matrix" };

	jit_elliptic(const atoms& args = {})
	: filter_mop(args)
	{}
};


MIN_EXTERNAL(jit_elliptic);
