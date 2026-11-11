#include <iostream> //for input / output
#include <string> //for string handling
#include <vector> //for use of dynamic array container
using namespace std; //avoid std:: prefix

class Monster 
{
protected: 
	string name; //monster name
	int health; //monster health

public: 
	Monster(const string& name, int health) : name(name), health(health) {} //base constructor. initialize health and name.

	virtual ~Monster() {} //virtual destructor for safe deletion.

	virtual void describe() const //shared "header" print for monsters.
	{
		cout << getType() << " \"" << name << "\" - HP: " << health << " - "; //print type, name, health.
	}

	virtual string getType() const = 0; //force derived classes to define type.
	virtual int attack() const = 0; //force derived classes to define attack damage.

};

class Goblin : public Monster //derived monster class: goblin
{
public: Goblin(const string& name, int health) : Monster(name, health) {} //constructor

	string getType() const override { return "Goblin"; } //type definition

	int attack() const override { return 4; } //attack damage definition

	void describe() const override  //description method.
	{
		Monster::describe();
		cout << "A sneaky little fella...\n Likes to throw rocks. (\n" "Throws a rock.. " << attack() << " damage)\n"; //prints a short description, and damage.
	}
};

class Orc : public Monster 
{
public: Orc(const string& name, int health) : Monster(name, health) {}

	string getType() const override { return "Orc"; }

	int attack() const override { return 8; }

	void describe() const override 
	{
		Monster::describe();
		cout << "A drunken brute!\n Watch out for his club. (\n" "Swings club.. " << attack() << " damage)\n";
	}
};

class Dragon : public Monster 
{
public: Dragon(const string& name, int health) : Monster(name, health) {}

	string getType() const override { return "Dragon"; }

	int attack() const override { return 15; }

	void describe() const override 
	{
		Monster::describe();
		cout << "Fast, heavy, and fiery!\n You should probably run... (\n" "Breathes fire.. " << attack() << " damage)\n";
	}
};

class RabidRat : public Monster 
{
public: RabidRat(const string& name, int health) : Monster(name, health) {}

	string getType() const override { return "Rabid Rat"; }

	int attack() const override { return 2; } 

	void describe() const override 
	{
		Monster::describe();
		cout << "Best not be bitten!\n He may not look like much, but he's vicious. (\n" "Bites you.. " << attack() << " damage)\n";
	}
};

int main() 
{
	vector<Monster*> bestiary; //container holding monster pointers.

	bestiary.push_back(new Goblin("Dirt Kneeblade", 25)); //add goblin to container
	bestiary.push_back(new Orc("Grog the Drunk", 50)); //add orc
	bestiary.push_back(new Dragon("Ashwing", 250)); //add dragon
	bestiary.push_back(new RabidRat("Screech", 10)); //add rabid rat

	cout << "[Codex]\n"; //header.

	for (Monster* m : bestiary) //go through each monster in "container"
	{
		m->describe(); //call each monsters describe method.
	}

	for (Monster* m : bestiary) //go through each monsater in "container" again.
	{
		cout << "[Freeing memory for " << m->getType() <<"\]\n"; //tell user we're freeing memory for each monster.
		delete m; //free memory.
	}
	bestiary.clear(); //clear container.
	return 0;
}
