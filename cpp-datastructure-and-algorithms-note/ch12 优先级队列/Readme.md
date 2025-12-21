ch12 优先级队列

优先级队列（Priority Queue） 是一种特殊的队列数据结构，它的特点可以一句话概括：
出队的不是“最早进入”的元素，而是“优先级最高”的元素。

| 对比       | 普通队列（Queue） | 优先级队列（Priority Queue） |
| -------- | ----------- | --------------------- |
| 出队顺序     | 先进先出（FIFO）  | **优先级高的先出**           |
| 是否保持插入顺序 | 是           | 否                     |
| 使用场景     | 排队买票        | **紧急任务先处理**           |


堆 Heap
堆是一种特殊的完全二叉树，满足 堆性质：
大根堆（Max Heap）
父结点 ≥ 子结点
小根堆（Min Heap）
父结点 ≤ 子结点

是 完全二叉树n 根结点是 最大 / 最小值 常用于 优先级队列



STL priority_queue
✅ 在 C++ STL 中，priority_queue 的底层实现就是 heap（堆）
更准确地说：是二叉堆（binary heap）

std::priority_queue 是一个 容器适配器（container adapter），
它内部使用堆算法（make_heap / push_heap / pop_heap）来维护数据。
