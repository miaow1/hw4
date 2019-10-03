// xll_black.cpp
#include "fms_normal.h"
#include"fms_black.h"
#include "../xll12/xll/xll.h"
#include "../xll12/xll/shfb/entities.h"

#ifndef CATEGORY
#define CATEGORY L"XLL"
#endif


//!!! Implement XLL.BLACK.PUT(f, sigma, k, t) and XLL.BLACK.CALL(f, sigma, k, t)
//!!! Document both function.
//!!! Test both function. 
//!!! put = 3.988 to three decimal places for f = 100, sigma = 0.2, k = 100, t = 0.25.
//!!! Also test call value for these parameters.

using namespace xll;

static AddIn xai_black_put(
	Function(XLL_DOUBLE, L"?xll_black_put", L"XLL.BLACK.PUT")
	.Arg(XLL_DOUBLE, L"f", L"is the current price of underlying asset.")
	.Arg(XLL_DOUBLE, L"sigma", L"is the volatility of the price of underlying asset .")
	.Arg(XLL_DOUBLE, L"k", L"is the strike price of the option.")
	.Arg(XLL_DOUBLE, L"t", L"is time to option maturity")
	.Category(CATEGORY)
	.FunctionHelp(L"Return the value of put option.")
	.Documentation(
		L"This function computes the European put option price"
		L"using the standard normal density "
	)
);
double WINAPI xll_black_put(double f,double sigma, double k, double t)
{
#pragma XLLEXPORT
	
	return fms::black::put(f, sigma, k, t);
}

static AddIn xai_black_call(
	Function(XLL_DOUBLE, L"?xll_black_call", L"XLL.BLACK.CALL")
	.Arg(XLL_DOUBLE, L"f", L"is the current price of underlying asset.")
	.Arg(XLL_DOUBLE, L"sigma", L"is the volatility of the price of underlying asset .")
	.Arg(XLL_DOUBLE, L"k", L"is the strike price of the option.")
	.Arg(XLL_DOUBLE, L"t", L"is time to option maturity")
	.Category(CATEGORY)
	.FunctionHelp(L"Return the value of call option.")
	.Documentation(
		L"This function computes the European call option price "
		L"using the standard normal density "
	)
);
double WINAPI xll_black_call(double f, double sigma, double k, double t)
{
#pragma XLLEXPORT

	return fms::black::call(f, sigma, k, t);
}