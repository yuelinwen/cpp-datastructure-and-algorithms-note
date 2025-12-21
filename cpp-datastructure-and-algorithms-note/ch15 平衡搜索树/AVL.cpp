
template <class T>
class AVLTree {
public:
	struct Node {
		T data;
		Node* left;
		Node* right;
		int height;
		Node(const T& val) : data(val), left(nullptr), right(nullptr), height(1) {}
	};
	AVLTree() : root(nullptr) {}
	void insert(const T& val) {
		root = insert(root, val);
	}
	void remove(const T& val) {
		root = remove(root, val);
	}
	bool search(const T& val) {
		return search(root, val);
	}
private:
	Node* root;
	int height(Node* node) {
		return node ? node->height : 0;
	}
	int getBalance(Node* node) {
		return node ? height(node->left) - height(node->right) : 0;
	}
	Node* rightRotate(Node* y) {
		Node* x = y->left;
		Node* T2 = x->right;
		x->right = y;
		y->left = T2;
		y->height = std::max(height(y->left), height(y->right)) + 1;
		x->height = std::max(height(x->left), height(x->right)) + 1;
		return x;
	}
	Node* leftRotate(Node* x) {
		Node* y = x->right;
		Node* T2 = y->left;
		y->left = x;
		x->right = T2;
		x->height = std::max(height(x->left), height(x->right)) + 1;
		y->height = std::max(height(y->left), height(y->right)) + 1;
		return y;
	}
	Node* insert(Node* node, const T& val) {
		if (!node) return new Node(val);
		if (val < node->data)
			node->left = insert(node->left, val);
		else if (val > node->data)
			node->right = insert(node->right, val);
		else
			return node; // Duplicate keys not allowed
		node->height = 1 + std::max(height(node->left), height(node->right)));
		int balance = getBalance(node);
		// Left Left Case
		if (balance > 1 && val < node->left->data)
			return rightRotate(node);
		// Right Right Case
		if (balance < -1 && val > node->right->data)
			return leftRotate(node);
		// Left Right Case
		if (balance > 1 && val > node->left->data) {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
		// Right Left Case
		if (balance < -1 && val < node->right->data) {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
		return node;
	}
	Node* minValueNode(Node* node) {
		Node* current = node;
		while (current->left)
			current = current->left;
		return current;
	}
	Node* remove(Node* node, const T& val) {
		if (!node) return node;
		if (val < node->data)
			node->left = remove(node->left, val);
		else if (val > node->data)
			node->right = remove(node->right, val);
		else {
			if (!node->left || !node->right) {
				Node* temp = node->left ? node->left : node->right;
				if (!temp) {
					temp = node;
					node = nullptr;
				}
				else
					*node = *temp;
				delete temp;
			}
			else {
				Node* temp = minValueNode(node->right);
				node->data = temp->data;
				node->right = remove(node->right, temp->data);
			}
		}
		if (!node) return node;
		node->height = 1 + std::max(height(node->left), height(node->right)));
		int balance = getBalance(node);
		// Left Left Case
		if (balance > 1 && getBalance(node->left) >= 0)
			return rightRotate(node);
		// Left Right Case
		if (balance > 1 && getBalance(node->left) < 0) {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
		// Right Right Case
		if (balance < -1 && getBalance(node->right) <= 0)
			return leftRotate(node);
		// Right Left Case
		if (balance < -1 && getBalance(node->right) > 0) {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
		return node;
	}
}