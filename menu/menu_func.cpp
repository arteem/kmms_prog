#include "menu_func.hpp"

#include <iostream>

const AEnis::MenuItem* AEnis::show_menu(const MenuItem* current) {
    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }

    std::cout << current->children[0]->title << std::endl;
    std::cout << "Турагент > ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    return current->children[user_input];
}

const AEnis::MenuItem* AEnis::exit(const MenuItem* current) {
    std::exit(0);
}

const AEnis::MenuItem* AEnis::vostok(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const AEnis::MenuItem* AEnis::altai(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const AEnis::MenuItem* AEnis::kolco(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}


const AEnis::MenuItem* AEnis::main_menu(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}

const AEnis::MenuItem* AEnis::vlad(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}

const AEnis::MenuItem* AEnis::sah(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}

const AEnis::MenuItem* AEnis::habr(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}

const AEnis::MenuItem* AEnis::back(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}