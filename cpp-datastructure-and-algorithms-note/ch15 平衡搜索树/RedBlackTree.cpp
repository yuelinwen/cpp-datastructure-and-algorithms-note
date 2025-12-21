enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* left, * right, * parent;

    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    // 核心旋转操作
    void rotateLeft(Node*& x);
    void rotateRight(Node*& y);

    // 插入后的平衡修复
    void fixViolation(Node*& ptr);

public:
    RedBlackTree() : root(nullptr) {}

    void insert(const int& data) {
        Node* newNode = new Node(data);
        root = bstInsert(root, newNode); // 标准 BST 插入
        fixViolation(newNode);           // 颜色调整与旋转
    }

    // 辅助函数：标准的 BST 插入逻辑
    Node* bstInsert(Node* root, Node* ptr) {
        if (root == nullptr) return ptr;
        if (ptr->data < root->data) {
            root->left = bstInsert(root->left, ptr);
            root->left->parent = root;
        }
        else {
            root->right = bstInsert(root->right, ptr);
            root->right->parent = root;
        }
        return root;
    }
};