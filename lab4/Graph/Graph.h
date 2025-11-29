#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <memory>
#include "VertexNode.h"
#include "EdgeNode.h"
#include "GraphExceptions.h"
#include "GraphIterators.h"

namespace dg {

template <typename T>
class Graph {
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    using vertex_iterator = dg::vertex_iterator<T>;
    using const_vertex_iterator = dg::const_vertex_iterator<T>;
    using edge_iterator = dg::edge_iterator<T>;
    using const_edge_iterator = dg::const_edge_iterator<T>;
    using incident_edge_iterator = dg::incident_edge_iterator<T>;
    using const_incident_edge_iterator = dg::const_incident_edge_iterator<T>;
    using adjacent_vertex_iterator = dg::adjacent_vertex_iterator<T>;
    using const_adjacent_vertex_iterator = dg::const_adjacent_vertex_iterator<T>;

    using reverse_vertex_iterator = std::reverse_iterator<vertex_iterator>;
    using const_reverse_vertex_iterator = std::reverse_iterator<const_vertex_iterator>;
    using reverse_edge_iterator = std::reverse_iterator<edge_iterator>;
    using const_reverse_edge_iterator = std::reverse_iterator<const_edge_iterator>;

public:
    Graph() = default;
    Graph(const Graph& other) { copy_from(other); }
    
    Graph& operator=(const Graph& other) {
        if (this != &other) {
            clear();
            copy_from(other);
        }
        return *this;
    }
    
    ~Graph() { clear(); }

    bool empty() const { return vertices_.empty(); }
    size_type vertex_count() const { return vertices_.size(); }
    
    size_type edge_count() const {
        size_type n = 0;
        for (auto* e = edges_head_; e; e = e->next_global) ++n;
        return n;
    }

    size_type add_vertex(const T& value) {
        auto* v = new VertexNode<T>(vertices_.size(), value);
        vertices_.push_back(v);
        return v->id;
    }

    bool contains_vertex(size_type id) const {
        return id < vertices_.size() && vertices_[id] != nullptr;
    }

    void remove_vertex(size_type id) {
        if (!contains_vertex(id))
            throw vertex_not_found("Vertex not found");
        
        auto out_it = out_edges_begin(id);
        while (out_it != out_edges_end(id)) {
            auto edge = *out_it;
            auto next_it = out_it;
            ++next_it;
            remove_edge(edge.first, edge.second);
            out_it = next_it;
        }
        
        auto in_it = in_edges_begin(id);
        while (in_it != in_edges_end(id)) {
            auto edge = *in_it;
            auto next_it = in_it;
            ++next_it;
            remove_edge(edge.first, edge.second);
            in_it = next_it;
        }
        
        delete vertices_[id];
        vertices_[id] = nullptr;
    }

    vertex_iterator remove_vertex(vertex_iterator it) {
        if (it == vertices_end()) return it;
        auto vertex_id = (*it).first;
        auto next_it = it;
        ++next_it;
        remove_vertex(vertex_id);
        return next_it;
    }

    void add_edge(size_type src, size_type dst) {
        if (!contains_vertex(src) || !contains_vertex(dst))
            throw vertex_not_found("Vertex not found");
        if (contains_edge(src, dst))
            throw duplicate_edge("Edge already exists");

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

    bool contains_edge(size_type src, size_type dst) const {
        if (!contains_vertex(src) || !contains_vertex(dst)) return false;
        for (auto* e = vertices_[src]->out_head; e; e = e->next_out)
            if (e->dst == dst) return true;
        return false;
    }

    void remove_edge(size_type src, size_type dst) {
        if (!contains_edge(src, dst)) return;
        
        EdgeNode* cur = edges_head_;
        while (cur) {
            if (cur->src == src && cur->dst == dst) {
                remove_edge_internal(cur);
                return;
            }
            cur = cur->next_global;
        }
    }

    void remove_edge(const std::pair<size_type, size_type>& edge) {
        remove_edge(edge.first, edge.second);
    }

    edge_iterator remove_edge(edge_iterator it) {
        if (it == edges_end()) return it;
        auto edge = *it;
        auto next_it = it;
        ++next_it;
        remove_edge(edge.first, edge.second);
        return next_it;
    }

    size_type degree_vertex(size_type id) const {
        if (!contains_vertex(id))
            throw vertex_not_found("Vertex not found");
        
        size_type deg = 0;
        for (auto* e = vertices_[id]->out_head; e; e = e->next_out) ++deg;
        return deg;
    }

    size_type in_degree(size_type id) const {
        if (!contains_vertex(id))
            throw vertex_not_found("Vertex not found");
        
        size_type deg = 0;
        for (auto* e = vertices_[id]->in_head; e; e = e->next_in) ++deg;
        return deg;
    }

    size_type out_degree(size_type id) const {
        return degree_vertex(id); 
    }

    size_type degree_edge(size_type src, size_type dst) const {
        return contains_edge(src, dst) ? 1 : 0; 
    }


    vertex_iterator vertices_begin() { return vertex_iterator(vertices_.begin()); }
    vertex_iterator vertices_end()   { return vertex_iterator(vertices_.end()); }
    const_vertex_iterator vertices_begin() const { return const_vertex_iterator(vertices_.begin()); }
    const_vertex_iterator vertices_end() const   { return const_vertex_iterator(vertices_.end()); }
    
    reverse_vertex_iterator vertices_rbegin() { return reverse_vertex_iterator(vertices_end()); }
    reverse_vertex_iterator vertices_rend()   { return reverse_vertex_iterator(vertices_begin()); }
    const_reverse_vertex_iterator vertices_rbegin() const { return const_reverse_vertex_iterator(vertices_end()); }
    const_reverse_vertex_iterator vertices_rend() const   { return const_reverse_vertex_iterator(vertices_begin()); }

    edge_iterator edges_begin() { return edge_iterator(edges_head_); }
    edge_iterator edges_end()   { return edge_iterator(nullptr); }
    const_edge_iterator edges_begin() const { return const_edge_iterator(edges_head_); }
    const_edge_iterator edges_end() const   { return const_edge_iterator(nullptr); }
    
    reverse_edge_iterator edges_rbegin() { return reverse_edge_iterator(edges_end()); }
    reverse_edge_iterator edges_rend()   { return reverse_edge_iterator(edges_begin()); }
    const_reverse_edge_iterator edges_rbegin() const { return const_reverse_edge_iterator(edges_end()); }
    const_reverse_edge_iterator edges_rend() const   { return const_reverse_edge_iterator(edges_begin()); }

    incident_edge_iterator out_edges_begin(size_type id) {
        return incident_edge_iterator(vertices_[id]->out_head);
    }
    incident_edge_iterator out_edges_end(size_type id) {
        return incident_edge_iterator(nullptr);
    }
    const_incident_edge_iterator out_edges_begin(size_type id) const {
        return const_incident_edge_iterator(vertices_[id]->out_head);
    }
    const_incident_edge_iterator out_edges_end(size_type id) const {
        return const_incident_edge_iterator(nullptr);
    }

    incident_edge_iterator in_edges_begin(size_type id) {
        return incident_edge_iterator(vertices_[id]->in_head);
    }
    incident_edge_iterator in_edges_end(size_type id) {
        return incident_edge_iterator(nullptr);
    }
    const_incident_edge_iterator in_edges_begin(size_type id) const {
        return const_incident_edge_iterator(vertices_[id]->in_head);
    }
    const_incident_edge_iterator in_edges_end(size_type id) const {
        return const_incident_edge_iterator(nullptr);
    }

    adjacent_vertex_iterator adjacent_vertices_begin(size_type id) {
        return adjacent_vertex_iterator(vertices_[id]->out_head, vertices_);
    }
    adjacent_vertex_iterator adjacent_vertices_end(size_type id) {
        return adjacent_vertex_iterator(nullptr, vertices_);
    }
    const_adjacent_vertex_iterator adjacent_vertices_begin(size_type id) const {
        return const_adjacent_vertex_iterator(vertices_[id]->out_head, vertices_);
    }
    const_adjacent_vertex_iterator adjacent_vertices_end(size_type id) const {
        return const_adjacent_vertex_iterator(nullptr, vertices_);
    }

    bool operator==(const Graph& other) const {
        if (vertex_count() != other.vertex_count() || edge_count() != other.edge_count())
            return false;
        
        for (auto it = edges_begin(); it != edges_end(); ++it) {
            auto edge = *it;
            if (!other.contains_edge(edge.first, edge.second))
                return false;
        }
        return true;
    }
    
    bool operator!=(const Graph& other) const { return !(*this == other); }
    bool operator<(const Graph& other) const { return vertex_count() < other.vertex_count(); }
    bool operator>(const Graph& other) const { return vertex_count() > other.vertex_count(); }
    bool operator<=(const Graph& other) const { return !(*this > other); }
    bool operator>=(const Graph& other) const { return !(*this < other); }

    friend std::ostream& operator<<(std::ostream& os, const Graph& g) {
        std::for_each(g.edges_begin(), g.edges_end(), [&](const auto& edge) {
            os << g.vertices_[edge.first]->value << " -> " << g.vertices_[edge.second]->value << "\n";
        });
        return os;
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
            if (v) delete v;
        }
        vertices_.clear();
    }

private:
    std::vector<VertexNode<T>*> vertices_;
    EdgeNode* edges_head_ = nullptr;
    EdgeNode* edges_tail_ = nullptr;

    void copy_from(const Graph& other) {
        for (auto* v : other.vertices_) {
            if (v) add_vertex(v->value);
        }
        
        for (auto it = other.edges_begin(); it != other.edges_end(); ++it) {
            auto edge = *it;
            add_edge(edge.first, edge.second);
        }
    }

    void remove_edge_internal(EdgeNode* edge) {
        if (vertices_[edge->src]->out_head == edge) {
            vertices_[edge->src]->out_head = edge->next_out;
        } else {
            EdgeNode* prev = vertices_[edge->src]->out_head;
            while (prev && prev->next_out != edge) prev = prev->next_out;
            if (prev) prev->next_out = edge->next_out;
        }
        
        if (vertices_[edge->dst]->in_head == edge) {
            vertices_[edge->dst]->in_head = edge->next_in;
        } else {
            EdgeNode* prev = vertices_[edge->dst]->in_head;
            while (prev && prev->next_in != edge) prev = prev->next_in;
            if (prev) prev->next_in = edge->next_in;
        }
        
        if (edge->prev_global) edge->prev_global->next_global = edge->next_global;
        if (edge->next_global) edge->next_global->prev_global = edge->prev_global;
        if (edge == edges_head_) edges_head_ = edge->next_global;
        if (edge == edges_tail_) edges_tail_ = edge->prev_global;
        
        delete edge;
    }
};

}
