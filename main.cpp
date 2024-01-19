/*
CSCI 235 Fall 2023
Project 2 - main
Created by Allison Lee on September 10, 2023
main.cpp tests functions from project 2
*/

#include "Character.hpp"
#include "Mage.hpp"
#include "Scoundrel.hpp"
#include "Ranger.hpp"
#include "Barbarian.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    Arrows arw1{"wood", 1};
    Arrows arw2{"fire", 200};
    Arrows arw3{"water", 300};
    vector<Arrows> arrows = {arw1, arw2, arw3};
    vector<std::string> affinity = {"fire", "water"};
    Ranger daniel("danie3l", "HUMAN", 100, 200, 300, false, arrows, affinity, true);
    daniel.addArrows("wood", 2);
    // daniel.fireArrow("wood");
    // daniel.addArrows("poison", 100);
    // daniel.addAffinity("fire");
    // daniel.addAffinity("water");
    // daniel.addAffinity("dandan");
    // daniel.addAffinity("water");
    
    for (int i = 0; i < daniel.getArrows().size(); i++){
        std::cout << daniel.getArrows()[i].type_ << " " << daniel.getArrows()[i].quantity_ << " ";
    }
    for (int i = 0; i < daniel.getAffinities().size(); i++){
        std::cout << "\n" << daniel.getAffinities()[i] << " ";
    }
}



        //bool i = true;
        // daniel.setDagger("steel");
        // daniel.setFaction("cutpurse");
        // daniel.setDisguise(i);
    // std::cout << daniel.getName() << endl;
    // std::cout << daniel.getRace() << endl;
    // std::cout << daniel.getVitality() << endl;
    // std::cout << daniel.getArmor() << endl;
    // std::cout << daniel.getLevel() << endl;
    // std::cout << daniel.isEnemy() << endl;
            // std::cout << daniel.getSchool() << endl;
            // std::cout << daniel.getCastingWeapon() << endl;
            // std::cout << daniel.hasIncarnateSummon() << endl;
            // std::cout << daniel.getDagger() << endl;
            // std::cout << daniel.getFaction() << endl;
            // std::cout << daniel.hasDisguise() << endl;