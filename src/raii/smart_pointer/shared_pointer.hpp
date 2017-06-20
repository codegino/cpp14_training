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

// add ownership of Name here
void showName(std::shared_ptr<Name> arg) {
	std::cout << "My name is " << arg->name_ << std::endl;
	std::cout << "Use count inside method call: " << arg.use_count()
			<< std::endl;
	// unique_ptr will delete Name here
}

void executeExample() {
	Name *myName = new Name("Gino");
	std::shared_ptr<Name> myFirstname(myName);
	std::cout << myFirstname.use_count() << std::endl;
	std::shared_ptr<Name> mySharedFirstName(myFirstname);
	std::cout << mySharedFirstName.use_count() << std::endl;

	showName(myFirstname);
	std::cout << myFirstname.use_count() << std::endl;
	showName(mySharedFirstName);
	std::cout << myFirstname.use_count() << std::endl;
}
