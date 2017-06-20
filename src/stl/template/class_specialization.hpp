template<class T>
class calc {
public:
	T multiply(T x, T y);

	T add(T x, T y);
};

template<class T>
T calc<T>::multiply(T x, T y){
	return x * y;
}

template<class T>
T calc<T>::add(T x, T y) {
	return x + y;
}

template<>
std::string calc<std::string>::multiply(std::string x, std::string y) {
	return "Operation not permitted";
}

void executeExample() {
	calc<std::string> stringCalc;
	std::cout << stringCalc.add("carlo", "gino") << std::endl;
	std::cout << stringCalc.multiply("carlo", "gino") << std::endl;
}
