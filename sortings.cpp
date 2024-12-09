#include "sortings.hpp"

void eaa::shell::shell_sort(int* const arr, const int size) {
    int j;
    for (int step = size / 2; step > 0; step /= 2)
        for (int i = step; i < size; i++)
        {
            int tmp = arr[i];
            for (j = i; j >= step; j -= step){
                if (tmp < arr[j - step])
                    arr[j] = arr[j - step];
                else {
                    break;
                }
            }
            arr[j] = tmp;
        }
}