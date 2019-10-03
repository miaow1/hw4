// fms_black.h - Black model
#pragma once
#include "fms_normal.h"
#include <math.h>

namespace fms::black {
	inline double black_call(double f, double sigma, double k, double t)
	{
		double d1 = (log(f / k) + sigma * sigma / 2.0 * t) / (sigma * pow(t, 0.5));
		double d2= d1 - sigma * pow(t, 0.5);
		double Nd1 = fms::normal::cdf(d1);
		double Nd2 = fms::normal::cdf(d2);
		double call = f * Nd1 - k * Nd2;

		return call;
	}

	inline double black_put(double f, double sigma, double k, double t)
	{
		double d1 = (log(f / k) + sigma * sigma / 2.0 * t) / (sigma * pow(t, 0.5));
		double d2 = d1 - sigma * pow(t, 0.5);
		double Nnd1 = fms::normal::cdf(-d1);
		double Nnd2 = fms::normal::cdf(-d2);
		double put = k * Nnd2-f * Nnd1;

		return put;
	}


    //!!! Black put and call code goes here.
    //!!! Use the functions in fms_normal.h

} // fms::black


