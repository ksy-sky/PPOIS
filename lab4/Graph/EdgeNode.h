#pragma once
#include <cstddef>

class EdgeNode {
public:
    std::size_t src;  
    std::size_t dst;  

    EdgeNode* next_out    = nullptr; 
    EdgeNode* next_in     = nullptr; 
    EdgeNode* next_global = nullptr; 
    EdgeNode* prev_global = nullptr; 

    EdgeNode(std::size_t s, std::size_t d) : src(s), dst(d) {}
};
