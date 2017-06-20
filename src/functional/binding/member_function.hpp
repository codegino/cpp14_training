#include <functional>
#include <iostream>

struct Number {
	Number(int i) :
			i(i) {
	}

	int multiply(int j) {
		return i * j;
	}

	int add(int j) {
		return i + j;
	}

	int add(int j, int k) {
		return i + j + k;
	}

	int i;
};

void executeExample() {
	Number number(100);
	std::function<int()> addNumberByTwo = std::bind(
			(int (Number::*)(int))&Number::add, &number, 2);
	std::function<int()> addNumberByTwoAndThree = std::bind(
			(int (Number::*)(int, int))&Number::add, &number, 2,3);
	std::function<int()> multiplyNumberByTwo = std::bind(&Number::multiply,
			&number, 2);

	std::cout << addNumberByTwo() << std::endl;
	std::cout << addNumberByTwoAndThree() << std::endl;
	std::cout << multiplyNumberByTwo() << std::endl;

}
