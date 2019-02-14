#ifndef ALGORITHM_LIBRARY_SRC_DFS_H_
#define ALGORITHM_LIBRARY_SRC_DFS_H_

#include <list>

class Graph {
 public:
  explicit Graph(int V);
  void AddEdge(int src, int dest);
  void DFS(int vertex);
  int num_vertices() const;
  void Init();
 private:
  int num_vertices_;
  std::list<int> *adjacency_lists_;
  bool *is_visited_;
};



#endif  // ALGORITHM_LIBRARY_SRC_DFS_H_