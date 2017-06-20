#include "utils.hpp"

// Case 1: ParamType is a Reference or Pointer, but not a Universal Reference

// 1. If expr's type is a reference/pointer, ignore the reference part.
// 2. Then pattern-match expr's type against ParamType to determine T.

template<typename T>
void f(T& param) {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	std::cout << "Param Type = " << type_name<decltype(param)>() << std::endl
			<< std::endl;
}

void runCase1_reference() {
	int x = 27;			// x is an int
	const int cx = x;	// cx is a const int
	const int& rx = x;	// rx is a reference to x as a const int

	f(x);				// T is int, param's type is int&
	f(cx);				// T is const int, param's type is const int&
	f(rx);				// T is const int, param's type is const int&
}

template<typename T>
void f(T* param) {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	std::cout << "Param Type = " << type_name<decltype(param)>() << std::endl
			<< std::endl;
}

void runCase1_pointer() {
	int x = 27;			// x is an int
	const int *px = &x;	// px is a ptr to x as a const int

	f(&x);				// T is int, param's type is int*
	f(px);				// T is const int, param's type is const int*
}

void executeExample() {
	runCase1_reference();
	runCase1_pointer();
}

