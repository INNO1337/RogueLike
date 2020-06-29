//
// Created by inno on 24.03.2020.
//
#include "Entities.hpp"
#include <random>
#include <ctime>


int random(int min, int max) {
    if (min < max) {
        srand(time(0));
        return (rand() % max + min);
    } else
        return 0;
}

Entity::Entity(int x, int y, char sym): Pos(coords(x, y)), Sym(sym) {}

coords Entity::get_pos() const{
    return Pos;
}

char Entity::get_sym() const{
    return Sym;
}

void Entity::set_pos(int x, int y) {
    Pos.x = x;
    Pos.y = y;
}

void Entity::set_char(char sym) {
    Sym = sym;
};

Character::Character(int x, int y, char sym, int hp, int dmg): Entity(x, y, sym), hp(hp), dmg(dmg) {}

void Character::move(int key, Map &map) {
    std::cout << "Done" << key << " ";
    switch (key) {
        case 0:
            if (get_pos().y - 1 >= 0) {
                if ((map.get_cell(get_pos().x, get_pos().y - 1))->get_sym() == '.') { ///TODO * +
                    std::shared_ptr<Entity> tmp_ptr = map.get_cell(get_pos().x, get_pos().y);
                    map.get_cell(get_pos().x, get_pos().y - 1) = tmp_ptr;
                    std::cout << map.get_cell(get_pos().x, get_pos().y - 1)->get_sym() << "\n";
                    map.get_cell(get_pos().x, get_pos().y) = std::make_shared<Dot>(get_pos().x, get_pos().y);
                    set_pos(get_pos().x, get_pos().y - 1); ///DONE
                } else {
                    collide(*map.get_cell(get_pos().x, get_pos().y - 1));
                }
            }
            break;
        case 1:
            if (get_pos().x - 1 >= 0) {
                if ((map.get_cell(get_pos().x - 1, get_pos().y))->get_sym() == '.') { ///TODO * +
                    map.get_cell(get_pos().x - 1, get_pos().y) = map.get_cell(get_pos().x, get_pos().y);
                    std::cout << map.get_cell(get_pos().x - 1, get_pos().y)->get_sym() << "\n";
                    map.get_cell(get_pos().x, get_pos().y) = std::make_shared<Dot>(get_pos().x, get_pos().y);
                    set_pos(get_pos().x - 1, get_pos().y); ///DONE
                } else {
                    collide(*map.get_cell(get_pos().x - 1, get_pos().y));
                }
            }
            break;
//        case 2:
//            if (get_pos().y + 1 < map.get_n()) {
//                if ((map.get_cell(get_pos().x, get_pos().y + 1))->get_sym() == '.') { ///TODO * +
//                    map.get_cell(get_pos().x, get_pos().y + 1) = map.get_cell(get_pos().x, get_pos().y);
//                    std::cout << map.get_cell(get_pos().x, get_pos().y + 1)->get_sym() << "\n";
//                    map.get_cell(get_pos().x, get_pos().y) = std::make_shared<Dot>(get_pos().x, get_pos().y);
//                    set_pos(get_pos().x, get_pos().y + 1); ///DONE
//                } else {
//                    collide(*map.get_cell(get_pos().x, get_pos().y + 1));
//                }
//            }
//            break;
//        case 3:
//            if (get_pos().x + 1 < map.get_n()) {
//                if ((map.get_cell(get_pos().x + 1, get_pos().y))->get_sym() == '.') { ///TODO * +
//                    map.get_cell(get_pos().x + 1, get_pos().y) = map.get_cell(get_pos().x, get_pos().y);
//                    std::cout << map.get_cell(get_pos().x + 1, get_pos().y)->get_sym() << "\n";
//                    map.get_cell(get_pos().x, get_pos().y) = std::make_shared<Dot>(get_pos().x, get_pos().y);
//                    set_pos(get_pos().x + 1, get_pos().y); ///DONE
//                } else {
//                    collide(*map.get_cell(get_pos().x + 1, get_pos().y));
//                }
//            }
//            break;
//        default:
//            std::cout << "SCOOP di WOOP" << "\n" << "auf" << "\n";
//            break;
//    }
        default:
            if (get_pos().x - 1 >= 0) {
                if ((map.get_cell(get_pos().x - 1, get_pos().y))->get_sym() == '.') { ///TODO * +
                    map.get_cell(get_pos().x - 1, get_pos().y) = map.get_cell(get_pos().x, get_pos().y);
                    std::cout << map.get_cell(get_pos().x - 1, get_pos().y)->get_sym() << "\n";
                    map.get_cell(get_pos().x, get_pos().y) = std::make_shared<Dot>(get_pos().x, get_pos().y);
                    set_pos(get_pos().x - 1, get_pos().y); ///DONE
                } else {
                    collide(*map.get_cell(get_pos().x - 1, get_pos().y));
                }
            }
            break;
    }
}

int Character::get_hp() {
    return hp;
}

void Character::set_hp(int value) {
    hp -= value;
}

int Character::get_damage() {
    return dmg;
}

void Character::collide(Entity &that) {
    that.collide(*this);
}

Knight::Knight(int x, int y): Character(x, y, '@', 1, 5) {}


void Knight::move(int key, Map &map) {
    switch (key) {
        case 'w':
            if (get_pos().y - 1 >= 0) {
                if ((map.get_cell(get_pos().x, get_pos().y - 1))->get_sym() == '.') { ///TODO * +
                    std::shared_ptr<Entity> tmp_ptr = map.get_cell(get_pos().x, get_pos().y);
                    map.get_cell(get_pos().x, get_pos().y - 1) = tmp_ptr;
                    std::cout << map.get_cell(get_pos().x, get_pos().y - 1)->get_sym() << "\n";
                    map.get_cell(get_pos().x, get_pos().y) = std::make_shared<Dot>(get_pos().x, get_pos().y);
                    set_pos(get_pos().x, get_pos().y - 1); ///DONE
                } else {
                    collide(*map.get_cell(get_pos().x, get_pos().y - 1));
                }
            }
            break;
        case 'a':
            if (get_pos().x - 1 >= 0) {
                if ((map.get_cell(get_pos().x - 1, get_pos().y))->get_sym() == '.') { ///TODO * +
                    map.get_cell(get_pos().x - 1, get_pos().y) = map.get_player();
                    std::cout << map.get_cell(get_pos().x - 1, get_pos().y)->get_sym() << "\n";
                    map.get_cell(get_pos().x, get_pos().y) = std::make_shared<Dot>(get_pos().x, get_pos().y);
                    set_pos(get_pos().x - 1, get_pos().y); ///DONE
                } else {
                    collide(*map.get_cell(get_pos().x - 1, get_pos().y));
                }
            }
            break;
        case 's':
            if (get_pos().y + 1 < map.get_n()) {
                if ((map.get_cell(get_pos().x, get_pos().y + 1))->get_sym() == '.') { ///TODO * +
                    map.get_cell(get_pos().x, get_pos().y + 1) = map.get_player();
                    std::cout << map.get_cell(get_pos().x, get_pos().y + 1)->get_sym() << "\n";
                    map.get_cell(get_pos().x, get_pos().y) = std::make_shared<Dot>(get_pos().x, get_pos().y);
                    set_pos(get_pos().x, get_pos().y + 1); ///DONE
                } else {
                    collide(*map.get_cell(get_pos().x, get_pos().y + 1));
                }
            }
            break;
        case 'd':
            std::cout << "aufasdasdsadsadasdasdasdsad" << "\n";
            if (get_pos().x + 1 < map.get_n()) {
                if ((map.get_cell(get_pos().x + 1, get_pos().y))->get_sym() == '.') { ///TODO * +
                    map.get_cell(get_pos().x + 1, get_pos().y) = map.get_player();
                    std::cout << map.get_cell(get_pos().x + 1, get_pos().y)->get_sym() << "\n";
                    map.get_cell(get_pos().x, get_pos().y) = std::make_shared<Dot>(get_pos().x, get_pos().y);
                    set_pos(get_pos().x + 1, get_pos().y); ///DONE
                } else {
                    std::cout << "aufasdasdsadsadasdasdasdsad" << "\n";
                    collide(*map.get_cell(get_pos().x + 1, get_pos().y));
                }
            }
            break;
        default:
            break;
    }
}

void Knight::collide(Zombie &that) {
    that.set_hp(get_damage());
    if (that.get_hp() > 0) {
        set_hp(that.get_damage());
    }
}

void Knight::collide(Entity &that) {
    that.collide(*this);
}

Princess::Princess(int x, int y): Entity(x, y, 'P') {}

void Princess::collide(Entity &that) {
    that.collide(*this);
};

Zombie::Zombie(int x, int y): Character(x, y, 'Z', random(2, 20), random(2, 5)) {}

void Zombie::collide(Knight &that) {
    that.collide(*this);
}

void Zombie::collide(Entity &that) {
    that.collide(*this);
}


Dragon::Dragon(int x, int y): Character(x, y, 'D', 30, 10) {}

void Dragon::collide(Entity &that) {
    that.collide(*this);
}


Wall::Wall(int x, int y): Entity(x, y, '#') {};

Dot::Dot(int x, int y): Entity(x, y, '.' ) {};
