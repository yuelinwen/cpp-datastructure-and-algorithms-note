#include "chainNode.cpp"
// 单向循环链表，在链表前面增加头节点


template<class T>
circularListWithHeader<T>::circularListWithHeader()
{
	firstNode = new chainNode<T>; // 创建头节点
	firstNode->next = firstNode;  // 头节点指向自己，形成循环
	listSize = 0;
}

// 搜索带有头结点的单向循环链表
template<class T>
int circularListWithHeader<T>::indexOf(const T& theElement) const
{
	headerNode->element = theElement; // 哨兵

	chainNode<T>* currentNode = firstNode->next;
	int index = 0;
	while(currentNode->element != theElement)
	{
		currentNode = currentNode->next;
		index++;
	}

	if(currentNode == firstNode) // 到达头节点，表示没有找到
		return -1;
	else
		return index;
}