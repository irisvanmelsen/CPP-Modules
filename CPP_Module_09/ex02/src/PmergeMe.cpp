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

template <typename T, typename P>
T PmergeMe::SortAll(T& container, P& pairs) {
	int unpaired_elem;
	if (_vector.size() % 2 != 0) { // checks whether container is odd
		auto it = _vector.end();
		it--; // moves it back one position, so it points to last element
		unpaired_elem = *it; // if odd last pair is stored in unpaired_elem and removed from vector
	}
	else {
		unpaired_elem = -1; // there is no unpaired element
	}

	 std::vector<std::pair<int, int>> pairs;
	 for (size_t i = 0; i + 1 < _vector.size(); i += 2) { // loops in steps of 2 so pairs are formed
        if (_vector[i] > _vector[i + 1]) // checks whether pair needs swap
            std::swap(_vector[i], _vector[i + 1]);
        pairs.push_back(std::make_pair(_vector[i], _vector[i + 1])); // then added to pairs
    }

    T result;
    for (const auto& pair : pairs) { // autotomatically deduces, extracts first element from pairs
        result.push_back(pair.first);
    }
    result = MergeSort(result);

    T temp;
    for (const auto& pair : pairs) { // second element of each pair is extracted
        temp.push_back(pair.second);
    }

    result = InsertionSort(result, temp, unpaired_elem); // called with sorted elements in result, second elements in temp and the inpaired element
    return (result);
}

template <typename T>
void PmergeMe::PrintAnyArray(T array)
{
    int count = 0;
    for (auto it = array.begin(); it != array.end(); it++)
    {
        if (counter == 5)
        {
            std::cout << "[...]" << std::endl;
            break;
        }
        std::cout << *it << " ";
        count++;
    }
    std::cout << std::endl;
}

void	PmergeMe::SortData() {

	time_t start;

	std::cout << "Before: " << PrintAnyArray(this->_vector) << std::endl;

	this->SortAll(this->_vector);
	this->SortAll(this->_deque);

	std::cout << "After: " << PrintAnyArray(this->_deque) << std::endl;
}