#include <UnitTest++/UnitTest++.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include "Graph.h"
#include "GraphExceptions.h"
#include "GraphTestTypes.h"

using namespace dg;

SUITE(GraphConstructionTests) {
    TEST(DefaultConstructorCreatesEmptyGraph) {
        Graph<int> g;
        CHECK_EQUAL(0, g.vertex_count());
        CHECK_EQUAL(0, g.edge_count());
    }

    TEST(CopyConstructor) {
        Graph<int> g1;
        auto v1 = g1.add_vertex(1);
        auto v2 = g1.add_vertex(2);
        g1.add_edge(v1, v2);
        
        Graph<int> g2 = g1;
        
        CHECK_EQUAL(g1.vertex_count(), g2.vertex_count());
        CHECK_EQUAL(g1.edge_count(), g2.edge_count());
        CHECK(g2.contains_vertex(v1));
        CHECK(g2.contains_vertex(v2));
        CHECK(g2.contains_edge(v1, v2));
    }

    TEST(AssignmentOperator) {
        Graph<int> g1, g2;
        auto v1 = g1.add_vertex(1);
        auto v2 = g1.add_vertex(2);
        g1.add_edge(v1, v2);
        
        g2 = g1;
        
        CHECK_EQUAL(g1.vertex_count(), g2.vertex_count());
        CHECK_EQUAL(g1.edge_count(), g2.edge_count());
        CHECK(g2.contains_edge(v1, v2));
    }

    TEST(SelfAssignment) {
        Graph<int> g;
        auto v1 = g.add_vertex(1);
        auto v2 = g.add_vertex(2);
        g.add_edge(v1, v2);
        
        g = g;
        
        CHECK_EQUAL(2, g.vertex_count());
        CHECK_EQUAL(1, g.edge_count());
        CHECK(g.contains_edge(v1, v2));
    }
}

SUITE(VertexOperationTests) {
    TEST(AddVertexReturnsSequentialIds) {
        Graph<std::string> g;
        auto id1 = g.add_vertex("first");
        auto id2 = g.add_vertex("second");
        auto id3 = g.add_vertex("third");
        
        CHECK_EQUAL(0, id1);
        CHECK_EQUAL(1, id2);
        CHECK_EQUAL(2, id3);
        CHECK_EQUAL(3, g.vertex_count());
    }

    TEST(ContainsVertex) {
        Graph<int> g;
        auto v1 = g.add_vertex(1);
        auto v2 = g.add_vertex(2);
        
        CHECK(g.contains_vertex(v1));
        CHECK(g.contains_vertex(v2));
        CHECK(!g.contains_vertex(999));
    }

    TEST(AddMultipleVertices) {
        Graph<int> g;
        auto v1 = g.add_vertex(1);
        auto v2 = g.add_vertex(2);
        auto v3 = g.add_vertex(3);
        
        CHECK_EQUAL(3, g.vertex_count());
        CHECK(g.contains_vertex(v1));
        CHECK(g.contains_vertex(v2));
        CHECK(g.contains_vertex(v3));
    }

    TEST(ClearRemovesAllVerticesAndEdges) {
        Graph<int> g;
        auto v1 = g.add_vertex(1);
        auto v2 = g.add_vertex(2);
        g.add_edge(v1, v2);
        
        g.clear();
        
        CHECK_EQUAL(0, g.vertex_count());
        CHECK_EQUAL(0, g.edge_count());
        CHECK(!g.contains_vertex(v1));
        CHECK(!g.contains_vertex(v2));
    }

    TEST(VertexValuesAreStoredCorrectly) {
        Graph<std::string> g;
        auto v1 = g.add_vertex("hello");
        auto v2 = g.add_vertex("world");
        
        std::vector<std::string> values;
        for (auto it = g.vertices_begin(); it != g.vertices_end(); ++it) {
            values.push_back(*(*it).value);
        }
        
        CHECK_EQUAL(2, values.size());
        CHECK(std::find(values.begin(), values.end(), "hello") != values.end());
        CHECK(std::find(values.begin(), values.end(), "world") != values.end());
    }
}

SUITE(EdgeOperationTests) {
    TEST(AddEdge) {
        Graph<int> g;
        auto v1 = g.add_vertex(1);
        auto v2 = g.add_vertex(2);
        
        g.add_edge(v1, v2);
        
        CHECK_EQUAL(1, g.edge_count());
        CHECK(g.contains_edge(v1, v2));
        CHECK(!g.contains_edge(v2, v1));
    }

    TEST(AddMultipleEdges) {
        Graph<int> g;
        auto v1 = g.add_vertex(1);
        auto v2 = g.add_vertex(2);
        auto v3 = g.add_vertex(3);
        
        g.add_edge(v1, v2);
        g.add_edge(v2, v3);
        g.add_edge(v3, v1);
        
        CHECK_EQUAL(3, g.edge_count());
        CHECK(g.contains_edge(v1, v2));
        CHECK(g.contains_edge(v2, v3));
        CHECK(g.contains_edge(v3, v1));
    }

    TEST(ContainsEdge) {
        Graph<int> g;
        auto v1 = g.add_vertex(1);
        auto v2 = g.add_vertex(2);
        
        CHECK(!g.contains_edge(v1, v2));
        g.add_edge(v1, v2);
        CHECK(g.contains_edge(v1, v2));
        CHECK(!g.contains_edge(v2, v1));
    }

    TEST(EdgeCountAccuracy) {
        Graph<int> g;
        auto v1 = g.add_vertex(1);
        auto v2 = g.add_vertex(2);
        auto v3 = g.add_vertex(3);
        
        CHECK_EQUAL(0, g.edge_count());
        g.add_edge(v1, v2);
        CHECK_EQUAL(1, g.edge_count());
        g.add_edge(v2, v3);
        CHECK_EQUAL(2, g.edge_count());
        g.add_edge(v3, v1);
        CHECK_EQUAL(3, g.edge_count());
    }

    TEST(CycleCreation) {
        Graph<int> g;
        auto v1 = g.add_vertex(1);
        auto v2 = g.add_vertex(2);
        auto v3 = g.add_vertex(3);
        
        g.add_edge(v1, v2);
        g.add_edge(v2, v3);
        g.add_edge(v3, v1);
        
        CHECK_EQUAL(3, g.edge_count());
        CHECK(g.contains_edge(v1, v2));
        CHECK(g.contains_edge(v2, v3));
        CHECK(g.contains_edge(v3, v1));
    }
}

SUITE(IteratorTests) {
    TEST(VertexIteratorBasic) {
        Graph<int> g;
        auto v1 = g.add_vertex(1);
        auto v2 = g.add_vertex(2);
        auto v3 = g.add_vertex(3);
        
        std::vector<size_t> ids;
        for (auto it = g.vertices_begin(); it != g.vertices_end(); ++it) {
            ids.push_back((*it).id);
        }
        
        CHECK_EQUAL(3, ids.size());
        CHECK(std::find(ids.begin(), ids.end(), v1) != ids.end());
        CHECK(std::find(ids.begin(), ids.end(), v2) != ids.end());
        CHECK(std::find(ids.begin(), ids.end(), v3) != ids.end());
    }

    TEST(VertexIteratorValues) {
        Graph<std::string> g;
        auto v1 = g.add_vertex("A");
        auto v2 = g.add_vertex("B");
        auto v3 = g.add_vertex("C");
        
        std::vector<std::string> values;
        for (auto it = g.vertices_begin(); it != g.vertices_end(); ++it) {
            values.push_back(*(*it).value);
        }
        
        CHECK_EQUAL(3, values.size());
        CHECK(std::find(values.begin(), values.end(), "A") != values.end());
        CHECK(std::find(values.begin(), values.end(), "B") != values.end());
        CHECK(std::find(values.begin(), values.end(), "C") != values.end());
    }

    TEST(ConstVertexIterator) {
        Graph<int> g;
        g.add_vertex(1);
        g.add_vertex(2);
        g.add_vertex(3);
        
        const Graph<int>& const_g = g;
        int count = 0;
        for (auto it = const_g.vertices_begin(); it != const_g.vertices_end(); ++it) {
            CHECK((*it).value != nullptr);
            count++;
        }
        CHECK_EQUAL(3, count);
    }

    TEST(EdgeIteratorBasic) {
        Graph<int> g;
        auto v1 = g.add_vertex(1);
        auto v2 = g.add_vertex(2);
        auto v3 = g.add_vertex(3);
        
        g.add_edge(v1, v2);
        g.add_edge(v2, v3);
        g.add_edge(v3, v1);
        
        std::vector<std::pair<size_t, size_t>> edges;
        for (auto it = g.edges_begin(); it != g.edges_end(); ++it) {
            edges.push_back(std::make_pair((*it).src, (*it).dst));
        }
        
        CHECK_EQUAL(3, edges.size());
        CHECK(std::find(edges.begin(), edges.end(), std::make_pair(v1, v2)) != edges.end());
        CHECK(std::find(edges.begin(), edges.end(), std::make_pair(v2, v3)) != edges.end());
        CHECK(std::find(edges.begin(), edges.end(), std::make_pair(v3, v1)) != edges.end());
    }

    TEST(ConstEdgeIterator) {
        Graph<int> g;
        auto v1 = g.add_vertex(1);
        auto v2 = g.add_vertex(2);
        g.add_edge(v1, v2);
        
        const Graph<int>& const_g = g;
        int count = 0;
        for (auto it = const_g.edges_begin(); it != const_g.edges_end(); ++it) {
            CHECK_EQUAL(v1, (*it).src);
            CHECK_EQUAL(v2, (*it).dst);
            count++;
        }
        CHECK_EQUAL(1, count);
    }

    TEST(EmptyGraphIterators) {
        Graph<int> g;
        
        CHECK(g.vertices_begin() == g.vertices_end());
        CHECK(g.edges_begin() == g.edges_end());
        
        const Graph<int>& const_g = g;
        CHECK(const_g.vertices_begin() == const_g.vertices_end());
        CHECK(const_g.edges_begin() == const_g.edges_end());
    }

    TEST(SingleVertexIterator) {
        Graph<int> g;
        g.add_vertex(42);
        
        int count = 0;
        for (auto it = g.vertices_begin(); it != g.vertices_end(); ++it) {
            CHECK_EQUAL(42, *(*it).value);
            count++;
        }
        CHECK_EQUAL(1, count);
    }

    TEST(SingleEdgeIterator) {
        Graph<int> g;
        auto v1 = g.add_vertex(1);
        auto v2 = g.add_vertex(2);
        g.add_edge(v1, v2);
        
        int count = 0;
        for (auto it = g.edges_begin(); it != g.edges_end(); ++it) {
            CHECK_EQUAL(v1, (*it).src);
            CHECK_EQUAL(v2, (*it).dst);
            count++;
        }
        CHECK_EQUAL(1, count);
    }

    TEST(BidirectionalVertexIterator) {
        Graph<int> g;
        g.add_vertex(1);
        g.add_vertex(2);
        
        auto it = g.vertices_begin();
        auto first_id = (*it).id;
        ++it;
        --it;
        
        CHECK_EQUAL(first_id, (*it).id);
    }

    TEST(BidirectionalEdgeIterator) {
        Graph<int> g;
        auto v1 = g.add_vertex(1);
        auto v2 = g.add_vertex(2);
        auto v3 = g.add_vertex(3);
        g.add_edge(v1, v2);
        g.add_edge(v2, v3);
        
        auto it = g.edges_begin();
        auto first_edge = *it;
        ++it;
        auto second_edge = *it;
        --it;
        
        CHECK(first_edge.src == (*it).src && first_edge.dst == (*it).dst);
    }
}

SUITE(ExceptionTests) {
    TEST(VertexNotFoundOnAddEdgeFirstVertex) {
        Graph<int> g;
        auto v1 = g.add_vertex(1);
        
        CHECK_THROW(g.add_edge(999, v1), vertex_not_found);
    }

    TEST(VertexNotFoundOnAddEdgeSecondVertex) {
        Graph<int> g;
        auto v1 = g.add_vertex(1);
        
        CHECK_THROW(g.add_edge(v1, 999), vertex_not_found);
    }

    TEST(VertexNotFoundOnAddEdgeBothVertices) {
        Graph<int> g;
        
        CHECK_THROW(g.add_edge(999, 1000), vertex_not_found);
    }

    TEST(DuplicateEdge) {
        Graph<int> g;
        auto v1 = g.add_vertex(1);
        auto v2 = g.add_vertex(2);
        
        g.add_edge(v1, v2);
        CHECK_THROW(g.add_edge(v1, v2), duplicate_edge);
    }

    TEST(ContainsVertexForNonExistent) {
        Graph<int> g;
        CHECK(!g.contains_vertex(999));
    }

    TEST(EdgeOperationsWithInvalidVertices) {
        Graph<int> g;
        auto v1 = g.add_vertex(1);
        
        CHECK(!g.contains_edge(999, v1));
        CHECK(!g.contains_edge(v1, 999));
        CHECK(!g.contains_edge(999, 1000));
    }
}

SUITE(CustomTypeTests) {
    TEST(CityGraph) {
        Graph<City> g;
        
        auto nyc = g.add_vertex(City("New York", 8419000));
        auto london = g.add_vertex(City("London", 8982000));
        auto paris = g.add_vertex(City("Paris", 2148000));
        auto tokyo = g.add_vertex(City("Tokyo", 13960000));
        
        g.add_edge(nyc, london);
        g.add_edge(london, paris);
        g.add_edge(paris, tokyo);
        g.add_edge(tokyo, nyc);
        
        CHECK_EQUAL(4, g.vertex_count());
        CHECK_EQUAL(4, g.edge_count());
        
        for (auto it = g.vertices_begin(); it != g.vertices_end(); ++it) {
            CHECK((*it).value != nullptr);
            CHECK(!(*it).value->name.empty());
            CHECK((*it).value->population > 0);
        }
    }

    TEST(CoursePrerequisites) {
        Graph<Course> g;
        
        auto math101 = g.add_vertex(Course("Math 101", 3));
        auto cs101 = g.add_vertex(Course("CS 101", 4));
        auto cs201 = g.add_vertex(Course("CS 201", 4));
        auto algorithms = g.add_vertex(Course("Algorithms", 5));
        
        g.add_edge(math101, cs101);
        g.add_edge(cs101, cs201);
        g.add_edge(cs201, algorithms);
        
        CHECK_EQUAL(4, g.vertex_count());
        CHECK_EQUAL(3, g.edge_count());
        CHECK(g.contains_edge(math101, cs101));
        CHECK(g.contains_edge(cs101, cs201));
        CHECK(g.contains_edge(cs201, algorithms));
    }

    TEST(CustomTypeCopy) {
        Graph<City> g1;
        auto v1 = g1.add_vertex(City("Moscow", 12500000));
        auto v2 = g1.add_vertex(City("Berlin", 3645000));
        g1.add_edge(v1, v2);
        
        Graph<City> g2 = g1;
        
        CHECK_EQUAL(g1.vertex_count(), g2.vertex_count());
        CHECK_EQUAL(g1.edge_count(), g2.edge_count());
        CHECK(g2.contains_edge(v1, v2));
    }
}

SUITE(ComplexOperationTests) {
    TEST(LargeGraph) {
        Graph<int> g;
        const size_t NUM_VERTICES = 100;
        
        std::vector<size_t> vertices;
        for (int i = 0; i < NUM_VERTICES; ++i) {
            vertices.push_back(g.add_vertex(i));
        }
        
        for (size_t i = 0; i < NUM_VERTICES - 1; ++i) {
            g.add_edge(vertices[i], vertices[i + 1]);
        }
        
        CHECK_EQUAL(NUM_VERTICES, g.vertex_count());
        CHECK_EQUAL(NUM_VERTICES - 1, g.edge_count());
        
        for (size_t i = 0; i < NUM_VERTICES - 1; ++i) {
            CHECK(g.contains_edge(vertices[i], vertices[i + 1]));
        }
    }

    TEST(CompleteGraphSmall) {
        Graph<int> g;
        const size_t N = 5;
        
        std::vector<size_t> vertices;
        for (size_t i = 0; i < N; ++i) {
            vertices.push_back(g.add_vertex(i));
        }
        
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < N; ++j) {
                if (i != j) {
                    g.add_edge(vertices[i], vertices[j]);
                }
            }
        }
        
        CHECK_EQUAL(N * (N - 1), g.edge_count());
    }

    TEST(MultipleOperations) {
        Graph<int> g;
        
        auto v1 = g.add_vertex(1);
        auto v2 = g.add_vertex(2);
        auto v3 = g.add_vertex(3);
        auto v4 = g.add_vertex(4);
        
        g.add_edge(v1, v2);
        g.add_edge(v1, v3);
        g.add_edge(v2, v4);
        g.add_edge(v3, v4);
        g.add_edge(v4, v1);
        
        CHECK_EQUAL(4, g.vertex_count());
        CHECK_EQUAL(5, g.edge_count());
        
        CHECK(g.contains_edge(v1, v2));
        CHECK(g.contains_edge(v1, v3));
        CHECK(g.contains_edge(v2, v4));
        CHECK(g.contains_edge(v3, v4));
        CHECK(g.contains_edge(v4, v1));
        
        Graph<int> g_copy = g;
        CHECK_EQUAL(g.vertex_count(), g_copy.vertex_count());
        CHECK_EQUAL(g.edge_count(), g_copy.edge_count());
        CHECK(g_copy.contains_edge(v1, v2));
        CHECK(g_copy.contains_edge(v4, v1));
    }

    TEST(ClearAndReuse) {
        Graph<int> g;
        
        auto v1 = g.add_vertex(1);
        auto v2 = g.add_vertex(2);
        g.add_edge(v1, v2);
        
        CHECK_EQUAL(2, g.vertex_count());
        CHECK_EQUAL(1, g.edge_count());
        
        g.clear();
        
        CHECK_EQUAL(0, g.vertex_count());
        CHECK_EQUAL(0, g.edge_count());
        
        auto v3 = g.add_vertex(3);
        auto v4 = g.add_vertex(4);
        auto v5 = g.add_vertex(5);
        g.add_edge(v3, v4);
        g.add_edge(v4, v5);
        
        CHECK_EQUAL(3, g.vertex_count());
        CHECK_EQUAL(2, g.edge_count());
        CHECK(g.contains_edge(v3, v4));
        CHECK(g.contains_edge(v4, v5));
    }
}

int main() {
    std::cout << "Running Graph Tests...\n";
    int result = UnitTest::RunAllTests();
    std::cout << "Tests completed.\n";
    return result;
}