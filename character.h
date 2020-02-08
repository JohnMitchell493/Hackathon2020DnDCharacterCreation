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