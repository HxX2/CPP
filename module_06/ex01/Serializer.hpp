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
private:
	Serializer();
public:
	~Serializer();
	Serializer(const Serializer &src);
	Serializer &operator=(const Serializer &src);

	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif