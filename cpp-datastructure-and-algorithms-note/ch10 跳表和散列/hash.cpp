#include <iostream>
#include <vector>
#include <list>
#include <string>

// 键值对节点
template<class K, class E>
struct HashNode {
	K key; // 键
	E value; // 值
    HashNode(K k, E v) : key(k), value(v) {}
};

template<class K, class E>
class SimpleHashMap {
private:
    // 散列表的底层数组，每个格子（Bucket）是一个链表，用来处理哈希冲突（拉链法）
    std::vector<std::list<HashNode<K, E>>> table;
    int capacity;

    // 散列函数：将 Key 转换为数组索引
    // 这里简单演示，实际开发中会使用更复杂的算法如 MurmurHash 或映射到内置 hash
    int hashFunction(const K& key) const {
        // 使用 C++ 标准库提供的 hash 对象
        return std::hash<K>{}(key) % capacity;
    }

public:
    SimpleHashMap(int size = 10) : capacity(size) {
        table.resize(capacity);
    }

    // 插入操作
    void insert(const K& key, const E& value) {
        int index = hashFunction(key);

        // 检查键是否已经存在，存在则更新
        for (auto& node : table[index]) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }

        // 不存在则在该索引的链表中添加新节点
		table[index].emplace_back(key, value); // 使用 emplace_back 直接构造节点
    }

    // 查找操作
    E* find(const K& key) {
        int index = hashFunction(key);

        // 在对应的链表中线性查找
        for (auto& node : table[index]) {
            if (node.key == key) {
                return &node.value;
            }
        }
        return nullptr; // 没找到
    }

    // 删除操作
    bool remove(const K& key) {
        int index = hashFunction(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                return true;
            }
        }
        return false;
    }
};

int main() {
    SimpleHashMap<std::string, std::string> dict(5);

    // 插入数据
    dict.insert("apple", "苹果");
    dict.insert("banana", "香蕉");
    dict.insert("cat", "猫");

    // 查找
    std::string* val = dict.find("apple");
    if (val) std::cout << "找到 apple: " << *val << std::endl;

    // 删除
    if (dict.remove("banana")) {
        std::cout << "成功删除 banana" << std::endl;
    }

    return 0;
}