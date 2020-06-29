#include "Entities.hpp"
#include "Map.hpp"
#include "Loop.hpp"
#include <iostream>
#include "ncurses.h"

int main() {
    Game New_Game("/home/inno/Рабочий стол/RogueLike/map.txt");

    New_Game.start();

//    initscr();                   // Переход в curses-режим
//    printw("Hello world!\n");  // Отображение приветствия в буфер
//    refresh();                   // Вывод приветствия на настоящий экран
//    getch();                     // Ожидание нажатия какой-либо клавиши пользователем
//    endwin();                    // Выход из curses-режима. Обязательная команда.
    return 0;
}
