#include <functional>

int add(int a, int b) {
	return a - b;
}



using namespace std::placeholders;

void executeExample() {
	std::function<int(int)> lessThreeOf = std::bind(add, _1, 3);
	std::cout << lessThreeOf(30) << std::endl;

	std::function<int(int, int)> subtractTwoNumbers = std::bind(add, _1, _2);
	std::cout << subtractTwoNumbers(6, 2) << std::endl;

	std::function<int(int, int)> subtractTwoNumbersFlipped = std::bind(add, _2, _1);
	std::cout << subtractTwoNumbersFlipped(6, 2) << std::endl;
}
