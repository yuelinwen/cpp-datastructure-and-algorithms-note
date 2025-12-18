
// 自定义双向迭代器类模板
class interator {
public:
	typedef bidirectional_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;

	// note: 在 C++ 里，typedef 是一个类型别名（type alias）工具，可以用来给已有类型起一个新的名字，让代码更清晰或更易维护。

	// 构造函数
	iterator(T* thePosition = 0)
		: position(thePosition) {
	}

	// 解引用运算符
	T& operator*() const { // 返回对象引用
		return *position; // 表示取出 指针指向的对象 
	}
	T* operator->() const { // 返回指向迭代器所指对象的地址
		return &*position;
		// 为什么 要写成 &*position 而不是直接返回 position？
		// 因为 position 是一个指针，&*position 先解引用得到对象，然后取地址，确保返回类型是 T*。
		// &*position 是为了保证迭代器无论内部怎么实现，都能返回指向元素的指针，使 it->成员 始终可用。
		// 直接返回 position 只能在迭代器内部就是普通指针时可行，但不通用，也不符合 STL 标准。
	}

	// 迭代器的值增加
	iterator& operator++() { // 前置++
		++position; // 指针向后移动一个位置
		return *this; // 返回当前对象的引用
	}
	iterator operator++(int) { // 后置++
		iterator old = *this; // 先保存当前状态
		++position; // 指针向后移动一个位置
		return old; // 返回旧状态的迭代器
	}

	// 减少运算符
	iterator& operator--() { // 前置--
		--position; // 指针向前移动一个位置
		return *this; // 返回当前对象的引用
	}
	iterator operator--(int) { // 后置--
		iterator old = *this; // 先保存当前状态
		--position; // 指针向前移动一个位置
		return old; // 返回旧状态的迭代器
	}

	//测试是否相等
	bool operator==(const iterator& right) const {
		return position == right.position;
	}
	bool operator!=(const iterator& right) const {
		return position != right.position;
	}

	protected:
		T* position; // 指向容器中某个元素的指针
}