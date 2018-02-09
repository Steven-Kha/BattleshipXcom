#include <string>
#include <iostream>

class ship {
public:
	ship(int health = 0, int attack = 0, int range = 0, int speed = 0, double prob = 0, std::string name = " ", char rep = ' ')			// constructor
		: health_(health), attack_(attack), range_(range), speed_(speed), hitProb_(prob), shipName(name), rep_(rep) {}

	void printStats()
	{
		std::cout << "===============================\n";
		std::cout << "Name:           " << shipName << "\n";
		std::cout << "Health:           " << health_ << "\n";
		std::cout << "Attack:           " << attack_ << "\n";
		std::cout << "Range:            " << range_ << "\n";
		std::cout << "Speed:            " << speed_ << "\n";
		std::cout << "Hit probability:  " << hitProb_ << "\n";
		std::cout << "Representation:   " <<  rep_ << "\n";
	}
	int getHealth() { return health_; }
	int getAttack() { return attack_; }
	int getRange() { return range_; }
	int getSpeed() { return speed_; }
	double getHitProb() { return hitProb_; }
	char getRep() { return rep_; }


private:
	char rep_;							// a ship is represented on the board as 'c', 'f', or 'i' 
	int health_;
	int attack_;						// damage a ship can inflict per shot
	int range_;							// how far a ship can shoot
	int speed_;							// determines how far can the ship can move
	double hitProb_;				// the odds that an attack is a successful hit
	std::string shipName;
};
