#include <iostream>

// A function is a reusable piece of code
// This function outputs nothing ("void"), takes no inputs, and is named Function
void Function()
{
	printf("Function has been called!\n");
}

// This function outputs a decimal number given two decimal number inputs, and is named Add
float Add(float a, float b)
{
	// (Not a good function because this is better expressed directly with '+')
	return a + b;
}

int main()
{
	printf("Call a function by typing its name + parentheses\n");
	Function();
	Function();
	Function();

	int runCount = 1;
	printf("\nHow many times would you like to run the previous function?\n");
	//std::cin >> runCount; <-- uncomment to run more than once
	printf("Running Function %i times:\n", runCount);
	for (int i = 0; i < runCount; i++)
	{
		Function();
	}

	// An array of 5 decimal numbers (float) named numbers.
	float numbers[5];
	numbers[0] = 5.0f;
	numbers[1] = 69.0f;
	numbers[2] = 420.0f;
	numbers[3] = 1337.0f;
	numbers[4] = 9001.0f;

	printf("\nSummating the following numbers:\n");
	float sum = 0.0f;
	for (int i = 0; i < 5; i++)
	{
		float number = numbers[i];
		sum += number;
		printf("Number %i: %f\n", i + 1, number);
	}
	printf("Sum is: %f\n", sum);

	// Review complete -- you are now an expert on functions, arrays, and loops!
	return 0;
}
