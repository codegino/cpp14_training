int getSomeRValue(){
	return 1;
}

void executeExample() {
	int variable = 4;
	std::cout << &variable << std::endl;
	auto variableToReference =&variable;
//	the function called below will return an rvalue that is why we cannot get it's address
//	auto i = &getSomeRValue();
}
