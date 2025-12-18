#include <iostream>
using namespace std;


// 线性表的抽象类 LinearList（线性表）是“抽象概念”，没有实现代码的成员函数，用于定义了接口
// 包含纯虚函数
template <class T>
class linearList {
public:
	virtual ~linearList() {};
	virtual bool empty() const = 0; // 如果必须要在
	virtual int size() const = 0;
	virtual T& get(int theIndex) const = 0;
	virtual int indexOf(const T& theElement) const = 0;
	virtual void erase(int theIndex) = 0;
	virtual void insert(int theIndex, const T& theElement) = 0;
	virtual void output(std::ostream& out) const = 0;
}

// 改变一维数组的长度
template <class T>
void changeLength1D(T*& a, int oldLength, int newLength) {
	if (newLength < 0)
		throw "new length must be >= 0";
	T* temp = new T[newLength]; // 新数组
	int number = std::min(oldLength, newLength); // 复制元素个数
	for (int i = 0; i < number; i++)
		temp[i] = a[i];
	delete[] a; // 释放旧数组
	a = temp;
}

