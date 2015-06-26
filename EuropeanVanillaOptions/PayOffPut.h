#pragma once
#include "PayOff.h"
class PayOffPut : public PayOff
{
private:
	double K;

public:
	PayOffPut(const double K_){};
	virtual ~PayOffPut(){};

	virtual double operator() (const double S) const;
};

