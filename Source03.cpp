#include <iostream>

#include "Circle.h"

int main() {
	Circle c;
	double radius = 1.0;
	bool valid_input = false;

	do {
		std::cout << "Input Radius: " << std::flush;
		std::cin >> radius;

		try {
			c.SetRadius(radius);
			valid_input = true;
		}
		catch (const std::invalid_argument& e) {
			std::cout << e.what() << std::endl;
			valid_input = false;
		}
	} while (!valid_input);

	double area = GetArea(c);
	std::cout << "Circle area is " << area << " sq. units." << std::endl;
}

/*
- E.5: Let a constructor establish an invariant, and throw if it cannot.
- Leaving an object without its invariant established is asking for trouble.
- E.15: Throw by value, catch exceptions from a hierarchy by reference
  - Throwing by value (not by pointer) and catching by reference prevents copying, especially slicing base subobjects.
  - Most handlers do not modify their exception object, hence it is recommended to catch it by const reference.
  - To rethrow a caught exception use throw; not throw e;.
  - Using throw e; would throw a new copy of e (sliced to the static type std::exception, when the exception is
    caught by catch (const std::exception& e)) instead of rethrowing the original exception of type std::runtime_error. 
*/
