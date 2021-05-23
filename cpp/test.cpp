#include "graph.hpp"
#include <fstream>


int main () {

try {
	Graph graph(6);

	graph.AddEdge(0, 1, 7);
	graph.AddEdge(0, 5, 14);
	graph.AddEdge(0, 2, 9);
	graph.AddEdge(1, 0, 7);
	graph.AddEdge(1, 2, 10);
	graph.AddEdge(1, 3, 15);
	graph.AddEdge(2, 0, 9);
	graph.AddEdge(2, 1, 10);
	graph.AddEdge(2, 3, 11);
	graph.AddEdge(2, 5, 2);
	graph.AddEdge(3, 1, 15);
	graph.AddEdge(3, 2, 11);
	graph.AddEdge(3, 4, 6);
	graph.AddEdge(4, 3, 6);
	graph.AddEdge(4, 5, 9);
	graph.AddEdge(5, 4, 9);
	graph.AddEdge(5, 2, 2);
	graph.AddEdge(5, 0, 14);
	// 1 до 2-й составляет 7, до 3-й — 9, до 4-й — 20, до 5-й — 20, до 6-й — 11.

	cout << graph << endl;

	cout << graph.Degree(7);
	dijkstra(graph, 0);
}
catch (const out_of_range& o_o_r) {
	cerr << "Out of range: " << o_o_r.what() << endl;

}
catch (const runtime_error& e) {
	cerr << "Cannot build graph: " << e.what() << endl;
}

	return 0;
}
