#pragma once
#include <cstddef>

template <typename T>
class VertexNode {
public:
    std::size_t id;       
    T value;             

    class EdgeNode* out_head = nullptr; 
    class EdgeNode* in_head  = nullptr; 
    VertexNode(std::size_t i, const T& v) : id(i), value(v) {}
};
