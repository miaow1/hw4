// fms_black.h - Black model
#pragma once
#include "fms_normal.h"

namespace fms::black {

    //!!! Black put and call code goes here.

	//XLL.BLACK.PUT(f, sigma, k, t)
	inline double put(double f, double sigma, double k, double t)
	{
		double d1 = (log(f / k) + (sigma * sigma * t/ 2)) / (sigma * sqrt(t));
		double d2 = d1 - (sigma * sqrt(t));

		double result = fms::normal::cdf(-d2) * k - fms::normal::cdf(-d1) * f;
		return result;
	}

	//XLL.BLACK.CALL(f, sigma, k, t)
	inline double call(double f, double sigma, double k, double t)
	{
		double d1 = (log(f / k) + (sigma * sigma * t / 2)) / (sigma * sqrt(t));
		double d2 = d1 - (sigma * sqrt(t));
		return fms::normal::cdf(d1) * f - fms::normal::cdf(d2) * k;
	}

} // fms::black