#include <iostream>

void print_array(int* arr, int lenght);

int main()
{
    int const lenght = 20;
    int arr[lenght];
    std::cout << "изначальный массив: ";

    for (int i = 0; i < lenght; i++)
    {
        arr[i] = rand() % 20;
    }

    print_array(arr, lenght);
    
    for (int i = 0; i < lenght / 2; i++)
    {
        std::swap(arr[i], arr[lenght-1-i]);
    }

    std::cout << "перевернутый массив: ";

    print_array(arr, lenght);

    return 0;
}

void print_array(int* arr, int lenght)
{
    char format = ' ';
    for (int i = 0; i < lenght; i++)
    {
        std::cout << arr[i] << format;
    }
    std::cout << std::endl;
}

