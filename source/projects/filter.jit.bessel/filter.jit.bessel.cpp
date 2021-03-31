/// @file
/// @copyright	Copyright (c) 2017, Cycling '74
/// @author		Timothy Place
/// @license	Usage of this file and its contents is governed by the MIT License

#include "DspFilters/Bessel.h"
using namespace Dsp::Bessel::Design;
#include "../filter.h"


class jit_bessel : public filter_mop<jit_bessel> {
public:

	MIN_DESCRIPTION { "Nth-order Bessel filter. " 
					  "The Bessel filter has the slowest rolloff but maximally-linear phase response." };
	MIN_TAGS		{ "filters" };
	MIN_AUTHOR		{ "Cycling '74" };
	MIN_RELATED		{ "filterdesign, filterdetail, slide, filter.bessel~" };

	inlet<>		in	{ this, "(matrix) input to be filtered", "matrix" };
	outlet<>	out	{ this, "(matrix) filtered output", "matrix" };

	jit_bessel(const atoms& args = {})
	: filter_mop(args)
	{}
};


MIN_EXTERNAL(jit_bessel);
