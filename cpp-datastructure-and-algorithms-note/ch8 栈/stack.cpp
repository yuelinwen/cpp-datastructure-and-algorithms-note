// 问：C++ 中栈是什么？
// 答：栈（Stack）是一种** 后进先出（LIFO）** 的受限线性表，只允许在栈顶进行插入（push）和删除（pop）操作。

// 问：栈和队列替代数组或普通线性表的意义是什么？
// 答：栈和队列作为受限线性表，提供了更高效的插入和删除操作，避免了数组或普通线性表在这些操作中可能出现的性能瓶颈。

#include <iostream>
#include "arrayList.cpp"
#include "chainNode.cpp"

tempalte<class T>
class stack
{
public:
	virtual ~stack() {}
	virtual bool empty() const = 0; // return true if the stack is empty
	virtual int size() const = 0; // return the number of elements in the stack
	virtual T& top() = 0; //	return the top element
	virtual void pop() = 0; // remove the top element
	virtual void push(const T& x) = 0; // insert the element x at the top of the stack
};

// Array-based stack implementation
template<class T>
class derivedArrayStack : private arrayList<T>, public stack<T>
{
public:
	derivedArrayStack(int initialCapacity = 10) : arrayList<T>(initialCapacity) {}
	bool empty() const { return arrayList<T>::empty(); }
	int size() const { return arrayList<T>::size(); }
	T& top() { 
		if (arrayList<T>::empty()) { // check for empty stack
			throw stackEmpty();
		}
		return arrayList<T>::get(arrayList<T>::size() - 1); // return the last element
	}
	void pop() {
		if (arrayList<T>::empty()) {
			throw stackEmpty();
		}
		arrayList<T>::erase(arrayList<T>::size() - 1);
	}
	void push(const T& theElement) {
		arrayList<T>::insert(arrayList<T>::size(), theElement);
	}
}



// Linked-list-based stack implementation
template<class T>
class linkedStack: public stack<T>
{
public:
	linkedStack(int initialCapacity = 10) {
		stackTop = NULL; stackSize = 10;
	}
	~linkedStack();
	bool empty()cosnt { return stackSize == 0; }
	int size() const { return stackSize; }
	T& top() {
		if (stackTop == 0) {
			throw stackEmpty();
		}
		return stackTop->element; // return the top element
	}
	void pop() {
		if (stackTop == NULL) {
			throw stackEmpty();
		}
		chainNode<T>* nextNode = stackTop->next; // point to the next node
		delete stackTop; // delete the top node
		stackTop = nextNode;
		stackSize--;
	}
	void push (const T& theElement) {
		stackTop = new chainNode<T>(theElement, stackTop); // create a new node
		stackSize++;
	}
private:
	chainNode<T>* stackTop; // pointer to stack top
	int stackSize; // number of stack elements
};

template<class T>
linkedStack<T>::~linkedStack() {
	while (stackTop != NULL) {
		chainNode<T>* nextNode = stackTop->next;
		delete stackTop;
		stackTop = nextNode;
	}
}

