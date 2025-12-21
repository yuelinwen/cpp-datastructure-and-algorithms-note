#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>

template<class T>
class Graph {
	public:
	virtual ~Graph() {}
	virtual int V() const = 0; // Return the number of vertices
	virtual int E() const = 0; // Return the number of edges
	virtual void addEdge(int v, int w) = 0; // Add an edge between vertex v and vertex w
	virtual bool hasEdge(int v, int w) const = 0; // Check if there is an edge between vertex v and vertex w
	virtual std::vector<T> adj(int v) const = 0; // Return all adjacent vertices of vertex v
	virtual std::string toString() const = 0; // Return a string representation of the graph
};


// bfs
virtual void bfs(int v, int reach[], int label)
 {
	std::queue<int> q;
	q.push(v);
	reach[v] = label;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int w : adj(curr)) {
			if (reach[w] == 0) {
				reach[w] = label;
				q.push(w);
			}
		}
	}
}

// dfs
virtual void dfs(int v, int reach[], int label)
 {
	reach[v] = label;
	for (int w : adj(v)) {
		if (reach[w] == 0) {
			dfs(w, reach, label);
		}
	}
}