/*
CSCI 235 Fall 2023
Project 2 - Barbarian Class
Created by Allison Lee on September 17 2023
Barbarian.cpp defines the constructors and private and public function implementation of the Barbarian class
*/

#include "Character.hpp"
#include "Barbarian.hpp"
#include <iostream>
using namespace std;

/**
    Default constructor.
    Default-initializes all private members. Default character name: "NAMELESS". 
    Booleans are default-initialized to False. 
    Default weapons: "NONE". 
*/
Barbarian::Barbarian(){
    this->main_weapon_ = "NONE";
    this->secondary_weapon_ = "NONE";
    this->enraged_ = false;
}

    /**
        Parameterized constructor.
        @param      : The name of the character (a const string reference)
        @param      : The race of the character (a const string reference)
        @param      : The character's vitality (an integer). Default to 0
        @param      : The character's max armor level (an integer). Default to 0
        @param      : The character's level (an integer). Default to 0
        @param      : A flag indicating whether the character is an enemy. Default to false
        @param      : The character's main weapon (a const string reference). 
                    String inputs can be in lowercase, but must be converted to uppercase 
                    when setting the variable. Only alphabetical characters are allowed.
                    Default to "NONE"
        @param      : The character's offhand weapon (a const string reference). 
                    String inputs can be in lowercase, but must be converted to uppercase 
                    when setting the variable. Only alphabetical characters are allowed.
                    Default to "NONE"
        @param      : A flag indicating whether the character is enraged. Default to false
        @post       : The private members are set to the values of the corresponding parameters. 
                    : If the main and secondary weapons are not provided or invalid, the variables                    are set to "NONE".
    */
    Barbarian::Barbarian(const std::string& name, const std::string& race, int vitality, int armor,
        int level, bool enemy, const std::string& main_weapon, const std::string& secondary_weapon, 
        bool enraged){
            setName(name);
            setRace(race);
            if(vitality >= 0){setVitality(vitality);} else {setVitality(0);}
            if(armor >= 0){setArmor(armor);} else {setArmor(0);}
            if(level >= 0){setLevel(level);} else {setLevel(0);}
            if(enemy == true){setEnemy();}
            if (setMainWeapon(main_weapon) == true){setMainWeapon(main_weapon);}
                else {main_weapon_ = "NONE";}
            if (setSecondaryWeapon(secondary_weapon) == true){setSecondaryWeapon(secondary_weapon);}
                else {secondary_weapon_ = "NONE";}
            setEnrage(enraged);
        }

    /**
        @param    : a reference to a string representing the Character's main weapon
        @post     : sets the private member variable to the value of the parameter. 
                    Only alphabetical characters are allowed.
                    String inputs can be in lowercase, but must be converted to uppercase when 
                    setting the variable.
                    If the given input is invalid (i.e contains numbers), do nothing and return false
        @return   : true if setting the variable was successful, false otherwise.
    **/
    bool Barbarian::setMainWeapon(const std::string& main_weapon){
        std::string upper_weapon = "";
        for (int i = 0; i < main_weapon.length(); i++){
            if (!isalpha(main_weapon[i])){
                return false;
            }
            else {
                upper_weapon += toupper(main_weapon[i]);
            }
        }
        this->main_weapon_ = upper_weapon;
        return true;
    }

    /**
        @return   : a string of the Character's main weapon
    **/
    std::string Barbarian::getMainWeapon() const{
        return main_weapon_;
    }

    /**
        @param    : a reference to a string representing the Character's secondary weapon
        @post     : sets the private member variable to the value of the parameter. 
                    Only alphabetical characters are allowed.
                    String inputs can be in lowercase, but must be converted to uppercase when 
                    setting the variable.
                : If the given input is invalid (i.e contains numbers), do nothing and return false
        @return   : true if setting the variable was successful, false otherwise.
    **/
    bool Barbarian::setSecondaryWeapon(const std::string& secondary_weapon){
        std::string upper_weapon = "";
        for (int i = 0; i < secondary_weapon.length(); i++){
            if (!isalpha(secondary_weapon[i])){
                return false;
            }
            else {
                upper_weapon += toupper(secondary_weapon[i]);
            }
        }
        this->secondary_weapon_ = upper_weapon;
        return true;
    }

    /**
        @return    : a string of the Character's secondary weapon
    **/
    std::string Barbarian::getSecondaryWeapon() const{
        return secondary_weapon_;
    }

    /**
        @param      : a reference to a bool
        @post       : sets the private member variable to the value of the parameter.
    **/
    void Barbarian::setEnrage(const bool& enrage){
        this->enraged_ = enrage;
    }

    /**
        @return  : a boolean of whether the Character is enraged
    **/
    bool Barbarian::getEnrage() const{
        return enraged_;
    }

    /**
        @post   : sets the enraged variable to the opposite of what it was
    **/
    void Barbarian::toggleEnrage(){
        if (enraged_ == false){
            this->enraged_ = true;
        }
        else {
            this->enraged_ = false;
        }
    }