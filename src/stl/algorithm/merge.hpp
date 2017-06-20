#include <algorithm>
#include <vector>
#include <iterator>

void executeExample() {
	std::vector<int> odd = { 1, 3, 5, 7, 9 };
	std::vector<int> even = { 2, 4, 6, 8, 10 };

	std::vector<int> mergeResult;

	std::merge(odd.begin(), odd.end(), even.begin(), even.end(),
			std::back_inserter(mergeResult));

	for (auto i : mergeResult) {
		std::cout << i << " ";
	}
}
