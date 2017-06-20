#include <iostream>
#include <functional>

auto print = [](std::string text) {
	std::cout<< text<<std::endl;
};

auto doubleValue = [](int a) {
	return a*2;
};

void passByReferenceLambda() {
	int num = 10;

	std::function<void()> func = [&num]() {std::cout<<num++<<std::endl;};
	func();
	std::cout << num << std::endl;
}

void passByValueLambda() {
	int num = 10;

	std::function<void()> func = [num]() {std::cout<<num<<std::endl;};
	func();
	std::cout << num << std::endl;
}

void executeExample() {
	print("shiz");
	std::cout << doubleValue(2) << std::endl;
	passByReferenceLambda();
	passByValueLambda();
}
