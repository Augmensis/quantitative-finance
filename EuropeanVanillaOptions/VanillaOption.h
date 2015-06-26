#pragma once

class VanillaOption
{
public:
	VanillaOption();
	VanillaOption(const double& _K, const double& _r, const double& _T, const double& _S, const double& _sigma);
	VanillaOption(const VanillaOption& rhs);			// Copy Constructor
	VanillaOption& operator=(const VanillaOption& rhs); // Assignmet operator
	virtual ~VanillaOption();

	double getK() const;
	double getr() const;
	double getT() const;
	double getS() const;
	double getsigma() const;
	
	double calc_call_price() const;
	double calc_put_price() const;


private:
	void init();
	void copy(const VanillaOption& rhs);

	double K;		// Strike Price
	double r;		// Risk-free Rate
	double T;		// Maturity Time
	double S;		// Underlying asset price
	double sigma;	// Volatility of underlying asset

};



