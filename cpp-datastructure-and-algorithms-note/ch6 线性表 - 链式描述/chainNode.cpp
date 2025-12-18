#include "linearList.cpp"

// 单向链表节点类

template <class T>
struct chainNode
{
	T element;
	chainNode<T>* next;

	chainNode() {};
	chainNode(const T& element) : element(element) {};
	chainNode(const T& element, chainNode<T>* next) : element(element), next(next) {};
};


template <class T>
class chain : public linearList<T>
{
public:
	// 构造函数, 复制构造函数和析构函数
	chain(int initialCapacity = 10);
	chain(const chain<T>&);
	~chain();

	// 抽象数据类型ADT的方法
	bool empty() const { return listSize == 0; };
	int size() const { return listSize; };
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(std::ostream& out) const;

protected:
	void checkIndex(int theIndex) const;
	chainNode<T>* firstNode; // 指向链表第一个节点的指针
	int listSize;          // 线性表的元素个数
};

template <class T>
chain<T>::chain(int initialCapacity)
{
	if (initialCapacity < 1)
		throw "initialCapacity must be > 0";
	firstNode = nullptr;
	listSize = 0;
}

template <class T>
chain<T>::chain(const chain<T>& theList)
{
	listSize = theList.listSize;
	if (listSize == 0)
	{
		firstNode = nullptr;
		return;
	}
	// 复制链表的第一个节点
	chainNode<T>* sourceNode = theList.firstNode;
	firstNode = new chainNode<T>(sourceNode->element);
	sourceNode = sourceNode->next;
	chainNode<T>* targetNode = firstNode;
	// 复制其余节点
	while (sourceNode != nullptr)
	{
		targetNode->next = new chainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = nullptr;
}

template<class T>
chain<T>::~chain()
{
	while (firstNode != nullptr)
	{
		chainNode<T>* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}

template<class T>
T& chain<T>::get(int theIndex) const
{
	checkIndex(theIndex);
	chainNode<T>* currentNode = firstNode;
	for (int i = 0; i < theIndex; i++)
		currentNode = currentNode->next;
	return currentNode->element;
}

template<class T>
int chain<T>::indexOf(const T& theElement) const
{
	chainNode<T>* currentNode = firstNode;
	int index = 0;
	while (currentNode != nullptr && currentNode->element != theElement)
	{
		currentNode = currentNode->next;
		index++;
	}
	if (currentNode == nullptr)
		return -1;
	else
		return index;
}

template<class T>
void chain<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	chainNode<T>* deleteNode;
	if (theIndex == 0)
	{
		deleteNode = firstNode;
		firstNode = firstNode->next;
	}
	else
	{
		chainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; i++)
			p = p->next;
		deleteNode = p->next;
		p->next = p->next->next;
	}
	listSize--;
	delete deleteNode;
}

template<class T>
void chain<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex < 0 || theIndex > listSize)
		throw "index out of range";
	if (theIndex == 0)
		firstNode = new chainNode<T>(theElement, firstNode);
	else
	{
		chainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; i++)
			p = p->next;
		p->next = new chainNode<T>(theElement, p->next);
	}
	listSize++;
}


template<class T>
void chain<T>::output(std::ostream& out) const
{
	chainNode<T>* currentNode = firstNode;
	while (currentNode != nullptr)
	{
		out << currentNode->element << " ";
		currentNode = currentNode->next;
	}
}

class iterator
{
public:
	iterator(chainNode<T>* theNode = nullptr)
	{
		node = theNode;
	}

	T& operator*() const
	{
		return node->element; // 表示取出 指针指向的对象
	}
	T* operator->() const
	{
		return &node->element; // 返回指向迭代器所指对象的地址
	}

	iterator& operator++() // 前置++
	{
		node = node->next; // 指针向后移动一个位置
		return *this;     // 返回当前对象的引用
	}
	iterator operator++(int) // 后置++
	{
		iterator old = *this; // 先保存当前状态
		node = node->next;    // 指针向后移动一个位置
		return old;          // 返回旧状态的迭代器
	}

	bool operator==(const iterator& right) const
	{
		return node == right.node;
	}
	bool operator!=(const iterator& right) const
	{
		return node != right.node;
	}

protected:
	chainNode<T>* node;

}


