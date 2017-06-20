template<class A, class B>
A multiply(A x, B y);

template<class A, class B>
A multiply(A x, B y) {
	return x * y;
}

template<class A, class B>
A add(A x, B y) {
	return x + y;
}

template<>
std::string multiply(std::string x, int y) {
	std::string ret;
	for(auto i = 0; i < y; i++){
		ret += x;
	}
	return ret;
}

void executeExample() {
	auto x = multiply<std::string, int>("abc", 4);
	std::cout << x << std::endl;
}
