#include <string>
#include <iostream>
#include <cstdlib>
#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
private:
	std::string RaceName;
	std::string SubRaceName;
	std::string ClassName;
	std::string SubClassName;
	std::string BGName;
	int stats[6] = [0, 0, 0, 0, 0, 0];
	int mods[6] = [0, 0, 0, 0, 0, 0];
	int BiasArr[6] = [-1, -1, -1, -1, -1, -1];
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
		int first = (rand()) % 9;
		switch (first) {
		case 0:
			setRaceName("Dragonborn");
			stats[0] += 2;
			stats[5] += 1;
			break;
		case 1:
			setRaceName("Dwarf");
			int second = (rand()) % 2;
			switch (second) {
			case 0:
				setSubRaceName("Mountain Dwarf");
				stats[0] += 2;
				stats[2] += 2;
				break;
			case 1:
				setSubRaceName("Hill Dwarf");
				stats[2] += 2;
				stats[4] += 1;
				break;
			}
			break;
		case 2:
			setRaceName("Elf");
			stats[1] += 2;
			perc = true;
			int second = (rand()) % 3;
			switch (second) {
			case 0:
				setSubRaceName("High Elf");
				stats[3] += 1;
				break;
			case 1:
				setSubRaceName("Wood Elf");
				stats[4] += 1;
				break;
			case 2:
				setSubRaceName("Dark Elf");
				stats[5] += 1;
				break;
			}
			break;
		case 3:
			setRaceName("Gnome");
			stats[3] += 2;
			int second = (rand()) % 2;
			switch (second) {
			case 0:
				setSubRaceName("Forest Gnome");
				stats[1] += 1;
				break;
			case 1:
				setSubRaceName("Rock Gnome");
				stats[2] += 1;
				break;
			}
			break;
		case 4:
			setRaceName("Half-Elf");
			stats[5] += 2;
			int choose1 = (rand()) % 5;
			stats[choose1] += 1;
			int choose2 = (rand()) % 5;
			if (choose2 == choose1) {
				choose2 = (choose2 + 1) % 5;
			}
			stats[choose2] += 1;
			// half elf skill proficiencies happen after classes
			break;
		case 5:
			setRaceName("Halfling");
			stats[1] += 1;
			int second = (rand()) % 2;
			switch (second) {
			case 0:
				setSubRaceName("Lightfoot Halfling");
				stats[5] += 1;
				break;
			case 1:
				setSubRaceName("Stout Halfling");
				stats[2] += 1;
				break;
			}
			break;
		case 6:
			setRaceName("Half-Orc");
			stats[0] += 2;
			stats[2] += 1;
			inti = true;
			break;
		case 7:
			setRaceName("Human");
			stats[0] += 1;
			stats[1] += 1;
			stats[2] += 1;
			stats[3] += 1;
			stats[4] += 1;
			stats[5] += 1;
			break;
		case 8:
			setRaceName("Tiefling");
			stats[3] += 1;
			stats[5] += 2;
			break;
		default:
			exit(-1);
			break;
		}
	}

	void fillBias(&int[])

	void genClass {
		int choice = (rand()) % 12;
		int sub = (rand()) % 2;
		switch (choice) {
			case 0: // Barbarian
				BiasArr[0] = 0;
				BiasArr[1] = 2;
				fillBias(&BiasArr);
				break;
			case 1: // Bard
				BiasArr[0] = 5;
				BiasArr[1] = 1;
				fillBias(&BiasArr);
				break;
			case 2: // Cleric
				BiasArr[0] = 4
				switch (sub) {
					case 0: 
						BiasArr[1] = 0;
						break;
					case 1:
						BiasArr[1] = 2;
						break;
					default:
						exit(-1);
						break;
					}
				fillBias(&BiasArr);
				break;
			case 3: // Druid
				BiasArr[0] = 4;
				BiasArr[1] = 2;
				fillBias(&BiasArr);
				break;
			case 4: // Fighter
				switch (sub) {
					case 0: 
						BiasArr[0] = 0;
						break;
					case 1:
						BiasArr[0] = 1;
						break;
					default:
						exit(-1);
					}
				BiasArr[1] = 2
				fillBias(&BiasArr);
				break;
			case 5: // Monk
				BiasArr[0] = 1;
				BiasArr[1] = 4;
				fillBias(&BiasArr);
				break;
			case 6: // Paladin
				BiasArr[0] = 0;
				BiasArr[1] = 5;
				fillBias(&BiasArr);
				break;
			case 7: // Ranger
				BiasArr[0] = 1;
				BiasArr[1] = 4;
				fillBias(&BiasArr);
				break;
			case 8: // Rogue
				BiasArr[0] = 1
				switch (sub) {
					case 0: 
						BiasArr[1] = 3;
						break;
					case 1:
						BiasArr[1] = 5;
						break;
					default:
						exit(-1);
						break;
					}
				fillBias(&BiasArr);
				break;
			case 9: // Sorcerer
			case 10: // Warlock
				BiasArr[0] = 5;
				BiasArr[1] = 2;
				fillBias(&BiasArr);
				break;
			case 11: // Wizard
				BiasArr[0] = 3
				switch (sub) {
					case 0: 
						BiasArr[1] = 1;
						break;
					case 1:
						BiasArr[1] = 2;
						break;
					default:
						exit(-1);
						break;
					}
				fillBias(&BiasArr);
				break;
			default:
				exit (-1);
				break;
			}
	std::string getRaceName() {
		return this.RaceName;
	}
	std::string getSubRaceName() {
		return this.SubRaceName;
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
	void setSubRaceName(std::string s) {
		this.SubRaceName = s;
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
