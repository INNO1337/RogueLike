//
// Created by inno on 24.04.2020.
//

#ifndef ROGUELIKE_REMASTERED_LOOP_HPP
#define ROGUELIKE_REMASTERED_LOOP_HPP

#include <iostream>
#include <fstream>
#include "Entities.hpp"
#include "Map.hpp"
#include <string>
#include <vector>
#include <memory>
#include <bits/shared_ptr.h>

class Game {
 public:
    Game(std::string path);

    void start();
    Map map;
 private:
    std::string path;
};

#endif //ROGUELIKE_REMASTERED_LOOP_HPP
