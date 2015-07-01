#pragma once
#include "PayOff.h"
class PayOffCall :	public PayOff
{
private:
	double K; // strike price

public:
	PayOffCall(const double K_);
	virtual ~PayOffCall();

	virtual double operator() (const double S) const; // Payoff is max(S-K, 0)
};

