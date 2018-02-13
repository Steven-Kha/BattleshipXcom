// testing 0.03
// moving ship speed of 1 from the four corners
// later on test moving from the four sides with top, left, right, bottom cut off
//X: 0 Y:0 passes
//X: 5 Y:0 passes
//X:0 Y:5 passes
//X:5 Y:5 passes
// all four corners have passed
// cout << "success! \n";


#include "ship.h"
#include <time.h>
using namespace std;

// function prototypes
void moveOne(int & oneX, int & oneY, int & twoX, int & twoY, ship player, ship player2, char board[][6]);
void print(ship player, ship player2, char board[][6]);
void attack(int oneX, int oneY, int & twoX, int & twoY, ship & player, ship & player2, char board[][6]);
bool checkRange(int range, int xNum, int oneX, int oneY, int twoX, int twoY,
	int coordY, ship player, ship player2, char board[][6]);

int main() {
	char oceanBoard[6][6] = {};
	// health_(health), attack_(attack), range_(range), speed_(speed), hitProb_(prob), shipName(name), rep_(rep)
	//           hp,atk,rg,spd,prob,    name,    rep
	ship corvette(10, 2, 2, 2, 0.80, "corvette", 'C');
	ship ironclad(15, 6, 1, 1, 0.99, "Ironclad", 'i');

	//player one's starting coordinates
	int OneX = 3;
	int OneY = 3;

	//player two's starting coordinates
	int TwoX = 5;
	int TwoY = 5;

	oceanBoard[OneY][OneX] = corvette.getRep();		// placing player 1's ship on the board
	oceanBoard[TwoY][TwoX] = ironclad.getRep();		// placing player 2's ship on the board

	print(corvette, ironclad, oceanBoard);				// printing the gameboard to the console
	int menuSelection = 0;												// the player's selection from the menu

	// this is the actual menu itself
	while (corvette.getHealth() > 0 && ironclad.getHealth() > 0) {
		std::cout << "Select an option:\n";
		std::cout << "1) Move\n";
		std::cout << "2) Attack\n";
		std::cin >> menuSelection;

		// player chooses to move
		if (menuSelection == 1) {
			moveOne(OneX, OneY, TwoX, TwoY, corvette, ironclad, oceanBoard);
		}
		// player chooses to attack
		else if (menuSelection == 2) {
			attack(OneX, OneY, TwoX, TwoY, corvette, ironclad, oceanBoard);
		}
		else {
			cout << "Please enter a number from the menu\n";
			system("pause");
			system("cls");
			print(corvette, ironclad, oceanBoard);
			// note: program will be trapped in infinite loop if user makes a non-numerical entry
			//		 or enters a very large number
		}
	}
	if (ironclad.getHealth() < 0 || ironclad.getHealth() == 0) {
		cout << "Enemy ironclad has been sunk. You've won!\n\n";
	}
	else if (corvette.getHealth() < 0 || corvette.getHealth() == 0) {
		cout << "Your ship was sunk. You've lost...\n\n";
	}
	else {
		cout << "I'm not sure what happened...  :P\n\n";
	}
	system("pause");
	return 0;
}

void moveOne(int & oneX, int & oneY, int & twoX, int & twoY, ship player, ship player2, char board[][6]) {
	bool rangePass = false;
	int coordY = 0;					// user input: y-coordinates
	char coordX;						// user input: x-Coordinates
	int xNum = 0;						// the corresponding array index
	bool xPass = false;
	bool yPass = false;
	cout << "------------------------";

	// a do-while loop to ask for new destination coordinates, then checks to speed
	// if the coordinates are within movement range
	do
	{
		cout << "Enter X coordinate: ";
		cin >> coordX;

		//converting Letters to their corresponding array index
		if 			(coordX == 'A' || coordX == 'a') 	{ xNum = 0; }
		else if (coordX == 'B' || coordX == 'b') 	{ xNum = 1; }
		else if (coordX == 'C' || coordX == 'c') 	{ xNum = 2; }
		else if (coordX == 'D' || coordX == 'd') 	{ xNum = 3; }
		else if (coordX == 'E' || coordX == 'e') 	{ xNum = 4; }
		else if (coordX == 'F' || coordX == 'f') 	{ xNum = 5; }
		else 		{ xNum = 7; }

		cout << "Enter Y coordinates: ";
		cin >> coordY;
		if (coordY < 1 || coordY > 6) {
			cout << "Please re-enter valid Y: ";
		}

		// here, we check if the user's coordinates are within range of the user's ship
		rangePass = checkRange(player.getSpeed(), xNum, oneX, oneY, twoX, twoY, coordY, player, player2, board);

	} while ((xNum == 7) || (coordY < 1 || coordY > 6) || (!rangePass));


	if (board[coordY - 1][xNum] != board[twoY][twoX]) {
		board[coordY - 1][xNum] = player.getRep();
		board[oneY][oneX] = 'X';
		oneY = coordY - 1;
		oneX = xNum;
		cout << "Coordinates received!... \n";
		system("pause");
		system("cls");
		print(player, player2, board);
	}

	else {
		cout << "That's where the other ship is!";
		system("pause");
		moveOne(oneX, oneY, twoX, twoY, player, player2, board);
	}
}


bool checkRange(int range, int xDest, int xCurr, int yCurr, int twoX, int twoY,
	int yDest, ship player, ship player2, char board[][6]) {

	bool xPass = false;
	bool yPass = false;

	// Here, we prove (Destination - current location)
	// This is a proof by contradiction
	//ex: dest :5 current location: 3 range: 2
	//5-3 = 2 and 2>0
	// but what if dest: 1 cur: 5
	// 1 - 5 = -4 so it would pass
	// so check if destination is greater or equal to current location
	if ((xDest - xCurr <= range && xDest >= xCurr)) { // xDest is destination; xCurr is current location
		xPass = true;
	}

	if (xPass == false) {
		//but what if:
		// dest: 3 curr: 5
		// 3-5 = -2 but
		//5-3 =2 so it should pass
		//so check current - destination is = or below range but current is greater than destination
		if (xCurr - xDest <= range && xCurr > xDest) {
			xPass = true;
		}
		else {
			cout << "Please re-enter valid X: ";
			system("pause");
			system("cls");
			print(player, player2, board);
			return false;
		}
	}

	//------------------------------check y coordinates now
	//check if coordinate is out of bounds and speed displacement is greater than one or
	//less than zero
	/*cout << "Enter Y coordinates: ";
	cin >> yDest;*/

	//destination - current location
	//we are offsetting the coord y because the board starts at one instead of zero
	if ((yDest - 1) - yCurr <= range && (yDest - 1) >  0) {
		//cout << "Failed Y part 1 \n";
		yPass = true;
	}

	if (yPass == false) {
		//current location - destination
		//we are offsetting the coord y because the board starts at one instead of zero
		if (  ( (yCurr + 1) - yDest <= range  ) && ( (yCurr + 1) > yDest)   ) {
			//cout << "Failed Y part 2 \n";
			yPass = true;
		}
		else {
			cout << "Please re-enter valid Y: ";
			system("pause");
			system("cls");
			print(player, player2, board);
			return false;
		}
	}
	// this is if the user enters their current position as a move destination
	if (board[yDest - 1][xDest] == board[yCurr][xCurr]) {
		char answer;
		cout << "You didn't move. \n"
			<< "Re-enter coordinates or quit? \n";
		cout << "------------------------- \n"
			<< "[Any key] Re-enter \n"
			<< "[N] No\n"
			<< "Choice: ";
		cin >> answer;
		if (answer == 'n' || answer == 'N') { exit(1); }
		else {
			system("cls");
			print(player, player2, board);
			return false;
		}
	}
	return true;
}

// the following is the attack function==================================================================
void attack(int oneX, int oneY, int & twoX, int & twoY, ship & player, ship & player2, char board[][6]) {
	char coordX;
	int coordY = 0;
	int xNum = 0;
	bool rangePass = false;

	do
	{
		cout << "Loading rounds...\n";
		cout << "Enter X coordinates: ";
		cin >> coordX;			// coordX is user input

								//converting Letters to x coordinates
		if (coordX == 'A' || coordX == 'a') { xNum = 0; }
		else if (coordX == 'B' || coordX == 'b') { xNum = 1; }
		else if (coordX == 'C' || coordX == 'c') { xNum = 2; }
		else if (coordX == 'D' || coordX == 'd') { xNum = 3; }
		else if (coordX == 'E' || coordX == 'e') { xNum = 4; }
		else if (coordX == 'F' || coordX == 'f') { xNum = 5; }

		else { xNum = 7; }
		cout << "Enter Y coordinates: ";
		cin >> coordY;
		if (coordY < 1 || coordY > 6) {
			cout << "Please re-enter valid Y: ";
		}

		rangePass = checkRange(player.getRange(), xNum, oneX, oneY, twoX, twoY, coordY, player, player2, board);




	} while ((xNum == 7) || (coordY < 1 || coordY > 6) || (!rangePass));


	cout << "Target coordinates received. Firing for effect...\n";
	system("pause");

	// if user's targeting coordinates == coordinates of enemy ship...
	if (board[coordY - 1][xNum] == board[twoY][twoX]) {
		srand(time(NULL));
		double random = rand() % 100 + 1;
		random /= 100;
		if (random <= player.getHitProb()) {
			int p2DamagedHealth = player2.getHealth() - player.getAttack();
			player2.setHealth(p2DamagedHealth);
			cout << "--------------------------------------\n";
			cout << "Confirmed hit!\n";
			cout << "Enemy " << player2.getName() << "'s health is now at " << player2.getHealth() << " HP\n";
			system("pause");
			system("cls");
			print(player, player2, board);
		}
		else {
			cout << "------------------------------------------\n";
			cout << "Shots missed! Enemy " << player2.getName() << " is undamaged!\n";
			system("pause");
			system("cls");
			print(player, player2, board);
		}
	}
	else {
		cout << "-------------------------------------------------\n";
		cout << "Shots landed in open water\n";
		system("pause");
		system("cls");
		print(player, player2, board);
	}
}

// following function prints the entire game board
void print(ship player, ship player2, char board[][6]) {
	char abcRow[6] = { 'A', 'B', 'C', 'D', 'E','F' };

	cout << "   ";
	for (int i = 0; i < 6; i++) {
		cout << abcRow[i] << " ";
	}
	cout << "\n";

	for (int i = 0; i < 6; i++) {
		cout << i + 1 << " ";
		for (int j = 0; j < 6; j++) {
			cout << " ";
			if (board[i][j] == player.getRep())
				cout << player.getRep();
			else if (board[i][j] == player2.getRep())
				cout << player2.getRep();
			else
				cout << "X";
		}
		cout << "\n";
	}
}
