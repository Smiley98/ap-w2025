#include <iostream>

void PointerExample()
{
	// Variable's value vs variable's address (its location in memory, stored as a pointer).
	int number = 5;
	int* numberAddress = &number; // '&' means "Address of" --> where the variable is stored in memory.
	printf("Value of number: %i\nAddress of number: %p\n", number, numberAddress);

	*numberAddress = 69;
	printf("New value of number: %i\nSame address of number: %p\n", number, numberAddress);

	// "Memory corruption" --> The compiler owns numberAddress, so by deleting it ourselves we break the rules (and our program crashes)!
	//delete numberAddress;

	// Generally you don't want to treat integers as addresses.
	// This is because they probably DON'T map to actual addresses.
	// Modifying an address that has NOT been allocated by YOUR program will result in memory corruption (crash)!
	//int* brokenAddress = (int*)number;
	//*brokenAddress = 69420;
	//printf("%p", brokenAddress);
	//printf("%i", *brokenAddress);
}

void ArrayExample()
{
	// Arrays are represented as a pointer to the first address.
	// From there, we can offset based on the size of our array (why numbers[0] means first number)!
	int* numbers = new int[10];
	for (int i = 0; i < 10; i++)
		numbers[i] = i + 1;

	// Since arrays are stored as a pointer to the address of the start of the array,
	// we can access the array values via pointer arithmetic!
	*(numbers + 0) = 69;	// "Changing numbers[0]"
	*(numbers + 1) = 420;	// "Changing numbers[1]"
	*(numbers + 2) = 1337;	// "Changing numbers[2]"
	*(numbers + 3) = 21;	// "Changing numbers[3]"

	// Should still prefer operator[] over pointer arithmetic, but its good to know!
	for (int i = 0; i < 10; i++)
		printf("Number %i: %i\n", i + 1, *(numbers + i));

	// Not required, but setting a deleted pointer to nullptr signifies that its been deallocated.
	delete[] numbers;
	numbers = nullptr;

	// Setting to nullptr prevents the "double-delete" bug where deleting deallocated but non-null memory crashes the program.
	// (I generally don't like setting to nullptr because I WANT to know if I'm accidentally calling delete[] twice+).
	delete[] numbers;
	delete[] numbers;
	delete[] numbers;
}

int main()
{
	PointerExample();
	ArrayExample();
	return 0;
}
