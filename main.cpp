#include <iostream>

int main()
{
	// Input player health
	int playerHealth = 0;
	printf("How much health does the player have?\n");
	std::cin >> playerHealth;
	printf("The player has %i health.\n\n", playerHealth);

	// Input player damage
	int playerDamage = 0;
	printf("How much damage does the player do?\n");
	std::cin >> playerDamage;
	printf("The player does %i damage.\n\n", playerDamage);

	// Input enemy health
	int enemyHealth = 0;
	printf("How much health does the enemy have?\n");
	std::cin >> enemyHealth;
	printf("The enemy has %i health.\n\n", enemyHealth);

	// Input enemy damage
	int enemyDamage = 0;
	printf("How much damage does the enemy do?\n");
	std::cin >> enemyDamage;
	printf("The enemy has %i damage.\n\n", enemyDamage);

	// Simulate 1 turn of combat
	printf("Combat turn one...\n");
	playerHealth -= enemyDamage;
	enemyHealth -= playerDamage;
	printf("Player does %i damage to the enemy. The enemy now has %i health.\n", playerDamage, enemyHealth);
	printf("Enemy does %i damage to the player. The player now has %i health.\n", enemyDamage, playerHealth);

	// Task 1: Write a while-loop that runs the battle until the player and/or enemy is dead!
	// Task 2: Write a function that replaces each of the 4 damge/health inputs.

	return 0;
}
