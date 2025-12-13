#include <iostream>

class illegalParameterValue {
public:
	illegalParameterValue(const char* theMessage = "Illegal parameter value")
		: message(theMessage) {
	}
	void outputMessage() const {
		std::cout << message << std::endl;
	}
private:
	const char* message;
};

int abc(int a, int b, int c) {
	if (b < 0)
		throw illegalParameterValue("b must be non-negative");
	return a + b + c;
}