#include <UnitTest++/UnitTest++.h>
#include <sstream>
#include <algorithm>
#include "Graph.h"
#include "GraphExceptions.h"
#include "City.h"
#include "Course.h"

SUITE(GraphCoreTests) {
    TEST(DefaultConstructorAndTypedefs) {
        dg::Graph<int> graph;
        
        CHECK(typeid(typename dg::Graph<int>::value_type) == typeid(int));
        CHECK(typeid(typename dg::Graph<int>::reference) == typeid(int&));
        CHECK(typeid(typename dg::Graph<int>::const_reference) == typeid(const int&));
        CHECK(typeid(typename dg::Graph<int>::pointer) == typeid(int*));
        CHECK(typeid(typename dg::Graph<int>::const_pointer) == typeid(const int*));
        CHECK(typeid(typename dg::Graph<int>::size_type) == typeid(std::size_t));
        
        CHECK(graph.empty());
        CHECK_EQUAL(0, graph.vertex_count());
        CHECK_EQUAL(0, graph.edge_count());
    }

    TEST(EmptyMethod) {
        dg::Graph<int> graph;
        CHECK(graph.empty());
        
        graph.add_vertex(10);
        CHECK(!graph.empty());
        
        graph.remove_vertex(0);
        CHECK(!graph.empty());
        
        graph.clear();
        CHECK(graph.empty());
    }
}

SUITE(VertexOperationsTests) {
    TEST(AddVertex) {
        dg::Graph<int> graph;
        
        auto id1 = graph.add_vertex(10);
        CHECK_EQUAL(0, id1);
        CHECK_EQUAL(1, graph.vertex_count());
        CHECK(graph.contains_vertex(0));
        
        auto id2 = graph.add_vertex(20);
        CHECK_EQUAL(1, id2);
        CHECK_EQUAL(2, graph.vertex_count());
        CHECK(graph.contains_vertex(1));
        
        auto it = graph.vertices_begin();
        CHECK_EQUAL(10, (*it).second);
        ++it;
        CHECK_EQUAL(20, (*it).second);
    }

    TEST(AddVertexWithCustomType) {
        dg::Graph<City> graph;
        
        auto id1 = graph.add_vertex(City("Moscow", 12000000));
        CHECK_EQUAL(0, id1);
        CHECK(graph.contains_vertex(0));
        
        auto id2 = graph.add_vertex(City("London", 9000000));
        CHECK_EQUAL(1, id2);
        
        auto it = graph.vertices_begin();
        CHECK_EQUAL("Moscow", (*it).second.name);
        CHECK_EQUAL(12000000, (*it).second.population);
    }

    TEST(ContainsVertex) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        
        CHECK(graph.contains_vertex(0));
        CHECK(graph.contains_vertex(1));
        CHECK(!graph.contains_vertex(2));
        CHECK(!graph.contains_vertex(100));
        
        graph.remove_vertex(0);
        CHECK(!graph.contains_vertex(0));
        CHECK(graph.contains_vertex(1));
    }

    TEST(RemoveVertex) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        graph.add_vertex(30);
        graph.add_edge(0, 1);
        graph.add_edge(1, 2);
        graph.add_edge(2, 0);
        
        CHECK_EQUAL(3, graph.vertex_count());
        CHECK_EQUAL(3, graph.edge_count());
        
        graph.remove_vertex(1);
        
        CHECK_EQUAL(3, graph.vertex_count());
        CHECK(!graph.contains_vertex(1));
        CHECK_EQUAL(1, graph.edge_count());
        CHECK(graph.contains_edge(2, 0));
        CHECK(!graph.contains_edge(0, 1));
        CHECK(!graph.contains_edge(1, 2));
    }

    TEST(RemoveVertexByIterator) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        graph.add_vertex(30);
        graph.add_edge(0, 1);
        graph.add_edge(1, 2);
        
        auto it = graph.vertices_begin();
        ++it;
        
        auto next_it = graph.remove_vertex(it);
        CHECK_EQUAL(2, (*next_it).first);
        CHECK(!graph.contains_vertex(1));
        CHECK_EQUAL(0, graph.edge_count());
    }

    TEST(RemoveVertexNotFound) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        
        CHECK_THROW(graph.remove_vertex(1), dg::vertex_not_found);
    }

    TEST(RemoveLastVertexByIterator) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        
        auto it = graph.vertices_begin();
        auto result = graph.remove_vertex(it);
        CHECK(result == graph.vertices_end());
        CHECK(!graph.contains_vertex(0));
    }
}

SUITE(EdgeOperationsTests) {
    TEST(AddEdge) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        graph.add_vertex(30);
        
        graph.add_edge(0, 1);
        graph.add_edge(1, 2);
        
        CHECK(graph.contains_edge(0, 1));
        CHECK(graph.contains_edge(1, 2));
        CHECK(!graph.contains_edge(0, 2));
        CHECK_EQUAL(2, graph.edge_count());
    }

    TEST(AddEdgeVertexNotFound) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        
        CHECK_THROW(graph.add_edge(0, 1), dg::vertex_not_found);
        CHECK_THROW(graph.add_edge(1, 0), dg::vertex_not_found);
        CHECK_THROW(graph.add_edge(1, 2), dg::vertex_not_found);
    }

    TEST(AddDuplicateEdge) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        graph.add_edge(0, 1);
        
        CHECK_THROW(graph.add_edge(0, 1), dg::duplicate_edge);
    }

    TEST(AddSelfLoop) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        
        graph.add_edge(0, 0);
        CHECK(graph.contains_edge(0, 0));
        CHECK_EQUAL(1, graph.edge_count());
        CHECK_EQUAL(1, graph.degree_vertex(0));
    }

    TEST(ContainsEdge) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        graph.add_vertex(30);
        graph.add_edge(0, 1);
        
        CHECK(graph.contains_edge(0, 1));
        CHECK(!graph.contains_edge(1, 0));
        CHECK(!graph.contains_edge(0, 2));
        CHECK(!graph.contains_edge(2, 1));
        
        CHECK(!graph.contains_edge(0, 5));
        CHECK(!graph.contains_edge(5, 0));
        CHECK(!graph.contains_edge(5, 6));
    }

    TEST(RemoveEdge) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        graph.add_vertex(30);
        graph.add_edge(0, 1);
        graph.add_edge(1, 2);
        graph.add_edge(0, 2);
        
        CHECK_EQUAL(3, graph.edge_count());
        
        graph.remove_edge(0, 1);
        CHECK_EQUAL(2, graph.edge_count());
        CHECK(!graph.contains_edge(0, 1));
        CHECK(graph.contains_edge(1, 2));
        CHECK(graph.contains_edge(0, 2));
        
        graph.remove_edge(1, 2);
        CHECK_EQUAL(1, graph.edge_count());
        CHECK(graph.contains_edge(0, 2));
    }

    TEST(RemoveEdgeByPair) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        graph.add_edge(0, 1);
        
        graph.remove_edge(std::make_pair(0, 1));
        CHECK(!graph.contains_edge(0, 1));
        CHECK_EQUAL(0, graph.edge_count());
    }

    TEST(RemoveEdgeByIterator) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        graph.add_vertex(30);
        graph.add_edge(0, 1);
        graph.add_edge(1, 2);
        
        auto it = graph.edges_begin();
        auto next_it = graph.remove_edge(it);
        
        CHECK_EQUAL(1, graph.edge_count());
        CHECK(!graph.contains_edge(0, 1));
        CHECK(graph.contains_edge(1, 2));
        CHECK_EQUAL(1, (*next_it).first);
        CHECK_EQUAL(2, (*next_it).second);
    }

    TEST(RemoveLastEdgeByIterator) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        graph.add_edge(0, 1);
        
        auto it = graph.edges_begin();
        auto result = graph.remove_edge(it);
        CHECK(result == graph.edges_end());
        CHECK_EQUAL(0, graph.edge_count());
    }

    TEST(RemoveNonExistentEdge) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        
        graph.remove_edge(0, 1);
        graph.remove_edge(1, 0);
        graph.remove_edge(std::make_pair(0, 1));
    }
}

SUITE(DegreeTests) {
    TEST(DegreeVertex) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        graph.add_vertex(30);
        graph.add_vertex(40);
        
        graph.add_edge(0, 1);
        graph.add_edge(0, 2);
        graph.add_edge(1, 3);
        graph.add_edge(2, 3);
        
        CHECK_EQUAL(2, graph.degree_vertex(0));
        CHECK_EQUAL(1, graph.degree_vertex(1));
        CHECK_EQUAL(1, graph.degree_vertex(2));
        CHECK_EQUAL(0, graph.degree_vertex(3));
        
        graph.add_edge(3, 3);
        CHECK_EQUAL(1, graph.degree_vertex(3));
    }

    TEST(InDegree) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        graph.add_vertex(30);
        
        graph.add_edge(0, 1);
        graph.add_edge(0, 2);
        graph.add_edge(1, 2);
        
        CHECK_EQUAL(0, graph.in_degree(0));
        CHECK_EQUAL(1, graph.in_degree(1));
        CHECK_EQUAL(2, graph.in_degree(2));
        
        graph.add_edge(2, 2);
        CHECK_EQUAL(3, graph.in_degree(2));
    }

    TEST(OutDegree) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        graph.add_vertex(30);
        
        graph.add_edge(0, 1);
        graph.add_edge(0, 2);
        graph.add_edge(1, 2);
        
        CHECK_EQUAL(2, graph.out_degree(0));
        CHECK_EQUAL(1, graph.out_degree(1));
        CHECK_EQUAL(0, graph.out_degree(2));
        
        graph.add_edge(2, 2);
        CHECK_EQUAL(1, graph.out_degree(2));
    }

    TEST(DegreeVertexNotFound) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        
        CHECK_THROW(graph.degree_vertex(1), dg::vertex_not_found);
        CHECK_THROW(graph.in_degree(1), dg::vertex_not_found);
        CHECK_THROW(graph.out_degree(1), dg::vertex_not_found);
    }

    TEST(DegreeEdge) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        graph.add_vertex(30);
        graph.add_edge(0, 1);
        graph.add_edge(1, 2);
        
        CHECK_EQUAL(1, graph.degree_edge(0, 1));
        CHECK_EQUAL(0, graph.degree_edge(1, 0));
        CHECK_EQUAL(0, graph.degree_edge(0, 2));
        CHECK_EQUAL(0, graph.degree_edge(2, 2));
    }
}

SUITE(IteratorTests) {
    TEST(VertexIterators) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        graph.add_vertex(30);
        
        std::vector<int> values;
        for (auto it = graph.vertices_begin(); it != graph.vertices_end(); ++it) {
            values.push_back((*it).second);
        }
        
        CHECK_EQUAL(3, values.size());
        CHECK_EQUAL(10, values[0]);
        CHECK_EQUAL(20, values[1]);
        CHECK_EQUAL(30, values[2]);
        
        const auto& const_graph = graph;
        values.clear();
        for (auto it = const_graph.vertices_begin(); it != const_graph.vertices_end(); ++it) {
            values.push_back((*it).second);
        }
        CHECK_EQUAL(3, values.size());
        
        auto it = graph.vertices_begin();
        ++it;
        --it;
        CHECK_EQUAL(0, (*it).first);
        CHECK_EQUAL(10, (*it).second);
    }

    TEST(ReverseVertexIterators) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        graph.add_vertex(30);
        
        std::vector<int> values;
        for (auto it = graph.vertices_rbegin(); it != graph.vertices_rend(); ++it) {
            values.push_back((*it).second);
        }
        
        CHECK_EQUAL(3, values.size());
        CHECK_EQUAL(30, values[0]);
        CHECK_EQUAL(20, values[1]);
        CHECK_EQUAL(10, values[2]);
        
        const auto& const_graph = graph;
        values.clear();
        for (auto it = const_graph.vertices_rbegin(); it != const_graph.vertices_rend(); ++it) {
            values.push_back((*it).second);
        }
        CHECK_EQUAL(3, values.size());
        CHECK_EQUAL(30, values[0]);
    }

    TEST(EdgeIterators) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        graph.add_vertex(30);
        graph.add_vertex(40);
        
        graph.add_edge(0, 1);
        graph.add_edge(1, 2);
        graph.add_edge(2, 3);
        graph.add_edge(3, 0);
        
        std::vector<std::pair<std::size_t, std::size_t>> edges;
        for (auto it = graph.edges_begin(); it != graph.edges_end(); ++it) {
            edges.push_back(*it);
        }
        
        CHECK_EQUAL(4, edges.size());
        CHECK_EQUAL(0, edges[0].first);
        CHECK_EQUAL(1, edges[0].second);
        
        const auto& const_graph = graph;
        edges.clear();
        for (auto it = const_graph.edges_begin(); it != const_graph.edges_end(); ++it) {
            edges.push_back(*it);
        }
        CHECK_EQUAL(4, edges.size());
        
        auto it = graph.edges_begin();
        ++it;
        --it;
        CHECK_EQUAL(0, (*it).first);
        CHECK_EQUAL(1, (*it).second);
    }

    TEST(AdjacentVerticesIterators) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        graph.add_vertex(30);
        graph.add_vertex(40);
        
        graph.add_edge(0, 1);
        graph.add_edge(0, 2);
        graph.add_edge(0, 3);
        
        std::vector<std::pair<std::size_t, int>> adjacent;
        for (auto it = graph.adjacent_vertices_begin(0); it != graph.adjacent_vertices_end(0); ++it) {
            adjacent.push_back(*it);
        }
        
        CHECK_EQUAL(3, adjacent.size());
        
        std::vector<std::size_t> ids;
        for (const auto& adj : adjacent) {
            ids.push_back(adj.first);
        }
        std::sort(ids.begin(), ids.end());
        CHECK_EQUAL(1, ids[0]);
        CHECK_EQUAL(2, ids[1]);
        CHECK_EQUAL(3, ids[2]);
    }

    TEST(EmptyIterators) {
        dg::Graph<int> graph;
        
        CHECK(graph.vertices_begin() == graph.vertices_end());
        CHECK(graph.edges_begin() == graph.edges_end());
        CHECK(graph.vertices_rbegin() == graph.vertices_rend());
        CHECK(graph.edges_rbegin() == graph.edges_rend());
    }

    TEST(SingleVertexIterators) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        
        auto v_it = graph.vertices_begin();
        CHECK(v_it != graph.vertices_end());
        CHECK_EQUAL(0, (*v_it).first);
        CHECK_EQUAL(10, (*v_it).second);
        
        ++v_it;
        CHECK(v_it == graph.vertices_end());
        
        CHECK(graph.edges_begin() == graph.edges_end());
        CHECK(graph.out_edges_begin(0) == graph.out_edges_end(0));
        CHECK(graph.in_edges_begin(0) == graph.in_edges_end(0));
        CHECK(graph.adjacent_vertices_begin(0) == graph.adjacent_vertices_end(0));
    }
}

SUITE(CopyAndAssignmentTests) {
    TEST(CopyConstructor) {
        dg::Graph<int> original;
        original.add_vertex(10);
        original.add_vertex(20);
        original.add_vertex(30);
        original.add_edge(0, 1);
        original.add_edge(1, 2);
        
        dg::Graph<int> copy(original);
        
        CHECK_EQUAL(original.vertex_count(), copy.vertex_count());
        CHECK_EQUAL(original.edge_count(), copy.edge_count());
        
        CHECK(copy.contains_vertex(0));
        CHECK(copy.contains_vertex(1));
        CHECK(copy.contains_vertex(2));
        CHECK(copy.contains_edge(0, 1));
        CHECK(copy.contains_edge(1, 2));
        
        original.remove_edge(0, 1);
        CHECK(copy.contains_edge(0, 1));
    }

    TEST(CopyAssignment) {
        dg::Graph<int> original;
        original.add_vertex(10);
        original.add_vertex(20);
        original.add_edge(0, 1);
        
        dg::Graph<int> copy;
        copy.add_vertex(100);
        copy.add_vertex(200);
        copy.add_vertex(300);
        copy.add_edge(0, 1);
        copy.add_edge(1, 2);
        
        copy = original;
        
        CHECK_EQUAL(original.vertex_count(), copy.vertex_count());
        CHECK_EQUAL(original.edge_count(), copy.edge_count());
        CHECK(copy.contains_vertex(0));
        CHECK(copy.contains_vertex(1));
        CHECK(copy.contains_edge(0, 1));
        CHECK(!copy.contains_vertex(2));
        
        copy = copy;
        CHECK_EQUAL(2, copy.vertex_count());
        CHECK_EQUAL(1, copy.edge_count());
    }

    TEST(CopyAssignmentWithCustomType) {
        dg::Graph<City> original;
        original.add_vertex(City("Moscow", 12000000));
        original.add_vertex(City("London", 9000000));
        original.add_edge(0, 1);
        
        dg::Graph<City> copy;
        copy = original;
        
        CHECK_EQUAL(2, copy.vertex_count());
        CHECK_EQUAL(1, copy.edge_count());
        
        auto it = copy.vertices_begin();
        CHECK_EQUAL("Moscow", (*it).second.name);
        ++it;
        CHECK_EQUAL("London", (*it).second.name);
    }
}

SUITE(ComparisonTests) {
    TEST(EqualityOperators) {
        dg::Graph<int> graph1;
        graph1.add_vertex(10);
        graph1.add_vertex(20);
        graph1.add_edge(0, 1);
        
        dg::Graph<int> graph2;
        graph2.add_vertex(10);
        graph2.add_vertex(20);
        graph2.add_edge(0, 1);
        
        dg::Graph<int> graph3;
        graph3.add_vertex(10);
        graph3.add_vertex(20);
        graph3.add_vertex(30);
        graph3.add_edge(0, 1);
        
        dg::Graph<int> graph4;
        graph4.add_vertex(10);
        graph4.add_vertex(20);
        graph4.add_edge(1, 0);
        
        CHECK(graph1 == graph2);
        CHECK(graph1 != graph3);
        CHECK(graph1 != graph4);
        CHECK(graph2 != graph3);
        CHECK(graph2 != graph4);
    }
}

SUITE(OutputTests) {
    TEST(OutputOperator) {
        dg::Graph<std::string> graph;
        graph.add_vertex("A");
        graph.add_vertex("B");
        graph.add_vertex("C");
        graph.add_edge(0, 1);
        graph.add_edge(1, 2);
        
        std::ostringstream oss;
        oss << graph;
        
        std::string output = oss.str();
        CHECK(output.find("A -> B") != std::string::npos);
        CHECK(output.find("B -> C") != std::string::npos);
    }

    TEST(OutputEmptyGraph) {
        dg::Graph<int> graph;
        
        std::ostringstream oss;
        oss << graph;
        
        std::string output = oss.str();
        CHECK(output.empty());
    }

    TEST(OutputWithCustomType) {
        dg::Graph<City> graph;
        graph.add_vertex(City("Moscow", 12000000));
        graph.add_vertex(City("London", 9000000));
        graph.add_edge(0, 1);
        
        std::ostringstream oss;
        oss << graph;
        
        std::string output = oss.str();
        CHECK(output.find("Moscow") != std::string::npos);
        CHECK(output.find("London") != std::string::npos);
    }
}

SUITE(ClearTests) {
    TEST(ClearMethod) {
        dg::Graph<int> graph;
        graph.add_vertex(10);
        graph.add_vertex(20);
        graph.add_vertex(30);
        graph.add_edge(0, 1);
        graph.add_edge(1, 2);
        graph.add_edge(0, 2);
        
        CHECK_EQUAL(3, graph.vertex_count());
        CHECK_EQUAL(3, graph.edge_count());
        
        graph.clear();
        
        CHECK_EQUAL(0, graph.vertex_count());
        CHECK_EQUAL(0, graph.edge_count());
        CHECK(graph.empty());
        
        auto id = graph.add_vertex(100);
        CHECK_EQUAL(0, id);
        CHECK_EQUAL(1, graph.vertex_count());
    }

    TEST(ClearEmptyGraph) {
        dg::Graph<int> graph;
        
        graph.clear();
        
        CHECK(graph.empty());
        CHECK_EQUAL(0, graph.vertex_count());
        CHECK_EQUAL(0, graph.edge_count());
    }
}

SUITE(ComplexScenariosTests) {
    TEST(CompleteGraph) {
        dg::Graph<int> graph;
        
        const int n = 5;
        for (int i = 0; i < n; ++i) {
            graph.add_vertex(i);
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    graph.add_edge(i, j);
                }
            }
        }
        
        CHECK_EQUAL(n, graph.vertex_count());
        CHECK_EQUAL(n * (n - 1), graph.edge_count());
        
        for (int i = 0; i < n; ++i) {
            CHECK_EQUAL(n - 1, graph.degree_vertex(i));
            CHECK_EQUAL(n - 1, graph.in_degree(i));
        }
    }

    TEST(CycleGraph) {
        dg::Graph<int> graph;
        
        const int n = 6;
        for (int i = 0; i < n; ++i) {
            graph.add_vertex(i * 10);
        }
        
        for (int i = 0; i < n; ++i) {
            graph.add_edge(i, (i + 1) % n);
        }
        
        CHECK_EQUAL(n, graph.vertex_count());
        CHECK_EQUAL(n, graph.edge_count());
        
        for (int i = 0; i < n; ++i) {
            CHECK_EQUAL(1, graph.degree_vertex(i));
            CHECK_EQUAL(1, graph.in_degree(i));
        }
    }
}

SUITE(CustomTypesTests) {
    TEST(CityGraph) {
        dg::Graph<City> graph;
        
        auto moscow_id = graph.add_vertex(City("Moscow", 12000000));
        auto london_id = graph.add_vertex(City("London", 9000000));
        auto paris_id = graph.add_vertex(City("Paris", 7000000));
        auto berlin_id = graph.add_vertex(City("Berlin", 6000000));
        
        graph.add_edge(moscow_id, london_id);
        graph.add_edge(london_id, paris_id);
        graph.add_edge(paris_id, berlin_id);
        graph.add_edge(berlin_id, moscow_id);
        graph.add_edge(moscow_id, paris_id);
        
        CHECK_EQUAL(4, graph.vertex_count());
        CHECK_EQUAL(5, graph.edge_count());
        
        int total_population = 0;
        for (auto it = graph.vertices_begin(); it != graph.vertices_end(); ++it) {
            total_population += (*it).second.population;
        }
        CHECK_EQUAL(34000000, total_population);
        
        int adjacent_count = 0;
        for (auto it = graph.adjacent_vertices_begin(moscow_id); 
             it != graph.adjacent_vertices_end(moscow_id); ++it) {
            adjacent_count++;
        }
        CHECK_EQUAL(2, adjacent_count);
    }

    TEST(CourseGraph) {
        dg::Graph<Course> graph;
        
        auto math_id = graph.add_vertex(Course("Mathematics", 5));
        auto physics_id = graph.add_vertex(Course("Physics", 4));
        auto programming_id = graph.add_vertex(Course("Programming", 6));
        auto algorithms_id = graph.add_vertex(Course("Algorithms", 5));
        
        graph.add_edge(math_id, physics_id);
        graph.add_edge(physics_id, programming_id);
        graph.add_edge(math_id, programming_id);
        graph.add_edge(programming_id, algorithms_id);
        
        CHECK_EQUAL(4, graph.vertex_count());
        CHECK_EQUAL(4, graph.edge_count());
        
        int prerequisites_count = 0;
        for (auto it = graph.in_edges_begin(programming_id); 
             it != graph.in_edges_end(programming_id); ++it) {
            prerequisites_count++;
        }
        CHECK_EQUAL(2, prerequisites_count);
        
        int total_credits = 0;
        for (auto it = graph.vertices_begin(); it != graph.vertices_end(); ++it) {
            total_credits += (*it).second.credits;
        }
        CHECK_EQUAL(20, total_credits);
    }
}

SUITE(StressTests) {
    TEST(MultipleAddRemove) {
        dg::Graph<int> graph;
        
        for (int i = 0; i < 100; ++i) {
            graph.add_vertex(i);
        }
        
        CHECK_EQUAL(100, graph.vertex_count());
        
        for (int i = 0; i < 100; ++i) {
            for (int j = i + 1; j < std::min(i + 5, 100); ++j) {
                graph.add_edge(i, j);
            }
        }
        
        for (int i = 0; i < 100; i += 2) {
            graph.remove_vertex(i);
        }
        
        CHECK_EQUAL(100, graph.vertex_count());
        
        for (int i = 1; i < 100; i += 2) {
            CHECK(graph.contains_vertex(i));
        }
        
        for (int i = 0; i < 100; i += 2) {
            CHECK(!graph.contains_vertex(i));
        }
    }

    TEST(IteratorStability) {
        dg::Graph<int> graph;
        
        for (int i = 0; i < 10; ++i) {
            graph.add_vertex(i);
        }
        
        for (int i = 0; i < 9; ++i) {
            graph.add_edge(i, i + 1);
        }
        
        std::size_t count_before = graph.edge_count();
        auto it = graph.edges_begin();
        while (it != graph.edges_end()) {
            it = graph.remove_edge(it);
        }
        
        CHECK_EQUAL(0, graph.edge_count());
        CHECK_EQUAL(count_before, 9);
    }
}

int main() {
    return UnitTest::RunAllTests();
}
