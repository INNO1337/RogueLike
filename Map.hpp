//
// Created by inno on 20.04.2020.
//

#ifndef ROGUELIKE_REMASTERED_MAP_HPP
#define ROGUELIKE_REMASTERED_MAP_HPP

#include "Entities.hpp"
#include "Map.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <bits/shared_ptr.h>
#include "ncurses.h"

class Character;
class Entity;
class Knight;
class Princess;


class Map {
 public:
    Map() {};
    Map(std::string path);
    int get_count_of_characters();
    std::shared_ptr<Character> &get_charactrer(int ind);
    void characters_resize(int cnt);
    std::shared_ptr<Entity> &get_cell(int x, int y);
    void set_cell(int x, int y, std::shared_ptr<Entity> ptr);
    int get_n();
    std::shared_ptr<Knight> get_player();
    void draw_map(WINDOW * frame);
    void map_output();
 private:
    int n = 16;
    std::vector<std::vector<std::shared_ptr<Entity>>> field; ///Game field n x n;
    std::vector<std::shared_ptr<Character>> characters;
    void read_txt(std::string path);
    std::shared_ptr<Knight> player;
    std::shared_ptr<Princess> exit;
    std::string path;


};
#endif //ROGUELIKE_REMASTERED_MAP_HPP
