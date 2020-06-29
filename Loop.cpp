//
// Created by inno on 24.04.2020.
//
#include <ncurses.h>
#include <random>
#include <ctime>
#include "Loop.hpp"
#include <chrono>
#include <thread>

Game::Game(std::string path): path(path) {
    Map New_Map(path);
    map = New_Map;
}

void Game::start() {
    srand(time(0));
    initscr();
    noecho();
    cbreak();
    WINDOW * frame = newwin(map.get_n() + 2, map.get_n() * 2 + 2, 5, 5);
    WINDOW * hood = newwin(5, 10, 0, 0);
    keypad(stdscr, true);
    nodelay(stdscr, true);
    std::string tmp;
    while (true) {
        if (map.get_player()->get_hp() <= 0) {
            break;
        }
        wclear(frame);
        wclear(hood);
        std::string hp = std::to_string(map.get_player()->get_hp());
        std::string dmg = std::to_string(map.get_player()->get_damage());
        wprintw(hood, hp.c_str());
        wprintw(hood, "  ");
        wprintw(hood, dmg.c_str());

        int c = getch();
        if (c == KEY_HOME) {
            wclear(hood);
            box(hood, 0, 0);
            wclear(frame);
            nodelay(stdscr, false);
            std::ifstream exit("/home/inno/Рабочий стол/RogueLike/exitquestion.txt");
            tmp = "";
            for (int i = 0; i < 17; i++) {
                getline(exit, tmp);
                wprintw(frame, tmp.c_str());
                wprintw(frame, "\n");
                tmp = "";
            }
            box(frame, 0, 0);
            wrefresh(frame);
            wrefresh(hood);
            refresh();
            while (true) {
                c = getch();
                if (c == 'Y' || c == 'y') {
                    break;
                } else if (c == 'N' || c == 'n') {
                    break;
                }
            }
            if (c == 'Y' || c == 'y') {
                break;
            } else {
                wclear(frame);
                map.draw_map(frame);
                wrefresh(frame);
                refresh();
                continue;
            }
        }
        if (c != ERR) {
            if (c == 'w' || c == 'a' || c == 's' || c == 'd' || c == 'W' || c == 'A' || c == 'S' || c == 'D') {
                map.get_player()->move(c, map);
                std::cout << map.get_player()->get_pos().x << " " << map.get_player()->get_pos().y << "\n";

                for (int i = 0; i < map.get_count_of_characters(); i++) {
                    int key = rand() % 5;
                    map.get_charactrer(i)->move(key, map);
                }
                for (int i = 0; i < map.get_count_of_characters(); i++) {
                    int cnt = 0;
                    if (map.get_charactrer(i)->get_hp() <= 0) {
                        for (int j = 1; j <= map.get_count_of_characters(); j++) {
                            if (map.get_charactrer(map.get_count_of_characters() - j)->get_hp() > 0) {
                                map.get_charactrer(i) = map.get_charactrer(map.get_count_of_characters() - j);
                                cnt++;
                                break;
                            }
                        }
                    }
                    map.characters_resize(cnt);
                }
                map.draw_map(frame);
            }
        } else if (c == ERR) {
            for (int i = 0; i < map.get_count_of_characters(); i++) {
                int key = rand() % 5;
                map.get_charactrer(i)->move(key, map);
            }
            for (int i = 0; i < map.get_count_of_characters(); i++) {
                int cnt = 0;
                if (map.get_charactrer(i)->get_hp() <= 0) {
                    for (int j = 1; j <= map.get_count_of_characters(); j++) {
                        if (map.get_charactrer(map.get_count_of_characters() - j)->get_hp() > 0) {
//                            std::shared_ptr<Character> tmp_ = map.get_charactrer(i);
                            map.get_charactrer(i) = map.get_charactrer(map.get_count_of_characters() - j);
                            cnt++;
                            break;
                        }
                    }
                }
                map.characters_resize(cnt);
            }
            map.draw_map(frame);
            std::this_thread::sleep_for(std::chrono::milliseconds (200));
        }
        wrefresh(hood);
    }
    wclear(frame);
    std::ifstream over("/home/inno/Рабочий стол/RogueLike/gameover.txt");
    tmp = "";
    for (int i = 0; i < 17; i++) {
        getline(over, tmp);
        wprintw(frame, tmp.c_str());
        wprintw(frame, "\n");
        tmp = "";
    }
    nodelay(stdscr, false);///TODO
    wclear(hood);
    wrefresh(hood);
    refresh();
    wprintw(hood, " GAME OVER");
    wrefresh(hood);
    box(frame, 0, 0);
    wrefresh(frame);
    refresh();
    getch();
    endwin();
}
