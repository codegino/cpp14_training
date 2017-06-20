#include <functional>

void adder(int i, int j) {
	std::cout << "SUM: " << i + j << std::endl;
}

double divide(int i, int j) {
	return i / j;
}

double divideWithPrints(int i, int j) {
	std::cout << "I will divide " << i << " with " << j << std::endl;
	return i / j;
}

void executeExample() {
	// creates an std function with signature of
	// a function that accepts two integers and returns void
	std::function<void(int, int)> adderFunc(adder);

	// creates an std function with signature of
	// a function that accepts two integers and returns double
	// we can just do declaration
	std::function<double(int, int)> divideFunc;

	adderFunc(1, 2);

	divideFunc = divide;
	std::cout << "QUOTIENT: " << divideFunc(2, 1) << std::endl;

	divideFunc = divideWithPrints;
	std::cout << "QUOTIENT: " << divideFunc(2, 1) << std::endl;
}
