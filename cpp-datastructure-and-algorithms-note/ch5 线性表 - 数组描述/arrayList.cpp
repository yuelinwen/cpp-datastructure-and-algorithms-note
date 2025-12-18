#include <iostream>
#include "LinearList.cpp"
using namespace std;

// 数组描述
// arrayList （顺序表）是“具体实现方式”
template <class T>
class arrayList : public linearList<T> {
public: // public：谁都能访问
	arrayList(int initialCapacity = 10);
	arrayList(const arrayList<T>&);
	~arrayList() { delete[] element; }

	// ADT 具体实现
	bool empty() const { return listSize == 0; }
	int size() const { return listSize; }
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(std::ostream& out) const;

	// 其他方法
	int capacity() const { return arrayLength; }

protected: // protected：只有“自己 + 子类”能访问
	void checkIndex(int theIndex) const; // 检查下标合法性
	T* element; // 一维数组
	int arrayLength; // 数组长度
	int listSize; // 线性表元素个数
}

// arrayList 构造函数
template <class T>
arrayList::arrayList(int initialCapacity) {
	if (initialCapacity < 1)
		throw "initialCapacity must be > 0";
	arrayLength = initialCapacity;
	element = new T[arrayLength];
	listSize = 0;
}

// arrayList 复制构造函数
template <class T>
arrayList<T>::arrayList(const arrayList<T>& theList) {
	arrayLength = theList.arrayLength;
	listSize = theList.listSize;
	element = new T[arrayLength];
	for (int i = 0; i < listSize; i++)
		element[i] = theList.element[i];
}

// 检查下标合法性
template <class T>
void arrayList<T>::checkIndex(int theIndex) const {
	if (theIndex < 0 || theIndex >= listSize)
		throw "index out of range";
}

// 获取指定下标元素
template <class T>
T& arrayList<T>::get(int theIndex) const {
	checkIndex(theIndex);
	return element[theIndex];
}

// 查找指定元素下标
template<class T>
int arrayList<T>::indexOf(const T& theElement) const {
	for (int i = 0; i < listSize; i++)
		if (element[i] == theElement)
			return i;
	return -1; // 未找到
}

// 删除指定下标元素
template <class T>
void arrayList<T>::erase(int theIndex) {
	checkIndex(theIndex);
	for (int i = theIndex + 1; i < listSize; i++)
		element[i - 1] = element[i];
	listSize--;
}

// 在指定下标插入元素
template <class T>
void arrayList<T>::insert(int theIndex, const T& theElement) {
	if (theIndex < 0 || theIndex > listSize)
		throw "index out of range";
	if (listSize == arrayLength) { // 数组满，扩容
		changeLength1D(element, arrayLength, 2 * arrayLength);
		arrayLength *= 2; // 更新数组长度 加倍。因为扩容后数组长度是原来的两倍比增加1或2 要好
	}
	for (int i = listSize - 1; i >= theIndex; i--)
		element[i + 1] = element[i];
	element[theIndex] = theElement;
	listSize++;
}

template <class T>
void arrayList<T>::output(std::ostream& out) const {
	for (int i = 0; i < listSize; i++)
		out << element[i] << " ";
}

template <class T>
ostream& operator<<(ostream& out, const arrayList<T>& x) {
	x.output(out);
	return out;
}



