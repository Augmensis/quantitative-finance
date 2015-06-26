// EuropeanCallOptions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "random.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Monte Carlo European Call Options";

	double T = 1;			// Maturity
	double K = 100;			// Strike Price
	double S0 = 100;		// Spot Price
	double sigma = 0.10;	// Volatility
	double r = 0.05;		// Interest Rate
	const int N = 500;			// Number of steps
	const int M = 10000;			// Number of simulations
	double S[N + 1];
	double sumPayoff = 0;
	double premium = 0;
	double dt = T / N;


	for (auto i = 0; i < M; i++)
	{
		S[0] = S0;

		for (auto j = 0; j < N; j++)
		{
			double epsilon = random::SampleBoxMuller();
			S[i + 1] = S[i] * (1 + r * dt + sigma * sqrt(dt) * epsilon);
		}

		sumPayoff += max(S[N] - K, 0.0);
	}

	premium = exp(-r * T) * (sumPayoff / M);

	cout << "\nCalculated Premium = " << premium;

	return 0;
}

