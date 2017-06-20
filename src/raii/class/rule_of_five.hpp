class SimpleArray {
public:
	SimpleArray(size_t size) :
			size_(size), array_(new int[size_]) {
		std::cout << "Basic constructor invoked." << std::endl;
	}

	~SimpleArray() {
		std::cout << "Destructor invoked." << std::endl;
		delete[] array_;
	}

	SimpleArray(SimpleArray&& source) :
			size_(source.size_), array_(std::move(source.array_)) {
		std::cout << "Move constructor invoked." << std::endl;
		source.array_ = nullptr;
		source.size_ = 0;
	}

	SimpleArray(const SimpleArray& source) :
			size_(source.size_), array_(new int[size_]) {
		std::cout << "Copy constructor invoked." << std::endl;
		for (size_t i = 0; i < size_; ++i) {
			array_[i] = source.array_[i];
		}
	}

	SimpleArray& operator=(const SimpleArray& source) {
		std::cout << "Copy assignment invoked." << std::endl;
		for (size_t i = 0; i < size_; ++i) {
			array_[i] = source.array_[i];
		}

		return *this;
	}

	SimpleArray& operator=(SimpleArray&& source) {
		std::cout << "Move assignment invoked." << std::endl;
		if (this != &source) {
			array_ = std::move(source.array_);
			source.array_ = nullptr;
			source.size_ = 0;
		}

		return *this;
	}

	int& operator[](size_t index) {
		return array_[index];
	}

private:
	size_t size_;
	int *array_;
};

void executeExample() {
	int size = 5;
	SimpleArray array1(5);
	for (int i = 0; i < size; ++i) {
		array1[i] = i * i + 1;
	}

	SimpleArray array2(5);
	array2 = array1;
	array2 = std::move(array1);

	std::cout << std::endl;

	for (int i = 0; i < size; ++i) {
		std::cout << "Accessing Array2 index " << i << std::endl;
		std::cout << "value: " << array2[i] << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < size; ++i) {
		std::cout << "Accessing Array1 index " << i << std::endl;
		std::cout << "value: " << array1[i] << std::endl;
	}
}
