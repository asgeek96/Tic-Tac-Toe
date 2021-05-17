#include <iostream>
#include <stdlib.h>
#include <Windows.h>
using namespace std;
char square[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
int checkwin()
{
	int i, n = 0;
	if (n == 0)
	{
		for (i = 0; i < 9; i = i + 3)
		{
			if (square[i] == square[i + 1] && square[i + 1] == square[i + 2])
			{
				if (square[i] == 'X')
					return 1;
				else if (square[i] == 'O')
					return 2;
			}
			else
				n++;
		}
	}
	else if (n > 2)
	{
		for (i = 0; i < 3; i++)
		{
			if (square[i] == square[i + 3] && square[i + 3] == square[i + 6])
			{
				if (square[i] == 'X')
					return 1;
				else if (square[i] == 'O')
					return 2;
			}
			else
				n++;
		}
	}
	else if (n > 5)
	{
		if (square[0] == square[4] && square[4] == square[8])
		{

			if (square[0] == 'X')
				return 1;
			else if (square[0] == 'O')
				return 2;
		}
		else if (square[2] == square[4] && square[4] == square[6])
		{
			if (square[2] == 'X')
				return 1;
			else if (square[2] == 'O')
				return 2;
		}
		else
			return 0;
	}
}
void mark(int player, int box)
{
	if (player == 1)
	{
		square[box] = 'X';
	}
	else
	{
		square[box] = 'Y';
	}
}
void display()
{
	system("cls");
	for (int i = 0; i < 9; i++)
	{
		cout << square[i] << "\t";
		if (i == 2 || i == 5 || i == 8)
			cout << "\n";
	}
}
void p_v_p()
{
	int player1 = 1, player2 = 2;
	int box, result = 0, flag = 0;
	for (int i = 1; i < 5; i++)
	{
		cout << "Player  " << player1 << "Enter the Box" << endl;
		cin >> box;
		while (square[box] == 'X' || square[box] == 'Y')
		{
			cout << "\nField already occupied.\n\nEnter the correct
						field -\n\n ";
						cin >>
				box;
		}
		mark(player1, box);
		display();
		result = checkwin();
		if (result == 1)
		{
			cout << "Congratualtions! player" << player1 << "has Won" << endl;
			flag = 1;
			break;
		}
		else if (result == 2)
		{
			cout << "Congratualtions! player" << player2 << "has Won" << endl;
			flag = 1;
			break;
		}
		cout << "Player" << endl
			 << player2 << "Enter the Box" << endl;
		cin >> box;
		while (square[box] == 'X' || square[box] == 'Y')
		{
			cout << "\nField already occupied.\n\nEnter the correct field
\n\n ";
					cin >>
				box;
		}
		mark(player2, box);
		display();
		result = checkwin();
		if (result == 1)
		{
			cout << "Congratualtions! player" << player1 << "has
				Won "<<endl;
				flag = 1;
			break;
		}
		else if (result == 2)
		{
			cout << "Congratualtions! player" << player2 << "has
				Won "<<endl;
				flag = 1;
			break;
		}
	}
	if (flag == 0)
		cout << " \n Sorry, The game is a draw " << endl;
}
void p_v_pc()
{
	int player1 = 1, computer = 2;
	int box, result = 0, flag = 0;
	for (int i = 1; i < 5; i++)
	{
		cout << "Player  " << player1 << "Enter the Box" << endl;
		cin >> box;
		while (square[box] == 'X' || square[box] == 'Y')
		{
			cout << "\nField already occupied.\n\nEnter the correct field
\n\n ";
					cin >>
				box;
		}
		mark(player1, box);
		display();
		result = checkwin();
		if (result == 1)
		{
			cout << "Congratualtions! player" << player1 << "has
				Won "<<endl;
				flag = 1;
			break;
		}
		else if (result == 2)
		{
			cout << "Congratualtions! player" << computer << "has
				Won "<<endl;
				flag = 1;
			break;
		}
		cout << "Player" << endl
			 << computer << "Enter the Box" << endl;
		box = rand() % 8 + 1;
		while (square[box] == 'X' || square[box] == 'Y')
		{
			box = rand() % 8 + 1;
		}
		mark(computer, box);
		display();
		result = checkwin();
		if (result == 1)
		{
			cout << "Congratualtions! player" << player1 << "has Won" << endl;
			flag = 1;
			break;
		}
		else if (result == 2)
		{
			cout << "Congratualtions! player" << computer << "has
				Won "<<endl;
				flag = 1;
			break;
		}
	}
	if (flag == 0)
		cout << " \n Sorry, The game is a draw " << endl;
}
int main()
{
	for (;;)
	{
		int ch;
		cout << "1.Player vs Player" << endl
			 << "
			2.Computer vs Player "<<endl<<" 3.Exit "<<endl;
			cout
			 << "Enter your choice" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			p_v_p();
			break;
		case 2:
			p_v_pc();
			break;
		default:
			exit(0);
		}
	}
	return 0;
}
