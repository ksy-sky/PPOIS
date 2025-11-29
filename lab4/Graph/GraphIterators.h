#pragma once
#include <iterator>
#include <vector>
#include <utility>
#include "VertexNode.h"
#include "EdgeNode.h"

namespace dg {

template <typename T, bool Const> class VertexIterator;
template <typename T, bool Const> class EdgeIterator;
template <typename T, bool Const> class IncidentEdgeIterator;
template <typename T, bool Const> class AdjacentVertexIterator;

template <typename T, bool Const>
class VertexIterator {
public:
    using container_type = std::vector<VertexNode<T>*>;
    using value_type = std::pair<std::size_t, T>;
    using reference = typename std::conditional<Const, const value_type, value_type>::type&;
    using pointer = typename std::conditional<Const, const value_type, value_type>::type*;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;

    using iter_t = typename std::conditional<Const,
                        typename container_type::const_iterator,
                        typename container_type::iterator>::type;

    VertexIterator() = default;
    explicit VertexIterator(iter_t it) : it_(it) {}

    reference operator*() const { 
        static value_type result;
        result = value_type{(*it_)->id, (*it_)->value};
        return result;
    }
    
    pointer operator->() const { 
        static value_type result;
        result = value_type{(*it_)->id, (*it_)->value};
        return &result;
    }

    VertexIterator& operator++() { ++it_; return *this; }
    VertexIterator operator++(int) { auto tmp = *this; ++it_; return tmp; }
    VertexIterator& operator--() { --it_; return *this; }
    VertexIterator operator--(int) { auto tmp = *this; --it_; return tmp; }

    bool operator==(const VertexIterator& other) const { return it_ == other.it_; }
    bool operator!=(const VertexIterator& other) const { return it_ != other.it_; }

private:
    iter_t it_{};
};

template <typename T, bool Const>
class EdgeIterator {
public:
    using value_type = std::pair<std::size_t, std::size_t>;
    using reference = typename std::conditional<Const, const value_type, value_type>::type&;
    using pointer = typename std::conditional<Const, const value_type, value_type>::type*;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;

    using node_ptr = typename std::conditional<Const, const EdgeNode*, EdgeNode*>::type;

    EdgeIterator() = default;
    explicit EdgeIterator(node_ptr p) : p_(p) {}

    reference operator*() const { 
        static value_type result;
        result = value_type{p_->src, p_->dst};
        return result;
    }
    
    pointer operator->() const { 
        static value_type result;
        result = value_type{p_->src, p_->dst};
        return &result;
    }

    EdgeIterator& operator++() { p_ = p_ ? p_->next_global : nullptr; return *this; }
    EdgeIterator operator++(int) { auto tmp = *this; ++(*this); return tmp; }
    EdgeIterator& operator--() { p_ = p_ ? p_->prev_global : nullptr; return *this; }
    EdgeIterator operator--(int) { auto tmp = *this; --(*this); return tmp; }

    bool operator==(const EdgeIterator& other) const { return p_ == other.p_; }
    bool operator!=(const EdgeIterator& other) const { return p_ != other.p_; }

private:
    node_ptr p_ = nullptr;
};

template <typename T, bool Const>
class IncidentEdgeIterator {
public:
    using value_type = std::pair<std::size_t, std::size_t>;
    using reference = typename std::conditional<Const, const value_type, value_type>::type&;
    using pointer = typename std::conditional<Const, const value_type, value_type>::type*;
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;

    using node_ptr = typename std::conditional<Const, const EdgeNode*, EdgeNode*>::type;

    IncidentEdgeIterator() = default;
    explicit IncidentEdgeIterator(node_ptr p) : p_(p) {}

    reference operator*() const { 
        static value_type result;
        result = value_type{p_->src, p_->dst};
        return result;
    }
    
    pointer operator->() const { 
        static value_type result;
        result = value_type{p_->src, p_->dst};
        return &result;
    }

    IncidentEdgeIterator& operator++() { p_ = p_ ? p_->next_out : nullptr; return *this; }
    IncidentEdgeIterator operator++(int) { auto tmp = *this; ++(*this); return tmp; }

    bool operator==(const IncidentEdgeIterator& other) const { return p_ == other.p_; }
    bool operator!=(const IncidentEdgeIterator& other) const { return p_ != other.p_; }

private:
    node_ptr p_ = nullptr;
};

template <typename T, bool Const>
class AdjacentVertexIterator {
public:
    using value_type = std::pair<std::size_t, T>;
    using reference = typename std::conditional<Const, const value_type, value_type>::type&;
    using pointer = typename std::conditional<Const, const value_type, value_type>::type*;
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;

    using node_ptr = typename std::conditional<Const, const EdgeNode*, EdgeNode*>::type;
    using vertex_ptr = typename std::conditional<Const, const VertexNode<T>*, VertexNode<T>*>::type;

    AdjacentVertexIterator() = default;
    explicit AdjacentVertexIterator(node_ptr p, const std::vector<vertex_ptr>& vertices) 
        : p_(p), vertices_(vertices) {}

    reference operator*() const { 
        static value_type result;
        result = value_type{p_->dst, vertices_[p_->dst]->value};
        return result;
    }
    
    pointer operator->() const { 
        static value_type result;
        result = value_type{p_->dst, vertices_[p_->dst]->value};
        return &result;
    }

    AdjacentVertexIterator& operator++() { p_ = p_ ? p_->next_out : nullptr; return *this; }
    AdjacentVertexIterator operator++(int) { auto tmp = *this; ++(*this); return tmp; }

    bool operator==(const AdjacentVertexIterator& other) const { return p_ == other.p_; }
    bool operator!=(const AdjacentVertexIterator& other) const { return p_ != other.p_; }

private:
    node_ptr p_ = nullptr;
    const std::vector<vertex_ptr>& vertices_;
};

template <typename T> using vertex_iterator = VertexIterator<T, false>;
template <typename T> using const_vertex_iterator = VertexIterator<T, true>;
template <typename T> using edge_iterator = EdgeIterator<T, false>;
template <typename T> using const_edge_iterator = EdgeIterator<T, true>;
template <typename T> using incident_edge_iterator = IncidentEdgeIterator<T, false>;
template <typename T> using const_incident_edge_iterator = IncidentEdgeIterator<T, true>;
template <typename T> using adjacent_vertex_iterator = AdjacentVertexIterator<T, false>;
template <typename T> using const_adjacent_vertex_iterator = AdjacentVertexIterator<T, true>;

} // namespace dg
