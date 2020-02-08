#include <string>
#include <iostream>
#include <cstdlib>
#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
private:
	std::string RaceName;
	std::string ClassName;
	std::string SubClassName;
	std::string BGName;
	int stats[6] = [0, 0, 0, 0, 0, 0];
	int mods[6] = [0, 0, 0, 0, 0, 0];
	bool acro=false;
	bool anim=false;
	bool arca=false;
	bool athl=false;
	bool dece=false;
	bool hist=false;
	bool insi=false;
	bool inti=false;
	bool inve=false;
	bool medi=false;
	bool natu=false;
	bool perc=false;
	bool perf=false;
	bool pers=false;
	bool reli=false;
	bool slei=false;
	bool stea=false;
	bool surv=false;
public:
	Character(){
		
	}

	void genRace() {
		switch ((rand()) % 9) {
		case 0:
			setRaceName("Dragonborn");

		case 1:
			setRaceName("Dwarf");

		case 2:
			setRaceName("Elf");

		case 3:
			setRaceName("Gnome");

		case 4:
			setRaceName("Half-Elf");

		case 5:
			setRaceName("Halfling");

		case 6:
			setRaceName("Half-Orc");

		case 7:
			setRaceName("Human");

		case 8:
			setRaceName("Tiefling");


		}
	}
	std::string getRaceName() {
		return this.RaceName;
	}
	std::string getClassName() {
		return this.ClassName;
	}
	std::string getSubClassName() {
		return this.SubClassName;
	}
	std::string getBGName() {
		return this.BGName;
	}
	void setRaceName(std::string s) {
		this.RaceName = s;
	}
	void setClassName(std::string s) {
		this.ClassName = s;
	}
	void setSubClassName(std::string s) {
		this.SubClassName = s;
	}
	void setBGName(std::string s) {
		this.BGName = s;
	}
	void printCharacter() {
		std::cout << "Race: " << RaceName << "\nClass: " << ClassName 
			<< "\nSubclass: " << SubClassName << "\nBackground: " << BGName 
			<< "\n" << std::endl;
	}
};

#endif