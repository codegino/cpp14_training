#include <iostream>
#include <cstdlib>

void voidFunction1() {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void voidFunction2() {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int integerReturningFunction() {
	return 1;
}

static int integerReturningFunctionStatic() {
    return 1000;
}

void executeExample() {
	srand(time(NULL));
	//declare void function pointer
	void (*p)();
	if (rand() % 2)
		p = &voidFunction1;
	else
		p = &voidFunction2;

	p();

	//declare int function pointer
	int (*i)();
	i = &integerReturningFunction;
	i = &integerReturningFunctionStatic;
	std::cout << i() << std::endl;
}
