#include <iostream>
#include <vector>

struct Engine {
	int fuel;
	int oxygen;
	int pressure;
	int temperature;
	int weight;

	void printEngine() {
		std::cout << "Fuel Storage Capacity: " << fuel << std::endl;
		std::cout << "Oxygen Storage Capacity: " << oxygen << std::endl;
		std::cout << "Pressure Levels: " << pressure << std::endl;
		std::cout << "Temperature Reduction: " << temperature << std::endl;
		std::cout << "Weight Reduction: " << weight << std::endl << std::endl;
	}

	void initializeEngine() {
		fuel = 1;
		oxygen = 1;
		pressure = 1;
		temperature = 1;
		weight = 1;
	}
};

struct Stage {
	int numOfEngines = 0;
	Engine engines[5];

	void printEngines() {
		for (int x = 0; x < numOfEngines; x++) {
			std::cout << "--Engine " << x << " Stats--\n";
			engines[x].printEngine();
		}
	}

	void addEngine() {
		if (numOfEngines < 5) {
			std::cout << "Creating Engine #" << numOfEngines + 1 << std::endl;
			engines[numOfEngines].initializeEngine();
			engines[numOfEngines].printEngine();
			numOfEngines++;
		}
		else {
			std::cout << "Reached Max Limit of Engines : " << numOfEngines << std::endl;
		}
	}
};

struct Rocket {
	int numOfStages;
	Stage stages[3];

	Rocket() {
		std::cout << "\n--Creating Your Rocket!--\n\n";
		numOfStages = 1;
		stages[0].addEngine();
		std::cout << "--Finished Creating Your Rocket!--\n\n";
	}

	int upgradeComponents(int stage, int engine, int money);

	int upgradeEngine(int stage, int money);

	int upgradeShop(int money);

	void engineStats();
};

int main(int argc, char* argv[]) {

	// Title
	std::cout << "__TO THE MOON__\n";

	// Check if Quit Game
	bool isActive = true;

	// Game Loop
	while (isActive) {
		//Menu
		std::cout << "\n--Menu--\n";

		std::cout << "A - Start Game\n";
		std::cout << "B - Quit Game\n\n";

		std::cout << "Enter the letter of your choice: ";

		char input;

		std::cin >> input;

		input = toupper(input);

		// Entering the Game
		if (input == 'A') {
			std::cout << "\nEntering game\n";

			std::cout << "\n--Welcome to the Hangar!--\n";

			bool inHangar = true;

			struct Rocket playerRocket = Rocket();

			unsigned int money = 0;

			while (inHangar) {
				
				std::cout << "\nWhat would you like to do?\n";
				std::cout << "Moon Bucks: $" << money << std::endl;
				std::cout << "A - Takeoff\n";
				std::cout << "B - Upgrades\n";
				std::cout << "C - Rocket Status\n";
				std::cout << "D - Quit To Menu\n";

				std::cout << "Enter the letter of your choice: ";

				char hInput;

				std::cin >> hInput;

				hInput = toupper(hInput);

				switch (hInput) {
				case 'A':
					std::cout << "\n--Takeoff--\n";

					std::cout << "\n--Flight End--\n";
					money += 100;
					break;
					
				case 'B':
					std::cout << "\n--Upgrades--\n";
					money = playerRocket.upgradeShop(money);
					break;

				case 'C':
					std::cout << "\n--Rocket Status--\n";
					playerRocket.engineStats();
					break;

				case 'D':
					std::cout << "\n--Quit To Menu--\n";
					inHangar = false;
					break;

				default:
					std::cout << "Invalid Input\n";
				}
			}
		}
		// Quit Game
		else if (input == 'B') {
			isActive = false;
			std::cout << "Quitting Game\n";
		}
		// Wrong Input
		else {
			std::cout << "Invalid Input\n";
		}
	}
	

	return 0;
}

int Rocket::upgradeComponents(int stage, int engine, int money) {
	std::cout << "\n--Stage " << stage + 1 << " Engine #" << engine + 1 << " Component Upgrades--\n";

	bool isShopping = true;

	while (isShopping) {
		std::cout << "Moon Bucks: $" << money << std::endl;
		std::cout << "\nWhich Component of Stage " << stage + 1 << " Engine #" << engine + 1 << " to Upgrade?\n";

		std::cout << "A - [Fuel] " << stages[stage].engines[engine].fuel << "/10 : $" << stages[stage].engines[engine].fuel * 250 << std::endl;
		std::cout << "B - [Oxygen] " << stages[stage].engines[engine].oxygen << "/10 : $" << stages[stage].engines[engine].oxygen * 250 << std::endl;
		std::cout << "C - [Pressure] " << stages[stage].engines[engine].pressure << "/10 : $" << stages[stage].engines[engine].pressure * 250 << std::endl;
		std::cout << "D - [Temperature] " << stages[stage].engines[engine].temperature << "/10 : $" << stages[stage].engines[engine].temperature * 250 << std::endl;
		std::cout << "E - [Weight] " << stages[stage].engines[engine].weight << "/10 : $" << stages[stage].engines[engine].weight * 250 << std::endl;
		std::cout << "F - Exit\n\n";

		std::cout << "Enter the letter of your choice: ";

		char input;

		std::cin >> input;

		input = toupper(input);

		switch (input) {
		case 'A':
			if (stages[stage].engines[engine].fuel < 10) {
				if (money >= stages[stage].engines[engine].fuel * 250) {
					money -= stages[stage].engines[engine].fuel * 250;
					stages[stage].engines[engine].fuel++;
					std::cout << "You have upgraded Fuel\n";
				}
				else {
					std::cout << "You don't have enough Moon Bucks\n";
				}
			}
			else {
				std::cout << "FUEL MAXED";
			}
			break;
		case 'B':
			if (stages[stage].engines[engine].oxygen < 10) {
				if (money >= stages[stage].engines[engine].oxygen * 250) {
					money -= stages[stage].engines[engine].oxygen * 250;
					stages[stage].engines[engine].oxygen++;
					std::cout << "You have upgraded Oxygen\n";
				}
				else {
					std::cout << "You don't have enough Moon Bucks\n";
				}
			}
			else {
				std::cout << "OXYGEN MAXED";
			}
			break;
		case 'C':
			if (stages[stage].engines[engine].pressure < 10) {
				if (money >= stages[stage].engines[engine].pressure * 250) {
					money -= stages[stage].engines[engine].pressure * 250;
					stages[stage].engines[engine].pressure++;
					std::cout << "You have upgraded Pressure\n";
				}
				else {
					std::cout << "You don't have enough Moon Bucks\n";
				}
			}
			else {
				std::cout << "TEMPERATURE MAXED";
			}
			break;
		case 'D':
			if (stages[stage].engines[engine].temperature < 10) {
				if (money >= stages[stage].engines[engine].temperature * 250) {
					money -= stages[stage].engines[engine].temperature * 250;
					stages[stage].engines[engine].temperature++;
					std::cout << "You have upgraded Temperature\n";
				}
				else {
					std::cout << "You don't have enough Moon Bucks\n";
				}
			}
			else {
				std::cout << "PRESSURE MAXED";
			}
			break;
		case 'E':
			if (stages[stage].engines[engine].weight < 10) {
				if (money >= stages[stage].engines[engine].weight * 250) {
					money -= stages[stage].engines[engine].weight * 250;
					stages[stage].engines[engine].weight++;
					std::cout << "You have upgraded Weight\n";
				}
				else {
					std::cout << "You don't have enough Moon Bucks\n";
				}
			}
			else {
				std::cout << "WEIGHT MAXED";
			}
			break;
		case 'F':
			isShopping = false;
			std::cout << "\nExiting Component Upgrade\n";
			break;
		default:
			std::cout << "Invalid Input\n";
			break;
		}
	}

	return money;
}

// Open Shop For Engine Upgrades
int Rocket::upgradeEngine(int stage, int money) {
	std::cout << "\n--Stage " << stage + 1 << " Engine Upgrades--\n";
	bool isShopping = true;
	while (isShopping) {
		std::cout << "Moon Bucks: $" << money << std::endl;
		std::cout << "\nWhich Engine to Upgrade?\n";

		std::cout << "A - Engine #1\n";
		
		if (stages[stage].numOfEngines >= 2) {
			std::cout << "B - Engine #2\n";
		}

		if (stages[stage].numOfEngines >= 3) {
			std::cout << "C - Engine #3\n";
		}

		if (stages[stage].numOfEngines >= 4) {
			std::cout << "D - Engine #4\n";
		}

		if (stages[stage].numOfEngines == 5) {
			std::cout << "E - Engine #5\n";
		}

		std::cout << "F - Exit Engine Upgrade\n\n";

		std::cout << "Enter the letter of your choice: ";

		char input;

		std::cin >> input;

		input = toupper(input);

		switch (input)
		{
		case 'A':
			money = upgradeComponents(stage, 0, money);
			break;
		case 'B':
			if (stages[stage].numOfEngines < 2) {
				std::cout << "\nYou have not added Engine 2\n\n";
			}
			else {
				money = upgradeComponents(stage, 1, money);
			}
			break;
		case 'C':
			if (stages[stage].numOfEngines < 3) {
				std::cout << "\nYou have not added Engine 3\n\n";
			}
			else {
				money = upgradeComponents(stage, 2, money);
			}
			break;
		case 'D':
			if (stages[stage].numOfEngines < 4) {
				std::cout << "\nYou have not added Engine 4\n\n";
			}
			else {
				money = upgradeComponents(stage, 3, money);
			}
			break;
		case 'E':
			if (stages[stage].numOfEngines < 5) {
				std::cout << "\nYou have not added Engine 5\n\n";
			}
			else {
				money = upgradeComponents(stage, 4, money);
			}
			break;
		case 'F':
			isShopping = false;
			std::cout << "\n--Leaving Engines Upgrades--\n";
			break;
		default:
			std::cout << "Invalid Input\n";
			break;
		}
	}

	return money;
}

// Opens Shop For Upgrades
int Rocket::upgradeShop(int money) {
	std::cout << "\n--Upgrades Shop--\n";
	bool isShopping = true;
	while (isShopping) {
		std::cout << "Moon Bucks: $" << money << std::endl;
		std::cout << "\nOptions:\n";

		std::cout << "A - Stages Upgrades\n";

		if (numOfStages < 3) {
			std::cout << "B - Add Stage " << numOfStages + 1;

			if (numOfStages == 1) {
				std::cout << " : $1000\n";
			}
			else {
				std::cout << " : $10000\n";
			}
		}
		else {
			std::cout << "B - STAGES MAXED OUT\n";
		}

		std::cout << "C - Back to Hangar\n";

		std::cout << "Enter the letter of your choice: ";

		char input;

		std::cin >> input;

		input = toupper(input);

		bool isEngine = true;

		switch (input) {
		case 'A':
			std::cout << "\n--Stages Upgrades--\n";

			while (isEngine) {
				std::cout << "Moon Bucks: $" << money << std::endl;
				std::cout << "A - [Stage 1] Add Engine | Current Count ~ " << stages[0].numOfEngines << "/5 : $" << stages[0].numOfEngines * 500 << std::endl;
				std::cout << "B - [Stage 1] Engine Upgrades\n";

				if (numOfStages >= 2) {
					std::cout << "C - [Stage 2] Add Engine | Current Count ~ " << stages[1].numOfEngines << "/5 : $" << stages[1].numOfEngines * 1000 << std::endl;
					std::cout << "D - [Stage 2] Engine Upgrades\n";
				}

				if (numOfStages == 3) {
					std::cout << "E - [Stage 3] Add Engine | Current Count ~ " << stages[2].numOfEngines << "/5 : $" << stages[2].numOfEngines * 1500 << std::endl;
					std::cout << "F - [Stage 3] Engine Upgrades\n";
				}

				std::cout << "G - Leave Stages Upgrades\n\n";

				std::cout << "Enter the letter of your choice: ";

				char eInput;

				std::cin >> eInput;

				eInput = toupper(eInput);

				switch (eInput) {
				case 'A':
					if (money >= stages[0].numOfEngines * 500 && stages[0].numOfEngines < 5) {
						money -= stages[0].numOfEngines * 500;
						std::cout << "\nPurchased [Stage 1] Engine " << stages[0].numOfEngines + 1 << std::endl;
						stages[0].addEngine();
					}
					else {
						std::cout << "\nYou don't have enough Moon Bucks\n\n";
					}
					break;
				case 'B':
					money = upgradeEngine(0, money);
					break;
				case 'C':
					if (money >= stages[1].numOfEngines * 1000 && stages[1].numOfEngines < 5) {
						money -= stages[1].numOfEngines * 1000;
						std::cout << "\nPurchased [Stage 2] Engine " << stages[1].numOfEngines + 1 << std::endl;
						stages[1].addEngine();
					}
					else if (numOfStages < 2) {
						std::cout << "\nYou have not added Stage 2\n\n";
					}
					else {
						std::cout << "\nYou don't have enough Moon Bucks\n\n";
					}
					break;
				case 'D':
					money = upgradeEngine(1, money);
					break;
				case 'E':
					if (money >= stages[2].numOfEngines * 1500 && stages[2].numOfEngines < 5) {
						money -= stages[2].numOfEngines * 1500;
						std::cout << "\nPurchased [Stage 3] Engine " << stages[2].numOfEngines + 1 << std::endl;
						stages[2].addEngine();
					}
					else if (numOfStages < 3) {
						std::cout << "\nYou have not added Stage 3\n\n";
					}
					else {
						std::cout << "\nYou don't have enough Moon Bucks\n\n";
					}
					break;
				case 'F':
					money = upgradeEngine(2, money);
					break;
				case 'G':
					std::cout << "\n--Leaving Stages Upgrades--\n";
					isEngine = false;
					break;
				default:
					std::cout << "Invalid Input\n";
					break;
				}
			}

			break;
		case 'B':
			if (numOfStages == 1) {
				if (money >= 1000) {
					money -= 1000;
					std::cout << "\nYou have purchased Stage 2!\n";
					numOfStages++;
					stages[1].addEngine();
				}
				else {
					std::cout << "\nYou don't have enough Moon Bucks\n";
				}
			}
			else if (numOfStages == 2) {
				if (money >= 10000) {
					money -= 10000;
					std::cout << "\nYou have purchased Stage 3!\nSTAGES MAXED OUT\n";
					numOfStages++;
					stages[2].addEngine();
				}
				else {
					std::cout << "\nYou don't have enough Moon Bucks\n";
				}
			}
			else {
				std::cout << "B - STAGES MAXED OUT\n";
			}
			break;
		case 'C':
			std::cout << "\n--Going back to the Hangar--\n";
			isShopping = false;
			break;
		default:
			std::cout << "Invalid Input\n";
		}
	}

	return money;
}

// Prints Stats of All Engines
void Rocket::engineStats() {
	for (int x = 0; x < numOfStages; x++) {
		std::cout << "--Stage " << x + 1 << "--\n\n";
		stages[x].printEngines();
	}
}