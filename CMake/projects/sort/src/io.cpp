#include "io.hpp"
#include <iostream>


int eaa::io::input_user_max_value() {
	std::cout << "max:" << std::endl;
	int max_value;
	std::cin >> max_value;
	return max_value;
}

int eaa::io::input_user_size() {
	std::cout << "long:" << std::endl;
	int size;
	std::cin >> size;
	return size;
}


namespace eaa {
    namespace io {
        void print_array(const char* const comment, const int* const arr, const int size) {
            const char format = ' ';
            std::cout << comment;
            for (int i = 0; i < size; i++) {
                std::cout << format << arr[i];
            }
            std::cout << std::endl;
        }
    }
}