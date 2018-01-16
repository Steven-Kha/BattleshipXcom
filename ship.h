/*
The idea here is the have an abstract class that would act as a blueprint/template for the other ships
(Corvette, frigate, and iron clad). These ships would all inherit from "protoship" class. For now, the
only real difference between the corvette, frigate and iron clad ships are their stats.
*/	

class protoship {
public:
	protoship(int health = 0, int attack = 0, int range = 0, int speed = 0)			// constructor 
		: health_(health), attack_(attack), range_(range), speed_(speed) {}

	virtual ~protoship() {}		// a virtual destructor 
	

	int health() {				// keeps track of health
		
	}
	
private:
	int health_;
	int attack_;	
	int range_;			// how far a ship can shoot
	int speed_;			// determines how far can the ship can move
	double hitProb_;	// the odds that an attack is a successful hit 
};

// low health, low attack, medium range, high speed, high accuracy
class corvette : public protoship {			
public:

private: 
};

// medium health, medium attack, medium range, less-than-medium speed, medium accuracy
class frigate : public protoship {			  
public:

private:

};

// large health, high attack, short range, low speed, high accuracy at short range
// future ability: has a probability of negating an attack and take zero damage (deflections) 
class ironclad : public protoship {			
public:

private:
	
};

