#pragma once

struct InRange {
	InRange(int start, int end) :
			start_(start), end_(end) {
	}

	bool operator()(int value) const {
		return value >= start_ && value <= end_;
	}

private:
	int start_, end_;
};

bool isEvenSum(int value1, int value2) {
	return ((value1 + value2) % 2) == 0;
}

void executeExample() {
	std::cout << InRange(1, 10)(11) << std::endl;
	std::cout << InRange(1, 10)(5) << std::endl;

	std::cout << isEvenSum(1, 3) << std::endl;
	std::cout << isEvenSum(2, 3) << std::endl;
}
