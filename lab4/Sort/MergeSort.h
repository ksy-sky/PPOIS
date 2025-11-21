#pragma once
#include <vector>
#include <algorithm>
#include <iterator>

template<typename Container>
void merge_sort(Container& container) {
    using ValueType = typename Container::value_type;
    
    auto first = container.begin();
    auto last = container.end();
    
    auto size = std::distance(first, last);
    if (size <= 1) return;
    
    auto middle = first;
    std::advance(middle, size / 2);
    
    std::vector<ValueType> left(first, middle);
    std::vector<ValueType> right(middle, last);
    
    merge_sort(left);
    merge_sort(right);
    
    auto it = first;
    auto left_it = left.begin();
    auto right_it = right.begin();
    
    while (left_it != left.end() && right_it != right.end()) {
        if (*left_it < *right_it) {
            *it++ = *left_it++;
        } else {
            *it++ = *right_it++;
        }
    }
    
    while (left_it != left.end()) *it++ = *left_it++;
    while (right_it != right.end()) *it++ = *right_it++;
}