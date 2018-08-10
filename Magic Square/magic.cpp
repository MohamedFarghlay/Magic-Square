#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //for count

using namespace std;


string square = "          ";

//intro()
void intro();

//drawboard()
void drawBoard();

//getNumber()
void getNumbers();

//checkWin()
void checkWin();

//howToPlay()
void howToPlay();

//play()
void play();

//resetSquare()
void resetSquare();


///main()
int main()
{
	
	intro();

	int choice;
	cin >> choice;

	if (choice == 1)
	{
		play();
	}
	else if (choice == 2)
	{
		howToPlay();
		cout << "\n\nTo Play Press (1)\n\nTo Exit Press (3)\n";
		cin >> choice;
		if (choice == 1)
		{
			play();
		}
		else if (choice == 3)
		{
			return 0;
		}
	}
	else if (choice == 3)
	{
		return 0;
	}
	else
	{
		cout << "\nInvalid choice!\n\n";
	}
	system("pause");
	return 0;
}



//===================================================\\


//=================Introductio to the game==============\\

void intro()
{
	system("color 1F");
	cout << "\n\n\t  Welcome To Magic Square Game\n";
	cout << "\t--------------------------------\n\n\n";
	cout << "  1-Play\n\n  2-how to play\n\n  3-exit\n\n";

}



//=====================================================\\


//=================draw the board ======================\\

void drawBoard()
{
	system("cls");
	cout << "\n\n\t   MAGIC SQUARE :)\n\n";
	cout << "Re-arrange the numbers to make the square is a magic square (:\n\n";
	cout << endl;
	cout << "\t     |     |     " << endl;
	cout << "\t  " << square[0] << "  |  " << square[1] << "  |  " << square[2] << endl;
	cout << "\t_____|_____|_____" << endl;
	cout << "\t     |     |     " << endl;
	cout << "\t  " << square[3] << "  |  " << square[4] << "  |  " << square[5] << endl;
	cout << "\t_____|_____|_____" << endl;
	cout << "\t     |     |     " << endl;
	cout << "\t  " << square[6] << "  |  " << square[7] << "  |  " << square[8] << endl;
	cout << "\t     |     |     " << endl << endl;
}


//=====================================================\\

//=====================get numbers ===================\\

void getNumbers()
{
	drawBoard();
	char index;
	for (int i = 0; i < 9; i++)
	{
		cout << "\n\nsquare " << i + 1 << ": ";
		cin >> index;
		square[i] = index;

		int c = count(square.begin(), square.end(), index);
		if (c>1)
		{
			int indx = square.find(index);
			char same = square[indx];

			while (index == same&&i != 0)
			{
				if (index != same)
					break;
				cout << "\n Repeated Number!\n\n";
				cout << "Please don't repeated numbers\n\n";
				cout << "square " << i + 1 << ":";
				cin >> index;
				square[i] = index;
			}
		}

		drawBoard();
	}
}


//=====================================================\\

//=========================== Check win================\\

void checkWin()
{
	bool flag = false;
	int s1 = int(square[0]) - 48, s2 = int(square[1]) - 48, s3 = int(square[2]) - 48, s4 = int(square[3]) - 48, s5 = int(square[4]) - 48,
		s6 = int(square[5]) - 48, s7 = int(square[6]) - 48, s8 = int(square[7]) - 48, s9 = int(square[8]) - 48;
	if (((s1 + s2 + s3) == 15) && (s1 + s4 + s7) == 15 && (s1 + s5 + s9) == 15 && (s2 + s5 + s8) == 15 && (s3 + s5 + s7) == 15 && (s3 + s6 + s9) == 15)
	{
		flag = true;
	}
	if (flag)
	{
		cout << "\n\n\tCONGRATULATIOON...YOU CREATE A MAGIC SQUARE\n\n\n";
	}
	else
	{
		cout << "\n\n\tOhhh...you lose\n\n";
	}


}


//======================================================\\


//==================How To Play===========================\\

void howToPlay()
{
	system("cls");
	cout << "\n\n\t welcome to the guide of the magic square game\n";
	cout << "\t---------------------------------------------------\n\n";
	cout << "\n\tyou must fill the boxes with number from (0 -> 9)\n\n\twitout repeated number (every box must be unique)\n";
	cout << "\n\tsuch that the sum of every 3 box must be equal to (15) \n\n";
	cout << "\tHere's an example to make you feel more comfortabe with rules\n\n";
	square[0] = '8', square[1] = '3', square[2] = '4', square[3] = '1', square[4] = '5', square[5] = '9', square[6] = '6', square[7] = '7', square[8] = '2';
	cout << "\t     |     |     " << endl;
	cout << "\t  " << square[0] << "  |  " << square[1] << "  |  " << square[2] << endl;
	cout << "\t_____|_____|_____" << endl;
	cout << "\t     |     |     " << endl;
	cout << "\t  " << square[3] << "  |  " << square[4] << "  |  " << square[5] << endl;
	cout << "\t_____|_____|_____" << endl;
	cout << "\t     |     |     " << endl;
	cout << "\t  " << square[6] << "  |  " << square[7] << "  |  " << square[8] << endl;
	cout << "\t     |     |     " << endl << endl;
	cout << "\n\tas you see the sum of every 3 boxes = 15\n";
	cout << "\n\t8 + 3 + 4 = 15 , 8 + 5 + 2 =15 and so on...\n\n";
}


//========================================================\\


//======================== Play ===========================\\

void play()
{
	char ans;
	do{
		resetSquare(); //reset the square
		getNumbers();
		checkWin();

		//ask the user for another round
		cout << "\n\nPLAY AGAIN (y or n) :";
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');//terminate on enter n

}


//=====================Reset Square===========================\\

void resetSquare()
{
	square = "          ";
}