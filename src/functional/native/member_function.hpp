#include <iostream>

struct Foo {
	Foo(int i) :
			i(i) {
	}

	void Bar() {
		std::cout << __PRETTY_FUNCTION__ << " : " << i << std::endl;
	}

	void Boo() {
		std::cout << __PRETTY_FUNCTION__ << " : " << i << std::endl;
	}

	int i;
};

struct Function {
	Function(void (Foo::*newMem)(), Foo&f) :
			mem(newMem), f(f) {
	}

	void operator()(){
		(f.*mem)();
	}

	void (Foo::*mem)();
	Foo f;
};

void executeExample() {
	Foo a(1);
	Foo b(2);

	Function func(&Foo::Bar, a);
	func();

	func = Function(&Foo::Bar, b);
	func();

	func = Function(&Foo::Boo, a);
	func();

	func = Function(&Foo::Boo, b);
	func();
}
