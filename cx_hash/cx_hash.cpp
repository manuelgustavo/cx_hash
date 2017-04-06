#include <functional>
#include <cassert>
using namespace std;


constexpr size_t cx_hash(const char* input) {
	size_t hash = sizeof(size_t) == 8 ? 0xcbf29ce484222325 : 0x811c9dc5;
	const size_t prime = sizeof(size_t) == 8 ? 0x00000100000001b3 : 0x01000193;

	while (*input) {
		hash ^= static_cast<size_t>(*input);
		hash *= prime;
		++input;
	}

	return hash;
}


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	auto a = cx_hash("test");
	hash<string> func;
	auto b = func("test");
	assert(a == b);

	return 0;
}