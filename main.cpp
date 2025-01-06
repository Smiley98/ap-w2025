#include <iostream>

int main()
{
	int favouriteNumber = -1;
	std::cout << "What is your favourite number?\n";
	std::cin >> favouriteNumber;
	//std::cout << "Your favourite number is: " << favouriteNumber << std::endl;

	// C equivalent of the above output (%i means integer)
	printf("Your favourite number is: %i\n", favouriteNumber);
	//printf("C style hello\n");
	//std::cout << "C++ style hello" << std::endl;

	return 0;
}
