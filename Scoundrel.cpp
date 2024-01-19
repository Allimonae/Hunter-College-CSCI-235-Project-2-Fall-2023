/*
CSCI 235 Fall 2023
Project 2 - Scoundrel Class
Created by Allison Lee on September 12 2023
Scoundrel.cpp defines the constructors and private and public function implementation of the Scoundrel class
*/

#include "Scoundrel.hpp"
#include "Character.hpp"
#include <iostream>
using namespace std;

/**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". Booleans are default-initialized to False. 
    Default dagger: WOOD. Default faction: "NONE". 
*/
Scoundrel::Scoundrel(){
    this->dagger_ = WOOD;
    this->faction_ = "NONE";
    this->has_disguise_ = false;
}

/**
    Parameterized constructor.
    @param      : The name of the character (a const string reference)
    @param      : The race of the character (a const string reference)
    @param      : The character's vitality (an integer). Default to 0
    @param      : The character's max armor level (an integer). Default to 0
    @param      : The character's level (an integer). Default to 0
    @param      : A flag indicating whether the character is an enemy. Default to false.
    @param      : The character's dagger type (a const string reference).
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the dagger enum. Default to WOOD
    @param      : The character's Faction (a const string reference). 
                Valid Factions: [CUTPURSE, SHADOWBLADE, SILVERTONGUE] 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable. Default to "NONE"
    @param      : A flag indicating whether the character has a disguise. Default to false
    @post       : The private members are set to the values of the corresponding 
                parameters.
                If the dagger type is not provided or invalid, the variable should 
                be set to WOOD. 
                If the Faction is not provided or invalid, the variable should be 
                set to "NONE". 
*/
Scoundrel::Scoundrel(const std::string& name, const std::string& race, int vitality, int armor,
    int level, bool enemy, const std::string& dagger, const std::string& faction,
    bool disguise){
        setName(name);
        setRace(race);
        if(vitality >= 0){setVitality(vitality);} else {setVitality(0);}
        if(armor >= 0){setArmor(armor);} else {setArmor(0);}
        if(level >= 0){setLevel(level);} else {setLevel(0);}
        if(enemy == true){setEnemy();}
        setDagger(dagger);
        if (setFaction(faction) == true){setFaction(faction);} 
            else {this->faction_ = "NONE";}
        setDisguise(disguise);
    }

/**
    @param     : a reference to a string representing the dagger type
    @post      : sets the private member variable to the value of the parameter. 
                    String inputs can be in lowercase, but must be converted to 
                    uppercase when setting the variable.
                    If the dagger type is not valid (i.e, is one of the following: 
                    [WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE]), 
                    the variable should be set to WOOD. 
**/
void Scoundrel::setDagger(const std::string& dagger){
    std::string input = "";
    for(int i = 0; i < dagger.length(); i++){
        input += toupper(dagger[i]);
    }
    if(input == "BRONZE") {this->dagger_ = BRONZE;}
    else if(input == "IRON") {this->dagger_ = IRON;}
    else if(input == "STEEL") {this->dagger_ = STEEL;}
    else if(input == "MITHRIL") {this->dagger_ = MITHRIL;}
    else if(input == "ADAMANT") {this->dagger_ = ADAMANT;}
    else if(input == "RUNE") {this->dagger_ = RUNE;}
    else {this->dagger_ = WOOD;}
}

/**
    @return     : the string indicating the character's dagger type
**/
std::string Scoundrel::getDagger() const{
    if(dagger_ == BRONZE) {return "BRONZE";}
    else if(dagger_ == IRON) {return "IRON";}
    else if(dagger_ == STEEL) {return "STEEL";}
    else if(dagger_ == MITHRIL) {return "MITHRIL";}
    else if(dagger_ == ADAMANT) {return "ADAMANT";}
    else if(dagger_ == RUNE) {return "RUNE";}
    else {return "WOOD";}
}

/**
    @param    : a reference to a string representing the character's Faction
    @post     : sets the private member variable to the value of the parameter. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable.
                If the provided faction is not one of the following: 
            [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE], 
            do nothing and return false.
    @return   : true if setting the variable was successful, false otherwise.
**/
bool Scoundrel::setFaction(const std::string& faction){
    std::string input = "";
    for(int i = 0; i < faction.length(); i++){
        input += toupper(faction[i]);
    }
    if(input == "NONE" || input == "CUTPURSE" || input == "SHADOWBLADE" || 
        input == "SILVERTONGUE"){
            this->faction_ = input;
            return true;
        }
    else {return false;}
}

/**
    @return  : the string indicating the character's Faction
**/
std::string Scoundrel::getFaction() const {return faction_;}

/**
    @param  : a reference to boolean
    @post   : sets the private member variable indicating whether the character has a disguise
**/
void Scoundrel::setDisguise(const bool& disguise){this->has_disguise_ = disguise;}

/**
    @return  : the visual aid flag
**/
bool Scoundrel::hasDisguise() const {return has_disguise_;}