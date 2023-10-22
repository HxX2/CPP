#include "Serializer.hpp"

int main()
{
	Data *data = new Data;
	data->name = "John";
	data->age = 42;
	std::cout << "Data address: " << data << std::endl;
	std::cout << "------" << std::endl;
	uintptr_t raw = Serializer::serialize(data);
	std::cout << "Serialized Data: " << raw << std::endl;
	Data *data2 = Serializer::deserialize(raw);
	std::cout << "------" << std::endl;
	std::cout << "Deserialized Data: " << std::endl;
	std::cout << "name: " << data2->name << std::endl;
	std::cout << "age: " << data2->age << std::endl;
	std::cout << "------" << std::endl;
	std::cout << "Data address: " << data << std::endl;
	delete data;
	return (0);
}