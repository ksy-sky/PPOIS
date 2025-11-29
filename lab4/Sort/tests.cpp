#include <UnitTest++/UnitTest++.h>
#include <vector>
#include <iostream>
#include "MergeSorter.h"
#include "BozoSorter.h"
#include "Smartphone.h"
#include "Car.h"

TEST(MergeSort_Int_Vector_Simple) {
    std::vector<int> numbers = {5, 2, 8, 1, 9, 3};
    std::vector<int> expected = {1, 2, 3, 5, 8, 9};
    MergeSorter<int> sorter;
    sorter.sort(numbers);
    CHECK_ARRAY_EQUAL(expected.data(), numbers.data(), numbers.size());
}

TEST(MergeSort_Int_Vector_Reverse) {
    std::vector<int> numbers = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    MergeSorter<int> sorter;
    sorter.sort(numbers);
    CHECK_ARRAY_EQUAL(expected.data(), numbers.data(), numbers.size());
}

TEST(MergeSort_Int_Vector_Duplicates) {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    std::vector<int> expected = {1, 1, 2, 3, 4, 5, 5, 6, 9};
    MergeSorter<int> sorter;
    sorter.sort(numbers);
    CHECK_ARRAY_EQUAL(expected.data(), numbers.data(), numbers.size());
}

TEST(MergeSort_Int_Vector_Negative) {
    std::vector<int> numbers = {-3, -1, -4, -1, -5};
    std::vector<int> expected = {-5, -4, -3, -1, -1};
    MergeSorter<int> sorter;
    sorter.sort(numbers);
    CHECK_ARRAY_EQUAL(expected.data(), numbers.data(), numbers.size());
}

TEST(MergeSort_Int_Vector_Mixed) {
    std::vector<int> numbers = {-2, 5, -1, 0, 3, -4};
    std::vector<int> expected = {-4, -2, -1, 0, 3, 5};
    MergeSorter<int> sorter;
    sorter.sort(numbers);
    CHECK_ARRAY_EQUAL(expected.data(), numbers.data(), numbers.size());
}

TEST(MergeSort_Double_Vector) {
    std::vector<double> numbers = {5.5, 2.2, 8.8, 1.1, 9.9};
    std::vector<double> expected = {1.1, 2.2, 5.5, 8.8, 9.9};
    MergeSorter<double> sorter;
    sorter.sort(numbers);
    CHECK_ARRAY_EQUAL(expected.data(), numbers.data(), numbers.size());
}

TEST(MergeSort_String_Vector) {
    std::vector<std::string> words = {"banana", "apple", "cherry", "date"};
    std::vector<std::string> expected = {"apple", "banana", "cherry", "date"};
    MergeSorter<std::string> sorter;
    sorter.sort(words);
    CHECK_ARRAY_EQUAL(expected.data(), words.data(), words.size());
}


TEST(MergeSort_Smartphone_Multiple) {
    std::vector<Smartphone> phones = {
        Smartphone("Samsung", "Galaxy S23", 2023, 6.1, 256),
        Smartphone("Apple", "iPhone 12", 2020, 6.1, 128),
        Smartphone("Google", "Pixel 6", 2021, 6.4, 128),
        Smartphone("OnePlus", "8 Pro", 2020, 6.78, 256)
    };
    
    MergeSorter<Smartphone> sorter;
    sorter.sort(phones);
    
    CHECK_EQUAL(2020, phones[0].releaseYear);
    CHECK_EQUAL(2020, phones[1].releaseYear);
    CHECK_EQUAL(2021, phones[2].releaseYear);
    CHECK_EQUAL(2023, phones[3].releaseYear);
}

TEST(MergeSort_Smartphone_Same_Year) {
    std::vector<Smartphone> phones = {
        Smartphone("Xiaomi", "Mi 11", 2021, 6.81, 128),
        Smartphone("Sony", "Xperia 1 III", 2021, 6.5, 256),
        Smartphone("Oppo", "Find X3", 2021, 6.7, 256)
    };
    
    MergeSorter<Smartphone> sorter;
    sorter.sort(phones);
    CHECK(std::is_sorted(phones.begin(), phones.end()));
}

TEST(MergeSort_Car_Multiple) {
    std::vector<Car> cars = {
        Car("Tesla", "Model S", 2023, 0.0),
        Car("Ford", "Mustang", 1965, 4.7),
        Car("Toyota", "Corolla", 2020, 1.8),
        Car("Honda", "Civic", 2015, 1.5)
    };
    
    MergeSorter<Car> sorter;
    sorter.sort(cars);
    
    CHECK_EQUAL(1965, cars[0].year);
    CHECK_EQUAL(2015, cars[1].year);
    CHECK_EQUAL(2020, cars[2].year);
    CHECK_EQUAL(2023, cars[3].year);
}

TEST(MergeSort_Car_Same_Year) {
    std::vector<Car> cars = {
        Car("Toyota", "Camry", 2020, 2.5),
        Car("Honda", "Accord", 2020, 2.4),
        Car("Nissan", "Altima", 2020, 2.5)
    };
    
    MergeSorter<Car> sorter;
    sorter.sort(cars);
    CHECK(std::is_sorted(cars.begin(), cars.end()));
}

TEST(BozoSort_Int_Vector_Simple) {
    std::vector<int> numbers = {3, 1, 2};
    BozoSorter<int> sorter;
    sorter.sort(numbers);
    CHECK(std::is_sorted(numbers.begin(), numbers.end()));
}

TEST(BozoSort_Int_Vector_Four_Elements) {
    std::vector<int> numbers = {4, 2, 1, 3};
    BozoSorter<int> sorter;
    sorter.sort(numbers);
    CHECK(std::is_sorted(numbers.begin(), numbers.end()));
}

TEST(BozoSort_Int_Vector_Duplicates) {
    std::vector<int> numbers = {2, 1, 2, 1, 3};
    BozoSorter<int> sorter;
    sorter.sort(numbers);
    CHECK(std::is_sorted(numbers.begin(), numbers.end()));
}

TEST(BozoSort_Double_Vector) {
    std::vector<double> numbers = {3.3, 1.1, 2.2};
    BozoSorter<double> sorter;
    sorter.sort(numbers);
    CHECK(std::is_sorted(numbers.begin(), numbers.end()));
}

TEST(BozoSort_String_Vector) {
    std::vector<std::string> words = {"cherry", "apple", "banana"};
    BozoSorter<std::string> sorter;
    sorter.sort(words);
    CHECK(std::is_sorted(words.begin(), words.end()));
}

TEST(Single_Element_Smartphone) {
    std::vector<Smartphone> single = {Smartphone("Google", "Pixel 7", 2022, 6.3, 128)};
    MergeSorter<Smartphone> merge_sorter;
    merge_sorter.sort(single);
    BozoSorter<Smartphone> bozo_sorter;
    bozo_sorter.sort(single);
    CHECK_EQUAL(1, single.size());
    CHECK_EQUAL(2022, single[0].releaseYear);
}

TEST(BozoSort_Smartphone_Vector) {
    std::vector<Smartphone> phones = {
        Smartphone("Samsung", "Galaxy S21", 2021, 6.2, 128),
        Smartphone("Apple", "iPhone 13", 2021, 6.1, 256),
        Smartphone("Google", "Pixel 6", 2021, 6.4, 128)
    };
    
    BozoSorter<Smartphone> sorter;
    sorter.sort(phones);
    CHECK(std::is_sorted(phones.begin(), phones.end()));
}

TEST(BozoSort_Car_Vector) {
    std::vector<Car> cars = {
        Car("Toyota", "Camry", 2020, 2.5),
        Car("Honda", "Civic", 2018, 1.8),
        Car("BMW", "X5", 2022, 3.0)
    };
    
    BozoSorter<Car> sorter;
    sorter.sort(cars);
    CHECK(std::is_sorted(cars.begin(), cars.end()));
}


TEST(Empty_Vector) {
    std::vector<int> empty;
    MergeSorter<int> merge_sorter;
    merge_sorter.sort(empty);
    BozoSorter<int> bozo_sorter;
    bozo_sorter.sort(empty);
    CHECK(empty.empty());
}

TEST(Single_Element_Vector) {
    std::vector<int> single = {42};
    MergeSorter<int> merge_sorter;
    merge_sorter.sort(single);
    BozoSorter<int> bozo_sorter;
    bozo_sorter.sort(single);
    CHECK_EQUAL(1, single.size());
    CHECK_EQUAL(42, single[0]);
}

TEST(Single_Element_Car) {
    std::vector<Car> single = {Car("Toyota", "Camry", 2020, 2.5)};
    MergeSorter<Car> merge_sorter;
    merge_sorter.sort(single);
    BozoSorter<Car> bozo_sorter;
    bozo_sorter.sort(single);
    CHECK_EQUAL(1, single.size());
    CHECK_EQUAL(2020, single[0].year);
}

TEST(Already_Sorted_Ascending) {
    std::vector<int> sorted = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    MergeSorter<int> sorter;
    sorter.sort(sorted);
    CHECK_ARRAY_EQUAL(expected.data(), sorted.data(), sorted.size());
}

TEST(Already_Sorted_Descending) {
    std::vector<int> sorted = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    MergeSorter<int> sorter;
    sorter.sort(sorted);
    CHECK_ARRAY_EQUAL(expected.data(), sorted.data(), sorted.size());
}

TEST(Two_Elements_Unsorted) {
    std::vector<int> numbers = {2, 1};
    std::vector<int> expected = {1, 2};
    MergeSorter<int> sorter;
    sorter.sort(numbers);
    CHECK_ARRAY_EQUAL(expected.data(), numbers.data(), numbers.size());
}

TEST(Two_Elements_Sorted) {
    std::vector<int> numbers = {1, 2};
    std::vector<int> expected = {1, 2};
    MergeSorter<int> sorter;
    sorter.sort(numbers);
    CHECK_ARRAY_EQUAL(expected.data(), numbers.data(), numbers.size());
}

TEST(MergeSort_Large_Vector) {
    std::vector<int> numbers;
    for (int i = 100; i > 0; --i) {
        numbers.push_back(i);
    }
    
    MergeSorter<int> sorter;
    sorter.sort(numbers);
    CHECK(std::is_sorted(numbers.begin(), numbers.end()));
}

TEST(BozoSort_Small_Vector) {
    std::vector<int> numbers = {5, 2, 3, 1, 4};
    BozoSorter<int> sorter;
    sorter.sort(numbers);
    CHECK(std::is_sorted(numbers.begin(), numbers.end()));
}

int main() {
    return UnitTest::RunAllTests();
}
