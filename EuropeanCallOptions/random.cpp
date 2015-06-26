#include "random.h"
#include <random>
#include <cstdlib>
#include <cmath>

random::random()
{
}


random::~random()
{
}


double random::SampleBoxMuller()
{
	double result;
	double x;
	double y;
	double xySquare;

	do
	{
		x = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
		y = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
		xySquare = x*x + y*y;
	} while (xySquare >= 1.0);
	{
		result = x * sqrt(-2 * log(xySquare) / xySquare);
		return result;
	}

}