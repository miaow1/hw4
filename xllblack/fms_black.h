// fms_black.h - Black model
#pragma once
#include "fms_normal.h"

namespace fms::black {

    //!!! Black put and call code goes here.
    //!!! Use the functions in fms_normal.h

	inline double put(double f, double sigma, double k, double t)
	{
		double d2 = (log(f/ k)- pow(sigma, 2) * t / 2) / (sigma * sqrt(t));
		double d1 = d2 + sigma * sqrt(t);
		return k * fms::normal::cdf(-d2) - f * fms::normal::cdf(-d1);
	}

	inline double call(double f, double sigma, double k, double t)
	{
		double d2 = (log(f / k) - pow(sigma, 2) * t / 2) / (sigma * sqrt(t));
		double d1 = d2 + sigma * sqrt(t);
		return f * fms::normal::cdf(d1) - k * fms::normal::cdf(d2);
	}

} // fms::black