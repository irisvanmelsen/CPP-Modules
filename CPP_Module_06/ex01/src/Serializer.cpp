#include "Serializer.hpp"

//reinterpret_cast only guarantees that if you cast a pointer to a different type
// and then reinterpret_cast it back to the original type, you get the original value.

uintptr_t Serializer::serialize(Data *ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data * Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data *>(raw));
}