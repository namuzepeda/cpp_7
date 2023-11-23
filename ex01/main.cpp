#include "iter.hpp"

template<typename T> void log(const T &data) {
	std::cout << data << std::endl;
}

template<typename T> void increment(const T &var) {
	(const_cast<T &>(var)) += 10;
}

template<typename T> void changeValue(const T &str) {
    (const_cast<T &>(str)) = "TEST";
}

int main() {
	int ints[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::string strings[4] = {"hola", "adios", "hello", "bye"};

	std::cout << "Integer Array\n" << std::endl;
	::iter(ints, 10, &log);
    std::cout << std::endl;
    std::cout << "Incrementing Integer Array by 10\n" << std::endl;
	::iter(ints, 10, &increment);
	::iter(ints, 10, &log);

	std::cout << "\nSTRING ARRAY:\n" << std::endl;
	::iter(strings, 4, &log);
    std::cout << "\nChanging string value to TEST\n" << std::endl;
    ::iter(strings, 4, &changeValue);
    ::iter(strings, 4, &log);

	return 0;
}