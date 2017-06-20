#include <memory>

class Name {
public:
	Name(std::string name) :
			name_(name) {
		std::cout << "Invoking constructor of name " << name_ << std::endl;
	}

	~Name() {
		std::cout << "Invoking destructor of name " << name_ << std::endl;
	}

	std::string name_;
};

// shares ownership of Name here
void showName(std::shared_ptr<Name> arg) {
	std::cout << "My name is " << arg->name_ << std::endl;
	std::cout << "Use count inside method call: " << arg.use_count()
			<< std::endl;
	// unique_ptr will delete Name here
}

int functionThatShouldReturnIntButInsteadThrows();
void runSomethingThatAcceptsNameAndThrowable(std::shared_ptr<Name> name1, int i,
		std::shared_ptr<Name> name2);

// This example is not working. I do not know why. :(
void executeExample() {
	runSomethingThatAcceptsNameAndThrowable(std::make_shared<Name>("Gino"),
			functionThatShouldReturnIntButInsteadThrows(),
			std::make_shared<Name>("Carlo"));
}

void functionThatThrowsException() {
	throw std::exception();
}

int functionThatShouldReturnIntButInsteadThrows() {
	std::cout << "Throwing exception in 3" << std::endl;
	std::cout << "Throwing exception in 2" << std::endl;
	std::cout << "Throwing exception in 1" << std::endl;
	functionThatThrowsException();
	return 1;
}

void runSomethingThatAcceptsNameAndThrowable(std::shared_ptr<Name> name1, int i,
		std::shared_ptr<Name> name2) {
	std::cout << "This print should not be here." << std::endl;
}
