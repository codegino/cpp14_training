#include <algorithm>
#include <vector>
#include <iterator>

void executeExample() {
	std::vector<int> odd = { 1, 3, 5, 7, 9 };
	std::vector<int> even = { 2, 4, 6, 8, 10 };

	auto findResult1 = std::find(odd.begin(), odd.end(), 5);
	std::cout << *findResult1 << std::endl;

	auto findResult2 = std::find(even.begin(), even.end(), 5);
	std::cout << *findResult2 << std::endl;
}
