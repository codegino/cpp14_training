#include <iostream>
#include "utils.hpp"

class SimpleArray {
public:
	SimpleArray(size_t size) :
			size_(size), array_(new int[size_]) {
		for (auto i = 0; i < size; i++)
			array_[i] = i;
	}

	~SimpleArray() {
		delete[] array_;
	}

	SimpleArray(const SimpleArray& source) :
			size_(source.size_), array_(new int[size_]) {
		std::cout << "Copy constructor invoked." << std::endl;
		for (size_t i = 0; i < size_; ++i) {
			array_[i] = source.array_[i];
		}
	}

	int& operator[](size_t index) {
		return array_[index];
	}

private:
	size_t size_;
	int *array_;
};

template<typename Container, typename Index> // works, but
auto getValue(Container& c, Index i) // requires
		-> decltype(c[i])// refinement
		{
	return c[i];
}

void executeExample() {
	auto arr = SimpleArray(5);
	auto usingAuto = arr[0];
	decltype(auto) usingAutoWithDecl = arr[0];

	std::cout << type_name<decltype(usingAuto)>() << std::endl;
	std::cout << type_name<decltype(usingAutoWithDecl)>() << std::endl;
}
