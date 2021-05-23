#include "graph.hpp"
#include <fstream>


int main () {

for (int i = 0; i < 5; ++i) {
try {

	Graph graph(6);
if (i == 0){
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
else if (i == 1) {
	graph = Graph(2);
    graph.AddEdge(0, 1, 54);
    graph.AddEdge(0, 0, 1);
}
 else if (i == 2) { 
 // тест на недопустимый номер вершины в функции addEdge
	graph = Graph(2);
    graph.AddEdge(0, 1, 54);
    graph.AddEdge(0, 2, 54);
 }
 else if (i == 3) {
// тест на недопустимый номер вершины в функции degree
	graph = Graph(2);
    graph.AddEdge(0, 1, 54);
    graph.AddEdge(1, 0, 54);
    cout << graph.Degree(2) << endl;
 }
 else{
 // тест на слишком тяжелое ребро в dijkstra
	graph = Graph(2);
    graph.AddEdge(0, 1, LONG_MAX);
    graph.AddEdge(1, 0, 54);
    dijkstra(graph, 0);
 }
}

catch (const out_of_range& o_o_r) {
	cerr << "Out of range: " << o_o_r.what() << endl;

}
catch (const runtime_error& e) {
	cerr << "Cannot build graph: " << e.what() << endl;
}
}
	return 0;
}
