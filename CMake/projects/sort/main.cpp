#include "src/io.hpp"
#include "src/sortings.hpp"
#include "src/generate.hpp"

int main()
{
    const int arr_size = eaa::io::input_user_size();
    int* arr = new int[arr_size];
    const int max_value = eaa::io::input_user_max_value();

    eaa::io::print_array("before sort:", arr, arr_size);

    eaa::shell::shell_sort(arr, arr_size);

    eaa::io::print_array("after sort:", arr, arr_size);

    return 0;
}