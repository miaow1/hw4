// xll_black.cpp

//!!! Implement XLL.BLACK.PUT(f, sigma, k, t) and XLL.BLACK.CALL(f, sigma, k, t)
//!!! Document both function.
//!!! Test both function. 
//!!! put = 3.988 to three decimal places for f = 100, sigma = 0.2, k = 100, t = 0.25.
//!!! Also test call value for these parameters.

// xll_normal.cpp




// xll_normal.cpp
#include "fms_black.h"
#include "../xll12/xll/xll.h"
#include "../xll12/xll/shfb/entities.h"

#ifndef CATEGORY
#define CATEGORY L"XLL"
#endif

using namespace xll;

static AddIn xai_black_call(
	Function(XLL_DOUBLE, L"?xll_black_call", L"XLL.BCALL.PDF")
	.Arg(XLL_DOUBLE, L"f", L"is the current price")
	.Arg(XLL_DOUBLE, L"sigma", L"is the volatility")
	.Arg(XLL_DOUBLE, L"k", L"is the strike price")
	.Arg(XLL_DOUBLE, L"t", L"is the time span")
	.Category(CATEGORY)
	.FunctionHelp(L"calculate the call price")
	.Documentation(
		L"This function computes the call option price "
		L"using the black scholes formula"
		MATH_(L"e" SUP_(minus_ L"z" sup2_ L"/2") L"/" radic_ L"2" pi_)
	)
);
double WINAPI xll_black_call(double f, double sigma, double k,double t)
{
#pragma XLLEXPORT
	return fms::black::black_call(f,sigma,k,t);
}



#ifdef _DEBUG

test test_black_call([] {
	ensure(fabs(xll_black_call(100, 0.2, 100,0.25) -3.988) < 0.001);


	});

#endif





static AddIn xai_black_put(
	Function(XLL_DOUBLE, L"?xll_black_put", L"XLL.BPUT.PDF")
	.Arg(XLL_DOUBLE, L"f", L"is the current price")
	.Arg(XLL_DOUBLE, L"sigma", L"is the volatility")
	.Arg(XLL_DOUBLE, L"k", L"is the strike price")
	.Arg(XLL_DOUBLE, L"t", L"is the time span")
	.Category(CATEGORY)
	.FunctionHelp(L"calculate the put price")
	.Documentation(
		L"This function computes the put option price "
		L"using the black scholes formula"
		MATH_(L"e" SUP_(minus_ L"z" sup2_ L"/2") L"/" radic_ L"2" pi_)
	)
);
double WINAPI xll_black_put(double f, double sigma, double k, double t)
{
#pragma XLLEXPORT
	return fms::black::black_put(f, sigma, k, t);
}



#ifdef _DEBUG

test test_black_put([] {
	ensure(fabs(xll_black_put(100, 0.2, 100,0.25) -3.988) < 0.001);

	}); 

#endif
