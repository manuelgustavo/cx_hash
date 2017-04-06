#include <functional>
#include <cassert>
using namespace std;

constexpr size_t cx_hash(const char* input) {
#if defined(_WIN64)
	static_assert(sizeof(size_t) == 8, "size_t is not 64 bits long!");
	size_t hash = 0xcbf29ce484222325;
	const size_t prime = 0x00000100000001b3;
#else 
	static_assert(sizeof(size_t) == 4, "size_t is not 32 bits long!");
	size_t hash = 0x811c9dc5;
	const size_t prime = 0x01000193;
#endif

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