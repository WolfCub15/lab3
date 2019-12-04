#pragma once
#include"TPolIZ.h"
#include"Stack.h"
class Arithmetic {
private:
	std::string str;
	TPolIZ* poliz;
public:
	Arithmetic(std::string kek = "");
	Arithmetic(const Arithmetic & tmp);
	Arithmetic &operator=(const Arithmetic & tmp);
	~Arithmetic() {};
	double calc();
	TPolIZ* get_poliz();
};