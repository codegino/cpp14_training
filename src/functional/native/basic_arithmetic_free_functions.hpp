#include <iostream>

int add(int i, int j) {
	return i + j;
}

int sub(int i, int j) {
	return i - j;
}

int mul(int i, int j) {
	return i * j;
}

int divi(int i, int j) {
	return i / j;
}

void executeExample() {
	// declare an interger function pointer that accept two integers
	int(*p)(int i, int j);
	p = &add;
	std::cout << p(6, 2) << std::endl;

	p = &sub;
	std::cout << p(6, 2) << std::endl;

	p = &mul;
	std::cout << p(6, 2) << std::endl;

	p = &divi;
	std::cout << p(6, 2) << std::endl;

	// Notice that passing arguments and invoking the function cannot be separated.
	// What if we want to store arguments for function without calling it?
}
