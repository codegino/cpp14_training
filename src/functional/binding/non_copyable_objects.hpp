#include <functional>
#include <iostream>

class Foo {
public:
	Foo() {
	}
	int calc(int i, int j) const {
		return i + j;
	}
private:
	Foo(const Foo&);
	Foo& operator =(const Foo&);
};

void runByReference(Foo& f) {
	std::cout << f.calc(100, 2) << std::endl;
}

void runByConstantReference(const Foo& f) {
	std::cout << f.calc(100, 2) << std::endl;
}

void executeExample() {
	Foo foo;

	std::function<void()> functionBindedUsingReference = std::bind(
			runByReference, std::ref(foo));
	functionBindedUsingReference();

	std::function<void()> functionBindedUsingConstantReference = std::bind(
			runByConstantReference, std::cref(foo));
	functionBindedUsingConstantReference();
}
