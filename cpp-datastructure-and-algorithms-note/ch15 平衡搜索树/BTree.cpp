#include <vector>

// B-树节点类
class BTreeNode {
    int* keys;      // 关键字数组
    int t;          // 最小度数 (Minimum degree)
    BTreeNode** C;  // 子节点指针数组
    int n;          // 当前关键字数量
    bool leaf;      // 是否为叶子节点

public:
    BTreeNode(int _t, bool _leaf) {
        t = _t;
        leaf = _leaf;
        keys = new int[2 * t - 1];
        C = new BTreeNode * [2 * t];
        n = 0;
    }

    // 插入非满节点
    void insertNonFull(int k);
    // 分裂子节点
    void splitChild(int i, BTreeNode* y);
    // 遍历
    void traverse();

    friend class BTree;
};

// B-树主类
class BTree {
    BTreeNode* root;
    int t; // 最小度数

public:
    BTree(int _t) : root(nullptr), t(_t) {}

    void traverse() { if (root) root->traverse(); }

    void insert(int k) {
        if (root == nullptr) {
            root = new BTreeNode(t, true);
            root->keys[0] = k;
            root->n = 1;
        }
        else {
            // 如果根节点满了，树的高度会增加
            if (root->n == 2 * t - 1) {
                BTreeNode* s = new BTreeNode(t, false);
                s->C[0] = root;
                s->splitChild(0, root);

                // 决定新关键字去两个子节点中的哪一个
                int i = (s->keys[0] < k) ? 1 : 0;
                s->C[i]->insertNonFull(k);
                root = s;
            }
            else {
                root->insertNonFull(k);
            }
        }
    }
};