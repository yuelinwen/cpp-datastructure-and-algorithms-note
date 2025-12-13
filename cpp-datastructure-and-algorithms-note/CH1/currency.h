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
	void output(std::ostream&) const;  // “辅助打印函数”，封装了“对象如何打印”的逻辑
	// 	1.	output 是类的成员函数，可以直接访问私有数据。
	// 2.	operator<< 保持简洁，只负责和 C++ 标准流接口对接。
	// 3.	避免把所有打印逻辑都写进 operator<<，提高代码可维护性。
};

