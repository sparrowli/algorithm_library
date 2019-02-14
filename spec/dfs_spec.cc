#include "src/dfs.h"

#include "gtest/gtest.h"

namespace {

class DepthFirstSearchSpec : public testing::Test {
 protected:
  virtual void SetUp() {

  }


  virtual void TearDown() {}
};

TEST_F(DepthFirstSearchSpec, DefaultConstructor) {
  Graph *graph = new Graph(3);
  EXPECT_EQ(3, graph->num_vertices());
}

TEST_F(DepthFirstSearchSpec, FourVertices) {
  Graph *graph = new Graph(4);
  
  graph->AddEdge(0, 1);
  graph->AddEdge(0, 2);
  graph->AddEdge(1, 2);
  graph->AddEdge(2, 3);

  graph->Init();

  EXPECT_EQ(1, 1);
}
}  // namespace