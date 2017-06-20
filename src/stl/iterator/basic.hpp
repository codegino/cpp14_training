#include <vector>

void executeExample() {
	std::vector<int> integers = { 1, 2, 3, 4, 5, 6 };

	std::vector<int>::iterator iter = integers.begin();
	std::vector<int>::const_iterator constIter = integers.begin();

	*iter = 100;
	std::cout<<*++iter<<std::endl;

//	*constIter= 101;     // can't change value when using const iterator
	std::cout<<*constIter<<std::endl;
}
