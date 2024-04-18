#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data data;
	uintptr_t	raw = Serializer::serialize(&data);
	std::cout << "data: " << &data << std::endl;
	std::cout << "raw: " << raw << std::endl;
	Data *pointer = Serializer::deserialize(raw);
	std::cout << "data: " << pointer << std::endl;
}
