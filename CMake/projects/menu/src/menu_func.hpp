#pragma once 

#include "menu.hpp"

namespace AEnis {
    const MenuItem* show_menu(const MenuItem* current);

    const MenuItem* exit(const MenuItem* current);

    const MenuItem* vostok(const MenuItem* current);
    const MenuItem* altai(const MenuItem* current);
    const MenuItem* kolco(const MenuItem* current);
    const MenuItem* main_menu(const MenuItem* current);

    const MenuItem* vlad(const MenuItem* current);
    const MenuItem* sah(const MenuItem* current);
    const MenuItem* habr(const MenuItem* current);
    const MenuItem* back(const MenuItem* current);
}