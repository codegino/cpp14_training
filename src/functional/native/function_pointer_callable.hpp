#include <iostream>

struct Callable {
	virtual void call() = 0;
	virtual ~Callable() {
	}
};

struct Adder: Callable {
	Adder(const int i, const int j) :
			i(i), j(j) {
	}

	void call() {
		std::cout << i + j << std::endl;
	}

	int i, j;
};

struct Multiplier: Callable {
	Multiplier(const int i, const int j) :
			i(i), j(j) {
	}

	void call() {
		std::cout << i * j << std::endl;
	}

	int i, j;
};

// This is just a free function that accepts a Callable interface
// Examples are Adder and Multiplier since both inherits the Callable interface
void run(Callable& callable) {
	callable.call();
}

void executeExample() {
	// Now we can store our arguments first before using
	Callable *operation;
	operation = new Adder(2, 3);

	// use assigned adder
	run(*operation);

	operation = new Multiplier(2, 3);

	// use assigned multiplier
	run(*operation);

	// But this is just polymorphism we want to focus on functional style.
	// Meaning we want to pass only functions not the whole struct/class
	// I need to define new type for each new function call..
}
