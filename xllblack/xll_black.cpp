// xll_black.cpp
#include "fms_black.h"
#include "xll_black.h"
using namespace fms::black;
using namespace xll;

//!!! Implement XLL.BLACK.PUT(f, sigma, k, t) and XLL.BLACK.CALL(f, sigma, k, t)
//!!! Document both function.
//!!! Test both function. 
//!!! put = 3.988 to three decimal places for f = 100, sigma = 0.2, k = 100, t = 0.25.
//!!! Also test call value for these parameters.

// XLL.BLACK.PUT(f, sigma, k, t)
static AddIn xai_black_put(
	Function(XLL_DOUBLE, L"?xll_black_put", L"XLL.BLACK_PUT")
	.Arg(XLL_DOUBLE, L"f", L"is the current option price.")
	.Arg(XLL_DOUBLE, L"k", L"is the exercise price.")
	.Arg(XLL_DOUBLE, L"t", L"is the maturity period.")
	.Arg(XLL_DOUBLE, L"sigma", L"is the Volatility.")
	.Category(L"xll")
	.FunctionHelp(L"Return the expected put value for given option.")
);
double WINAPI xll_black_put(double f, double k, double t, double sigma)
{
#pragma XLLEXPORT
	return BLACK_PUT(f, k, t, sigma);
}
#ifdef _DEBUG

xll::test test_xll_black_put([]() {
	double test_result;
	double f = 150;
	double k = 150;
	double t = 0.5;
	double sigma = 0.2;
	test_result = BLACK_PUT(f, k, t, sigma);
	ensure((test_result - 8.4558) < 0.001);
	});

#endif // _DEBUG

// XLL.BLACK.CALL(f, sigma, k, t)
static AddIn xai_black_call(
	Function(XLL_DOUBLE, L"?xll_black_call", L"XLL.BLACK.CALL")
	.Arg(XLL_DOUBLE, L"f", L"is the current option price.")
	.Arg(XLL_DOUBLE, L"k", L"is the exercise price.")
	.Arg(XLL_DOUBLE, L"t", L"is the maturity period.")
	.Arg(XLL_DOUBLE, L"sigma", L"is the Volatility.")
	.Category(L"xll")
	.FunctionHelp(L"Return the expected call value for given option.")
);
double WINAPI xll_black_call(double f, double k, double t, double sigma)
{
#pragma XLLEXPORT
	return BLACK_CALL(f, k, t, sigma);
}

#ifdef _DEBUG

xll::test test_xll_black_put([]() {
	double test_result;
	double f = 150;
	double k = 150;
	double t = 0.5;
	double sigma = 0.2;
	test_result = BLACK_PUT(f, k, t, sigma);
	ensure((test_result - 8.4558) < 0.001);
	});

#endif // _DEBUG
//TEST BASED ON THE PARAMETERS GIVEN BY PROFESSOR.

#ifdef _DEBUG

xll::test test_xll_black_put([]() {
	double test_Result;
	double f = 100;
	double k = 100;
	double t = 0.25;
	double sigma = 0.2;
	test_Result = BLACK_PUT(f, k, t, sigma);
	ensure((test_Result - 3.988) < 0.001);
	});
#endif // _DEBUG

#ifdef _DEBUG

xll::test test_xll_blackcall([]() {
	double test_Result;
	double f = 100;
	double k = 100;
	double t = 0.25;
	double sigma = 0.2;
	test_Result = BLACK_CALL(f, k, t, sigma);
	ensure((test_Result - 3.988) < 0.001);
	});
#endif // _DEBUG









