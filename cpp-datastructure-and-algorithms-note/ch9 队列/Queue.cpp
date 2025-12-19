#include <iostream>
#include "arrayList.cpp"
#include "chainNode.cpp"

template<class T>
class queue
{
public:
	virtual ~queue() {}
	virtual bool empty() const = 0; // return true if the queue is empty
	virtual int size() const = 0; // return the number of elements in the queue
	virtual T& front() = 0; // return the front element
	virtual T& back() = 0; // return the back element
	virtual void pop() = 0; // remove the front element
	virtual void push(const T& e) = 0; // insert the element e at the back of the queue
};

// Array-based queue implementation 循环队列
template <class T>
class derivedArrayQueue : private arrayList<T>, public queue<T>
{
	public:
	derivedArrayQueue(int initialCapacity = 10) : arrayList<T>(initialCapacity) {}
	bool empty() const { return arrayList<T>::empty(); }
	int size() const { return arrayList<T>::size(); }
	T& front() {
		if (arrayList<T>::empty()) {
			throw "queue is empty";
		}
		return arrayList<T>::get(0);
	}
	T& back() {
		if (arrayList<T>::empty()) {
			throw "queue is empty";
		}
		return arrayList<T>::get(arrayList<T>::size() - 1);
	}
	void pop() {
		if (theFront == theBack) {
			throw "queue is empty"; // 已空，无法删除
		}
		theFront = (theFront + 1) % arrayLength;
		queue[theFront].~T(); // 可选：清除被删除元素
	}
	void push(const T& theElement) {
		if((theBack + 1 % arrayLength == theFront) ) {
			throw "queue is full"; // 已满，需要加倍长度
		}
		// 在队列尾部插入元素
		queueBack = (queueBack + 1) % arrayLength;
		queue[queueBack] = theElement;
	}
}

// Linked-list-based queue implementation
template <class T>
class linkedListQueue : public queue<T>
{
	public:
	linkedListQueue() {
		frontNode = backNode = nullptr;
		queueSize = 0;
	}
	~linkedListQueue() {
		while (!empty()) {
			pop();
		}
	}
	bool empty() const { return queueSize == 0; }
	int size() const { return queueSize; }
	T& front() {
		if (empty()) {
			throw "queue is empty";
		}
		return frontNode->element;
	}
	T& back() {
		if (empty()) {
			throw "queue is empty";
		}
		return backNode->element;
	}
	void pop() {
		if (empty()) {
			throw "queue is empty"; // 删除首元素
		}
		chainNode<T>* nextNode = queueNode -> next;
		delete queueFront;
		queueFront = nextNode;
		queueSize--;
	}
	void push(const T& theElement) {
		chainNode<T>* newNode = new chainNode<T>(theElement);
		if (empty()) { // 队列为空
			frontNode = newNode;
		} else {
			backNode->next = newNode; // 队列不为空
			backNode = newNode;
		}
		queueSize++;
	}
}