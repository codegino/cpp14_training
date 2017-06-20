#include <algorithm>
#include <vector>

void executeExample() {
	std::vector<int> numbers = { 1, 2, 3, 4, 5 };

	int sum = std::accumulate(numbers.begin(), numbers.end(), 0,
			[](int a, int b) {return a +b;});


	std::cout << sum << std::endl;
}
