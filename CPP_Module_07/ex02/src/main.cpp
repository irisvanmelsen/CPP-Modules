#include "Array.hpp"

int main () {
    // Test default constructor
    Array<int> defaultArray;
    std::cout << "Default constructed array size: " << defaultArray.size() << std::endl;

    // Test constructor with size parameter
    Array<int> sizedArray(5);
    std::cout << "Sized array (5 elements) size: " << sizedArray.size() << std::endl;
    std::cout << "Elements initialization check (should be zero): ";
    for (size_t i = 0; i < sizedArray.size(); ++i) {
        std::cout << sizedArray[i] << " ";  // Access using subscript operator
    }
    std::cout << std::endl;

    // Test copy constructor
    Array<int> copyArray = sizedArray;
    copyArray[0] = 10;  // Modify the copy and check the original
    std::cout << "Original array after modifying copy: " << sizedArray[0] << std::endl;

    // Test assignment operator
    Array<int> assignedArray;
    assignedArray = sizedArray;
    assignedArray[0] = 20;  // Modify the assigned array and check the original
    std::cout << "Original array after assigning and modifying: " << sizedArray[0] << std::endl;

    // Test out-of-bounds access
    try {
        std::cout << "Accessing out-of-bounds element: " << sizedArray[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception for out-of-bounds access: " << e.what() << std::endl;
    }

    // All tests done
    return 0;
}