/*
CSCI 235 Fall 2023
Project 2 - Mage Class
Created by Allison Lee on September 10 2023
Mage.cpp defines the constructors and private and public function implementation of the Mage class
*/

#include "Character.hpp"
#include "Mage.hpp"
#include <iostream>
using namespace std;

/**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". Booleans are default-initialized to False. 
    Default school of magic and weapon: "NONE". 
*/
Mage::Mage(){
    this->school_of_magic_ = "NONE";
    this->weapon_ = "NONE";
    this->can_summon_incarnate_ = false;
}

/**
    Parameterized constructor.
    @param      : The name of the character (a const string reference)
    @param      : The race of the character (a const string reference)
    @param      : The character's vitality (an integer). Default to 0
    @param      : The character's max armor level (an integer). Default to 0
    @param      : The character's level (an integer). Default to 0
    @param      : A flag indicating whether the character is an enemy. Default to false.
    @param      : The character's school of magic (a const string reference). Valid schools: 
                    [ELEMENTAL, NECROMANCY, ILLUSION]. 
                    String inputs can be in lowercase, but must be converted to 
                    uppercase when setting the variable.
                    If the school name is invalid, set it to "NONE"
    @param      : The character's choice of weapon (a const string reference). 
                    Valid weapons: [WAND, STAFF]
                    String inputs can be in lowercase, but must be converted to 
                    uppercase when setting the variable.
                    If the weapon is invalid, set it to "NONE"
    @param      : A flag indicating whether the character is able to summon an 
                    incarnate. Default to false.
    @post       : The private members are set to the values of the corresponding 
                    parameters.
                    REMEMBER: If the school of magic or weapon is not provided or invalid, the 
                    variables should be set to "NONE". 
*/
Mage::Mage (const std::string& name, const std::string& race, int vitality, int armor, int level, 
    bool enemy, const std::string& school, const std::string& weapon, bool can_summon){
        setName(name);
        setRace(race);
        if(vitality >= 0){setVitality(vitality);} else {setVitality(0);}
        if(armor >= 0){setArmor(armor);} else {setArmor(0);}
        if(level >= 0){setLevel(level);} else {setLevel(0);}
        if(enemy == true){setEnemy();}
        if(setSchool(school) == true){setSchool(school);}
            else if(setSchool(school) == false){this->school_of_magic_ = "NONE";}
        if(setCastingWeapon(weapon) == true){setCastingWeapon(school);}
            else if(setCastingWeapon(weapon) == false){this->weapon_ = "NONE";}
        setIncarnateSummon(can_summon);
    }
/**
    @param  : a reference to a string representing the school of magic
    @post   : sets the private member variable to the value of the parameter. If 
                the provided school of magic is not one of the following: [ELEMENTAL, 
                NECROMANCY, ILLUSION], do nothing and return false.
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable.
    @return  : true if setting the variable was successful, false otherwise.
**/
bool Mage::setSchool(const std::string& school){
    std::string input = "";
    for (int i = 0; i < school.length(); i++){
        input += toupper(school[i]);
    }
    if (input == "ELEMENTAL" || input == "NECROMANCY" || input == "ILLUSION"){
        this->school_of_magic_ = input;
        return true;
    }
    else {return false;}
}
/**
    @return  : the string indicating the character's school of magic
**/
std::string Mage::getSchool() const {return school_of_magic_;}

/**
    @param  : a reference to a string representing the character's weapon
    @post   : sets the private member variable to the value of the parameter.
              String inputs can be in lowercase, but must be converted to 
              uppercase when setting the variable.
              If the provided weapon is not one of the following: 
              [WAND, STAFF], do nothing and return false.
    @return  : true if setting the variable was successful, false otherwise.
**/
bool Mage::setCastingWeapon(const std::string& weapon){
    std::string input = "";
    for (int i = 0; i < weapon.length(); i++){
        input += toupper(weapon[i]);
    }
    if (input == "WAND" || input == "STAFF"){
        this->weapon_ = input;
        return true;
    }
    else {return false;}
}

/**
    @return  : the string indicating the character's weapon
**/
std::string Mage::getCastingWeapon() const {return weapon_;}

/**
    @param  : a reference to boolean
    @post   : sets the private member variable indicating whether the character can 
                summon an incarnate
**/
void Mage::setIncarnateSummon(const bool& can_summon){
    this->can_summon_incarnate_ = can_summon;
}

/**
    @return  : the summon-incarnate flag
**/
bool Mage::hasIncarnateSummon() const {return can_summon_incarnate_;}