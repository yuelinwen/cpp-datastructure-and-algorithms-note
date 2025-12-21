
tempalte <class T>
void maxHeap<T>::push(const T& x)
{
	if (currentSize == maxSize)
		throw overflow_error("heap size exceeds");
	// 将新元素插入到数组末尾
	int hole = ++currentSize;
	// 上滤新元素
	for (; hole > 1 && x > array[hole / 2]; hole /= 2)
		array[hole] = array[hole / 2];
	array[hole] = x;
}

template <class T>
void maxHeap<T>::pop()
{
	if (empty())
		throw underflow_error("heap is empty");
	// 用最后一个元素替换堆顶元素
	array[1] = array[currentSize--];
	// 下滤堆顶元素
	int hole = 1;
	T x = array[hole];
	int child;
	for (; hole * 2 <= currentSize; hole = child)
	{
		child = hole * 2;
		// 找出较大的子节点
		if (child != currentSize && array[child + 1] > array[child])
			++child;
		if (array[child] > x)
			array[hole] = array[child];
		else
			break;
	}
	array[hole] = x;
}