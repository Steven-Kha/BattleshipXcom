// testing 0.03
// moving ship speed of 1 from the four corners
// later on test moving from the four sides with top, left, right, bottom cut off
//X: 0 Y:0 passes
//X: 5 Y:0 passes
//X:0 Y:5 passes
//X:5 Y:5 passes
// all four corners have passed
// cout << "success! \n";


#include <iostream>
#include <string>
using std::string;
using namespace std;

void moveOne(int & oneX, int & oneY, int & twoX, int & twoY, char board[][6]);
void print(char board[][6]);
int main() {
	
	char oceanBoard[6][6] = {};
	//player one coordinates
	int OneX = 0; 
	int OneY = 0;
	
	//player two coordinates
	int TwoX = 5;
	int TwoY = 5;

	//$ is your ship symbol & is the cpu
	oceanBoard[OneY][OneX] = '$';
	oceanBoard[TwoY][TwoX] = '&';


	print(oceanBoard);

	moveOne(OneX, OneY, TwoX, TwoY, oceanBoard);

	system("pause");
	return 0;
}

void moveOne(int & oneX, int & oneY, int & twoX, int & twoY, char board[][6])
{
	system("pause");
	int coordY = 0;
	char coordX;
	int xNum = 0; //destination
	bool xPass = false;
	bool yPass = false;
	cout << "------------------------";
	
	cout << "Enter X coordinate: ";
	cin >> coordX;

	//converting Letters to x coordinates
	if (coordX == 'A' || coordX == 'a')
		xNum = 0;
	else if (coordX == 'B' || coordX == 'b')
		xNum = 1;
	else if (coordX == 'C' || coordX == 'c')
		xNum = 2;
	else if (coordX == 'D' || coordX == 'd')
		xNum = 3;
	else if (coordX == 'E' || coordX == 'e')
		xNum = 4;
	else if (coordX == 'F' || coordX == 'f')
		xNum = 5;
	else
		xNum = 7;

	/*cout << xNum << "\n";
	cout << oneX << "\n";
	cout << "xNum - oneX equals: " << xNum - oneX << "\n";
	cout << "oneX - xNum equals: " << oneX - xNum << "\n";*/

	//check if coordinate is out of bounds and speed displacement is greater than one or
	//less than zero

	//destination - current location
	if ((xNum - oneX > 1 || xNum - oneX < 0 ))
	{
		//cout << "Failed X part 1 \n"; //so xPass is false if destination is less than current
	}
	else
	{
		xPass = true;
	}
	
	if (xPass == false) //only runs if destintion is lower than current
	{
		//current location - destination
		if (oneX - xNum > 1 || oneX - xNum < 0)
		{
			//cout << "Failed X part 2 \n";
			cout << "Please re-enter valid X: ";
			system("pause");
			system("cls");
			print(board);
			moveOne(oneX, oneY, twoX, twoY, board);
			return;
		}

		//cout << "I passed x part 2! \n";
		xPass = true;
	}

	if ((xNum < 0 || xNum > 5))
	{
		cout << "Please re-enter valid X: ";
		system("pause");
		system("cls");
		print(board);
		moveOne(oneX, oneY, twoX, twoY, board);
		return;
	}

	//------------------------------check y coordinates now
	//check if coordinate is out of bounds and speed displacement is greater than one or
	//less than zero
	cout << "Enter Y coordinates: ";
	cin >> coordY;

	//destination - current location
	if (  (coordY-1) - oneY > 1  || (coordY - 1) - oneY < 0  )
	{
		//cout << "Failed Y part 1 \n";
	}
	else
	{
		yPass = true;
	}
	
	if (yPass == false)
	{
		//current location - destination
		if ( ((oneY+1) - coordY > 1  ) || ( (oneY+1) - coordY < 0)   )
		{
			/*cout << "Failed Y part 2 \n";
			cout << "Please re-enter valid Y: ";*/		
			system("pause");
			system("cls");
			print(board);
			moveOne(oneX, oneY, twoX, twoY, board);
			return;
		}
		cout << "I passed part 2! \n";
		yPass = true;
	}

	while (coordY < 1 || coordY > 6)
	{
		cout << "Please re-enter valid Y: ";
		system("pause");
		system("cls");
		print(board);
		moveOne(oneX, oneY, twoX, twoY, board);
		return;
	}
	
	if (xPass == false && yPass == false)
	{
		//cout << "do nothing \n";
		return;
	}

	else {
		if (board[coordY - 1][xNum] == board[oneY][oneX])
		{
			char answer;
			cout << "You didn't move. \n"
				<< "Re-enter coordinates or quit? \n";
			cout << "------------------------- \n"
				<< "[Any key] Re-enter \n"
				<< "[N] No\n"
				<< "Choice: ";
			cin >> answer;
			if (answer == 'n' || answer == 'N')
			{		
				exit(1);				
			}
			else
			{
				system("cls");
				print(board);
				moveOne(oneX, oneY, twoX, twoY, board);
				return;
			}

		}

		if (board[coordY - 1][xNum] != board[twoY][twoX])
		{
			board[coordY - 1][xNum] = '$';
			board[oneY][oneX] = 'X';
			oneY = coordY - 1;
			oneX = xNum;
			print(board);
			cout << "success! \n";
			//to save time compiling when it succeeds
			/*oneY = 5;
			oneX = 5;
			board[oneY][oneX] = '$';
			board[coordY - 1][xNum] = 'X';
			moveOne(oneX, oneY, twoX, twoY, board);*/
		}

		else
		{
			cout << "That's where the other ship is!";
			system("pause");
			moveOne(oneX, oneY, twoX, twoY, board);
		}
	}
	
}

void print(char board[][6])
{
	char abcRow[6] = { 'A', 'B', 'C', 'D', 'E','F' };

	cout << "   ";
	for (int i = 0; i < 6; i++)
	{
		cout << abcRow[i] << " ";
	}
	cout << "\n";

	for (int i = 0; i < 6; i++)
	{
		cout << i + 1 << " ";
		for (int j = 0; j < 6; j++)
		{
			cout << " ";
			if (board[i][j] == '$')
				cout << board[i][j];
			else if (board[i][j] == '&')
				cout << board[i][j];
			else
				cout << "X";
			
		}
		cout << "\n";
	}
}
