#include <iostream>
#include <functional>

struct Callable {
	Callable(int i) :
			i(i) {
	}

	int operator()() {
		return i;
	}

	int i;
};

void executeExample() {
	std::function<int()> func(Callable(69));
	std::cout << func() << std::endl;

	func = Callable(100);
	std::cout<<func()<<std::endl;
}
