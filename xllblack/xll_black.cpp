// xll_black.cpp

//!!! Implement XLL.BLACK.PUT(f, sigma, k, t) and XLL.BLACK.CALL(f, sigma, k, t)
//!!! Document both function.
//!!! Test both function. 
//!!! put = 3.988 to three decimal places for f = 100, sigma = 0.2, k = 100, t = 0.25.
//!!! Also test call value for these parameters.

#include"fms_black.h"
#include "../xll12/xll/xll.h"
#include "../xll12/xll/shfb/entities.h"

#ifndef CATEGORY
#define CATEGORY L"XLL"
#endif

using namespace xll;

//Implement XLL.BLACK.PUT here--------------------------------------------------------------------
static AddIn xai_black_put(
	Function(XLL_DOUBLE, L"?xll_black_put", L"XLL.BLACK.PUT")
	.Arg(XLL_DOUBLE, L"f", L"is the current underlying price.")
	.Arg(XLL_DOUBLE, L"sigma", L"is the volatility.")
	.Arg(XLL_DOUBLE, L"k", L"is the strike price.")
	.Arg(XLL_DOUBLE, L"t", L"is the time to maturity")
	.Category(CATEGORY)
	.FunctionHelp(L"Return the price of the put option.")
	.Documentation(
		L"This function calculates the put option "
		L"using the price, volatility, strike price and time-to-maturity. "
		//MATH_(L"e" SUP_(minus_ L"z" sup2_ L"/2") L"/" radic_ L"2" pi_)
	)
);
double WINAPI xll_black_put(double f, double sigma, double k, double t)
{
#pragma XLLEXPORT
	/*if (sigma == 0) {
		sigma = 1;
	}*/

	return fms::black::put(f, sigma, k, t);
}

#ifdef _DEBUG

test test_black_put([] {
	ensure(fabs(xll_black_put(100, 0.2, 100, 0.25) - 3.988) < 1e-3);
	});

#endif

//Implement XLL.BLACK.CALL here-----------------------------------------------------------------------
static AddIn xai_black_call(
	Function(XLL_DOUBLE, L"?xll_black_call", L"XLL.BLACK.CALL")
	.Arg(XLL_DOUBLE, L"f", L"is the current underlying price.")
	.Arg(XLL_DOUBLE, L"sigma", L"is the volatility.")
	.Arg(XLL_DOUBLE, L"k", L"is the strike price.")
	.Arg(XLL_DOUBLE, L"t", L"is the time to maturity")
	.Category(CATEGORY)
	.FunctionHelp(L"Return the price of the call option.")
	.Documentation(
		L"This function calculates the call option "
		L"using the price, volatility, strike price and time-to-maturity. "
		//MATH_(L"e" SUP_(minus_ L"z" sup2_ L"/2") L"/" radic_ L"2" pi_)
	)
);
double WINAPI xll_black_call(double f, double sigma, double k, double t)
{
#pragma XLLEXPORT
	/*if (sigma == 0) {
		sigma = 1;
	}*/

	return fms::black::call(f, sigma, k, t);
}

#ifdef _DEBUG

test test_black_call([] {
	ensure(fabs(xll_black_call(100, 0.2, 100, 0.25) - 3.988) < 1e-3);
	});

#endif
