/*
CSCI 235 Fall 2023
Project 2 - Ranger Class
Created by Allison Lee on September 16 2023
Ranger.cpp defines the constructors and private and public function implementation of the Ranger class
*/

#include "Character.hpp"
#include "Ranger.hpp"
#include <iostream>
#include <vector>
using namespace std;

/**
        Default constructor.
        Default-initializes all private members. Default character name: "NAMELESS". 
        Booleans are default-initialized to False. 
    */
    Ranger::Ranger(){
        arrows_ = {};
        affinities_ = {};
        has_companion_ = false;
    }

    /**
         Parameterized constructor.
        @param      : The name of the character (a const string reference)
        @param      : The race of the character (a const string reference)
        @param      : The character's vitality (an integer). Default to 0
        @param      : The character's max armor level (an integer). Default to 0
        @param      : The character's level (an integer). Default to 0
        @param      : A flag indicating whether the character is an enemy. Default to false
        @param      : A vector of arrows. Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
                        Lowercase valid arrow types are retained but converted to uppercase.
                        Invalid arrows are those with non-positive quantities or invalid types.
                        If the vector contains invalid arrows, those arrows are discarded. 
                        Default to empty vector
        @param      : A vector of affinities. Valid Affinities: [FIRE, WATER, POISON, BLOOD]
                        String inputs can be in lowercase, but must be converted to uppercase.
                        If the vector contains invalid affinities, those affinities are discarded.
                        Default to empty vector
        @param      : A flag indicating whether the character is able to recruit an animal companion. 
                        Default to false
        @post       : The private members are set to the values of the corresponding parameters
    */
    Ranger::Ranger(const std::string& name, const std::string& race, int vitality, int armor, int level, 
        bool enemy, vector<Arrows> arrows, vector<string> affinities, bool has_companion){
            setName(name);
            setRace(race);
            if(vitality >= 0){setVitality(vitality);} else {setVitality(0);}
            if(armor >= 0){setArmor(armor);} else {setArmor(0);}
            if(level >= 0){setLevel(level);} else {setLevel(0);}
            if(enemy == true){setEnemy();}
            for (int i = 0; i < arrows.size(); i++){
                addArrows(arrows[i].type_, arrows[i].quantity_);
            }
            for (int i = 0; i < affinities.size(); i++){
                addAffinity(affinities[i]);
            }
            setCompanion(has_companion);
        }

    /**
        @return     : a vector of the Character's arrows
    **/
    vector<Arrows> Ranger::getArrows() const {return arrows_;}

    /**
        convert word to uppercase
        @param          : A string
        @return         : A string in uppercase
    */
    std::string toUpper(std::string word){
        std::string upper_word = "";
        for (int i = 0; i < word.length(); i++){
                upper_word += toupper(word[i]);
        }
        return upper_word;
    }

    /**
        @param    : a reference to string representing the arrow type
        @param    : a reference to an integer quantity
        @post     : If the character already has that type of arrow, the quantity in the vector 
                    is updated. If not, the arrow is added to the vector. 
                    Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
                    Lowercase valid arrow types are retained but converted to uppercase.
                    Quantity of arrows must be greater than 0
                    Invalid arrows are those with non-positive quantities or invalid types.
                    If the arrows are invalid, they are not added.
        @return   : True if the arrows were added successfully, false otherwise
    **/
    bool Ranger::addArrows(const std::string& arrow, const int& quantity){
        if (quantity <= 0){return false;}
        std::string upper_arrow = toUpper(arrow);
        if (upper_arrow != "WOOD" && upper_arrow != "FIRE" && upper_arrow != "WATER" && 
            upper_arrow != "POISON" && upper_arrow != "BLOOD"){return false;}
        else {
            bool search = false;
            int index = 0;
            for (int i = 0; i < arrows_.size(); i++){
                if (upper_arrow == arrows_[i].type_){
                    search = true;
                    index = i;
                }
            }
            if (search == true){
                arrows_[index].quantity_ += quantity;
            }
            else {
                Arrows arws{upper_arrow, quantity};
                arrows_.push_back(arws);
            }
            return true;
        }
    }

    /**
        @param    : a reference to string representing the arrow type
        @post     : If the character has the listed arrow AND enough arrows to fire one, 
                    the quantity of remaining arrows in the vector is updated.
                    Lowercase valid arrow types are accepted but converted to uppercase.
                    If firing the last arrow, simply decrement the quantity to 0.
        @return   : True if the character had the listed arrow AND enough arrows, False otherwise.
    **/
    bool Ranger::fireArrow(const std::string& arrow){
        std::string upper_arrow = toUpper(arrow);
        if (upper_arrow != "WOOD" && upper_arrow != "FIRE" && upper_arrow != "WATER" && 
            upper_arrow != "POISON" && upper_arrow != "BLOOD"){return false;}
        bool search = false;
        int index = 0;
        for (int i = 0; i < arrows_.size(); i++){
            if (upper_arrow == arrows_[i].type_){
                search = true;
                index = i;
            }
        }
        if (search == false){return false;}
        else if (arrows_[index].quantity_ == 0){return false;}
        else {
            arrows_[index].quantity_--;
            return true;
        }
    }

    /**
        @param  : a reference to string representing an affinity 
        @post   : If the affinity does not already exist in the vector, add it to the vector.
                Valid Affinities: [FIRE, WATER, POISON, BLOOD] 
                String inputs can be in lowercase, but must be converted to uppercase when 
                setting the variable.
                There should be no duplicate affinities.
                If the affinity is invalid, it is NOT added.
        @return : True if the affinity was added successfully, false otherwise
    **/
    bool Ranger::addAffinity(const std::string& affinity){
        std::string upper_affinity = toUpper(affinity);
        if (upper_affinity != "FIRE" && upper_affinity != "WATER" && upper_affinity != "POISON" &&
            upper_affinity != "BLOOD"){return false;}
        bool search = false;
        for (int i = 0; i < affinities_.size(); i++){
            if (affinities_[i] == upper_affinity){
                search = true;
            }
        }
        if (search == true){return false;}
        else {
            affinities_.push_back(upper_affinity);
            return true;
        }
    }

    /**
        @return     : a vector of the Character's affinities
    **/
    vector<std::string> Ranger::getAffinities() const{
        return affinities_;
    }

    /**
        @param    : a reference to a boolean indicating whether the character is able to recruit 
                    an animal companion
        @post     : sets the private member variable to the value of the parameter.
    **/
    void Ranger::setCompanion(const bool& has_companion){
        this->has_companion_ = has_companion;
    }

    /**
        @return   : a boolean indicating whether the character is able to recruit an animal companion
    **/
    bool Ranger::getCompanion() const{
        return has_companion_;
    }

