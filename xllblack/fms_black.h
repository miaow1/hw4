// fms_black.h - Black model
#pragma once
#include "fms_normal.h"
#include "math.h"

namespace fms::black {

    //!!! Black put and call code goes here.
 // Black-Scholes Call Price
	double BLACK_CALL(double f, double k, double t, double sigma)
	{
		double d = (log(f / k) + t * ( 0.5 * sigma * sigma)) / (sigma * sqrt(t));
		double call = f * fms::normal::cdf(d) - exp(0 *t) * k * fms::normal::cdf(d - sigma * sqrt(t));
		
		return call;

	}
	// Black-Scholes put Price
	double BLACK_PUT(double f, double k, double t, double sigma)
	{
		double d = (log(f / k) + t * ( 0.5 * sigma * sigma)) / (sigma * sqrt(t));
		double put = exp(0 * t) * k * fms::normal::cdf(sigma * sqrt(t) - d) - f * fms::normal::cdf(-d);
		
		return put;
	
	}
	
	//!!! Use the functions in fms_normal.h

} // fms::black