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
void showName(std::auto_ptr<Name> arg) {
	std::cout << "My name is " << arg->name_ << std::endl;
	// auto_ptr will delete Name here
}

void executeExample() {
	std::auto_ptr<Name> myAutoPointerName(new Name("Gino"));

	showName(myAutoPointerName);
	showName(myAutoPointerName); // Seg fault here. because Gino was deleted during first showName. :(
}
