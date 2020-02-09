


	int genGold(Class) {
		int gold = 0;
		if (Class.compare("Barbarian") == 0)
			gold = (((rand()) % 4+1) + ((rand()) % 4+1))*10;
		if (Class.compare("Bard") == 0)
			gold = (((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1))*10;
		if (Class.compare("Cleric") == 0)
			gold = (((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1))*10;
		if (Class.compare("Druid") == 0)
			gold = (((rand()) % 4+1) + ((rand()) % 4+1))*10;
		if (Class.compare("Fighter") == 0)
			gold = (((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1))*10;
		if (Class.compare("Monk") == 0)
			gold = ((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4)+1;
		if (Class.compare("Paladin") == 0)
			gold = (((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1))*10;
		if (Class.compare("Ranger) == 0)
			gold = (((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1))*10;
		if (Class.compare("Rogue") == 0)
			gold = (((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1))*10;
		if (Class.compare("Sorcerer") == 0)
			gold = (((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1))*10;
		if (Class.compare("Warlock") == 0)
			gold = (((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1))*10;
		if (Class.compare("Wizard") == 0)
			gold = (((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1) + ((rand()) % 4+1))*10;
		else
			gold = 0;
	return gold
	
	}
