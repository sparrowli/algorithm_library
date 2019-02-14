#include "src/dfs.h"

#include <iostream>

#include "src/checks.h"

Graph::Graph(int V) :
  num_vertices_(V),
  adjacency_lists_(new std::list<int>[V]),
  is_visited_(new bool[V])
{

}

void Graph::Init() {
  for (int i = 0; i < num_vertices_; ++i) {
    is_visited_[i] = false;
  }

  for (int i = 0; i < num_vertices_; ++i) {
    DFS(i);
  }
}

int Graph::num_vertices() const {
  return num_vertices_;
}

void Graph::AddEdge(int src, int dest) {
  RTC_CHECK_GT(num_vertices_, src);
  RTC_CHECK_GT(num_vertices_, dest);

  adjacency_lists_[src].emplace_front(dest);
}

void Graph::DFS(int vertex) {
  is_visited_[vertex] = true;

  std::list<int> adjacency_list = adjacency_lists_[vertex];

  std::cout << vertex << " ";

  std::list<int>::iterator it;
  for (it = adjacency_list.begin(); it != adjacency_list.end(); ++it) {
    if (is_visited_[*it] == false) {
      DFS(*it);
    }
  }
}