#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include "graph.cpp"

// 邻接表表示法实现图 
// 在这种实现中，我们用一个数组（或 std::vector）来存放每个顶点的头指针，每个顶点后面跟着一个链表，记录与其相连的所有邻居。
template<class T>
class AdjListGraph : public Graph<T> {
private:
    int numVertices;
    int numEdges;
    // 使用 vector 存储每个顶点的邻接链表
    std::vector<std::list<T>> adjLists;

public:
    AdjListGraph(int v) : numVertices(v), numEdges(0), adjLists(v) {}

    int V() const override { return numVertices; }
    int E() const override { return numEdges; }

    void addEdge(int v, int w) override {
        // 以无向图为例
        adjLists[v].push_back(w);
        adjLists[w].push_back(v);
        numEdges++;
    }

    bool hasEdge(int v, int w) const override {
        for (const auto& neighbor : adjLists[v]) {
            if (neighbor == w) return true;
        }
        return false;
    }

    std::vector<T> adj(int v) const override {
        return std::vector<T>(adjLists[v].begin(), adjLists[v].end());
    }

    std::string toString() const override {
        std::stringstream ss;
        for (int i = 0; i < numVertices; ++i) {
            ss << i << ": ";
            for (const auto& neighbor : adjLists[i]) {
                ss << neighbor << " ";
            }
            ss << "\n";
        }
        return ss.str();
    }
};
