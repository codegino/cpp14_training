#include <functional>
#include <vector>
#include <algorithm>

struct Foo {
	Foo(int i) :
			i(i) {
	}

	float Bar(float f) {
		std::cout << __PRETTY_FUNCTION__ << " : " << f * i << std::endl;
		return f * i;
	}

	int i;
};

using namespace std::placeholders;

void executeExample() {
	std::function<float(Foo&, float)> f = std::bind(&Foo::Bar, _1, _2);

	Foo foo(3);

	f(foo, 3);

	std::vector<Foo> foos = { Foo(1), Foo(2), Foo(3) };
	std::for_each(foos.begin(), foos.end(), std::bind(f, _1, 100));
}
