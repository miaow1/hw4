// fms_black.h - Black model
#pragma once
#include "fms_normal.h"

namespace fms::black {

    //!!! Black put and call code goes here.
    //!!! Use the functions in fms_normal.h
	inline double pdf(double x, double mu = 0, double sigma = 1)
	{
		auto z = (x - mu) / sigma;

		return fms::normal::cdf(2);
	}
} // fms::black