//
// Created by inno on 20.04.2020.
//

#include "Map.hpp"
#include "Entities.hpp"
#include <fstream>




void Map::read_txt(std::string path /*, *std::vector<std::vector<std::shared_ptr<Entity>>> &field*/) {
    std::ifstream input(path);
    std::vector<std::shared_ptr<Entity>> tmp(n);
    bool knight = 0;
    bool princess = 0;
    char sym;
    for (int i = 0; i < n; i++) {
        field.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input.get(sym);
            if (sym == '\n') {
                input.get(sym);
            }
            switch (sym) {
                case '.':
                    field[i][j] = std::make_shared<Dot>(j, i);
                    break;
                case '@':
                    if (!knight) {
                        player = std::make_shared<Knight>(j, i);
                        field[i][j] = player;
                        knight = true;
                    }
                    break;
                case 'P':
                    if(!princess) {
                        exit = std::make_shared<Princess>(j, i);
                        field[i][j] = exit;
                        princess = true;
                    }
                    break;
                case 'Z':
                    characters.push_back(std::make_shared<Zombie>(j, i));
                    field[i][j] = characters.back();

                    break;
                case 'D':
                    characters.push_back(std::make_shared<Dragon>(j, i));
                    field[i][j] = characters.back();
                    break;
                case '#':
                    field[i][j] = std::make_shared<Wall>(j, i);
                    break;
                default:
                    field[i][j] = std::make_shared<Dot>(j, i);
                    break;
            }
        }
    }
    if (!knight) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (knight) {
                    break;
                }
                if (field[i][j]->get_sym() == '.') {
                    player = std::make_shared<Knight>(j, i);
                    field[i][j] = player;
                    knight = true;
                }
            }
        }
        if(!knight) {
            std::cout << "You should add a knight('@') to the map or empty 1 dot('.')  for it!" << "\n";
            field.clear();
            field.resize(0);
            characters.clear();
        }
    }
    if (!princess) {
        for (int i = n - 1; i > 0; i--) {
            for (int j = n - 1; j > 0; j--) {
                if (princess) {
                    break;
                }
                if (field[i][j]->get_sym() == '.') {
                    exit = std::make_shared<Princess>(j, i);
                    field[i][j] = exit;
                    princess = true;
                }
            }
        }
        if(!princess) {
            std::cout << "You should add a princess('P') to the map or empty 1 dot('.')  for it!" << "\n";
            field.clear();
            field.resize(0);
            characters.clear();
        }
    }
}

void Map::map_output() {
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << field[i][j]->get_sym() << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    int D_count = 0;
    int Z_count = 0;
    for (int i = 0; i < characters.size(); i++) {
        switch (characters[i]->get_sym()) {
            case 'D':
                D_count++;
                break;
            case 'Z':
                Z_count++;
                break;
        }
        std::cout << characters[i]->get_sym() << " ";
    }
    std::cout << "\n";
    std::cout << "Zombies: " << Z_count << "\n";
    std::cout << "Dragons: " << D_count << "\n";
}

std::shared_ptr<Character> &Map::get_charactrer(int ind) {
    return characters[ind];
}

Map::Map(std::string path): path(path) {
    read_txt(path);
}

int Map::get_count_of_characters() {
    return characters.size();
}

void Map::draw_map(WINDOW * frame) {
    std::string tmp = " ";
    wprintw(frame, "\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp += field[i][j]->get_sym();
            tmp += ' ';
        }
        wprintw(frame, tmp.c_str());
        wprintw(frame, "\n");
        tmp = " ";
    }
    box(frame, 0, 0);
    wrefresh(frame);
    refresh();
}

int Map::get_n() {
    return n;
}

std::shared_ptr<Entity> &Map::get_cell(int x, int y) {
    return field[y][x];
}

std::shared_ptr<Knight> Map::get_player() {
    return player;
}

void Map::set_cell(int x, int y, std::shared_ptr<Entity> ptr) {
    field[y][x] = ptr;
}

void Map::characters_resize(int cnt) {
    characters.resize(characters.size() - cnt);
}

//std::vector<std::vector<std::shared_ptr<Entity>>> *Map::get_field() {
//    return &field;
//}


