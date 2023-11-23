#ifndef ITER_HPP

# define ITER_HPP

# include <iostream>

# include <cstddef>

template<typename T> void iter(T *arr, std::size_t lenght, void (*f)(const T &)) {
	for (std::size_t i = 0; i < lenght; ++i) {
		f(arr[i]);
	}
}

#endif
