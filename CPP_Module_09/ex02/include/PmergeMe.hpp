#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <exception>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &obj);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &obj);

    void SortData();

    // Exception classes
    class InvalidNumbersException : public std::exception {
    public:
        const char* what() const throw();
    };

    class DoubleNumbersException : public std::exception {
    public:
        const char* what() const throw();
    };

    // Public method to add numbers from the command line arguments
    void AddNumberToBoth(const char* number);

private:
    std::vector<int> _vector;
    std::deque<int> _deque;
    double _vect_time;
    double _deq_time;

    template <typename T, typename P>
    T SortAll(T& container, P& pairs);

    template <typename T>
    void PrintAnyArray(T array);

    template <typename T>
    T Merge(T &left, T &right);

    template <typename T>
    T MergeSort(T &container);

    template <typename T>
    T InsertionSort(T& result, T& temp, int straggler);

    void PrintTime(double time, bool is_vec);
    void CheckDoubles(std::vector<int> container);
};

#endif