#include "Serializer.hpp"

int main()
{
	Serializer serializer;
	Data *data = new Data;
	data->name = "John";
	data->age = 42;
	uintptr_t raw = serializer.serialize(data);
	std::cout << "Serialized Data: " << raw << std::endl;
	Data *data2 = serializer.deserialize(raw);
	std::cout << "Deserialized Data: " << std::endl;
	std::cout << "name: " << data2->name << std::endl;
	std::cout << "age: " << data2->age << std::endl;
	delete data;
	return (0);
}