#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <iterator>
#include <climits>

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
	uint32_t numVertices_;
	double max_weight_ = -1.;

	Graph() = delete;
	Graph(const Graph& graph) = delete;
	Graph(size_t size); // с количеством вершин
	~Graph() = default;

	void AddEdge(const uint32_t& start, const uint32_t& final, const double& weight);
	const int Degree(const uint32_t& vert_num);

	friend ostream& operator<< (std::ostream &out, const Graph& graph);



};


void dijkstra(const Graph& graph, const int& start);
