
template<class T>
struct binaryTreeNode {
	T data;
	binaryTreeNode<T>* leftChild;
	binaryTreeNode<T>* rightChild;
	binaryTreeNode() {
		leftChild = nullptr;
		rightChild = nullptr;
	}
	binaryTreeNode(const T& theElement) {
		data = theElement;
		leftChild = nullptr;
		rightChild = nullptr;
	}
	binaryTreeNode(const T& theElement, binaryTreeNode<T>* left, binaryTreeNode<T>* right) {
		data = theElement;
		leftChild = left;
		rightChild = right;
	}
};

//前序遍历，
tempalte <class T>
void preOrder(binaryTreeNode<T>* root) {
	if (root != nullptr) {
		std::cout << root->data << " "; // 访问根节点
		preOrder(root->leftChild); // 递归遍历左子树
		preOrder(root->rightChild); // 递归遍历右子树
	}
}

//中序遍历，
template <class T>
void inOrder(binaryTreeNode<T>* root) {
	if (root != nullptr) {
		inOrder(root->leftChild); // 递归遍历左子树
		std::cout << root->data << " "; // 访问根节点
		inOrder(root->rightChild); // 递归遍历右子树
	}
}

//后序遍历，
template <class T>
void postOrder(binaryTreeNode<T>* root) {
	if (root != nullptr) {
		postOrder(root->leftChild); // 递归遍历左子树
		postOrder(root->rightChild); // 递归遍历右子树
		std::cout << root->data << " "; // 访问根节点
	}
}

//层次遍历
template <class T>
void levelOrder(binaryTreeNode<T>* root) {
	if (root == nullptr) return;
	std::queue<binaryTreeNode<T>*> q;
	q.push(root);
	while (!q.empty()) {
		binaryTreeNode<T>* current = q.front();
		q.pop();
		std::cout << current->data << " "; // 访问当前节点
		if (current->leftChild != nullptr) {
			q.push(current->leftChild); // 将左子节点加入队列
		}
		if (current->rightChild != nullptr) {
			q.push(current->rightChild); // 将右子节点加入队列
		}
	}
}