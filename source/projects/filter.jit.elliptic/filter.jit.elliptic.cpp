/// @file
/// @copyright	Copyright (c) 2017, Cycling '74
/// @author		Timothy Place
/// @license	Usage of this file and its contents is governed by the MIT License

#include "DspFilters/Elliptic.h"
using namespace Dsp::Elliptic::Design;

#include "c74_min.h"
#include "DspFilters/Filter.h"
using namespace c74::min;


class jit_elliptic : public object<jit_elliptic>, public matrix_operator {
public:

	MIN_DESCRIPTION { "Nth-order elliptic filter" };
	MIN_TAGS		{ "filters" };
	MIN_AUTHOR		{ "Cycling '74" };
	MIN_RELATED		{ "filterdesign, filterdetail, slide, filter.elliptic~" };

	inlet<>		in	{ this, "(matrix) input to be filtered", "matrix" };
	outlet<>	out	{ this, "(matrix) filtered output", "matrix" };

	jit_elliptic(const atoms& args = {})
	: matrix_operator(false)
	{
		auto planecount = 4;
		for (auto i=0; i<planecount; ++i) {
			m_filters.push_back(std::make_unique<Dsp::FilterDesign<LowPass<24>, 1>>());
		}

		for (auto& filter : m_filters) {
			filter->setParams({{
				1.0, //			samplerate(),
				8, //			order,
				0.25, //			frequency,
				3.0,//			ripple,
				-2.0,	//		rolloff,
			}});
		}
	}


	template<class matrix_type, size_t planecount>
	cell<matrix_type,planecount> calc_cell(cell<matrix_type,planecount> input, const matrix_info& info, matrix_coord& position) {
		cell<matrix_type,planecount> output;

		m_x = position.x();
		if (position.y() != m_y) {
			m_y = position.y();
			for (auto& filter : m_filters)
				filter->reset();
		}

		for (auto plane=0; plane<info.planecount(); ++plane) {
			double x[1];

			if (is_same<matrix_type, unsigned char>::value)
				x[0] = input[plane] / 255.0;
			else
				x[0] = input[plane];

			double* y = x;
			m_filters[plane]->process(1, &y);

			if (is_same<matrix_type, unsigned char>::value)
				output[plane] = *y * 255.0;
			else
				output[plane] = *y;
		}
		return output;
	}

private:
	vector<unique_ptr<Dsp::Filter>>	m_filters;
	int								m_x {};
	int								m_y {};
};


MIN_EXTERNAL(jit_elliptic);
