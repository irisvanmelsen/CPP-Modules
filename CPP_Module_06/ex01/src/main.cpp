#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data data;
	uintptr_t raw = Serializer::serialize(&data); // Serialize the address of the Data object
	std::cout << "data: " << &data << std::endl; // Print the address of the original Data object
	std::cout << "raw: " << raw << std::endl; // Print the serialized uintptr_t value
	Data *pointer = Serializer::deserialize(raw); // Deserialize the uintptr_t value back to a Data pointer
	std::cout << "data: " << pointer << std::endl; // Print the address of the deserialized Data object
}
