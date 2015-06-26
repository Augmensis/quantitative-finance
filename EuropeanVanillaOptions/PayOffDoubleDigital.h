#pragma once
#include "PayOff.h"
class PayOffDoubleDigital :	public PayOff
{
private:
	double U;	// Upper strike price
	double D;	// Lower strike price

public:
	PayOffDoubleDigital(const double U_, const double D_);
	virtual ~PayOffDoubleDigital();

	virtual double operator() (const double S) const;
};

// Page36