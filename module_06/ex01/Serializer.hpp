#ifndef _SERIALIZER_HPP_
#define _SERIALIZER_HPP_

#include <iostream>
#include <string>
#include <cstdint>

struct Data
{
	std::string name;
	int age;
};

class Serializer
{
public:
	Serializer();
	~Serializer();
	Serializer(const Serializer &src);
	Serializer &operator=(const Serializer &src);

	uintptr_t serialize(Data *ptr);
	Data *deserialize(uintptr_t raw);
};

#endif