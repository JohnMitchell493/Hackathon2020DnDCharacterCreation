
#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>

class Character {
private:
	std::string RaceName;
	std::string SubRaceName="NONE";
	std::string ClassName;
	std::string SubClassName="NONE";
	std::string BGName;
	std::string Ideal;
	std::string Bond;
	std::string Trait;
	std::string Flaw;
	std::string Special="NONE";
	int gold = 0;
	int stats[6] = {0, 0, 0, 0, 0, 0};
	int mods[6] = {0, 0, 0, 0, 0, 0};
	int BiasArr[6] = {-1, -1, -1, -1, -1, -1};
	int HitPoints = 0;
	bool acro = false;
	bool anim = false;
	bool arca = false;
	bool athl = false;
	bool dece = false;
	bool hist = false;
	bool insi = false;
	bool inti = false;
	bool inve = false;
	bool medi = false;
	bool natu = false;
	bool perc = false;
	bool perf = false;
	bool pers = false;
	bool reli = false;
	bool slei = false;
	bool stea = false;
	bool surv = false;
	
	bool strS=false;
	bool dexS=false;
	bool conS=false;
	bool intS=false;
	bool wisS=false;
	bool chaS=false;
public:
	Character() {
		srand(time(0));
		genRace();
		genBG();
		genClass();
		genGold();
		genMod();
		genHP();
	}

	void genRace() {
		srand(time(0));
		int first = rand() % 9;
		int second;
		int choose1;
		int choose2;
		switch (first) {
		case 0:
			setRaceName("Dragonborn");
			stats[0] += 2;
			stats[5] += 1;
			break;
		case 1:
			setRaceName("Dwarf");
			second = (rand()) % 2;
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
			second = (rand()) % 3;
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
			second = (rand()) % 2;
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
			choose1 = (rand()) % 5;
			stats[choose1] += 1;
			choose2 = (rand()) % 5;
			if (choose2 == choose1) {
				choose2 = (choose2 + 1) % 5;
			}
			stats[choose2] += 1;
			// half elf skill proficiencies happen after classes
			break;
		case 5:
			setRaceName("Halfling");
			stats[1] += 2;
			second = (rand()) % 2;
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

	void genBG() {
		int first = (rand()) % 13;
		int second;
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
			second = (rand()) % 2;
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
		
			second = (rand()) % 2;
			switch (second) {
			case 0:
				setBGName("Entertainer");
				break;
			case 1:
				setBGName("Gladiator");
				break;
			}
		
			
			acro = true;
			perf = true;
			break;
		case 4:
			setBGName("Folk Hero");
			anim = true;
			surv = true;
			break;
		case 5:
			second = (rand()) % 2;
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
			second = (rand()) % 2;
			switch (second) {
			case 0:
				setBGName("Sailor");
				break;
			case 1:
				setBGName("Pirate");
				break;
			}
			
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
			
			second = (rand()) % 2;
			switch (second) {
			case 0:
				setBGName("Noble");
				break;
			case 1:
				setBGName("Knight");
				break;
			}
			
			hist = true;
			pers = true;
			break;
		}
	}

	void genClass() {
		int ranSkill1;
		int StdArray[6] = {15, 14, 13, 12, 10, 8};
		srand(time(0));
		int choice = (rand()) % 12;
		srand(time(0));
		int sub = (rand()) % 2;
		int sClass;
		std::vector<int> values;
		switch (choice) {
		case 0: // Barbarian
			ClassName="Barbarian";
			BiasArr[0] = 0;
			BiasArr[1] = 2;
			
			
			strS=true;
			
			conS=true;
			
			
			srand(time(0));
			ranSkill1 = (rand()) % 6;
			while (true) {
				if (ranSkill1 == 0 && anim == false) {
					anim = true;
					break;
				}
				else if (ranSkill1 == 1 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 2 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 3 && natu == false) {
					natu = true;
					break;
				}
				else if (ranSkill1 == 4 && perc == false) {
					perc = true;
					break;
				}
				else if (ranSkill1 == 5 && surv == false) {
					surv = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 6;
			}
			srand(time(0));
			ranSkill1 = (rand()) % 6;
			while (true) {
				if (ranSkill1 == 0 && anim == false) {
					anim = true;
					break;
				}
				else if (ranSkill1 == 1 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 2 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 3 && natu == false) {
					natu = true;
					break;
				}
				else if (ranSkill1 == 4 && perc == false) {
					perc = true;
					break;
				}
				else if (ranSkill1 == 5 && surv == false) {
					surv = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 6;
			}
			
			values.push_back(1);
			values.push_back(3);
			values.push_back(4);
			values.push_back(5);
			
			std::random_shuffle(values.begin(), values.end());
			for (int i = 0; i < 4; i++) {
				BiasArr[i + 2] = values[i];
			}
			
			for (int i = 0; i < 6; i++) {
				if (stats[i] != -1) {
					stats[BiasArr[i]] += StdArray[i];
				}
			}
			break;
		case 1: // Bard
			ClassName="Bard";
			BiasArr[0] = 5;
			BiasArr[1] = 1;
			
			
			dexS=true;
			
			chaS=true;
			
			srand(time(0));
			ranSkill1 = (rand()) % 18;
			while (true) {
				if (ranSkill1 == 0 && acro == false) {
					acro = true;
					break;
				}
				else if (ranSkill1 == 1 && anim == false) {
					anim = true;
					break;
				}
				else if (ranSkill1 == 2 && arca == false) {
					arca = true;
					break;
				}
				else if (ranSkill1 == 3 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 4 && dece == false) {
					dece = true;
					break;
				}
				else if (ranSkill1 == 5 && hist == false) {
					hist = true;
					break;
				}
				else if (ranSkill1 == 6 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 7 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 8 && inve == false) {
					inve = true;
					break;
				}
				else if (ranSkill1 == 9 && medi == false) {
					medi = true;
					break;
				}
				else if (ranSkill1 == 10 && natu == false) {
					natu = true;
					break;
				}
				else if (ranSkill1 == 11 && perc == false) {
					perc = true;
					break;
				}
				else if (ranSkill1 == 12 && perf == false) {
					perf = true;
					break;
				}
				else if (ranSkill1 == 13 && pers == false) {
					pers = true;
					break;
				}
				else if (ranSkill1 == 14 && reli == false) {
					reli = true;
					break;
				}
				else if (ranSkill1 == 15 && slei == false) {
					slei = true;
					break;
				}
				else if (ranSkill1 == 16 && stea == false) {
					stea = true;
					break;
				}
				else if (ranSkill1 == 17 && surv == false) {
					surv = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 18;
			}
			srand(time(0));
			ranSkill1 = (rand()) % 18;
			while (true) {
				if (ranSkill1 == 0 && acro == false) {
					acro = true;
					break;
				}
				else if (ranSkill1 == 1 && anim == false) {
					anim = true;
					break;
				}
				else if (ranSkill1 == 2 && arca == false) {
					arca = true;
					break;
				}
				else if (ranSkill1 == 3 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 4 && dece == false) {
					dece = true;
					break;
				}
				else if (ranSkill1 == 5 && hist == false) {
					hist = true;
					break;
				}
				else if (ranSkill1 == 6 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 7 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 8 && inve == false) {
					inve = true;
					break;
				}
				else if (ranSkill1 == 9 && medi == false) {
					medi = true;
					break;
				}
				else if (ranSkill1 == 10 && natu == false) {
					natu = true;
					break;
				}
				else if (ranSkill1 == 11 && perc == false) {
					perc = true;
					break;
				}
				else if (ranSkill1 == 12 && perf == false) {
					perf = true;
					break;
				}
				else if (ranSkill1 == 13 && pers == false) {
					pers = true;
					break;
				}
				else if (ranSkill1 == 14 && reli == false) {
					reli = true;
					break;
				}
				else if (ranSkill1 == 15 && slei == false) {
					slei = true;
					break;
				}
				else if (ranSkill1 == 16 && stea == false) {
					stea = true;
					break;
				}
				else if (ranSkill1 == 17 && surv == false) {
					surv = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 18;
			}
			srand(time(0));
			ranSkill1 = (rand()) % 18;
			while (true) {
				if (ranSkill1 == 0 && acro == false) {
					acro = true;
					break;
				}
				else if (ranSkill1 == 1 && anim == false) {
					anim = true;
					break;
				}
				else if (ranSkill1 == 2 && arca == false) {
					arca = true;
					break;
				}
				else if (ranSkill1 == 3 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 4 && dece == false) {
					dece = true;
					break;
				}
				else if (ranSkill1 == 5 && hist == false) {
					hist = true;
					break;
				}
				else if (ranSkill1 == 6 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 7 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 8 && inve == false) {
					inve = true;
					break;
				}
				else if (ranSkill1 == 9 && medi == false) {
					medi = true;
					break;
				}
				else if (ranSkill1 == 10 && natu == false) {
					natu = true;
					break;
				}
				else if (ranSkill1 == 11 && perc == false) {
					perc = true;
					break;
				}
				else if (ranSkill1 == 12 && perf == false) {
					perf = true;
					break;
				}
				else if (ranSkill1 == 13 && pers == false) {
					pers = true;
					break;
				}
				else if (ranSkill1 == 14 && reli == false) {
					reli = true;
					break;
				}
				else if (ranSkill1 == 15 && slei == false) {
					slei = true;
					break;
				}
				else if (ranSkill1 == 16 && stea == false) {
					stea = true;
					break;
				}
				else if (ranSkill1 == 17 && surv == false) {
					surv = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 18;
			}
			
			values.push_back(0);
			values.push_back(2);
			values.push_back(3);
			values.push_back(4);
			
			std::random_shuffle(values.begin(), values.end());
			for (int i = 0; i < 4; i++) {
				BiasArr[i + 2] = values[i];
			}
			
			for (int i = 0; i < 6; i++) {
				if (stats[i] != -1) {
					stats[BiasArr[i]] += StdArray[i];
				}
			}
			break;
		case 2: // Cleric
			ClassName="Cleric";
			
			wisS=true;
			chaS=true;
			
			BiasArr[0] = 4;
				switch (sub) {
				case 0:
					BiasArr[1] = 0;
					values.push_back(1);
					values.push_back(2);
					values.push_back(3);
					values.push_back(5);
					
					std::random_shuffle(values.begin(), values.end());
					for (int i = 0; i < 4; i++) {
						BiasArr[i + 2] = values[i];
					}
					
					for (int i = 0; i < 6; i++) {
						if (stats[i] != -1) {
							stats[BiasArr[i]] += StdArray[i];
						}
					}
					break;
				case 1:
					BiasArr[1] = 2;
					values.push_back(0);
					values.push_back(1);
					values.push_back(3);
					values.push_back(5);
					
					std::random_shuffle(values.begin(), values.end());
					for (int i = 0; i < 4; i++) {
						BiasArr[i + 2] = values[i];
					}
					
					for (int i = 0; i < 6; i++) {
						if (stats[i] != -1) {
							stats[BiasArr[i]] += StdArray[i];
						}
					}
					break;
				default:
					exit(-1);
					break;
				}
				srand(time(0));
			sClass = (rand()) % 7;
			switch (sClass) {
			case 0:
				SubClassName = "Knowledge";//prof is doubled
				srand(time(0));
					ranSkill1 = (rand()) % 4;
				while (true) {
					if (ranSkill1 == 0 && arca == false) {
						arca = true;
						break;
					}
					else if (ranSkill1 == 1 && hist == false) {
						hist = true;
						break;
					}
					else if (ranSkill1 == 2 && natu == false) {
						natu = true;
						break;
					}
					else if (ranSkill1 == 3 && reli == false) {
						reli = true;
						break;
					}
					srand(time(0));
					ranSkill1 = (rand()) % 4;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 4;
				while (true) {
					if (ranSkill1 == 0 && arca == false) {
						arca = true;
						break;
					}
					else if (ranSkill1 == 1 && hist == false) {
						hist = true;
						break;
					}
					else if (ranSkill1 == 2 && natu == false) {
						natu = true;
						break;
					}
					else if (ranSkill1 == 3 && reli == false) {
						reli = true;
						break;
					}
					srand(time(0));
					ranSkill1 = (rand()) % 4;
					break;
				}
				break;
			case 1:
				SubClassName = "Life";
					//heavy armor
					break;
			case 2:
				SubClassName = "Light";
					//light cantrip
					break;
			case 3:
				SubClassName = "Nature";
					ranSkill1 = (rand()) % 3;
				while (true) {
					if (ranSkill1 == 0 && anim == false) {
						anim = true;
						break;
					}
					else if (ranSkill1 == 1 && natu == false) {
						natu = true;
						break;
					}
					else if (ranSkill1 == 12 && surv == false) {
						surv = true;
						break;
					}
					srand(time(0));
					ranSkill1 = (rand()) % 3;
				}
				//heavy armor
				break;
			case 4:
				SubClassName = "Tempest";
					//Martial and heavy armor
					break;
			case 5:
				SubClassName = "Trickery";
					break;
			case 6:
				SubClassName = "War";
					//Martial and Heavy armor
					break;
			}
			ranSkill1 = (rand()) % 5;
			while (true) {
				if (ranSkill1 == 0 && hist == false) {
					hist = true;
					break;
				}
				else if (ranSkill1 == 1 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 2 && medi == false) {
					medi = true;
					break;
				}
				else if (ranSkill1 == 3 && pers == false) {
					pers = true;
					break;
				}
				else if (ranSkill1 == 4 && reli == false) {
					reli = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 5;
			}
			while (true) {
				if (ranSkill1 == 0 && hist == false) {
					hist = true;
					break;
				}
				else if (ranSkill1 == 1 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 2 && medi == false) {
					medi = true;
					break;
				}
				else if (ranSkill1 == 3 && pers == false) {
					pers = true;
					break;
				}
				else if (ranSkill1 == 4 && reli == false) {
					reli = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 5;
			}
			break;
		case 3: // Druid
			ClassName="Druid";
			BiasArr[0] = 4;
			BiasArr[1] = 2;
			
			intS=true;
			wisS=true;
			
			srand(time(0));
			ranSkill1 = (rand()) % 8;
			while (true) {
				if (ranSkill1 == 0 && anim == false) {
					anim = true;
					break;
				}
				else if (ranSkill1 == 1 && arca == false) {
					arca = true;
					break;
				}
				else if (ranSkill1 == 2 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 3 && medi == false) {
					medi = true;
					break;
				}
				else if (ranSkill1 == 4 && natu == false) {
					natu = true;
					break;
				}
				else if (ranSkill1 == 5 && perc == false) {
					perc = true;
					break;
				}
				else if (ranSkill1 == 6 && reli == false) {
					reli = true;
					break;
				}
				else if (ranSkill1 == 7 && surv == false) {
					surv = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 8;
			}
			while (true) {
				if (ranSkill1 == 0 && anim == false) {
					anim = true;
					break;
				}
				else if (ranSkill1 == 1 && arca == false) {
					arca = true;
					break;
				}
				else if (ranSkill1 == 2 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 3 && medi == false) {
					medi = true;
					break;
				}
				else if (ranSkill1 == 4 && natu == false) {
					natu = true;
					break;
				}
				else if (ranSkill1 == 5 && perc == false) {
					perc = true;
					break;
				}
				else if (ranSkill1 == 6 && reli == false) {
					reli = true;
					break;
				}
				else if (ranSkill1 == 7 && surv == false) {
					surv = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 8;
			}
			values.push_back(0);
			values.push_back(1);
			values.push_back(3);
			values.push_back(5);
			
			std::random_shuffle(values.begin(), values.end());
			for (int i = 0; i < 4; i++) {
				BiasArr[i + 2] = values[i];
			}
			
			for (int i = 0; i < 6; i++) {
				if (stats[i] != -1) {
					stats[BiasArr[i]] += StdArray[i];
				}
			}
			break;
		case 4: // Fighter
			ClassName="Fighter";
			
			strS=true;
			
			conS=true;
			
			
			BiasArr[1] = 2;
			switch (sub) {
			case 0:
				BiasArr[0] = 0;
				values.push_back(1);
				values.push_back(3);
				values.push_back(4);
				values.push_back(5);
				
				std::random_shuffle(values.begin(), values.end());
				for (int i = 0; i < 4; i++) {
					BiasArr[i + 2] = values[i];
				}
				
				for (int i = 0; i < 6; i++) {
					if (stats[i] != -1) {
						stats[BiasArr[i]] += StdArray[i];
					}
				}
				break;
			case 1:
				BiasArr[0] = 1;
				values.push_back(2);
				values.push_back(3);
				values.push_back(4);
				values.push_back(5);
				
				std::random_shuffle(values.begin(), values.end());
				for (int i = 0; i < 4; i++) {
					BiasArr[i + 2] = values[i];
				}
				
				for (int i = 0; i < 6; i++) {
					if (stats[i] != -1) {
						stats[BiasArr[i]] += StdArray[i];
					}
				}
				break;
			default:
				exit(-1);
			}
				srand(time(0));
				ranSkill1 = (rand()) % 8;
			while (true) {
				if (ranSkill1 == 0 && acro == false) {
					acro = true;
					break;
				}
				else if (ranSkill1 == 1 && anim == false) {
					anim = true;
					break;
				}
				else if (ranSkill1 == 2 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 3 && hist == false) {
					hist = true;
					break;
				}
				else if (ranSkill1 == 4 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 5 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 6 && perc == false) {
					perc = true;
					break;
				}
				else if (ranSkill1 == 7 && surv == false) {
					surv = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 8;
			}
			while (true) {
				if (ranSkill1 == 0 && acro == false) {
					acro = true;
					break;
				}
				else if (ranSkill1 == 1 && anim == false) {
					anim = true;
					break;
				}
				else if (ranSkill1 == 2 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 3 && hist == false) {
					hist = true;
					break;
				}
				else if (ranSkill1 == 4 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 5 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 6 && perc == false) {
					perc = true;
					break;
				}
				else if (ranSkill1 == 7 && surv == false) {
					surv = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 8;
			}
			break;
		case 5: // Monk
			ClassName="Monk";
			BiasArr[0] = 1;
			BiasArr[1] = 4;
			
			strS=true;
			dexS=true;
			
			values.push_back(0);
			values.push_back(2);
			values.push_back(3);
			values.push_back(5);
			
			std::random_shuffle(values.begin(), values.end());
			for (int i = 0; i < 4; i++) {
				BiasArr[i + 2] = values[i];
			}
			
			for (int i = 0; i < 6; i++) {
				if (stats[i] != -1) {
					stats[BiasArr[i]] += StdArray[i];
				}
			}
			srand(time(0));
			ranSkill1 = (rand()) % 6;
			while (true) {
				if (ranSkill1 == 0 && acro == false) {
					acro = true;
					break;
				}
				else if (ranSkill1 == 1 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 2 && hist == false) {
					hist = true;
					break;
				}
				else if (ranSkill1 == 3 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 4 && reli == false) {
					reli = true;
					break;
				}
				else if (ranSkill1 == 5 && stea == false) {
					stea = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 5;
			}
			while (true) {
				if (ranSkill1 == 0 && acro == false) {
					acro = true;
					break;
				}
				else if (ranSkill1 == 1 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 2 && hist == false) {
					hist = true;
					break;
				}
				else if (ranSkill1 == 3 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 4 && reli == false) {
					reli = true;
					break;
				}
				else if (ranSkill1 == 5 && stea == false) {
					stea = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 5;
			}
			break;
		case 6: // Paladin
			ClassName="Paladin";
			BiasArr[0] = 0;
			BiasArr[1] = 5;
			
			wisS=true;
			chaS=true;
			
			values.push_back(1);
			values.push_back(2);
			values.push_back(3);
			values.push_back(4);
			
			std::random_shuffle(values.begin(), values.end());
			for (int i = 0; i < 4; i++) {
				BiasArr[i + 2] = values[i];
			}
			
			for (int i = 0; i < 6; i++) {
				if (stats[i] != -1) {
					stats[BiasArr[i]] += StdArray[i];
				}
			}
			srand(time(0));
			ranSkill1 = (rand()) % 6;
			while (true) {
				if (ranSkill1 == 0 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 1 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 2 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 3 && medi == false) {
					medi = true;
					break;
				}
				else if (ranSkill1 == 4 && pers == false) {
					pers = true;
					break;
				}
				else if (ranSkill1 == 5 && reli == false) {
					reli = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 6;
			}
			while (true) {
				if (ranSkill1 == 0 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 1 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 2 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 3 && medi == false) {
					medi = true;
					break;
				}
				else if (ranSkill1 == 4 && pers == false) {
					pers = true;
					break;
				}
				else if (ranSkill1 == 5 && reli == false) {
					reli = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 6;
			}
			break;
		case 7: // Ranger
			ClassName="Ranger";
			BiasArr[0] = 1;
			BiasArr[1] = 4;
			
			strS=true;
			dexS=true;
			
			values.push_back(0);
			values.push_back(2);
			values.push_back(3);
			values.push_back(5);
			
			std::random_shuffle(values.begin(), values.end());
			for (int i = 0; i < 4; i++) {
				BiasArr[i + 2] = values[i];
			}
			
			for (int i = 0; i < 6; i++) {
				if (stats[i] != -1) {
					stats[BiasArr[i]] += StdArray[i];
				}
			}
			srand(time(0));
			ranSkill1 = (rand()) % 9;
			while (true) {
				if (ranSkill1 == 0 && anim == false) {
					anim = true;
					break;
				}
				else if (ranSkill1 == 1 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 2 && dece == false) {
					dece = true;
					break;
				}
				else if (ranSkill1 == 3 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 4 && inve == false) {
					inve = true;
					break;
				}
				else if (ranSkill1 == 5 && natu == false) {
					natu = true;
					break;
				}
				else if (ranSkill1 == 6 && perc == false) {
					perc = true;
					break;
				}
				else if (ranSkill1 == 7 && stea == false) {
					stea = true;
					break;
				}
				else if (ranSkill1 == 8 && surv == false) {
					surv = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 9;
			}
			while (true) {
				if (ranSkill1 == 0 && anim == false) {
					anim = true;
					break;
				}
				else if (ranSkill1 == 1 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 2 && dece == false) {
					dece = true;
					break;
				}
				else if (ranSkill1 == 3 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 4 && inve == false) {
					inve = true;
					break;
				}
				else if (ranSkill1 == 5 && natu == false) {
					natu = true;
					break;
				}
				else if (ranSkill1 == 6 && perc == false) {
					perc = true;
					break;
				}
				else if (ranSkill1 == 7 && stea == false) {
					stea = true;
					break;
				}
				else if (ranSkill1 == 8 && surv == false) {
					surv = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 9;
			}
			while (true) {
				if (ranSkill1 == 0 && anim == false) {
					anim = true;
					break;
				}
				else if (ranSkill1 == 1 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 2 && dece == false) {
					dece = true;
					break;
				}
				else if (ranSkill1 == 3 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 4 && inve == false) {
					inve = true;
					break;
				}
				else if (ranSkill1 == 5 && natu == false) {
					natu = true;
					break;
				}
				else if (ranSkill1 == 6 && perc == false) {
					perc = true;
					break;
				}
				else if (ranSkill1 == 7 && stea == false) {
					stea = true;
					break;
				}
				else if (ranSkill1 == 8 && surv == false) {
					surv = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 9;
			}
			break;
		case 8: // Rogue
			ClassName="Rogue";
			
			dexS=true;
			intS=true;
			
			BiasArr[0] = 1;
				switch (sub) {
				case 0:
					BiasArr[1] = 3;
					
					values.push_back(0);
					values.push_back(2);
					values.push_back(4);
					values.push_back(5);
					
					std::random_shuffle(values.begin(), values.end());
					for (int i = 0; i < 4; i++) {
						BiasArr[i + 2] = values[i];
					}
					
					for (int i = 0; i < 6; i++) {
						if (stats[i] != -1) {
							stats[BiasArr[i]] += StdArray[i];
						}
					}
					break;
				case 1:
					BiasArr[1] = 5;
					
					values.push_back(0);
					values.push_back(2);
					values.push_back(3);
					values.push_back(4);
					values.push_back(-1);
					std::random_shuffle(values.begin(), values.end());
					for (int i = 0; i < 5; i++) {
						BiasArr[i + 2] = values[i];
					}
					
					for (int i = 0; i < 6; i++) {
						if (stats[i] != -1) {
							stats[BiasArr[i]] += StdArray[i];
						}
					}
					break;
				default:
					exit(-1);
					break;
				}
				srand(time(0));
			ranSkill1 = (rand()) % 11;//rogue 4
			while (true) {
				if (ranSkill1 == 0 && acro == false) {
					acro = true;
					break;
				}
				else if (ranSkill1 == 1 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 2 && dece == false) {
					dece = true;
					break;
				}
				else if (ranSkill1 == 3 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 4 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 5 && inve == false) {
					inve = true;
					break;
				}
				else if (ranSkill1 == 6 && perc == false) {
					perc = true;
					break;
				}
				else if (ranSkill1 == 7 && perf == false) {
					perf = true;
					break;
				}
				else if (ranSkill1 == 8 && pers == false) {
					pers = true;
					break;
				}
				else if (ranSkill1 == 9 && slei == false) {
					slei = true;
					break;
				}
				else if (ranSkill1 == 10 && stea == false) {
					stea = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 11;
			}
			while (true) {
				if (ranSkill1 == 0 && acro == false) {
					acro = true;
					break;
				}
				else if (ranSkill1 == 1 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 2 && dece == false) {
					dece = true;
					break;
				}
				else if (ranSkill1 == 3 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 4 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 5 && inve == false) {
					inve = true;
					break;
				}
				else if (ranSkill1 == 6 && perc == false) {
					perc = true;
					break;
				}
				else if (ranSkill1 == 7 && perf == false) {
					perf = true;
					break;
				}
				else if (ranSkill1 == 8 && pers == false) {
					pers = true;
					break;
				}
				else if (ranSkill1 == 9 && slei == false) {
					slei = true;
					break;
				}
				else if (ranSkill1 == 10 && stea == false) {
					stea = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 11;
			}
			while (true) {
				if (ranSkill1 == 0 && acro == false) {
					acro = true;
					break;
				}
				else if (ranSkill1 == 1 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 2 && dece == false) {
					dece = true;
					break;
				}
				else if (ranSkill1 == 3 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 4 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 5 && inve == false) {
					inve = true;
					break;
				}
				else if (ranSkill1 == 6 && perc == false) {
					perc = true;
					break;
				}
				else if (ranSkill1 == 7 && perf == false) {
					perf = true;
					break;
				}
				else if (ranSkill1 == 8 && pers == false) {
					pers = true;
					break;
				}
				else if (ranSkill1 == 9 && slei == false) {
					slei = true;
					break;
				}
				else if (ranSkill1 == 10 && stea == false) {
					stea = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 11;
			}
			while (true) {
				if (ranSkill1 == 0 && acro == false) {
					acro = true;
					break;
				}
				else if (ranSkill1 == 1 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 2 && dece == false) {
					dece = true;
					break;
				}
				else if (ranSkill1 == 3 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 4 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 5 && inve == false) {
					inve = true;
					break;
				}
				else if (ranSkill1 == 6 && perc == false) {
					perc = true;
					break;
				}
				else if (ranSkill1 == 7 && perf == false) {
					perf = true;
					break;
				}
				else if (ranSkill1 == 8 && pers == false) {
					pers = true;
					break;
				}
				else if (ranSkill1 == 9 && slei == false) {
					slei = true;
					break;
				}
				else if (ranSkill1 == 10 && stea == false) {
					stea = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 11;
			}
			break;
		case 9: // Sorcerer
			ClassName="Sorcerer";
			BiasArr[0] = 5;
			BiasArr[1] = 2;

			conS=true;
			chaS=true;
			
			values.push_back(0);
			values.push_back(1);
			values.push_back(3);
			values.push_back(4);
		
			std::random_shuffle(values.begin(), values.end());
			for (int i = 0; i < 4; i++) {
				BiasArr[i + 2] = values[i];
			}
			
			for (int i = 0; i < 6; i++) {
				if (stats[i] != -1) {
					stats[BiasArr[i]] += StdArray[i];
				}
			}
			srand(time(0));
			sClass = (rand()) % 2;
			switch (sClass) {
			case 0:
				SubClassName = "Draconic";
				break;
			case 1:
				SubClassName = "Wild Magic";
					
				break;
			}
			srand(time(0));
			ranSkill1 = (rand()) % 6;//sorc 2
			while (true) {
				if (ranSkill1 == 0 && arca == false) {
					arca = true;
					break;
				}
				else if (ranSkill1 == 1 && dece == false) {
					dece = true;
					break;
				}
				else if (ranSkill1 == 2 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 3 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 4 && pers == false) {
					pers = true;
					break;
				}
				else if (ranSkill1 == 5 && reli == false) {
					reli = true;
					break;
				}
				ranSkill1 = (rand()) % 6;
			}
			while (true) {
				if (ranSkill1 == 0 && arca == false) {
					arca = true;
					break;
				}
				else if (ranSkill1 == 1 && dece == false) {
					dece = true;
					break;
				}
				else if (ranSkill1 == 2 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 3 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 4 && pers == false) {
					pers = true;
					break;
				}
				else if (ranSkill1 == 5 && reli == false) {
					reli = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 6;
			}
			break;
		case 10: // Warlock
			ClassName="Warlock";
			BiasArr[0] = 5;
			BiasArr[1] = 2;
			
			wisS=true;
			chaS=true;
			
			values.push_back(0);
			values.push_back(1);
			values.push_back(3);
			values.push_back(4);

			std::random_shuffle(values.begin(), values.end());
			for (int i = 0; i < 4; i++) {
				BiasArr[i + 2] = values[i];
			}
			
			for (int i = 0; i < 6; i++) {
				if (stats[i] != -1) {
					stats[BiasArr[i]] += StdArray[i];
				}
			}
			srand(time(0));
			sClass = (rand()) % 3;
			switch (sClass) {
			case 0:
				SubClassName = "Pact of the Archfey";
				break;
			case 1:
				SubClassName = "Pact of the Fiend";
					
				break;
				
			case 2:
				SubClassName = "Pact of the Great Old One";
					
				break;
			}
			srand(time(0));
			ranSkill1 = (rand()) % 7;//Warl 2
			while (true) {
				if (ranSkill1 == 0 && arca == false) {
					arca = true;
					break;
				}
				else if (ranSkill1 == 1 && dece == false) {
					dece = true;
					break;
				}
				else if (ranSkill1 == 2 && hist == false) {
					hist = true;
					break;
				}
				else if (ranSkill1 == 3 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 4 && inve == false) {
					inve = true;
					break;
				}
				else if (ranSkill1 == 5 && natu == false) {
					natu = true;
					break;
				}
				else if (ranSkill1 == 6 && reli == false) {
					reli = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 7;
			}
			while (true) {
				if (ranSkill1 == 0 && arca == false) {
					arca = true;
					break;
				}
				else if (ranSkill1 == 1 && dece == false) {
					dece = true;
					break;
				}
				else if (ranSkill1 == 2 && hist == false) {
					hist = true;
					break;
				}
				else if (ranSkill1 == 3 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 4 && inve == false) {
					inve = true;
					break;
				}
				else if (ranSkill1 == 5 && natu == false) {
					natu = true;
					break;
				}
				else if (ranSkill1 == 6 && reli == false) {
					reli = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 7;
			}
			break;
		case 11: // Wizard
			ClassName="Wizard";
			
			intS=true;
			wisS=true;
			
			BiasArr[0] = 3;
				switch (sub) {
				case 0:
					BiasArr[1] = 1;
					values.push_back(0);
					values.push_back(2);
					values.push_back(4);
					values.push_back(5);
					//values.push_back(-1);
					std::random_shuffle(values.begin(), values.end());
					for (int i = 0; i < 4; i++) {
						BiasArr[i + 2] = values[i];
					}
					
					for (int i = 0; i < 6; i++) {
						if (stats[i] != -1) {
							stats[BiasArr[i]] += StdArray[i];
						}
					}
					break;
				case 1:
					BiasArr[1] = 2;
					
					values.push_back(0);
					values.push_back(1);
					values.push_back(4);
					values.push_back(5);
					
					std::random_shuffle(values.begin(), values.end());
					for (int i = 0; i < 4; i++) {
						BiasArr[i + 2] = values[i];
					}
					
					for (int i = 0; i < 6; i++) {
						if (stats[i] != -1) {
							stats[BiasArr[i]] += StdArray[i];
						}
					}
					break;
				default:
					exit(-1);
					break;
				}
			srand(time(0));
			ranSkill1 = (rand()) % 6;//Wizlord 2
			while (true) {
				if (ranSkill1 == 0 && arca == false) {
					arca = true;
					break;
				}
				else if (ranSkill1 == 1 && hist == false) {
					hist = true;
					break;
				}
				else if (ranSkill1 == 2 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 3 && inve == false) {
					inve = true;
					break;
				}
				else if (ranSkill1 == 4 && medi == false) {
					medi = true;
					break;
				}
				else if (ranSkill1 == 5 && reli == false) {
					reli = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 6;
			}	
			while (true) {
				if (ranSkill1 == 0 && arca == false) {
					arca = true;
					break;
				}
				else if (ranSkill1 == 1 && hist == false) {
					hist = true;
					break;
				}
				else if (ranSkill1 == 2 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 3 && inve == false) {
					inve = true;
					break;
				}
				else if (ranSkill1 == 4 && medi == false) {
					medi = true;
					break;
				}
				else if (ranSkill1 == 5 && reli == false) {
					reli = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 6;
			}
			break;
		default:
			exit(-1);
			break;
		}
		if (this->RaceName == "Half-Elf") {
			srand(time(0));
			ranSkill1 = (rand()) % 18;
			while (true) {
				if (ranSkill1 == 0 && acro == false) {
					acro = true;
					break;
				}
				else if (ranSkill1 == 1 && anim == false) {
					anim = true;
					break;
				}
				else if (ranSkill1 == 2 && arca == false) {
					arca = true;
					break;
				}
				else if (ranSkill1 == 3 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 4 && dece == false) {
					dece = true;
					break;
				}
				else if (ranSkill1 == 5 && hist == false) {
					hist = true;
					break;
				}
				else if (ranSkill1 == 6 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 7 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 8 && inve == false) {
					inve = true;
					break;
				}
				else if (ranSkill1 == 9 && medi == false) {
					medi = true;
					break;
				}
				else if (ranSkill1 == 10 && natu == false) {
					natu = true;
					break;
				}
				else if (ranSkill1 == 11 && perc == false) {
					perc = true;
					break;
				}
				else if (ranSkill1 == 12 && perf == false) {
					perf = true;
					break;
				}
				else if (ranSkill1 == 13 && pers == false) {
					pers = true;
					break;
				}
				else if (ranSkill1 == 14 && reli == false) {
					reli = true;
					break;
				}
				else if (ranSkill1 == 15 && slei == false) {
					slei = true;
					break;
				}
				else if (ranSkill1 == 16 && stea == false) {
					stea = true;
					break;
				}
				else if (ranSkill1 == 17 && surv == false) {
					surv = true;
					break;
				}
				srand(time(0));
				ranSkill1 = (rand()) % 18;
			}
			srand(time(0));
			ranSkill1 = (rand()) % 18;
			while (true) {
				if (ranSkill1 == 0 && acro == false) {
					acro = true;
					break;
				}
				else if (ranSkill1 == 1 && anim == false) {
					anim = true;
					break;
				}
				else if (ranSkill1 == 2 && arca == false) {
					arca = true;
					break;
				}
				else if (ranSkill1 == 3 && athl == false) {
					athl = true;
					break;
				}
				else if (ranSkill1 == 4 && dece == false) {
					dece = true;
					break;
				}
				else if (ranSkill1 == 5 && hist == false) {
					hist = true;
					break;
				}
				else if (ranSkill1 == 6 && insi == false) {
					insi = true;
					break;
				}
				else if (ranSkill1 == 7 && inti == false) {
					inti = true;
					break;
				}
				else if (ranSkill1 == 8 && inve == false) {
					inve = true;
					break;
				}
				else if (ranSkill1 == 9 && medi == false) {
					medi = true;
					break;
				}
				else if (ranSkill1 == 10 && natu == false) {
					natu = true;
					break;
				}
				else if (ranSkill1 == 11 && perc == false) {
					perc = true;
					break;
				}
				else if (ranSkill1 == 12 && perf == false) {
					perf = true;
					break;
				}
				else if (ranSkill1 == 13 && pers == false) {
					pers = true;
					break;
				}
				else if (ranSkill1 == 14 && reli == false) {
					reli = true;
					break;
				}
				else if (ranSkill1 == 15 && slei == false) {
					slei = true;
					break;
				}
				else if (ranSkill1 == 16 && stea == false) {
					stea = true;
					break;
				}
				else if (ranSkill1 == 17 && surv == false) {
					surv = true;
					break;
				}
				ranSkill1 = (rand()) % 18;
			}
		}
	}
	void genGold() {
		srand(time(0));
		if (this->ClassName == "Barbarian")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this->ClassName == "Bard")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this->ClassName == "Cleric")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this->ClassName == "Druid")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this->ClassName == "Fighter")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this->ClassName == "Monk")
			gold = ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4) + 1;
		if (this->ClassName == "Paladin")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this->ClassName == "Ranger")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this->ClassName == "Rogue")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this->ClassName == "Sorcerer")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this->ClassName == "Warlock")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this->ClassName == "Wizard")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;	
	}
	void genMod() {
		for (int i = 0; i < 6; i++) {
			if (stats[i] <= 9) {
				mods[i] = (stats[i]-11)/2;
			}
			else {
				mods[i] = (stats[i]-10)/2;
			}
		}
	}
	void genHP() {
		if (ClassName == "Barbarian") {
			HitPoints += 12;
		}
		if (ClassName == "Bard") {
			HitPoints += 8;
		}
		if (ClassName == "Cleric") {
			HitPoints += 8;
		}
		if (ClassName == "Druid") {
			HitPoints += 8;
		}
		if (ClassName == "Fighter") {
			HitPoints += 10;
		}
		if (ClassName == "Monk") {
			HitPoints += 8;
		}
		if (ClassName == "Paladin") {
			HitPoints += 10;
		}
		if (ClassName == "Ranger") {
			HitPoints += 10;
		}
		if (ClassName == "Rogue") {
			HitPoints += 8;
		}
		if (ClassName == "Sorcerer") {
			HitPoints += 6;
		}
		if (ClassName == "Wizard") {
			HitPoints += 6;
		}
		if (ClassName == "Warlock") {
			HitPoints += 8;
		}
		HitPoints += mods[2];
		if (SubRaceName == "Hill Dwarf") {
			HitPoints += 1;
		}

	}
	std::string getRaceName() {
		return this->RaceName;
	}
	std::string getSubRaceName() {
		return this->SubRaceName;
	}
	std::string getClassName() {
		return this->ClassName;
	}
	std::string getSubClassName() {
		return this->SubClassName;
	}
	std::string getBGName() {
		return this->BGName;
	}
	int getGold() {
		return this->gold;
	}
	void setRaceName(std::string s) {
		this->RaceName = s;
	}
	void setSubRaceName(std::string s) {
		this->SubRaceName = s;
	}
	void setClassName(std::string s) {
		this->ClassName = s;
	}
	void setSubClassName(std::string s) {
		this->SubClassName = s;
	}
	void setBGName(std::string s) {
		this->BGName = s;
	}
	void printCharacter() {
		std::cout << "Race: " << RaceName << std::endl;
		if(SubRaceName!="NONE"){
			std::cout<< "Sub-Race: " << SubRaceName << std::endl;
		}
		std::cout<<"\nClass: " << ClassName<<std::endl;
		if(SubClassName!="NONE"){
			std::cout<< "Subclass: " << SubClassName << std::endl;
		}
		std::cout << "\nBackground: " << BGName << "\n\nGold:" << gold <<
			"\n\nSTR:" << stats[0] << " , Bonus: " << mods[0] << "\nDEX:" << stats[1] << " , Bonus: " << mods[1] << "\nCON:" << stats[2]
			<< " , Bonus: " << mods[2] << "\nINT:" << stats[3] << " , Bonus: " << mods[3] << "\nWIS:" << stats[4] << " , Bonus: "
			<< mods[4] << "\nCHA:" << stats[5] << " , Bonus: " << mods[5] << "\n\nHit Points: " << HitPoints << std::endl;
		
		
		std::cout << "\nInitiative: " << mods[1]<< std::endl;
		
		std::cout << "\nSaving Throws:" << std::endl;
		if (strS) {
			std::cout << "Strength"  << std::endl;
		}
		if (dexS) {
			std::cout << "Dexterity"  << std::endl;
		}
		if (conS) {
			std::cout << "Constitution"  << std::endl;
		}
		if (intS) {
			std::cout << "Intelligence"  << std::endl;
		}
		if (wisS) {
			std::cout << "Wisdom"  << std::endl;
		}
		if (chaS) {
			std::cout << "Charisma"  << std::endl;
		}
		
		
		std::cout << "\nSkill Proficiencies:" << std::endl;;
		if (acro) {
			std::cout << "Acrobatics"  << std::endl;
		}
		if (anim) {
			std::cout << "Animal Handling"  << std::endl;
		}
		if (arca) {
			std::cout << "Arcana"  << std::endl;
		}
		if (athl) {
			std::cout << "Athletics"  << std::endl;
		}
		if (dece) {
			std::cout << "Deception"  << std::endl;
		}
		if (hist) {
			std::cout << "History"  << std::endl;
		}
		if (insi) {
			std::cout << "Insight"  << std::endl;
		}
		if (inti) {
			std::cout << "Intimidation"  << std::endl;
		}
		if (inve) {
			std::cout << "Investigation"  << std::endl;
		}
		if (medi) {
			std::cout << "Medicine"  << std::endl;
		}
		if (natu) {
			std::cout << "Nature"  << std::endl;
		}
		if (perc) {
			std::cout << "Perception"  << std::endl;
		}
		if (perf) {
			std::cout << "Performance"  << std::endl;
		}
		if (pers) {
			std::cout << "Persuasion"  << std::endl;
		}
		if (reli) {
			std::cout << "Religion"  << std::endl;
		}
		if (slei) {
			std::cout << "Sleight of Hand"  << std::endl;
		}
		if (stea) {
			std::cout << "Stealth"  << std::endl;
		}
		if (surv) {
			std::cout << "Survival"  << std::endl;
		}
	}
};

#endif