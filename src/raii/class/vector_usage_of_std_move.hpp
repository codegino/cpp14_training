#include <vector>

class Integer {
public:

	Integer(int i) :
			i_(i) {
		std::cout << "Basic constructor invoked." << std::endl;
	}

	Integer(const Integer& source) :
			i_(source.i_) {
		std::cout << "Copy constructor invoked." << std::endl;
	}

	Integer(Integer&& source) :
			i_(source.i_) {
		std::cout << "Move constructor invoked." << std::endl;
	}

	int i_;
};

void executeExample() {
	Integer int1(1);
	Integer int2(int1);

	std::cout << std::endl;

	std::vector<Integer> ints;
	ints.reserve(2);

	ints.push_back(std::move(int1));
	ints.push_back(std::move(int2));
}
