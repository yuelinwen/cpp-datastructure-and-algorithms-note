#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include "graph.cpp"

// 邻接矩阵表示法实现图
// 这种实现使用一个二维数组（$V \times V$）。如果顶点 $v$ 和 $w$ 之间有边，则 matrix[v][w] = 1，否则为 0。
template<class T>
class AdjMatrixGraph : public Graph<T> {
private:
    int numVertices;
    int numEdges;
    // 使用二维 vector 存储布尔值
    std::vector<std::vector<bool>> matrix;

public:
    AdjMatrixGraph(int v) : numVertices(v), numEdges(0),
        matrix(v, std::vector<bool>(v, false)) {
    }

    int V() const override { return numVertices; }
    int E() const override { return numEdges; }

    void addEdge(int v, int w) override {
        if (!matrix[v][w]) {
            matrix[v][w] = true;
            matrix[w][v] = true;
            numEdges++;
        }
    }

    bool hasEdge(int v, int w) const override {
        return matrix[v][w];
    }

    std::vector<T> adj(int v) const override {
        std::vector<T> neighbors;
        for (int i = 0; i < numVertices; ++i) {
            if (matrix[v][i]) {
                neighbors.push_back(i);
            }
        }
        return neighbors;
    }

    std::string toString() const override {
        std::stringstream ss;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                ss << (matrix[i][j] ? "1 " : "0 ");
            }
            ss << "\n";
        }
        return ss.str();
    }
};