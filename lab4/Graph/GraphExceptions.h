#pragma once
#include <stdexcept>
#include <string>

namespace dg {

struct graph_error : std::runtime_error {
    explicit graph_error(const std::string& msg) : std::runtime_error(msg) {}
};

struct vertex_not_found : graph_error {
    explicit vertex_not_found(const std::string& msg) : graph_error(msg) {}
};

struct edge_not_found : graph_error {
    explicit edge_not_found(const std::string& msg) : graph_error(msg) {}
};

struct duplicate_vertex : graph_error {
    explicit duplicate_vertex(const std::string& msg) : graph_error(msg) {}
};

struct duplicate_edge : graph_error {
    explicit duplicate_edge(const std::string& msg) : graph_error(msg) {}
};

} // namespace dg
