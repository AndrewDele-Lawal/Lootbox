#include <iostream>
#include <vector>
#include "Supports.cpp"
#include <stdlib.h>
#include <string>
#include <time.h>
#include <dos.h>

int main() {
	/*Intialize Variables*/
	int numb_of_items{};
	std::string item{};
	std::vector<std::string> Lootbox{};
	std::string yes_or_no{};
	std::string Loot{};
	int index(0);
	int rolls(0);




	/*Setting the size of lootbox*/
	std::cout << "How many items do you want the lootbox to contain: ";
	std::cin >> numb_of_items;

	//while (is_numb_of_items_a_numb(numb_of_items) == false) {
	//	std::cout << "Enter a valid number of items you wish to include";
	//}

	
	while (std::cin.fail() || numb_of_items <= 0) {
		std::cout << "Please enter a valid number of items: ";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> numb_of_items;
	}


	/*Adding items to the lootbox*/
	for (int i = 0; i < numb_of_items; i++) {
		std::cout << "Enter the name of the item you wish to include in the lootbox: ";
		std::cin >> item;
		Lootbox.push_back(item);
	}
	/*Displaying the names of the items in the lootbox along with initializing the Number of items*/
	int Number_of_items = Lootbox.size();
	std::cout << "This lootbox contains: \n";
	for (const auto& loot : Lootbox) {
		std::cout << loot << std::endl;
	}

	/*Rolling for items in the lootbox*/
	std::cout << "Would you like to spin for items? (y/n) ";
	std::cin >> yes_or_no;
	/*Checks to see whether user entered a y(Yes) or n(No)*/
	while (!(y_or_n_check(yes_or_no))) {
		std::cout << "Enter y or n: ";
		std::cin >> yes_or_no;
	}
	/*If the user entered Y or N diverge into separate pathways*/
	if (y_or_n_check(yes_or_no)) {
		/*Y has been entered, Ask the User how many times they want to roll*/
		if (yes_or_no == "y") {
			std::cout << "How many times do you want to roll? ";
			std::cin >> rolls;
			/*User can't enter a value greater than the number of items in the Lootbox at the time of rolling, Trap user in a loop until they enter a logical amount of spins*/
			while (rolls > Lootbox.size()) {
				std::cout << "Enter a suitable amount of rolls: ";
				std::cin >> rolls;
			}
			/*Creates a loop based on the amount of rolls the user entered*/
			for (int i = 0; i < rolls; i++) {
				/*Welcoming message, only outputs on the first loop*/
				if (i == 0) {
					std::cout << "Great let's begin \n";
				}
				/*Roll for items in the lootbox using the size of the box, the amount of spins, and the random function*/
				index = rand() % Number_of_items;
				Loot = Lootbox[index];
				Lootbox.erase(std::next(Lootbox.begin(), index));
				std::cout << "You recieved " + Loot + ".\n";
				Number_of_items = Lootbox.size();
			}

		}
		/*If the user inputed n(No) then output the thank you message*/
		else {
			std::cout << "Thank you for playing! \n";
			exit(1);
		}
		
	}
	/*If the Lootbox is empty thank the player for playing*/
	if (Lootbox.size() == 0) {
		std::cout << "There are no more items left in the lootbox. \n";
		std::cout << "Thanks for playing! \n";
	}

	else
	{
		/*If the lootbox is not empty tell the player what remains after their roll(s)*/
		std::cout << "This lootbox contains: \n";
		for (const auto& loot : Lootbox) {
			std::cout << loot << std::endl;
		}
		/*While the box still has stuff in it ask the player if they would like to play again*/
		while (!(Lootbox.size() == 0)) {
			/*Pause for 3 seconds*/
			sleep(3);
			std::cout << "Would you like to roll again?";
			std::cin >> yes_or_no;

			/*Check whether they entered a proper input*/
			if (y_or_n_check(yes_or_no)) {

				/*If y(yes) Ask them how many rolls*/
				if (yes_or_no == "y") {
					std::cout << "How many times do you want to roll? ";
					std::cin >> rolls;

					/*While the rolls are bigger than the size loop them till they enter a proper amount of rolls*/
					while (rolls > Lootbox.size()) {
						std::cout << "Enter a suitable amount of rolls: ";
						std::cin >> rolls;
					}

					/*Spin for the loot in the lootbox*/
					for (int i = 0; i < rolls; i++) {
						std::cout << "Great let's begin \n";
						index = rand() % Number_of_items;
						Loot = Lootbox[index];
						Lootbox.erase(std::next(Lootbox.begin(), index));
						std::cout << "You recieved " + Loot + ".\n";
						Number_of_items = Lootbox.size();
					}
				}

				/*If they wish not to continue rolling thank them for playing*/
				else { std::cout << "Thank you for playing"; }
			}

		}
	}
	
	




	return 0;
}
