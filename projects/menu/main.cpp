#include <iostream>
#include <clocale>

#include "src/menu.hpp"
#include "src/menu_func.hpp"
#include "src/menu_items.hpp"

int main() {
    std::setlocale(LC_ALL, "");

    std::cout << "Турагент приветствует тебя, путешественник" << std::endl;

    const AEnis::MenuItem* current = &AEnis::MAIN;
    do {
        current = current->func(current);
    } while (true);

    return 0;
}