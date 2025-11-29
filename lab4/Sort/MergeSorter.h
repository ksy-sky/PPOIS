#pragma once
#include <vector>
#include <algorithm>
#include <iterator>

template<typename T>
class MergeSorter {
public:
    using Container = std::vector<T>;
    void sort(Container& container) {
        if (container.size() <= 1) return;
        merge_sort(container.begin(), container.end());
    }

private:
    template<typename Iterator>
    void merge_sort(Iterator first, Iterator last) {
        auto size = std::distance(first, last);
        if (size <= 1) return;

        auto middle = first;
        std::advance(middle, size / 2);

        std::vector<T> left(first, middle);
        std::vector<T> right(middle, last);

        merge_sort(left.begin(), left.end());
        merge_sort(right.begin(), right.end());

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
};
