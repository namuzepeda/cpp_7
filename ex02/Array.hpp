#ifndef ARRAY_HPP

# define ARRAY_HPP

# include <cstddef>
# include <exception>

template <typename T>
class Array {

	private:
		size_t	_size;
		T		*vector;

	public:

		Array(): _size(0) {
			this->vector = new T[0];
		}
		Array(size_t size):  _size(size), vector(new T[size]) {}

		Array(const Array &copy): _size(copy._size), vector(new T[copy._size]) {

			for (unsigned int i = 0; i < _size; i++)
				vector[i] = copy.vector[i];

		}

		Array& operator=(const Array &other) {

			if (this == &other) return (*this);

			if (this->_size != other._size) {
				if (this->vector != NULL) delete[] this->vector;
				this->vector = new T[other._size];
				this->_size = other._size;
			}

			for (std::size_t i = 0; i < this->_size; ++i) {
				this->vector[i] = other[i];
			}

			return (*this);
		}

		T& operator[]( unsigned int i ) const {
			if ( i >= this->_size || 0 > i)
				throw OutOfBoundsException();
			return vector[i];
		}

		~Array() {
			delete[] this->vector;
		}

		size_t size() const {
			return this->_size;
		}

		class OutOfBoundsException : public std::exception {

			public:

				virtual const char *what() const throw() {
					return "Index out of bounds";
				}
				
		};

};

#endif
