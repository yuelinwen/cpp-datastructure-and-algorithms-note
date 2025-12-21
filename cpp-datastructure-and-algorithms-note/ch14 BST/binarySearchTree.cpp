
template <class T>
class binarySearchTree {
   private:
	struct Node {
		T data;
		Node* left;
		Node* right;
		Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
	};
	Node* root;
	void insert(Node*& node, const T& value) {
		if (node == nullptr) {
			node = new Node(value);
		} else if (value < node->data) {
			insert(node->left, value);
		} else if (value > node->data) {
			insert(node->right, value);
		}
	}
	bool search(Node* node, const T& value) const {
		if (node == nullptr) {
			return false;
		} else if (value == node->data) {
			return true;
		} else if (value < node->data) {
			return search(node->left, value);
		} else {
			return search(node->right, value);
		}
	}
	void inorder(Node* node) const {
		if (node != nullptr) {
			inorder(node->left);
			std::cout << node->data << " ";
			inorder(node->right);
		}
	}
	void clear(Node* node) {
		if (node != nullptr) {
			clear(node->left);
			clear(node->right);
			delete node;
		}
	}
   public:
	binarySearchTree() : root(nullptr) {}
	~binarySearchTree() {
		clear(root);
	}
	void insert(const T& value) {
		insert(root, value);
	}
	bool search(const T& value) const {
		return search(root, value);
	}
	void inorder() const {
		inorder(root);
		std::cout << std::endl;
	}
};