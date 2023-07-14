#include <cassert>

void Foo(int n);

int main() {
	Foo(-5);
}

void Foo(int n) {
	assert(n > 0);
}
