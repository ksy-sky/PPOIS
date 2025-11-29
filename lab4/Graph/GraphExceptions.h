#pragma once
#include <stdexcept>
#include <string>

namespace dg {

class graph_error : public std::runtime_error {
public:
    explicit graph_error(const std::string& msg) : std::runtime_error(msg) {}
};

class vertex_not_found : public graph_error {
public:
    explicit vertex_not_found(const std::string& msg) : graph_error(msg) {}
};

class edge_not_found : public graph_error {
public:
    explicit edge_not_found(const std::string& msg) : graph_error(msg) {}
};

class duplicate_vertex : public graph_error {
public:
    explicit duplicate_vertex(const std::string& msg) : graph_error(msg) {}
};

class duplicate_edge : public graph_error {
public:
    explicit duplicate_edge(const std::string& msg) : graph_error(msg) {}
};

} 
