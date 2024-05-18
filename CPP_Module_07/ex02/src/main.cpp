#include "Array.hpp"

int main () {
    // Test default constructor
    Array<int> defaultArray;
    std::cout << "Default constructed array size: " << defaultArray.size() << std::endl;
	std::cout << "---------------------" << std::endl;
    // Test constructor with size parameter
  	std::cout << "test constructor with size 5" << std::endl;
	std::cout << "---------------------" << std::endl;
    Array<int> sizedArray(5);
    std::cout << "Sized array (5 elements) size: " << sizedArray.size() << std::endl;
    std::cout << "Elements initialization check (should be zero): ";
    for (int i = 0; i < sizedArray.size(); ++i) {
        std::cout << sizedArray[i] << " ";  // Access using subscript operator
    }
    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    // Test copy constructor
	std::cout << "test copy constructor" << std::endl;
	std::cout << "---------------------" << std::endl;
    Array<int> copyArray = sizedArray; // deep copy is copying in such a way that all og object's elements / data are newly allocated / duplicated.
    copyArray[0] = 10;  // Modify the copy and check the original
    std::cout << "Original array after modifying copy: " << sizedArray[0] << std::endl;
	std::cout << "---------------------" << std::endl;
    // Test assignment operator
	std::cout << "test assignment constructor" << std::endl;
	std::cout << "---------------------" << std::endl;
    Array<int> assignedArray;
    assignedArray = sizedArray;
    assignedArray[0] = 20;  // Modify the assigned array and check the original
	std::cout << "Assigned array after assigning and modifying: " << assignedArray[0] << std::endl;
    std::cout << "Original array after assigning and modifying: " << sizedArray[0] << std::endl;
	std::cout << "---------------------" << std::endl;
    // Test out-of-bounds access
	std::cout << "test out-of-bounds access"  << std::endl;
	std::cout << "---------------------" << std::endl;
    try {
        std::cout << "Accessing out-of-bounds element: " << sizedArray[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception for out-of-bounds access: " << e.what() << std::endl;
    }
	std::cout << "---------------------" << std::endl;
    return 0;
}