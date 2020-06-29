//
// Created by inno on 24.03.2020.
//

#ifndef ROGUELIKE_REMASTERED_ENTITIES_HPP
#define ROGUELIKE_REMASTERED_ENTITIES_HPP


#include <iostream>
#include "Map.hpp"

class Entity;
class Character;
class Knight;
class Princess;
class Zombie;
class Dragon;
class Dot;
class Wall;
class Map;

struct coords {
    coords() {};
    coords(int x, int y): x(x), y(y) {};
    int x = 0;
    int y = 0;
};

class Entity {
public:
    Entity(int x, int y, char sym);
    coords get_pos() const;
    char get_sym() const;
    void set_pos(int x, int y);
    void set_char(char sym);

    /**             Collides              **/
    virtual void collide (Entity& that) = 0;
    virtual void collide (Character& that) = 0;
    virtual void collide (Knight& that) = 0;
    virtual void collide (Zombie& that) = 0;
    virtual void collide (Dragon& that) = 0;
    virtual void collide (Wall& that) = 0;
    virtual void collide (Princess& that) = 0;
    virtual void collide (Dot& that) = 0;
    /**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/
private:
    coords Pos;
    char Sym = '.';
};
/**********Entity_description*******************/
///
///
///
///
///
/***********************************************/

class Character: public Entity {
public:
    Character(int x, int y, char sym, int hp, int dmg);
    virtual void move(int key, Map &map);
    int get_hp();
    void set_hp(int value);
    int get_damage();
    /**             Collides              **/
    void collide(Entity &that) override;
    void collide(Character &that) override {};
    void collide(Knight &that) override {};
    void collide(Zombie &that) override {};
    void collide(Dragon &that) override {};
    void collide(Dot &that) override {};
    void collide(Wall &that) override {};
    void collide(Princess &that) override {};
    /**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/
private:
    int hp = 0;
    int dmg = 0;
};
/**********Character_description****************/
///
///
///
///
///
/***********************************************/

class Knight: public Character {
public:
    Knight(int x, int y);
    void move(int key, Map &map) override;

    /**             Collides              **/
    void collide(Entity &that) override;
    void collide(Character &that) override {};
    void collide(Knight &that) override {};
    void collide(Dot &that) override {};
    void collide(Zombie &that) override;
    void collide(Dragon &that) override {};
    void collide(Wall &that) override {};
    void collide(Princess &that) override {};
    /**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/
private:

};
/**********Knight_description*******************/
///
///
///
///
///
/***********************************************/

class Princess: public Entity {
public:
    Princess(int x, int y);

    /**             Collides              **/
    void collide(Entity &that) override;
    void collide(Character &that) override {};
    void collide(Knight &that) override {};
    void collide(Zombie &that) override {};
    void collide(Dragon &that) override {};
    void collide(Dot &that) override {};
    void collide(Wall &that) override {};
    void collide(Princess &that) override {};
    /**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/
private:

};
/**********Princess_description*****************/
///
///
///
///
///
/***********************************************/

class Zombie: public Character {
public:
    Zombie(int x, int y);
    /**             Collides              **/
    void collide(Entity &that) override;
    void collide(Character &that) override {};
    void collide(Knight &that) override;
    void collide(Zombie &that) override {};
    void collide(Dragon &that) override {};
    void collide(Dot &that) override {};
    void collide(Wall &that) override {};
    void collide(Princess &that) override {};
    /**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/
private:

};
/**********Zombie_description*******************/
///
///
///
///
///
/***********************************************/



class Dragon: public Character {
public:
    Dragon(int x, int y);
    /**             Collides              **/
    void collide(Entity &that) override;
    void collide(Character &that) override {};
    void collide(Knight &that) override {};
    void collide(Zombie &that) override {};
    void collide(Dragon &that) override {};
    void collide(Dot &that) override {};
    void collide(Wall &that) override {};
    void collide(Princess &that) override {};
    /**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/
private:

};
/**********Dragon_description*******************/
///
///
///
///
///
/***********************************************/

class Dot: public Entity {
public:
    Dot(int x, int y);

    /**             Collides              **/
    void collide(Entity &that) override {};
    void collide(Character &that) override {};
    void collide(Knight &that) override {};
    void collide(Zombie &that) override {};
    void collide(Dragon &that) override {};
    void collide(Dot &that) override {};
    void collide(Wall &that) override {};
    void collide(Princess &that) override {};
    /**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/
private:

};
/**********Dot_description**********************/
///
///
///
///
///
/***********************************************/

class Wall: public Entity {
public:
    Wall(int x, int y);

    /**             Collides              **/
    void collide(Entity &that) override {};
    void collide(Character &that) override {};
    void collide(Knight &that) override {};
    void collide(Zombie &that) override {};
    void collide(Dragon &that) override {};
    void collide(Dot &that) override {};
    void collide(Wall &that) override {};
    void collide(Princess &that) override {};
    /**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/
private:

};
/**********Wall_description*********************/
///
///
///
///
///
/***********************************************/


#endif //ROGUELIKE_REMASTERED_ENTITIES_HPP
