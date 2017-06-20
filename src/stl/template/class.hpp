template<class A_Type>
class calc {
public:
	A_Type multiply(A_Type x, A_Type y) {
		return x * y;
	}
	A_Type add(A_Type x, A_Type y) {
		return x + y;
	}
};

void executeExample() {
	calc<int> intCalc;
	std::cout << intCalc.add(1, 2) << std::endl;
	std::cout << intCalc.multiply(1, 2) << std::endl;

	calc<std::string> stringCalc;
	std::cout << stringCalc.add("carlo ", "gino") << std::endl;

	calc<double> doubleCalc;
	std::cout << doubleCalc.add(1.0, 2.2) << std::endl;
	std::cout << doubleCalc.multiply(1.1, 2) << std::endl;
}
