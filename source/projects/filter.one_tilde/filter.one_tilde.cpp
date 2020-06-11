/// @file
///	@ingroup 	minexamples
///	@copyright	Copyright 2018 The Min-DevKit Authors. All rights reserved.
///	@license	Use of this source code is governed by the MIT License found in the License.md file.

#include "c74_min.h"

using namespace c74::min;


class integrator {
public:
	sample operator()(sample x) {
		sample sum1 = x + m_history;
		sample sum2 = sum1 + m_history;
		sample y = sum2 * 0.5;
		m_history = sum1;
		return y;
	}
private:
	sample m_history { 0 };
};


class one : public object<one>, public sample_operator<1,2> {
public:
	MIN_DESCRIPTION {"One pole filter. "};
	MIN_TAGS {"audio, filters"};
	MIN_AUTHOR {"Cycling '74"};
	MIN_RELATED {"onepole~, filterdesign"};

	inlet<>  m_inlet_decay		{this, "(signal) to filter" };
	outlet<> m_outlet			{this, "(signal) lowpass", "signal"};
	outlet<> m_outlet_active	{this, "(signal) highpass", "signal"};

	attribute<number> m_cutoff {this, "cutoff", false, description {"Cutoff frequency."}};

/*	samples<2> operator()(sample x) {
		sample diff = x - m_feedback;
		sample y = m_integrator(diff * m_cutoff);
		sample highpass = m_x - y;
		m_x = x;
		m_feedback = y;
		return {y, highpass}; // lowpass, highpass
	}
*/
	samples<2> operator()(sample x) {
		sample diff = x - m_feedback;
		sample y = m_integrator(diff * m_cutoff);
//		sample highpass = m_x - y;
//		m_x = x;
		m_feedback = y;
		return {y, 0.0}; // lowpass, highpass
	}

private:
	integrator	m_integrator;
	sample 		m_feedback {0};
//	sample		m_x {0}; // have to delay input to keep in phase and keep response to 1 pole
};

MIN_EXTERNAL(one);
