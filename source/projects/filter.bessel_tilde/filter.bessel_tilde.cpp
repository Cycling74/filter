/// @file
/// @copyright	Copyright (c) 2017, Cycling '74
/// @author		Timothy Place
/// @license	Usage of this file and its contents is governed by the MIT License

#include "DspFilters/Bessel.h"
using namespace Dsp::Bessel::Design;
#include "../filter.h"


class bessel : public filter<bessel,2,false,false>, public vector_operator {
public:

	MIN_DESCRIPTION { "Nth-order elliptic lowpass filter" };
	MIN_TAGS		{ "audio, filters" };
	MIN_AUTHOR		{ "Cycling '74" };
	MIN_RELATED		{ "filterdesign, filterdetail, biquad~, cascade~, filter.elliptic" };

	inlet<>		in_left		{ this, "(signal) left channel input" };
	inlet<>		in_right	{ this, "(signal) right channel input" };
	outlet<>	out_left	{ this, "(signal) left channel output", "signal" };
	outlet<>	out_right	{ this, "(signal) right channel output", "signal" };


	bessel(const atoms& args = {})
	: filter(args)
	{}


	void operator()(audio_bundle input, audio_bundle output) {
		output = input;
		if (m_update_pending) {
			m_filter = std::move(m_filter_pending);
			m_update_pending = false;
		}
		m_filter->process(output.framecount(), output.samples());
	}


	double samplerate() {
		return vector_operator::samplerate();
	}

};


MIN_EXTERNAL(bessel);
