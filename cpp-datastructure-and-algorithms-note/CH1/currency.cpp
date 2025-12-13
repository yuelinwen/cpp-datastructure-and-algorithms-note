#include "currency.h"

currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents) {
	setValue(theSign, theDollars, theCents);
}

void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents) {
	if (theCents > 99)
		std::cout << "Cents shuld be < 100" << std::endl;
	amount = theDollars * 100 + theCents;
	if (theSign == minus) amount = -amount;
}

void currency::setValut(double theAmount) {
	if (theAmount < 0)
		amount = (long)((theAmount - 0.001) * 100);
	else
		amount = (long)((theAmount + 0.001) * 100);
}

currency currency::operator+(const currency& x)const {
	currency result;
	result.amount = amount + x.amount;
	return result;
}

// “辅助打印函数”，封装了“对象如何打印”的逻辑，但是可以Friend function来代替
//void currency::output(std::ostream& out) const {
//	long theAmount = amount;
//	if (theAmount < 0) { out << '-'; theAmount = -theAmount; }
//	long dollars = theAmount / 100;
//	out << '$' << dollars << '.';
//	int cents = theAmount - dollars * 100;
//	if (cents < 10) out << '0';
//	out << cents;
//}

std::ostream& operator<<(std::ostream& out, const currency& x) {
	if (x.getSign() == minus) out << '-';
	out << '$' << x.getDollars() << '.';
	unsigned int cents = x.getCents();
	if (cents < 10) out << '0';
	out << cents;
	return out;
}
// 为什么要把 operator<< 定义成类外的非成员函数？
// 1. 必须是非成员函数：因为 cout 在左边。
// 2. 写成 Friend 的原因：为了让这个非成员函数能读取 private 数据。


