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
	int BiasArr[6] = [0, 0, 0, 0, 0, 0];
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
		int first = (rand()) % 13;
		switch (first) {
		case 0:
			setBGName("Acolyte");
			insi = true;
			reli = true;
			break;
		case 1:
			setBGName("Charlatan");
			dece = true;
			slei = true;
			break;
		case 2:
			int second = (rand()) % 2;
			switch (second) {
			case 0:
				setBGName("Spy");
				break;
			case 1:
				setBGName("Criminal");
				break;
			}
			dece = true;
			stea = true;
			break;
		case 3:
			setBGName("Entertainer");
			acro = true;
			perf = true;
			break;
		case 4:
			setBGName("Folk Hero");
			anim = true;
			surv = true;
			break;
		case 5:
			int second = (rand()) % 2;
			switch (second) {
			case 0:
				setBGName("Guild Artisan");
				break;
			case 1:
				setBGName("Guild Merchant");
				break;
			}
			insi = true;
			pers = true;
			break;
		case 6:
			setBGName("Hermit");
			medi = true;
			reli = true;
			break;
		case 7:
			setBGName("Outlander");
			athl = true;
			surv = true;
			break;
		case 8:
			setBGName("Sage");
			arca = true;
			hist = true;
			break;
		case 9:
			setBGName("Sailor");
			athl = true;
			perc = true;
			break;
		case 10:
			setBGName("Soldier");
			athl = true;
			inti = true;
			break;
		case 11:
			setBGName("Urchin");
			slei = true;
			stea = true;
			break;
		case 12:
			setBGName("Noble");
			insi = true;
			reli = true;
			break;
		}
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
