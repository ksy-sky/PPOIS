#pragma once
#include <iterator>
#include <vector>
#include "GraphTypes.h"

namespace dg {

// Итератор по вершинам
template <typename T, bool Const>
class VertexIterator {
public:
    using container_type   = std::vector<VertexNode<T>*>;
    using value_type       = Vertex<T>;
    using iterator_category= std::bidirectional_iterator_tag;

    using iter_t   = typename std::conditional<Const,
                        typename container_type::const_iterator,
                        typename container_type::iterator>::type;

    VertexIterator() = default;
    explicit VertexIterator(iter_t it) : it_(it) {}

    value_type operator*() const {
        const VertexNode<T>* n = *it_;
        return Vertex<T>(n->id, &n->value);
    }

    VertexIterator& operator++() { ++it_; return *this; }
    VertexIterator operator++(int){ auto tmp(*this); ++(*this); return tmp; }
    VertexIterator& operator--() { --it_; return *this; }
    VertexIterator operator--(int){ auto tmp(*this); --(*this); return tmp; }

    bool operator==(const VertexIterator& other) const { return it_ == other.it_; }
    bool operator!=(const VertexIterator& other) const { return it_ != other.it_; }

private:
    iter_t it_{};
};

// Итератор по рёбрам (глобальный список)
template <typename T, bool Const>
class EdgeIterator {
public:
    using value_type       = Edge<T>;
    using iterator_category= std::bidirectional_iterator_tag;

    using node_ptr = EdgeNode*;

    EdgeIterator() = default;
    explicit EdgeIterator(node_ptr p) : p_(p) {}

    value_type operator*() const { return Edge<T>(p_->src, p_->dst); }

    EdgeIterator& operator++() { p_ = p_ ? p_->next_global : nullptr; return *this; }
    EdgeIterator operator++(int){ auto tmp(*this); ++(*this); return tmp; }
    EdgeIterator& operator--() { p_ = p_ ? p_->prev_global : nullptr; return *this; }
    EdgeIterator operator--(int){ auto tmp(*this); --(*this); return tmp; }

    bool operator==(const EdgeIterator& other) const { return p_ == other.p_; }
    bool operator!=(const EdgeIterator& other) const { return p_ != other.p_; }

    node_ptr raw() const { return p_; }

private:
    node_ptr p_ = nullptr;
};

// Алиасы
template <typename T> using vertex_iterator       = VertexIterator<T,false>;
template <typename T> using const_vertex_iterator = VertexIterator<T,true>;
template <typename T> using edge_iterator         = EdgeIterator<T,false>;
template <typename T> using const_edge_iterator   = EdgeIterator<T,true>;

} // namespace dg
