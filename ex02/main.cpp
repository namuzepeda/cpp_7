#include <iostream>
#include <Array.hpp>
# include <ctime>
#include <cstdlib>

#define MAX_VAL 30000

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    

	std::cout << "Should output Outbounds error" << std::endl;
	try {
		numbers[MAX_VAL] = 5;
	} catch (Array<int>::OutOfBoundsException exception) {
		std::cerr << exception.what() << std::endl;
	}

	Array<int> numbersCopy = numbers;
	int i = 25;
	while(i--) {
		int randomNum = 0 + std::rand() % (MAX_VAL - 0 + 1);

		if(numbersCopy[randomNum] == numbers[randomNum]) {
			std::cout << "Numbers equals" << std::endl;
		} else {
			std::cout << "Numbers NOT equals" << std::endl;
		}
	}
    return 0;
}