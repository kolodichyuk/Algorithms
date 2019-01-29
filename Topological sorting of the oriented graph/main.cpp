#include <iostream>
#include <conio.h>
#include <vector>
#include "topologicalSort.h"
using namespace std;

int main() {
	// create new graph 
	int edges[] = { 1, 4, 4, 3, 3, 2, 4, 2 };
	const int vertexsCount = 4, edgesCount = sizeof(edges) / sizeof(*edges) / 2;
	vector<vector<int>> vertexs(vertexsCount);
	for (int i = 0; i < edgesCount * 2; i += 2) {
		vertexs[edges[i] - 1].push_back(edges[i + 1] - 1);
	}
	Graph graph(vertexs);
	TopologicalSort* sorting = new TopologicalSort(); // create a class object TopologicalSort
	sorting->Sort(graph);                             // topographical sorting of the graph
	for (const auto &element : graph.tSorted) {
		cout << element << " ";
	}
	_getch();
	return 0;
}
