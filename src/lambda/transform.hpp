#include <algorithm>
#include <vector>

void executeExample() {
	std::vector<int> numbers = { 1, 2, 3, 4, 5 };

	std::cout<<"Before transform"<<std::endl;
	for (auto i : numbers) {
		std::cout << i << ' ';
	}
	std::cout<<std::endl;

	std::transform(numbers.begin(), numbers.end(), numbers.begin(),
			[](int num) {
				return num*num;});

	std::cout<<"After transform"<<std::endl;
	for (auto i : numbers) {
		std::cout << i << ' ';
	}
}
