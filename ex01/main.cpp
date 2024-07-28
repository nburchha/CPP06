#include "Serializer.hpp"

int main()
{
	Data *data = new Data(42);
	uintptr_t serialized = Serializer::serialize(data);
	Data *deserialized = Serializer::deserialize(serialized);

	std::cout << "Original data: " << data->getValue() << std::endl;
	std::cout << "Deserialized data: " << deserialized->getValue() << std::endl;

	delete data;

	return 0;
}