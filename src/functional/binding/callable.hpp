#include <functional>

struct Multiplier: std::function<int(int)> {
	Multiplier(int i) :
			i(i) {

	}

	int operator()(int j) {
		return i * j;
	}

	int i;
};

void executeExample() {
	Multiplier m(100);

	std::function<int()> func = std::bind(m, 2);
	std::cout<<func()<<std::endl;
}
