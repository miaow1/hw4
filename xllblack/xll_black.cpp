// xll_black.cpp

//!!! Implement XLL.BLACK.PUT(f, sigma, k, t) and XLL.BLACK.CALL(f, sigma, k, t)
//!!! Document both function.
//!!! Test both function. 
//!!! put = 3.988 to three decimal places for f = 100, sigma = 0.2, k = 100, t = 0.25.
//!!! Also test call value for these parameters.

#include "../xll12/xll/xll.h"
#include "fms_black.h"

using namespace xll;
using namespace fms::black;

static AddIn xai_black_put(
	Function(XLL_DOUBLE, L"?xll_black_put",L"XLL_BLACK_PUT")
	.Arg(XLL_DOUBLE, L"f", L"is the current price of the underlying asset.")
	.Arg(XLL_DOUBLE, L"sigma", L"is the volatility of the underlying asset.")
	.Arg(XLL_DOUBLE, L"k", L"is the strike price of the option.")
	.Arg(XLL_DOUBLE, L"t", L"is the remaining time until the expiration of the option.")
	.Category(L"XLL")
	.FunctionHelp(L"Return the price of the put option determined by Black-Scholes model.")
	.Documentation(L"This function computes the price of the put option using the Black-Scholes model.")
);

double WINAPI xll_black_put(double f, double sigma, double k, double t)
{
#pragma XLLEXPORT
	return put(f, sigma, k, t);
}

#if _DEBUG
xll::test test_xll_black_put([]() {
	double f = 100, sigma = 0.2, k = 100, t = 0.25;
	double result = xll_black_put(f, sigma, k, t);
	ensure(fabs(result - 3.988) < 1e-3);
	});
#endif

static AddIn xai_black_call(
	Function(XLL_DOUBLE, L"?xll_black_call", L"XLL_BLACK_CALL")
	.Arg(XLL_DOUBLE, L"f", L"is the current price of the underlying asset.")
	.Arg(XLL_DOUBLE, L"sigma", L"is the volatility of the underlying asset.")
	.Arg(XLL_DOUBLE, L"k", L"is the strike price of the option.")
	.Arg(XLL_DOUBLE, L"t", L"is the remaining time until the expiration of the option.")
	.Category(L"XLL")
	.FunctionHelp(L"Return the price of the call option determined by Black-Scholes model.")
	.Documentation(L"This function computes the price of the call option using the Black-Scholes model.")
);

double WINAPI xll_black_call(double f, double sigma, double k, double t)
{
#pragma XLLEXPORT
	return call(f, sigma, k, t);
}


#if _DEBUG
xll::test test_xll_black_call([]() {
	double f = 100, sigma = 0.2, k = 100, t = 0.25;
	double result = xll_black_call(f, sigma, k, t);
	ensure(fabs(result - 3.988) < 1e-3);
});
#endif






