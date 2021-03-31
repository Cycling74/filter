/// @file
/// @copyright	Copyright (c) 2017, Cycling '74
/// @author		Timothy Place
/// @license	Usage of this file and its contents is governed by the MIT License

#include "DspFilters/Butterworth.h"
using namespace Dsp::Butterworth::Design;
#include "../filter.h"


class jit_butterworth : public filter_mop<jit_butterworth> {
public:

	MIN_DESCRIPTION { "Nth-order Butterworth filter. "
					  "The Butterworth filter has a slightly faster rolloff than the Bessel filter. "
					  "It has a maximally-flat magnitude in the passband." };
	MIN_TAGS		{ "filters" };
	MIN_AUTHOR		{ "Cycling '74" };
	MIN_RELATED		{ "filterdesign, filterdetail, slide, filter.butterworth~" };

	inlet<>		in	{ this, "(matrix) input to be filtered", "matrix" };
	outlet<>	out	{ this, "(matrix) filtered output", "matrix" };

	jit_butterworth(const atoms& args = {})
	: filter_mop(args)
	{}
};


MIN_EXTERNAL(jit_butterworth);
