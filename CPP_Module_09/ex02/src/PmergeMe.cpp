#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
    std::cout << "PmergeMe's Default Constructor has been called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &obj) {
    std::cout << "PmergeMe's Copy Constructor has been called" << std::endl;
    *this = obj;
}

PmergeMe::~PmergeMe() {
    std::cout << "PmergeMe's Destructor has been called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj) {
    std::cout << "PmergeMe's Operator Overload has been called" << std::endl;
	this->_deque = obj._deque;
	this->_vector = obj._vector;
    return *this;
}

template <typename T>
T PmergeMe::SortAll(T& container) {
    int unpaired_elem;
    if (container.size() % 2 != 0) { // checks whether container is odd
        auto it = container.end();
        it--; // moves it back one position, so it points to the last element
        unpaired_elem = *it; // if odd last element is stored in unpaired_elem
        container.pop_back(); // remove the unpaired element from the container
    } else {
        unpaired_elem = -1; // there is no unpaired element
    }

    std::vector<std::pair<int, int>> pairs;
    for (size_t i = 0; i + 1 < container.size(); i += 2) { // loops in steps of 2 so pairs are formed
        if (container[i] > container[i + 1]) // checks whether the pair needs a swap
            std::swap(container[i], container[i + 1]);
        pairs.push_back(std::make_pair(container[i], container[i + 1])); // then added to pairs
    }

    T result;
    for (const auto& pair : pairs) { // extracts first element from pairs
        result.push_back(pair.first);
    }
    result = MergeSort(result); // sort the first elements

    T temp;
    for (const auto& pair : pairs) { // extracts second element from pairs
        temp.push_back(pair.second);
    }

    result = InsertionSort(result, temp, unpaired_elem); // insert the second elements and the unpaired element
    return result;
}

template <typename T>
void PmergeMe::PrintAnyArray(T array) {
    int count = 0;
    for (auto it = array.begin(); it != array.end(); it++) {
        if (count == 10) {
            std::cout << "[...]" << std::endl;
            break;
        }
        std::cout << *it << " ";
        count++;
    }
    std::cout << std::endl;
}

template <typename T>
T PmergeMe::Merge(T &left, T &right) {
    T result;
    auto left_it = left.begin();
    auto right_it = right.begin();

    while (left_it != left.end() && right_it != right.end()) {
        if (*left_it < *right_it) {
            result.push_back(*left_it);
            ++left_it;
        } else {
            result.push_back(*right_it);
            ++right_it;
        }
    }
    result.insert(result.end(), left_it, left.end());
    result.insert(result.end(), right_it, right.end());
    return result;
}

template <typename T>
T PmergeMe::MergeSort(T &container) {
    if (container.size() < 2)
        return container;

    T left(container.begin(), container.begin() + container.size() / 2);
    T right(container.begin() + container.size() / 2, container.end());

    left = MergeSort(left);
    right = MergeSort(right);

    return Merge(left, right);
}

template <typename T>
T PmergeMe::InsertionSort(T& result, T& temp, int unpaired) {
    for (auto it_temp = temp.begin(); it_temp != temp.end(); ++it_temp) {
        auto it = std::lower_bound(result.begin(), result.end(), *it_temp);
        result.insert(it, *it_temp);
    }
    if (unpaired != -1) {
        auto it = std::lower_bound(result.begin(), result.end(), unpaired);
        result.insert(it, unpaired);
    }
    return result;
}

void PmergeMe::AddNumberToBoth(const char* number) {
    int num;
    try {
        num = std::stoi(number);  // Convert the string to an integer
		if (num < 0) {
            throw InvalidNumbersException();  // If the number is negative, throw your custom exception
		}
	} catch (const std::exception& e) {
        throw InvalidNumbersException();  // If there's an error in conversion, throw your custom exception
    }
    _vector.push_back(num);  // Add the number to the vector
    _deque.push_back(num);   // Add the number to the deque
}

void PmergeMe::PrintTime(double time, bool is_vec) {
    std::cout << "Time to process a range of " 
              << (is_vec ? _vector.size() : _deque.size());
    
    if (is_vec) {
        std::cout << " elements with std::vector<int>: ";
    } else {
        std::cout << " elements with std::deque<int>: ";
    }

    std::cout << std::fixed << std::setprecision(6) << time << " seconds" << std::endl;
}

void PmergeMe::SortData() {
    time_t start, end;

    std::cout << "--VECTOR CONTAINER--" << std::endl;
    std::cout << "Before Vector: ";
    PrintAnyArray(this->_vector);

    start = clock();
    this->_vector = this->SortAll(this->_vector);
    end = clock();

    std::cout << "After Vector: ";
    PrintAnyArray(this->_vector);
    _vect_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    PrintTime(_vect_time, true);

    std::cout << std::endl;

    std::cout << "--DEQUE CONTAINER--" << std::endl;
    std::cout << "Before Deque: ";
    PrintAnyArray(this->_deque);

    start = clock();	
    this->_deque = this->SortAll(this->_deque);
    end = clock();

    std::cout << "After Deque: ";
    PrintAnyArray(this->_deque);
    _deq_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    PrintTime(_deq_time, false);
}

const char* PmergeMe::InvalidNumbersException::what() const throw() {
    return "Error: Invalid number passed as parameter!";
}

const char* PmergeMe::DoubleNumbersException::what() const throw() {
    return "Error: Double integers found!";
}

