#include "io.hpp"
#include "sortings.hpp"

int main() {
    int arr[] = {34, 76, 12, 54, 98, 45};
	const int arr_size = sizeof(arr) / sizeof(arr[0]);
	
	eaa::print_array("Array before sort:", arr, arr_size);
    
    eaa::shell::shell_sort(arr, arr_size);

    eaa::print_array("Array after sort:", arr, arr_size);

    return 0;
}
