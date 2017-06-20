#include <algorithm>
#include <vector>

void executeExample() {
	std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	auto oddNumbers = std::remove_if(numbers.begin(), numbers.end(),
			[](int a) {return a % 2 == 0;});

	for (auto i = std::begin(numbers); i != oddNumbers; i++) {
		std::cout << *i << ' ';
	}
}
