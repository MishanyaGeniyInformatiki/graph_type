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


	int numVertices_;
	vector<vector<Vertex>> adjLists_;

public:
	Graph() = delete;
	Graph(size_t size); // с количеством вершин
	~Graph() = default;

	void AddEdge(const int& start, const int& final, const double& weight);
	const int Degree(const int& vert_num);

	friend ostream& operator<< (std::ostream &out, const Graph& graph);

};

Graph::Graph(size_t size) {
	adjLists_.resize(size);
}

void Graph::AddEdge(const int& start, const int& final, const double& weight) {
	adjLists_[start].push_back(Vertex(final, weight));
}

const int Graph::Degree(const int& vert_num) {
	return adjLists_[vert_num].size();
}

ostream& operator<< (std::ostream &out, const Graph& graph) {
	for (size_t i = 0; i < graph.adjLists_.size(); ++i)
    {

    	out << "Adjacency list of vertex " << i << endl;

    	out << i;
    	for (auto&& elem : graph.adjLists_[i]) {
    		out << " -(" << elem.weight <<")-> " << elem.num ;
    	}
    	out << endl;
    	out << endl;
    }

    return out;
}


int main () {


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

	cout << graph;

	return 0;
}

/*void dijkstra(struct Graph* graph, int start)
{	

	struct queue *q = queue_init(graph->numVertices); // создаю очередь

	bool visited[graph->numVertices];
	double dist[graph->numVertices];

	long int INF = pow(2, (sizeof(long int)*4 - 1)) - 1; // 2 147 483 647

	for (int i = 0; i < graph->numVertices; i++){
		visited[i] = false;
		dist[i] = INF;
	}

	dist[0] = 0;
	queue_push(q, 0);

	while (!queue_empty(q)){


		int vert = queue_pop(q); // достаю из очереди вершину
		visited[vert] = true; // помечаю ее как посещенную

		struct Vertex *currentVert = graph->adjLists[vert]; // текущая вершина 
				// (при i = 0 первая после head-вершины)


		for (int i = 0; i < degree(vert); i++){ // рассматриваю все вершины смежные с vert
	
			currentVert = currentVert->next;
			int weight = currentVert->weight; 
			int num = currentVert->num;

			if (!visited[num] && dist[vert] + weight < dist[num]){ // этап релаксации

				dist[num] = dist[vert] + weight;
			}
		}

		int min_dist = INF;
		for (int i = 0; i < graph->numVertices; i++){ // выбираю на роль следующей вершины вершину с минимальным dist 

			if (!visited[i] && dist[i] < min_dist){
				min_dist = dist[i];
				vert = i;
			}
		}

		if (!visited[vert]){ // проверяю, что эта вершина еще не посещена
			queue_push(q, vert);
		}
		
	}

	for (int i = 0; i < graph->numVertices; i++) { // печатаю расстояния
		printf("Distance from %d vertex to %d vertex = %d\n", start, i, dist[i]);
	}
}

*/