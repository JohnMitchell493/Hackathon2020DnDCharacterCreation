#include <string>
#include <iostream>
#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
private:
	std::string RaceName;
	std::string ClassName;
	std::string BGName;
	int stats[6] = [0, 0, 0, 0, 0, 0];
public:
	std::string getRaceName() {
		return this.RaceName;
	}
	std::string getClassName() {
		return this.ClassName;
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
	void setBGName(std::string s) {
		this.BGName = s;
	}
	void printCharacter() {
		std::cout << "Race: " << RaceName << "\nClass: " << ClassName << "\nBackground: " << BGName << "\n" << std::endl;
	}
};

#endif