// fms_black.h - Black model
#pragma once
#include "fms_normal.h"

namespace fms::black {
	inline double put(double f, double sigma, double k, double t) {
		double d2 = (log(f / k) - sigma * sigma * t / 2) / (sigma * sqrt(t));
		double d1 = d2 + sigma * sqrt(t);
		double putvalue = k * fms::normal::cdf(-d2) - f * fms::normal::cdf(-d1);
		return putvalue;
	}

	inline double call(double f, double sigma, double k, double t) {
		double d2 = (log(f / k) - sigma * sigma * t / 2) / (sigma * sqrt(t));
		double d1 = d2 + sigma * sqrt(t);
		double callvalue = f * fms::normal::cdf(d1) - k * fms::normal::cdf(d2);
		return callvalue;
	}
    //!!! Black put and call code goes here.
    //!!! Use the functions in fms_normal.h

} // fms::black