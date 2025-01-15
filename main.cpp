#include <iostream>

// -Stores players
// -Each player can have multiple weapons
// -Each weapon can have multiple attachments 
int main()
{
	int playerCount = 0;
	printf("Enter the number of players.\n");
	std::cin >> playerCount;
	printf("The game has %i players.\n", playerCount);
	return 0;
}
