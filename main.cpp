#include <iostream>

const int PLAYER_COUNT = 5;

// Encapsulation is generally bad. It leads to useless functions such as SetRadius that should instead be public variables
class Circle1
{
public:
	float GetArea() { return radius * 3.14f; }

	float GetRadius() { return radius; }		// <-- Shouldn't exist
	void SetRadius(float r) { radius = r; }		// <-- Shouldn't exist

private:
	float radius = 0.0f;
};

// Superior Procedural programming Circle implementation ;)
struct Circle2
{
	float radius;
};

float Area(Circle2 circle) { return circle.radius * 3.14f; }

// Just like Vector2 in Unity-C#
// Note the use of " = 0". This means whenever we create a Vector2, its x & y values will be 0.
struct Vector2
{
	float x = 0.0f;
	float y = 0.0f;
};

// '&' means "pass by reference", allowing the variable to be modified
void HealPlayer(float& health)
{
	health = 100.0f;
}

void MovePlayer(Vector2& position)
{
	position.x++;
	position.y--;
}

void ProceduralExample()
{
	float playerHealths[PLAYER_COUNT]{};
	Vector2 playerPositions[PLAYER_COUNT];

	for (int i = 0; i < PLAYER_COUNT; i++)
	{
		MovePlayer(playerPositions[i]);
		HealPlayer(playerHealths[i]);
		printf("Player x coordinate: %f\n", playerPositions[i].x);
	}

	Circle2 circle;
	circle.radius = 5.0f;
	printf("Circle with a radius %f has an area is %f\n", circle.radius, Area(circle));
}

class Player
{
public:
	void Heal() { health = 100.0f; }
	void Move() { position.x++; position.y--; }

private:
	Vector2 position;
	float health = 100.0f;
};

void ObjectOrientedExample()
{
	Player players[PLAYER_COUNT];
	for (int i = 0; i < PLAYER_COUNT; i++)
	{
		players[i].Heal();
		players[i].Move();
	}

	Circle1 circle;
	circle.SetRadius(5.0f);
	printf("Circle with a radius %f has an area is %f\n", circle.GetRadius(), circle.GetArea());
}

// Program that moves and heals 5 players:
// TODO Week 3 -- Constructors, Destructors, Pointers
int main()
{
	ProceduralExample();
	ObjectOrientedExample();

	// Note on memory:
	// C++ does NOT initialize variables, meaning if we do int numbers[3];
	// we see something like { -853411324, -853411324, -853411324 } in the debugger
	// We can avoid this by using {} to "default-initialize" our variables to get { 0, 0, 0 } via int numbers[3]{};
	
	//int numbers[10];		<-- "uninitialized" (bad, crazy stuff like -85283947)
	//int numbers[10]{};	<-- "default-initialized" (good, non-crazy stuff like 0)

	return 0;
}
