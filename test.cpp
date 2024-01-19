/*
CSCI 235 Fall 2023
Project 2 - Testing program
Created by Allison Lee on September 17 2023
test.cpp tests the constructors and private and public function implementation of the 
Mage, Scoundrel, Ranger, and Barbarian classes
*/

#include "Character.hpp"
#include "Mage.hpp"
#include "Scoundrel.hpp"
#include "Ranger.hpp"
#include "Barbarian.hpp"
#include <iostream>
#include <vector>
using namespace std;

void printCharacter(Character chara){
    std::string enemy = "not an enemy";
    if (chara.isEnemy() == true){
        enemy = "an enemy";
    }
    std::cout << chara.getName() << " is a Level " << chara.getLevel() <<
        " " << chara.getRace() << ". \nVitality: " << chara.getVitality() <<
        "\nArmor: " << chara.getArmor() << "\nThey are " << enemy << "\n"; 
}

void printMage(Mage chara){
    std::string can_summon = "FALSE";
    if (chara.hasIncarnateSummon() == true){
        can_summon = "TRUE";
    }
    std::cout << "School of Magic: " << chara.getSchool() << "\nWeapon: " <<
        chara.getCastingWeapon() << "\nSummon Incarnate: " << can_summon << "\n";
}

void printScoundrel(Scoundrel chara){
    std::string has_disguise = "FALSE";
    if (chara.hasDisguise() == true){
        has_disguise = "TRUE";
    }
    std::cout << "Dagger: " << chara.getDagger() << "\nFaction: " <<
        chara.getFaction() << "\nDisguise: " << 
        has_disguise << "\n";
}

void printRanger(Ranger chara){
    std::string has_companion = "FALSE";
    if (chara.getCompanion() == true){
        has_companion = "TRUE";
    }
    std::cout << "Vector or arrows: ";
    int arrow_size = chara.getArrows().size();
    if (arrow_size > 0){
        for (int i = 0; i < arrow_size - 1; i++){
            std::cout << chara.getArrows()[i].type_ << ", " << 
                chara.getArrows()[i].quantity_ << ", ";
        }
        std::cout << chara.getArrows()[arrow_size - 1].type_ << 
            ", " << chara.getArrows()[arrow_size - 1].quantity_;   
    }
    std::cout << "\nAffinities: ";
    if (chara.getAffinities().size() > 0){
        for (int i = 0; i < chara.getAffinities().size() - 1; i++){
            std::cout << chara.getAffinities()[i] << ", ";
        }
        std::cout << chara.getAffinities()[chara.getAffinities().size() - 1];
    }
    std::cout << "\nAnimal Companion: " << has_companion << "\n";
}

void printBarbarian(Barbarian chara){
    std::string enraged = "FALSE";
    if (chara.getEnrage() == true){
        enraged = "TRUE";
    }
    std::cout << "Main Weapon: " << chara.getMainWeapon() << 
        "\nOffhand Weapon: " << chara.getSecondaryWeapon() << 
        "\nEnraged: " << enraged << "\n";
}

int main() {
    /**
    2.1.1 Instantiate a default Mage
    - Sets its name, race, vitality, and armor levels using the appropriate setter functions
    Name: defaultMage
    Race: ELF
    Vitality: 5
    Armor: 3
    Level: 2
    Enemy: TRUE
    - Print out information for default Mage
    */
    Mage defaultMage;
    defaultMage.setName("defaultMage");
    defaultMage.setRace("ELF");
    defaultMage.setVitality(5);
    defaultMage.setArmor(3);
    defaultMage.setLevel(2);
    defaultMage.setEnemy();
    printCharacter(defaultMage);
    printMage(defaultMage);

    /**
    2.1.2 Instantiate a Mage with the parameterized constructor with the following character details:
    Name: SPYNACH
    Race: ELF
    Vitality: 6
    Armor: 4
    Level: 4
    Enemy: FALSE

    2.1.3 Set SPYNACH's unique private member variables to the following:
    School of Magic: Illusion
    Weapon: Wand
    Summon Incarnate: TRUE

    - Print out information for SPYNACH 
    */
    Mage spynach;
    spynach.setName("SPYNACH");
    spynach.setRace("ELF");
    spynach.setVitality(6);
    spynach.setArmor(4);
    spynach.setLevel(4);
    spynach.setSchool("Illusion");
    spynach.setCastingWeapon("Wand");
    spynach.setIncarnateSummon(true);
    printCharacter(spynach);
    printMage(spynach);

    /**
    2.2.1 Instantiate a default Scoundrel
    - Sets its name, race, vitality, and armor levels using the appropriate setter functions
    Name: defaultScoundrel
    Race: HUMAN
    Vitality: 6
    Armor: 4
    Level: 3
    Enemy: TRUE

    - Print out information for default Scoundrel 
    */
    Scoundrel defaultScoundrel;
    defaultScoundrel.setName("defaultScoundrel");
    defaultScoundrel.setRace("HUMAN");
    defaultScoundrel.setVitality(6);
    defaultScoundrel.setArmor(4);
    defaultScoundrel.setLevel(3);
    defaultScoundrel.setEnemy();
    printCharacter(defaultScoundrel);
    printScoundrel(defaultScoundrel);

    /**
    2.2.2 Instantiate a Scoundrel with the parameterized constructor with the following character details:
    Name: FLEA
    Race: DWARF
    Vitality: 12
    Armor: 7
    Level: 5
    Enemy: FALSE

    2.2.3 Set FLEA's unique private member variables to the following:
    Dagger: Adamant
    Faction: Cutpurse
    Disguise: TRUE

    - Print out information for FLEA
    */
    Scoundrel flea;
    flea.setName("FLEA");
    flea.setRace("DWARF");
    flea.setVitality(12);
    flea.setArmor(7);
    flea.setLevel(5);
    flea.setDagger("Adamant");
    flea.setFaction("Cutpurse");
    flea.setDisguise(true);
    printCharacter(flea);
    printScoundrel(flea);
    
    /**
    2.3.1 Instantiate a default Ranger
     - Sets its name, race, vitality, and armor levels using the appropriate setter functions
    Name: defaultRanger
    Race: UNDEAD
    Vitality: 8
    Armor: 4
    Level: 5
    Enemy: TRUE

    - Print out information for default Ranger
    */
    Ranger defaultRanger;
    defaultRanger.setName("defaultRanger");
    defaultRanger.setRace("UNDEAD");
    defaultRanger.setVitality(8);
    defaultRanger.setArmor(4);
    defaultRanger.setLevel(5);
    defaultRanger.setEnemy();
    printCharacter(defaultRanger);
    printRanger(defaultRanger);

    /**
    2.2.2 Instantiate a Ranger with the parameterized constructor with the following character details:
    Name: MARROW
    Race: UNDEAD
    Vitality: 9
    Armor: 6
    Level: 5
    Enemy: TRUE

    2.2.3 Set MARROW's unique private member variables to the following:
    Vector of arrows: Wood, 30, Fire, 5, Water, 5, Poison, 5
    Affinities: Fire, Poison
    Animal Companian: TRUE

    - Print out information for MARROW
    */
    Ranger marrow;
    marrow.setName("MARROW");
    marrow.setRace("UNDEAD");
    marrow.setVitality(9);
    marrow.setArmor(6);
    marrow.setLevel(5);
    marrow.setEnemy();
    marrow.addArrows("Wood", 30);
    marrow.addArrows("Fire", 5);
    marrow.addArrows("Water", 5);
    marrow.addArrows("Poison", 5);
    marrow.addAffinity("Fire");
    marrow.addAffinity("Poison");
    marrow.setCompanion(true);
    printCharacter(marrow);
    printRanger(marrow);

    /**
    2.4.1 Instantiate a default Barbarian
    - Sets its name, race, vitality, and armor levels using the appropriate setter functions
    Name: defaultBarbarian
    Race: HUMAN
    Vitality: 10
    Armor: 5
    Level: 5
    Enemy: TRUE

    - Print out information for default Barbarian
    */
    Barbarian defaultBarbarian;
    defaultBarbarian.setName("defaultBarbarian");
    defaultBarbarian.setRace("HUMAN");
    defaultBarbarian.setVitality(10);
    defaultBarbarian.setArmor(5);
    defaultBarbarian.setLevel(5);
    defaultBarbarian.setEnemy();
    printCharacter(defaultBarbarian);
    printBarbarian(defaultBarbarian);

    /**
    2.4.2 Instantiate a Barbarian with the parameterized constructor with the following character details:
    Name: BONK
    Race: HUMAN
    Vitality: 11
    Armor: 5
    Level: 5
    Enemy: TRUE

    2.4.3 Set BONK's unique private member variables to the following:
    Main Weapon: MACE
    Offhand Weapon: ANOTHERMACE
    Enraged: TRUE

    - Print out information for BONK
    */
    Barbarian bonk;
    bonk.setName("BONK");
    bonk.setRace("HUMAN");
    bonk.setVitality(11);
    bonk.setArmor(5);
    bonk.setLevel(5);
    bonk.setEnemy();
    bonk.setMainWeapon("MACE");
    bonk.setSecondaryWeapon("ANOTHERMACE");
    bonk.setEnrage(true);
    printCharacter(bonk);
    printBarbarian(bonk);
}