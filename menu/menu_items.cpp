#include "menu_items.hpp"
#include "menu_func.hpp"

const AEnis::MenuItem AEnis::VLAD = {
    "1 - Владивосток", AEnis::vlad, &AEnis::VOSTOK
};

const AEnis::MenuItem AEnis::SAH = {
    "2 - Сахалин", AEnis::sah, &AEnis::VOSTOK
};

const AEnis::MenuItem AEnis::HABR = {
    "3 - Хабаровск", AEnis::habr, &AEnis::VOSTOK
};

const AEnis::MenuItem AEnis::BACK = {
    "0 - Выход в предыдущее меню", AEnis::back, &AEnis::VOSTOK
};

namespace {
    const AEnis::MenuItem* vostok_children[] = {&AEnis::BACK, &AEnis::VLAD, &AEnis::SAH, &AEnis::HABR};
    const int vostok_size = sizeof(vostok_children) / sizeof(vostok_children[0]);
}

const AEnis::MenuItem AEnis::VOSTOK = {
    "1 - Дальний восток", AEnis::show_menu, &AEnis::SHOW_MENU, vostok_children, vostok_size
};

const AEnis::MenuItem AEnis::ALTAI = {
    "2 - Алтай", AEnis::altai, &AEnis::SHOW_MENU
};

const AEnis::MenuItem AEnis::KOLCO = {
    "3 - Золотое Кольцо России", AEnis::kolco, &AEnis::SHOW_MENU
};

const AEnis::MenuItem AEnis::MAIN_MENU = {
    "0 - Выйти в главное меню", AEnis::main_menu, &AEnis::SHOW_MENU
};

namespace {
    const AEnis::MenuItem* pytesh_children[] = {&AEnis::MAIN_MENU, &AEnis::VOSTOK, &AEnis::ALTAI, &AEnis::KOLCO,};
    const int pytesh_size = sizeof(pytesh_children) / sizeof(pytesh_children[0]);
}

const AEnis::MenuItem AEnis::SHOW_MENU = {
    "1 - Путешествовать по России", AEnis::show_menu, &AEnis::MAIN, pytesh_children, pytesh_size
};

const AEnis::MenuItem AEnis::EXIT = {
    "0 - Закончить путешествия", AEnis::exit, &AEnis::MAIN
};

namespace {
    const AEnis::MenuItem* main_children[] = {
        &AEnis::EXIT,
        &AEnis::SHOW_MENU
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const AEnis::MenuItem AEnis::MAIN = {
    nullptr, AEnis::show_menu, nullptr, main_children, main_size
};