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
	int gold = 0;
	int stats[6] = [0, 0, 0, 0, 0, 0];
	int mods[6] = [0, 0, 0, 0, 0, 0];
	int BiasArr[6] = [-1, -1, -1, -1, -1, -1];
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
public:
	Character() {
		genRace();
		genBG();
		genClass();
		genGold();
	}

	void genRace() {
		int first = (rand()) % 9;
		switch (first) {
		case 0:
			setRaceName("Dragonborn");
			//stats[0] += 2;
			//stats[5] += 1;
			break;
		case 1:
			setRaceName("Dwarf");
			int second = (rand()) % 2;
			switch (second) {
			case 0:
				setSubRaceName("Mountain Dwarf");
			//	stats[0] += 2;
			//	stats[2] += 2;
				break;
			case 1:
				setSubRaceName("Hill Dwarf");
			//	stats[2] += 2;
			//	stats[4] += 1;
				break;
			}
			break;
		case 2:
			setRaceName("Elf");
			//stats[1] += 2;
			//perc = true;
			int second = (rand()) % 3;
			switch (second) {
			case 0:
				setSubRaceName("High Elf");
			//	stats[3] += 1;
				break;
			case 1:
				setSubRaceName("Wood Elf");
			//	stats[4] += 1;
				break;
			case 2:
				setSubRaceName("Dark Elf");
			//	stats[5] += 1;
				break;
			}
			break;
		case 3:
			setRaceName("Gnome");
			//stats[3] += 2;
			int second = (rand()) % 2;
			switch (second) {
			case 0:
				setSubRaceName("Forest Gnome");
			//	stats[1] += 1;
				break;
			case 1:
				setSubRaceName("Rock Gnome");
			//	stats[2] += 1;
				break;
			}
			break;
		case 4:
			setRaceName("Half-Elf");
			/*stats[5] += 2;
			int choose1 = (rand()) % 5;
			stats[choose1] += 1;
			int choose2 = (rand()) % 5;
			if (choose2 == choose1) {
				choose2 = (choose2 + 1) % 5;
			}
			stats[choose2] += 1;*/
			// half elf skill proficiencies happen after classes
			break;
		case 5:
			setRaceName("Halfling");
			//stats[1] += 1;
			int second = (rand()) % 2;
			switch (second) {
			case 0:
				setSubRaceName("Lightfoot Halfling");
			//	stats[5] += 1;
				break;
			case 1:
				setSubRaceName("Stout Halfling");
			//	stats[2] += 1;
				break;
			}
			break;
		case 6:
			setRaceName("Half-Orc");
			//stats[0] += 2;
			//stats[2] += 1;
			//inti = true;
			break;
		case 7:
			setRaceName("Human");
			/*stats[0] += 1;
			stats[1] += 1;
			stats[2] += 1;
			stats[3] += 1;
			stats[4] += 1;
			stats[5] += 1;*/
			break;
		case 8:
			setRaceName("Tiefling");
			/*stats[3] += 1;
			stats[5] += 2;*/
			break;
		default:
			exit(-1);
			break;
		}
	}

	void genBG() {
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

	void genClass() {
		int ranSkill1;
		int choice = (rand()) % 12;
		int sub = (rand()) % 2;
		int sClass;
		switch (choice) {
		case 0: // Barbarian
			BiasArr[0] = 0;
			BiasArr[1] = 2;
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
				ranSkill1 = (rand()) % 6;
			}
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
				ranSkill1 = (rand()) % 6;
			}
			std::vector<int> values;
			values.push_back(1);
			values.push_back(3);
			value.push_back(4);
			value.push_back(5);
			value.push_back(-1);
			value.random_shuffle(value.begin, value.end);
			for (int i = 0; i < 5; i++) {
				BiasArr[i + 2] = value[i];
			}
			int StdArray[6] = [15, 14, 13, 12, 10, 8];
			for (int i = 0; i < 6; i++) {
				if (stats[i] != -1) {
					stats[i] = StdArray[BiasArr[i]];
				}
			}
			break;
		case 1: // Bard
			BiasArr[0] = 5;
			BiasArr[1] = 1;
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
			std::vector<int> values;
			values.push_back(0);
			values.push_back(2);
			value.push_back(3);
			value.push_back(4);
			value.push_back(-1);
			value.random_shuffle(value.begin, value.end);
			for (int i = 0; i < 5; i++) {
				BiasArr[i + 2] = value[i];
			}
			int StdArray[6] = [15, 14, 13, 12, 10, 8];
			for (int i = 0; i < 6; i++) {
				if (stats[i] != -1) {
					stats[i] = StdArray[BiasArr[i]];
				}
			}
			break;
		case 2: // Cleric
			BiasArr[0] = 4
				switch (sub) {
				case 0:
					BiasArr[1] = 0;
					std::vector<int> values;
					values.push_back(1);
					values.push_back(2);
					value.push_back(3);
					value.push_back(5);
					value.push_back(-1);
					value.random_shuffle(value.begin, value.end);
					for (int i = 0; i < 5; i++) {
						BiasArr[i + 2] = value[i];
					}
					int StdArray[6] = [15, 14, 13, 12, 10, 8];
					for (int i = 0; i < 6; i++) {
						if (stats[i] != -1) {
							stats[i] = StdArray[BiasArr[i]];
						}
					}
					break;
				case 1:
					BiasArr[1] = 2;
					std::vector<int> values;
					values.push_back(0);
					values.push_back(1);
					value.push_back(3);
					value.push_back(5);
					value.push_back(-1);
					value.random_shuffle(value.begin, value.end);
					for (int i = 0; i < 5; i++) {
						BiasArr[i + 2] = value[i];
					}
					int StdArray[6] = [15, 14, 13, 12, 10, 8];
					for (int i = 0; i < 6; i++) {
						if (stats[i] != -1) {
							stats[i] = StdArray[BiasArr[i]];
						}
					}
					break;
				default:
					exit(-1);
					break;
				}
			sClass = (rand()) % 7;
			switch (sClass) {
			case 0:
				SubClassName = "Knowledge"//prof is doubled
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
					ranSkill1 = (rand()) % 4;
				}
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
					ranSkill1 = (rand()) % 4;
					break;
				}
				break;
			case 1:
				SubClassName = "Life"
					//heavy armor
					break;
			case 2:
				SubClassName = "Light"
					//light cantrip
					break;
			case 3:
				SubClassName = "Nature"
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
					ranSkill1 = (rand()) % 3;
				}
				//heavy armor
				break;
			case 4:
				SubClassName = "Tempest"
					//Martial and heavy armor
					break;
			case 5:
				SubClassName = "Trickery"
					break;
			case 6:
				SubClassName = "War"
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
				ranSkill1 = (rand()) % 5;
			}
			break;
		case 3: // Druid
			BiasArr[0] = 4;
			BiasArr[1] = 2;

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
				ranSkill1 = (rand()) % 8;
			}
			std::vector<int> values;
			values.push_back(0);
			values.push_back(1);
			value.push_back(3);
			value.push_back(5);
			value.push_back(-1);
			value.random_shuffle(value.begin, value.end);
			for (int i = 0; i < 5; i++) {
				BiasArr[i + 2] = value[i];
			}
			int StdArray[6] = [15, 14, 13, 12, 10, 8];
			for (int i = 0; i < 6; i++) {
				if (stats[i] != -1) {
					stats[i] = StdArray[BiasArr[i]];
				}
			}
			break;
		case 4: // Fighter
			BiasArr[1] = 2
			switch (sub) {
			case 0:
				BiasArr[0] = 0;
				std::vector<int> values;
				values.push_back(1);
				values.push_back(3);
				value.push_back(4);
				value.push_back(5);
				value.push_back(-1);
				value.random_shuffle(value.begin, value.end);
				for (int i = 0; i < 5; i++) {
					BiasArr[i + 2] = value[i];
				}
				int StdArray[6] = [15, 14, 13, 12, 10, 8];
				for (int i = 0; i < 6; i++) {
					if (stats[i] != -1) {
						stats[i] = StdArray[BiasArr[i]];
					}
				}
				break;
			case 1:
				BiasArr[0] = 1;
				std::vector<int> values;
				values.push_back(2);
				values.push_back(3);
				value.push_back(4);
				value.push_back(5);
				value.push_back(-1);
				value.random_shuffle(value.begin, value.end);
				for (int i = 0; i < 5; i++) {
					BiasArr[i + 2] = value[i];
				}
				int StdArray[6] = [15, 14, 13, 12, 10, 8];
				for (int i = 0; i < 6; i++) {
					if (stats[i] != -1) {
						stats[i] = StdArray[BiasArr[i]];
					}
				}
				break;
			default:
				exit(-1);
			}

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
				ranSkill1 = (rand()) % 8;
			}
			break;
		case 5: // Monk
			BiasArr[0] = 1;
			BiasArr[1] = 4;
			std::vector<int> values;
			values.push_back(0);
			values.push_back(2);
			value.push_back(3);
			value.push_back(5);
			value.push_back(-1);
			value.random_shuffle(value.begin, value.end);
			for (int i = 0; i < 5; i++) {
				BiasArr[i + 2] = value[i];
			}
			int StdArray[6] = [15, 14, 13, 12, 10, 8];
			for (int i = 0; i < 6; i++) {
				if (stats[i] != -1) {
					stats[i] = StdArray[BiasArr[i]];
				}
			}
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
				ranSkill1 = (rand()) % 5;
			}
			break;
		case 6: // Paladin
			BiasArr[0] = 0;
			BiasArr[1] = 5;
			std::vector<int> values;
			values.push_back(1);
			values.push_back(2);
			value.push_back(3);
			value.push_back(4);
			value.push_back(-1);
			value.random_shuffle(value.begin, value.end);
			for (int i = 0; i < 5; i++) {
				BiasArr[i + 2] = value[i];
			}
			int StdArray[6] = [15, 14, 13, 12, 10, 8];
			for (int i = 0; i < 6; i++) {
				if (stats[i] != -1) {
					stats[i] = StdArray[BiasArr[i]];
				}
			}

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
				ranSkill1 = (rand()) % 6;
			}
			break;
		case 7: // Ranger
			BiasArr[0] = 1;
			BiasArr[1] = 4;
			std::vector<int> values;
			values.push_back(0);
			values.push_back(2);
			value.push_back(3);
			value.push_back(5);
			value.push_back(-1);
			value.random_shuffle(value.begin, value.end);
			for (int i = 0; i < 5; i++) {
				BiasArr[i + 2] = value[i];
			}
			int StdArray[6] = [15, 14, 13, 12, 10, 8];
			for (int i = 0; i < 6; i++) {
				if (stats[i] != -1) {
					stats[i] = StdArray[BiasArr[i]];
				}
			}
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
				ranSkill1 = (rand()) % 9;
			}
			break;
		case 8: // Rogue
			BiasArr[0] = 1
				switch (sub) {
				case 0:
					BiasArr[1] = 3;
					std::vector<int> values;
					values.push_back(0);
					values.push_back(2);
					value.push_back(4);
					value.push_back(5);
					value.push_back(-1);
					value.random_shuffle(value.begin, value.end);
					for (int i = 0; i < 5; i++) {
						BiasArr[i + 2] = value[i];
					}
					int StdArray[6] = [15, 14, 13, 12, 10, 8];
					for (int i = 0; i < 6; i++) {
						if (stats[i] != -1) {
							stats[i] = StdArray[BiasArr[i]];
						}
					}
					break;
				case 1:
					BiasArr[1] = 5;
					std::vector<int> values;
					values.push_back(0);
					values.push_back(2);
					value.push_back(3);
					value.push_back(4);
					value.push_back(-1);
					value.random_shuffle(value.begin, value.end);
					for (int i = 0; i < 5; i++) {
						BiasArr[i + 2] = value[i];
					}
					int StdArray[6] = [15, 14, 13, 12, 10, 8];
					for (int i = 0; i < 6; i++) {
						if (stats[i] != -1) {
							stats[i] = StdArray[BiasArr[i]];
						}
					}
					break;
				default:
					exit(-1);
					break;
				}
				
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
				ranSkill1 = (rand()) % 11;
			}
			break;
		case 9: // Sorcerer
			BiasArr[0] = 5;
			BiasArr[1] = 2;
			std::vector<int> values;
			values.push_back(0);
			values.push_back(1);
			value.push_back(3);
			value.push_back(4);
			value.push_back(-1);
			value.random_shuffle(value.begin, value.end);
			for (int i = 0; i < 5; i++) {
				BiasArr[i + 2] = value[i];
			}
			int StdArray[6] = [15, 14, 13, 12, 10, 8];
			for (int i = 0; i < 6; i++) {
				if (stats[i] != -1) {
					stats[i] = StdArray[BiasArr[i]];
				}
			}
			sClass = (rand()) % 2;
			switch (sClass) {
			case 0:
				SubClassName = "Draconic"
				break;
			case 1:
				SubClassName = "Wild Magic"
					
				break;
			}
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
				ranSkill1 = (rand()) % 6;
			}
			break;
		case 10: // Warlock
			BiasArr[0] = 5;
			BiasArr[1] = 2;
			std::vector<int> values;
			values.push_back(0);
			values.push_back(1);
			value.push_back(3);
			value.push_back(4);
			value.push_back(-1);
			value.random_shuffle(value.begin, value.end);
			for (int i = 0; i < 5; i++) {
				BiasArr[i + 2] = value[i];
			}
			int StdArray[6] = [15, 14, 13, 12, 10, 8];
			for (int i = 0; i < 6; i++) {
				if (stats[i] != -1) {
					stats[i] = StdArray[BiasArr[i]];
				}
			}
			sClass = (rand()) % 3;
			switch (sClass) {
			case 0:
				SubClassName = "Pact of the Archfey"
				break;
			case 1:
				SubClassName = "Pact of the Fiend"
					
				break;
				
			case 2:
				SubClassName = "Pact of the Great Old One"
					
				break;
			}
			
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
				ranSkill1 = (rand()) % 7;
			}
			break;
		case 11: // Wizard
			BiasArr[0] = 3
				switch (sub) {
				case 0:
					BiasArr[1] = 1;
					std::vector<int> values;
					values.push_back(0);
					values.push_back(2);
					value.push_back(4);
					value.push_back(5);
					value.push_back(-1);
					value.random_shuffle(value.begin, value.end);
					for (int i = 0; i < 5; i++) {
						BiasArr[i + 2] = value[i];
					}
					int StdArray[6] = [15, 14, 13, 12, 10, 8];
					for (int i = 0; i < 6; i++) {
						if (stats[i] != -1) {
							stats[i] = StdArray[BiasArr[i]];
						}
					}
					break;
				case 1:
					BiasArr[1] = 2;
					std::vector<int> values;
					values.push_back(0);
					values.push_back(1);
					value.push_back(4);
					value.push_back(5);
					value.push_back(-1);
					value.random_shuffle(value.begin, value.end);
					for (int i = 0; i < 5; i++) {
						BiasArr[i + 2] = value[i];
					}
					int StdArray[6] = [15, 14, 13, 12, 10, 8];
					for (int i = 0; i < 6; i++) {
						if (stats[i] != -1) {
							stats[i] = StdArray[BiasArr[i]];
						}
					}
					break;
				default:
					exit(-1);
					break;
				}
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
				ranSkill1 = (rand()) % 6;
			}
			break;
		default:
			exit(-1);
			break;
		}
		if (this.RaceName == "Half-Elf") {
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
		int gold = 0;
		if (this.ClassName == "Barbarian")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this.ClassName == "Bard")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this.ClassName == "Cleric")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this.ClassName == "Druid")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this.ClassName == "Fighter")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this.ClassName == "Monk")
			gold = ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4) + 1;
		if (this.ClassName == "Paladin")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this.ClassName == "Ranger")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this.ClassName == "Rogue")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this.ClassName == "Sorcerer")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this.ClassName == "Warlock")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		if (this.ClassName == "Wizard")
			gold = (((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1) + ((rand()) % 4 + 1)) * 10;
		else
			gold = 0;
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
	int getGold() {
		return this.gold;
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