#include <iostream>
#include <functional>

struct Foo {
	Foo(int i) :
			i(i) {
	}

	void bar() {
		std::cout << __PRETTY_FUNCTION__ << " : " << i << std::endl;
	}

	void buzz() {
		std::cout << __PRETTY_FUNCTION__ << " : " << i << std::endl;
	}

	int i;
};

void executeExample() {
	Foo a(69);
	std::function<void(Foo*)> functionAcceptingPointer(&Foo::bar);
	functionAcceptingPointer(&a);

	std::function<void(Foo&)> functionAcceptingReference(&Foo::buzz);
	functionAcceptingReference(a);

	std::function<void(Foo)> functionAcceptingVariable(&Foo::bar);
	functionAcceptingVariable(a);
}
