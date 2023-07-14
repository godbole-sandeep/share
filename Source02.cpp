#include <cassert>
#define BAD_ARGUMENT 101;

void Foo(int n);

int main() {
	Foo(-5);
}

void Foo(int n) {
	if (n < 0)
		throw BAD_ARGUMENT;
}

/*
- E.2 Throw an exception to signal that a function can’t perform its assigned task.
*/