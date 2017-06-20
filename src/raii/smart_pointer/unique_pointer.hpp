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

// transfers ownership of Name here
void showName(std::unique_ptr<Name> arg) {
	std::cout << "My name is " << arg->name_ << std::endl;
	// unique_ptr will delete Name here
}

void executeExample() {
	Name *myName = new Name("Gino");
	std::unique_ptr<Name> myFirstname(myName);

	showName(std::move(myFirstname)); // you can't assign directly unique_ptr
}
