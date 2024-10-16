#include <cmath> 
#include <iostream> 
int main()
{
    setlocale(LC_ALL, "RUS");
    int const lenght = 20;
    int arr[lenght];
    std::cout << "изначальный массив: ";
    for (int i = 0; i < lenght; i++)
    {
        arr[i] = rand() % 20;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < lenght / 2; i++)
    {
        int b = arr[i];
        arr[i] = arr[19 - i];
        arr[19 - i] = b;
    }
    std::cout << "перевернутый массив: ";
    for (int i = 0; i < lenght; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}