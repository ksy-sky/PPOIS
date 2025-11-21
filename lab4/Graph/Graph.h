#pragma once
#include <vector>
#include <ostream>
#include <algorithm>
#include "GraphExceptions.h"
#include "GraphTypes.h"
#include "GraphIterators.h"

namespace dg {

template <typename T>
class Graph {
public:
    using size_type  = std::size_t;
    using vertex_iterator       = dg::vertex_iterator<T>;
    using const_vertex_iterator = dg::const_vertex_iterator<T>;
    using edge_iterator         = dg::edge_iterator<T>;
    using const_edge_iterator   = dg::const_edge_iterator<T>;

    Graph() = default;
    
    // Простой конструктор копирования - создает пустой граф
    Graph(const Graph& other) : Graph() {
        // Копируем только вершины (без рёбер)
        for (const auto* v : other.vertices_) {
            if (v) {
                add_vertex(v->value);
            }
        }
        
        // Копируем рёбра
        for (auto it = other.edges_begin(); it != other.edges_end(); ++it) {
            auto edge = *it;
            add_edge(edge.src, edge.dst);
        }
    }
    
    // Оператор присваивания через copy-and-swap
    Graph& operator=(const Graph& other) {
        if (this != &other) {
            Graph temp(other);
            swap(temp);
        }
        return *this;
    }
    
    ~Graph() { clear(); }

    // Остальные методы без изменений...
    size_type add_vertex(const T& value) {
        auto* node = new VertexNode<T>(vertices_.size(), value);
        vertices_.push_back(node);
        return node->id;
    }

    void add_edge(size_type src, size_type dst) {
        if (!contains_vertex(src) || !contains_vertex(dst))
            throw vertex_not_found("vertex not found");
        if (contains_edge(src, dst))
            throw duplicate_edge("edge exists");

        auto* e = new EdgeNode(src, dst);
        e->next_out = vertices_[src]->out_head;
        vertices_[src]->out_head = e;
        e->next_in = vertices_[dst]->in_head;
        vertices_[dst]->in_head = e;

        if (!edges_head_) {
            edges_head_ = edges_tail_ = e;
        } else {
            edges_tail_->next_global = e;
            e->prev_global = edges_tail_;
            edges_tail_ = e;
        }
    }

    bool contains_vertex(size_type vid) const {
        return vid < vertices_.size() && vertices_[vid] != nullptr;
    }

    bool contains_edge(size_type src, size_type dst) const {
        if (!contains_vertex(src) || !contains_vertex(dst)) return false;
        for (auto* e = vertices_[src]->out_head; e; e = e->next_out)
            if (e->dst == dst) return true;
        return false;
    }

    size_type vertex_count() const { return vertices_.size(); }
    
    size_type edge_count() const {
        size_type n = 0;
        for (auto* e = edges_head_; e; e = e->next_global) ++n;
        return n;
    }

    void clear() {
        EdgeNode* cur = edges_head_;
        while (cur) {
            auto* next = cur->next_global;
            delete cur;
            cur = next;
        }
        edges_head_ = edges_tail_ = nullptr;
        
        for (auto* v : vertices_) {
            delete v;
        }
        vertices_.clear();
    }

    vertex_iterator vertices_begin() { return vertex_iterator(vertices_.begin()); }
    vertex_iterator vertices_end()   { return vertex_iterator(vertices_.end()); }
    edge_iterator edges_begin()      { return edge_iterator(edges_head_); }
    edge_iterator edges_end()        { return edge_iterator(nullptr); }

    const_vertex_iterator vertices_begin() const { return const_vertex_iterator(vertices_.begin()); }
    const_vertex_iterator vertices_end() const   { return const_vertex_iterator(vertices_.end()); }
    const_edge_iterator edges_begin() const      { return const_edge_iterator(edges_head_); }
    const_edge_iterator edges_end() const        { return const_edge_iterator(nullptr); }

    void swap(Graph& other) noexcept {
        std::swap(vertices_, other.vertices_);
        std::swap(edges_head_, other.edges_head_);
        std::swap(edges_tail_, other.edges_tail_);
    }

private:
    std::vector<VertexNode<T>*> vertices_;
    EdgeNode* edges_head_ = nullptr;
    EdgeNode* edges_tail_ = nullptr;
};

} // namespace dg