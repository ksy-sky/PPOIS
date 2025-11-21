#pragma once
#include <cstddef>

namespace dg {

template <typename T> class Graph;

template <typename T>
struct Vertex {
    using value_type = T;
    std::size_t id;
    const T* value;
    Vertex(std::size_t vid, const T* v) : id(vid), value(v) {}
};

template <typename T>
struct Edge {
    std::size_t src;
    std::size_t dst;
    Edge(std::size_t s, std::size_t d) : src(s), dst(d) {}
};

template <typename T>
struct VertexNode {
    std::size_t id;
    T value;
    struct EdgeNode* out_head = nullptr;
    struct EdgeNode* in_head  = nullptr;
    VertexNode(std::size_t vid, const T& v) : id(vid), value(v) {}
};

struct EdgeNode {
    std::size_t src;
    std::size_t dst;
    EdgeNode* next_out = nullptr;
    EdgeNode* next_in  = nullptr;
    EdgeNode* prev_global = nullptr;
    EdgeNode* next_global = nullptr;
    EdgeNode(std::size_t s, std::size_t d) : src(s), dst(d) {}
};

} // namespace dg
