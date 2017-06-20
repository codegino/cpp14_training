#include "utils.hpp"

// Case 3: ParamType is Neither a Pointer nor a Reference

// 1. As before, if expr's type is a reference, ignore the reference part.
// 2. If, after ignoring expr's reference-ness, expr is const, ignore that, too. If it's
// volatile, also ignore that.

template<typename T>
void f(T param) {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	std::cout << "Param Type = " << type_name<decltype(param)>() << std::endl
			<< std::endl;
}

void runCase3() {
	int x = 27;			// x is an int
	const int cx = x;	// cx is a const int
	const int& rx = x;	// rx is a reference to x as a const int

	f(x);				 // T's and param's types are both int

	f(cx);				 // T's and param's types are again both int

	f(rx);				 // T's and param's types are still both int

}

void executeExample() {
	runCase3();
}

