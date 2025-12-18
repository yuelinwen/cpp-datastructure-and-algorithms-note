
#include <iostream>
#include "LinearList.cpp"

template <class T>
class vectorList : public linearList<T>
{
public:
	// 构造函数
	vectorList(int initialCapacity = 10);
	vectorList(const vectorList<T>&);
	~vectorList() { delete[] element; }

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

	// 迭代器
	typedef typename vector<T>::iterator iterator;
	iterator begin() { return element; }
	iterator end() { return element + listSize; }

protected:
	void checkIndex(int theIndex) const; // 检查下标合法性
	vector<T> element; // 使用 vector 作为底层存储
};

// 构造函数
template <class T>
vectorList<T>::vectorList(int initialCapacity) {
	if (initialCapacity < 1)
		throw "initialCapacity must be > 0";
	elemnt = new vectorList<T>(initialCapacity);
	element->reserve(initialCapacity);
}

// 复制构造函数
template <class T>
vectorList<T>::vectorList(const vectorList<T>& theList){
	elemnt = new vectorList<T>(theList.capacity());
}

//删除
template <class T>
void vectorList<T>::erase(int theIndex) {
	checkIndex(theIndex);
	for (int i = theIndex + 1; i < listSize; i++)
		element[i - 1] = element[i];
	listSize--;
}

// 插入
template <class T>
void vectorList<T>::insert(int theIndex, const T& theElement) {
	if (theIndex < 0 || theIndex > listSize)
		throw "index out of range";
	if (listSize == arrayLength) {
		arrayLength *= 2;
		element.resize(arrayLength);
	}
	for (int i = listSize - 1; i >= theIndex; i--)
		element[i + 1] = element[i];
	element[theIndex] = theElement;
	listSize++;
}


