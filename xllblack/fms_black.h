// fms_black.h - Black model
#pragma once
#include <math.h>
#include <stdexcept>
#include <utility>
#include "fms_normal.h"

namespace fms::black {

    //!!! Black put and call code goes here.
    //!!! Use the functions in fms_normal.h

	inline double put(double f, double sigma, double k, double t) {
		double r=0;
		double d1, d2;
		double p;

		d1 = (log(f / k) + (r + pow(sigma,2) / 2) * t) / (sigma * sqrt(t));
		d2 = d1 - sigma * sqrt(t);

		p = k * exp(-r * t) * fms::normal::cdf(-d2) - f * fms::normal::cdf(-d1);

		return p;
	}

	inline double call(double f, double sigma, double k, double t) {
		double r = 0;
		double d1, d2;
		double c;

		d1 = (log(f / k) + (r + pow(sigma,2) / 2) * t) / (sigma * sqrt(t));
		d2 = d1 - sigma * sqrt(t);

		c = f * fms::normal::cdf(d1) - k * exp(-r * t) * fms::normal::cdf(d2);

		return c;

		
	}

} // fms::black