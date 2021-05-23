#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <iterator>

using namespace std;



class Graph {
private:
	struct Vertex
	{
		int num; 		// к какому присобачить
		double weight;	// вес исходящего из вершины ребра

		Vertex(){}
		Vertex(int num, double weight) : 
			   num(num), weight(weight) {}
		~Vertex() = default;
	};



public:
	vector<vector<Vertex>> adjLists_;
	int numVertices_;
	double max_weight_ = -1.;

	Graph() = delete;
	Graph(Graph graph) = delete;
	Graph(size_t size); // с количеством вершин
	~Graph() = default;

	void AddEdge(const int& start, const int& final, const double& weight);
	const int Degree(const uint32_t& vert_num);

	friend ostream& operator<< (std::ostream &out, const Graph& graph);



};


void dijkstra(const Graph& graph, const int& start);
