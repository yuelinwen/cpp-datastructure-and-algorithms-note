#pragma once
#include <iostream>
enum signType { plus, minus };

class currency
{
private:
	long amount;
public:
	currency(
		signType sign = plus,
		unsigned long dollars = 0,
		unsigned int cents = 0);

	~currency() {};
	void setValue(signType, unsigned long, unsigned int);
	void setValut(double);
	signType getSign() const { 
		if (amount < 0) return minus;
		else return plus;
	};
	unsigned long getDollars() const { 
		if (amount < 0) return (-amount) / 100;
		else return amount / 100;
	}; // constant function
	unsigned int getCents() const { 
		if (amount < 0) return -amount - getDollars() * 100;
		else return amount - getDollars() * 100;
	};
	currency operator+(const currency&) const;
	currency& operator+=(const currency& x) { amount += x.amount; return *this; };
	void output(std::ostream&) const;
};

