#include <iostream>
#include <string>

struct Attachment
{
	float damage = 0.0f;
};

struct Weapon
{
	Attachment* attachments = nullptr;
	int attachmentCount = 0;
	std::string name;
};

struct Player
{
	Weapon* weapons = nullptr;
	int weaponCount = 0;
};

// -Stores players
// -Each player can have multiple weapons
// -Each weapon can have multiple attachments
// 
// *Must declare objects in reverse-order*
// -Weapon needs to know what a Attachement is
// -Player needs to know what a Weapon is
int main()
{
	int playerCount = 0;
	printf("Enter the number of players.\n");
	std::cin >> playerCount;
	std::cin.ignore();
	printf("The game has %i players.\n", playerCount);

	Player* players = new Player[playerCount];
	for (int i = 0; i < playerCount; i++)
	{
		Player& player = players[i];
		int playerNumber = i + 1;
		printf("Creating player %i.\n", playerNumber);

		printf("How many weapons does player %i have?\n", playerNumber);
		std::cin >> player.weaponCount;
		std::cin.ignore();

		player.weapons = new Weapon[player.weaponCount];
		printf("Player %i has %i weapons.\n", playerNumber, player.weaponCount);

		for (int j = 0; j < player.weaponCount; j++)
		{
			Weapon& weapon = player.weapons[j];
			int weaponNumber = j + 1;
			printf("Creating weapon %i.\n", weaponNumber);
			printf("What is the name of weapon %i?\n", weaponNumber);
			std::cin >> weapon.name;
			std::cin.ignore();
			printf("Weapon %i is named %s.\n", weaponNumber, weapon.name.c_str());

			// TODO -- In your homework, you'll need a 3rd loop to define achievements.
			// Ensure you've allocated memory for achievements before defining them!
		}

		//delete[] player.weapons;
	}
	//delete[] players;

	// Remember to call delete[] when you're done with your dynamic memory!
	// (I commented out delete[] calls because I wanted to inspect my memory in the debugger)
	return 0;
}
