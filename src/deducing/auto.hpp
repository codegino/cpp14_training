#include "utils.hpp"

void executeExample() {
	// case 2
	auto x = 27;
	const auto cx = x;

	std::cout << "x Type = " << type_name<decltype(x)>() << std::endl;
	std::cout << "cx Type = " << type_name<decltype(cx)>() << std::endl;
	std::cout << std::endl;

	// case 1
	const auto& rx = x;
	const auto* px = &x;

	std::cout << "rx Type = " << type_name<decltype(rx)>() << std::endl;
	std::cout << "px Type = " << type_name<decltype(px)>() << std::endl;
	std::cout << std::endl;

	// case 3
	auto&& uref1 = x;
	auto&& uref2 = cx;
	auto&& uref3 = 27;

	std::cout << "uref1 Type = " << type_name<decltype(uref1)>() << std::endl;
	std::cout << "uref2 Type = " << type_name<decltype(uref2)>() << std::endl;
	std::cout << "uref3 Type = " << type_name<decltype(uref3)>() << std::endl;
	std::cout << std::endl;

	const char name[] = "Carlo Gino Catapang";

	auto arr1 = name;
	auto& arr2 = name;

	std::cout << "arr1 Type = " << type_name<decltype(arr1)>() << std::endl;
	std::cout << "arr2 Type = " << type_name<decltype(arr2)>() << std::endl;
	std::cout << std::endl;
}
