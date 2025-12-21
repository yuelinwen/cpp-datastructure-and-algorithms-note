template<class K, class E>
struct SkipNode {
    K key;
    E element;
    SkipNode<K, E>** next; // 指针数组，存储各层的下一个节点

    SkipNode(K k, E e, int levels) : key(k), element(e) {
        next = new SkipNode<K, E>* [levels];
        for (int i = 0; i < levels; i++) next[i] = nullptr;
    }
    ~SkipNode() { delete[] next; }
};

#include <iostream>
#include <cmath>
#include <ctime>

template<class K, class E>
class SkipList : public Dictionary<K, E> {
private:
    float cutOff;          // 用于随机层数决策
    int maxLevel;          // 允许的最大层数
    int levels;            // 当前跳表层数
    int dSize;             // 字典中的元素个数
    K tailKey;             // 边界键（哨兵）
    SkipNode<K, E>* head;  // 头节点

public:
    SkipList(K largeKey, int maxLev = 10, float prob = 0.5) {
        cutOff = prob;
        maxLevel = maxLev;
        levels = 0;
        dSize = 0;
        tailKey = largeKey;
        // 初始化头节点，层数为 maxLevel
        head = new SkipNode<K, E>(K(), E(), maxLevel);
    }

    ~SkipList() {
        SkipNode<K, E>* curr;
        while (head != nullptr) {
            curr = head->next[0];
            delete head;
            head = curr;
        }
    }

    int size() const override { return dSize; }
    bool isEmpty() const override { return dSize == 0; }

    // 查找操作
    E* find(const K& key) const override {
        if (key >= tailKey) return nullptr;
        SkipNode<K, E>* before = head;
        // 从最高层向下寻找
        for (int i = levels; i >= 0; i--) {
            while (before->next[i] != nullptr && before->next[i]->key < key) {
                before = before->next[i];
            }
        }
        SkipNode<K, E>* target = before->next[0];
        if (target != nullptr && target->key == key) return &target->element;
        return nullptr;
    }

    // 插入操作
    void insert(const K& key, const E& element) override {
        if (key >= tailKey) return; // 简单处理边界

        // 1. 寻找每一层待插入位置的前驱节点
        SkipNode<K, E>* last[10]; // 假设 maxLevel <= 10
        SkipNode<K, E>* curr = head;
        for (int i = levels; i >= 0; i--) {
            while (curr->next[i] != nullptr && curr->next[i]->key < key)
                curr = curr->next[i];
            last[i] = curr;
        }

        // 2. 如果 Key 已存在，更新值
        if (curr->next[0] != nullptr && curr->next[0]->key == key) {
            curr->next[0]->element = element;
            return;
        }

        // 3. 随机生成新节点的层数
        int newLevel = 0;
        while ((float)rand() / RAND_MAX < cutOff && newLevel < maxLevel - 1)
            newLevel++;

        if (newLevel > levels) {
            for (int i = levels + 1; i <= newLevel; i++) last[i] = head;
            levels = newLevel;
        }

        // 4. 创建并链入新节点
        SkipNode<K, E>* newNode = new SkipNode<K, E>(key, element, newLevel + 1);
        for (int i = 0; i <= newLevel; i++) {
            newNode->next[i] = last[i]->next[i];
            last[i]->next[i] = newNode;
        }
        dSize++;
    }

    // 删除操作
    E* remove(const K& key) override {
        if (key >= tailKey) return nullptr;

        SkipNode<K, E>* last[10];
        SkipNode<K, E>* curr = head;
        for (int i = levels; i >= 0; i--) {
            while (curr->next[i] != nullptr && curr->next[i]->key < key)
                curr = curr->next[i];
            last[i] = curr;
        }

        SkipNode<K, E>* target = curr->next[0];
        if (target == nullptr || target->key != key) return nullptr;

        // 从各层索引中移除
        for (int i = 0; i <= levels && last[i]->next[i] == target; i++) {
            last[i]->next[i] = target->next[i];
        }

        // 更新当前跳表高度
        while (levels > 0 && head->next[levels] == nullptr) levels--;

        E* result = new E(target->element); // 复制一份返回
        delete target;
        dSize--;
        return result;
    }
};