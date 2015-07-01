#include "PayOffPut.h"


PayOffPut::PayOffPut(const double _K)
{
	K = _K;
}


PayOffPut::~PayOffPut()
{
}

double PayOffPut::operator()(const double S) const
{
	return std::max(K - S, 0.0); // Standard European put payoff
}
