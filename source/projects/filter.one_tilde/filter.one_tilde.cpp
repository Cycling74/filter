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
	MIN_DESCRIPTION {"Single-channel, basic one-pole filter"};
	MIN_TAGS {"audio, filters"};
	MIN_AUTHOR {"Cycling '74"};
	MIN_RELATED {"onepole~, filterdesign"};

	inlet<>  m_inlet_decay		{this, "(signal) to filter" };
	outlet<> m_outlet			{this, "(signal) lowpass", "signal"};
	outlet<> m_outlet_active	{this, "(signal) highpass", "signal"};

	attribute<number, threadsafe::no, limit::clamp> m_cutoff {this, "cutoff", false, 
		description {"Cutoff frequency."},
		range { 0.0, 1.0 }
	};

	samples<2> operator()(sample x) {
		sample diff = x - m_feedback;
		sample y = m_integrator(diff * m_cutoff);
		m_feedback = y;
		return {y, 0.0};  // lowpass, highpass
	}

private:
	integrator	m_integrator;
	sample 		m_feedback {0};
};

MIN_EXTERNAL(one);
