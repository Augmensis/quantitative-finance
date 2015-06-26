#include "VanillaOption.h"
#include <cmath>
#include "statistics.h"

VanillaOption::VanillaOption()
{
	init();
}


VanillaOption::~VanillaOption()
{
}


void VanillaOption::init()
{
	K = 100.0;		// Strike rate
	r = 0.05;		// 5% interest rate
	T = 1.0;		// 1 year to maturity
	S = 100.0;		// Option "at the money as spot == strike
	sigma = 0.2;	// Volatility = 20%
}


void VanillaOption::copy(const VanillaOption& rhs)
{
	K = rhs.getK();
	r = rhs.getr();
	T = rhs.getT();
	S = rhs.getS();
	sigma = rhs.getsigma();
}

VanillaOption::VanillaOption(const double& _K, const double& _r, const double& _T, const double& _S, const double& _sigma)
{
	K = _K;
	r = _r;
	T = _T;
	S = _S;
	sigma = _sigma;
}

VanillaOption::VanillaOption(const VanillaOption& rhs)
{
	copy(rhs);
}

VanillaOption& VanillaOption::operator=(const VanillaOption& rhs)
{
	if (this == &rhs) return *this;
	copy(rhs);
	return *this;
}

double VanillaOption::getK() const
{
	return K;
}

double VanillaOption::getr() const
{
	return r;
}

double VanillaOption::getT() const
{
	return T;
}

double VanillaOption::getS() const
{
	return S;
}

double VanillaOption::getsigma() const
{
	return sigma;
}

double VanillaOption::calc_call_price() const
{
	double sigmaSqrtT = sigma * sqrt(T);
	double d1 = (log(S / K) + (r + sigma * sigma * 0.5) * T) / sigmaSqrtT;
	double d2 = d1 - sigmaSqrtT;

	return S * statistics::N(d1) - K * exp(-r * T) * statistics::N(d2);
}

double VanillaOption::calc_put_price() const
{
	double sigmaSqrtT = sigma * sqrt(T);
	double d1 = (log(S / K) + (r + sigma * sigma * 0.5) * T) / sigmaSqrtT;
	double d2 = d1 - sigmaSqrtT;

	return K * exp(-r * T) * statistics::N(d2) - S * statistics::N(-d1);
}
