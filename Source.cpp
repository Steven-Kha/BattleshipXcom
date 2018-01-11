#include <iostream>
#include <string>
using std::string;
using namespace std;

void move(int & oneX, int & oneY, int & twoX, int & twoY, char board[]);

int main() {

	char abcRow[6] = { 'A', 'B', 'C', 'D', 'E','F' };
	char oceanBoard[6][6] = {};
	int OneX = 0;
	int OneY = 0;
	int TwoX = 5;
	int TwoY = 5;

	oceanBoard[OneY][OneX] = '$';
	oceanBoard[TwoY][TwoX] = '&';

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
			if (oceanBoard[i][j] == '$')
			{
				cout << oceanBoard[i][j];
			}

			else if (oceanBoard[i][j] == '&')
			{
				cout << oceanBoard[i][j];
			}
			else
			{
				cout << "X";
			}
			
		}
		cout << "\n";
	}
	system("pause");
	return 0;
}

void move(int & oneX, int & oneY, int & twoX, int & twoY, char board[])
{
	system("pause");
	int coordY = 0;
	int coordX = ' ';
	char xNum = 0;
	cout << "------------------------";
	
	cout << "Enter X coordinates: ";
	cin >> coordX;

	cout << "Enter Y coordinates: ";
	cin >> coordY;

	if (coordX == 'A' || 'a')
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

}
