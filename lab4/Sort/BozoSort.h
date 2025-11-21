#pragma once
#include <algorithm>
#include <random>

constexpr std::size_t MAX_ITERATIONS = 10000;
template<typename Container>
void bozo_sort(Container& container) {
    auto first = container.begin();
    auto last = container.end();
    
    std::random_device rd;
    std::mt19937 gen(rd());
    auto size = std::distance(first, last);
    
    if (size <= 1) return;
    
    std::uniform_int_distribution<> dis(0, size - 1);
    
    size_t iterations = 0;
    
    while (!std::is_sorted(first, last) && iterations < MAX_ITERATIONS) {
        auto leftIndex = dis(gen);
        auto rightIndex = dis(gen);

        if (leftIndex != rightIndex) {
            std::iter_swap(first + leftIndex, first + rightIndex);
        }
        iterations++;
    }
}