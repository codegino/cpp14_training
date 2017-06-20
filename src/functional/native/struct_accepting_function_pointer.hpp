#include <iostream>

struct Function{
	Function(void (*p)(int, int), int i, int j) :
			p(p), i(i), j(j) {
	}

	void call() {
		p(i, j);
	}

	void (*p)(int, int);
	int i, j;
};

void add(int i, int j) {
	std::cout << "SUM: " << i + j << std::endl;
}

void mul(int i, int j) {
	std::cout << "PRODUCT: " << i * j << std::endl;
}

void executeExample() {
	// Instead of declaring a pointer we declare a normal struct
	Function operation(&add, 4, 5);
	operation.call();

	operation = Function(&mul, 4, 5);
	operation.call();

	// But what if I wanted to store the value returned by call instead of printing it?
	// I need to change void to int. But what if I want both?

}
