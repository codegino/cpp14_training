#include <functional>

int multiplyBy100(int i) {
	return i * 100;
}

int add(int i, int j) {
	return i + j;
}

void executeExample() {
	std::function<int()> mulBy100 = std::bind(multiplyBy100, 5);
	std::cout << mulBy100() << std::endl;

	std::function<int()> adder = std::bind(add, 1, 2);
	std::cout << adder() << std::endl;

	std::function<int(int)> combo = std::bind(multiplyBy100,
			std::bind(add, 1, 2));
	std::cout << combo(5) << std::endl;

	std::function<int(int, int)> addTwoNumbers = add;
	std::function<int(int)> combo1 = std::bind(multiplyBy100,
			addTwoNumbers(1, 2));
	std::cout << combo(5) << std::endl;
}
