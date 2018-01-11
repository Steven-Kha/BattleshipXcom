#include <iostream>
#include <string>
using std::string;
using namespace std;

void moveOne(int & oneX, int & oneY, int & twoX, int & twoY, char board[][6]);
void print(char board[][6]);
int main() {
	
	char oceanBoard[6][6] = {};
	int OneX = 0;
	int OneY = 0;
	int TwoX = 5;
	int TwoY = 5;

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
	int xNum = 0;
	cout << "------------------------";
	
	cout << "Enter X coordinate: ";
	cin >> coordX;

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

	while (xNum < 0 || xNum > 6)
	{
		cout << "Please re-enter valid X: ";
		cin >> coordX;
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
	}

	cout << "Enter Y coordinates: ";
	cin >> coordY;
	while (coordY < 0 || coordY > 6)
	{
		cout << "Please re-enter valid Y: ";
		cin >> coordY;
	}

		

	if (board[coordY - 1][xNum] != board[twoY][twoX])
	{
		board[coordY - 1][xNum] = '$';
		board[oneY][oneX] = 'X';
		oneY = coordY - 1;
		oneX = xNum;
		print(board);
	}

	else
	{
		cout << "That's where the other ship is!";
		system("pause");
		moveOne(oneX, oneY, twoX, twoY, board);
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
