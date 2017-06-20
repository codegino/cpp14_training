#include "utils.hpp"

// Case 2: ParamType is a Universal Reference

// 1. If expr is an lvalue, both T and ParamType are deduced to be lvalue references.
// That's doubly unusual. First, it's the only situation in template type deduction
// where T is deduced to be a reference. Second, although ParamType is declared
// using the syntax for an rvalue reference, its deduced type is an lvalue reference.
// 2. If expr is an rvalue, the "normal" (i.e., Case 1) rules apply.

template<typename T>
void f(T&& param) {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	std::cout << "Param Type = " << type_name<decltype(param)>() << std::endl
			<< std::endl;
}

void runCase2() {
	int x = 27;			// x is an int
	const int cx = x;	// cx is a const int
	const int& rx = x;	// rx is a reference to x as a const int

	f(x); 				// x is lvalue, so T is int&,
						// param's type is also int&

	f(cx); 				// cx is lvalue, so T is const int&,
						// param's type is also const int&

	f(rx); 				// rx is lvalue, so T is const int&,
						// param's type is also const int&

	f(27); 				// 27 is rvalue, so T is int,
						// param's type is therefore int&&
}

void executeExample() {
	runCase2();
}

