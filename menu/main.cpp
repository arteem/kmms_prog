#include <iostream>

#include "menu.hpp"
#include "menu_func.hpp"
#include "menu_items.hpp"

int main() {
    std::setlocale(LC_ALL, "");

    std::cout << "Турагент приветствует тебя, путешественник" << std::endl;

    const AEnis::MenuItem* current = &AEnis::MAIN;
    do {
        current = current->func(current);
    } while (true);

    return 0;
}