// Step 1: Race


// Step 2: Background



// Step 3: Class


// Step 4: Stat Line

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
for (int i = 0; i < 6; i++) {
	if (stats[i] != -1) {

	}
}

"Major personality trait: " << Trait << "\nIdeal by which the character lives: " << Ideal << "\nBonds to which they hold themselves: "
<< Bond << "\nGreatest flaw: " << Flaw

int HitPoints;

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
		HitPoints += 8;
	}
	if (ClassName == "Warlock") {
		HitPoints += 6;
	}
	HitPoints += mods[2];
	if (SubRaceName == "Hill Dwarf") {
		HitPoints += 1;
	}

}

<< "\nHit Points: " << HitPoints <<