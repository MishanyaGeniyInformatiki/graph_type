#pragma once
#include "graph.hpp"
#include <climits>

Graph::Graph(size_t size) {
  adjLists_.resize(size);
  numVertices_ = size;
}

void Graph::AddEdge(const int &start, const int &final, const double &weight) {
  if ((start >= numVertices_) || (final >= numVertices_)) {
    throw runtime_error("Start point or final destination are out of range");
  }
  if (start == final) {
    throw runtime_error("Loops are not allowed");
  }

  if (max_weight_ < weight) {
    max_weight_ = weight;
  }
  adjLists_[start].push_back(Vertex(final, weight));
}

const int Graph::Degree(const uint32_t &vert_num) {
  if (vert_num >= numVertices_) {
    throw overflow_error("Vertex numer is out of range");
  }
  return adjLists_[vert_num].size();
}

ostream &operator<<(std::ostream &out, const Graph &graph) {
  for (size_t i = 0; i < graph.adjLists_.size(); ++i) {

    out << "Adjacency list of vertex " << i << endl;

    out << i;
    for (auto &&elem : graph.adjLists_[i]) {
      out << " -(" << elem.weight << ")-> " << elem.num;
    }
    out << endl;
    out << endl;
  }

  return out;
}

void dijkstra(const Graph &graph, const int &start) {

  queue<int> q;
  size_t numvert = graph.numVertices_;

  const long INF = LONG_MAX; // 2 147 483 647

  vector<bool> visited(numvert, false);
  vector<double> dist(numvert, INF);

  dist[0] = 0;
  q.push(0);

  while (!q.empty()) {

    int vert = q.front(); // достаю из очереди вершину
    q.pop();
    visited[vert] = true; // помечаю ее как посещенную

    for (auto &&elem :
         graph.adjLists_[vert]) { // рассматриваю все вершины смежные с vert

      int weight = elem.weight;
      int num = elem.num;

      if (!visited[num] && dist[vert] + weight < dist[num]) { // этап релаксации

        dist[num] = dist[vert] + weight;
      }
    }

    long min_dist = INF;
    for (int i = 0; i < numvert;
         i++) { // выбираю на роль следующей вершины вершину с минимальным dist

      if (!visited[i] && dist[i] < min_dist) {
        min_dist = dist[i];
        vert = i;
      }
    }

    if (!visited[vert]) { // проверяю, что эта вершина еще не посещена
      q.push(vert);
    }
  }

  for (int i = 0; i < numvert; i++) { // печатаю расстояния
    cout << "Distance from " << start << " vertex to " << i
         << " vertex = " << dist[i] << endl;
  }
}