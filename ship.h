/*
The idea here is to have an abstract class that would act as a blueprint/template for the other ships
(Corvette, frigate, and iron clad). These ships would all inherit from "protoship" class. For now, the
only real difference between the corvette, frigate and iron clad ships are their stats.
*/	
#include <ostream>
#include <iostream>

//class protoship {
//public:
//	protoship(int health = 0, int attack = 0, int range = 0, int speed = 0)			// constructor 
//		: health_(health), attack_(attack), range_(range), speed_(speed) {}
//
//	//virtual ~protoship() {}			// a virtual destructor 
//	virtual int shipStats();		// this function will print out the stats of each ship type. 
//	//virtual void shipRep();			// this function will print out an upper/lower-case 'c', 'f', or 'i'
//	//								//		depending on the ship's owner. Upper case for computer, lower for the user 
//
//	//virtual bool checkRange();		// returns true if target ship is within range. False if out-of-range
//	//virtual bool checkSpeed();		// returns true if  move destination is allowed by speed constraint. Otherwise, returns false 
//	//virtual int health();			// keeps track of health
//	
//	
//private:
//	int health_;
//	int attack_;
//	int range_;			// how far a ship can shoot
//	int speed_;			// determines how far can the ship can move
//	double hitProb_;	// the odds that an attack is a successful hit 
//};


// low health, low attack, medium range, high speed, high accuracy
class corvette {
public:
	corvette(int health = 10, int attack = 3, int range = 2, int speed = 4, double hitProb = 0.95)
		: health_(health), attack_(attack), range_(range), speed_(speed), hitProb_(hitProb) {}

	friend std::ostream& operator<<(std::ostream& os, const corvette c) {
		return os << "C";
	}

	int shipStats() {
		std::cout << "===============================\n";
		std::cout << "Health:           " << health_ << "\n";
		std::cout << "Attack:           " << attack_ << "\n";
		std::cout << "Range:            " << range_ << "\n";
		std::cout << "Speed:            " << speed_ << "\n";
		std::cout << "Hit probability:  " << hitProb_ << "\n";
		std::cout << "Representation:   " << "C\n";
		return 0;
	}
private:
	int health_;
	int attack_;
	int range_;			// how far a ship can shoot
	int speed_;			// determines how far can the ship can move
	double hitProb_;	// the odds that an attack is a successful hit 
};

// medium health, medium attack, medium range, less-than-medium speed, medium accuracy
class frigate {			  
public:
	frigate(int health = 20, int attack = 5, int range = 3, int speed = 2, double hitProb = 0.65)
		: health_(health), attack_(attack), range_(range), speed_(speed), hitProb_(hitProb) {}

	friend std::ostream& operator<<(std::ostream& os, const frigate f) {
		return os << "F";
	}

	int shipStats() {
		std::cout << "===============================\n";
		std::cout << "Health:           " << health_ << "\n";
		std::cout << "Attack:           " << attack_ << "\n";
		std::cout << "Range:            " << range_ << "\n";
		std::cout << "Speed:            " << speed_ << "\n";
		std::cout << "Hit probability:  " << hitProb_ << "\n";
		std::cout << "Representation:   " << "F\n";
		return 0;
	}
private:
	int health_;
	int attack_;
	int range_;			// how far a ship can shoot
	int speed_;			// determines how far can the ship can move
	double hitProb_;	// the odds that an attack is a successful hit 
};

// large health, high attack, short range, low speed, high accuracy at short range
// future ability: has a probability of negating an attack and take zero damage (deflections) 
class ironclad {			
public:
	ironclad(int health = 30, int attack = 6, int range = 1, int speed = 1, double hitProb = 0.90)
		: health_(health), attack_(attack), range_(range), speed_(speed), hitProb_(hitProb) {}
	friend std::ostream& operator<<(std::ostream& os, const ironclad i) {
		return os << "I";
	}

	int shipStats() {
		std::cout << "===============================\n";
		std::cout << "Health:           " << health_ << "\n";
		std::cout << "Attack:           " << attack_ << "\n";
		std::cout << "Range:            " << range_ << "\n";
		std::cout << "Speed:            " << speed_ << "\n";
		std::cout << "Hit probability:  " << hitProb_ << "\n";
		std::cout << "Representation:   " << "I\n";
		return 0;
	}
private:
	int health_;
	int attack_;
	int range_;			// how far a ship can shoot
	int speed_;			// determines how far can the ship can move
	double hitProb_;	// the odds that an attack is a successful hit 
};
