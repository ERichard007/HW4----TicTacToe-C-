// Programmer: Evan Richard
// Date: 3/10/24 
// File: HW#4
// Assignment: HW4
// Purpose: Designing a tic-tac-toe game up to size 9x9.

#include <iostream>
#include <string>
using namespace std;

/*INITIATORS*/

/*
Gen: prints a welcome message to the player at very beginning of game.
Post: welcome message is printed out to the output.
*/
void printWelcomeMessage();

/*
Gen: shows the game menu to the player, offering differing board sizes and option to quit.
Post: Menu displayed to player with prompt to choose an option.
*/
void displayMenu();

/*
Gen: Prepares the board string and fills it with the desired amount of numbered positions.
Pre: size must be nonnegative.
Post: Returns a string for board with filled positions.
*/
string initializeBoard(const int size);

/*
Gen: Prints the current state of the game board.
Pre: board must be initialized already.
Post: Prints out current state of the board in tic-tac-toe format.
*/
void printBoard(const string& board, const int size);

/*
Gen: Updates the board based off the player's cell choice.
Pre: chosen cell must be within the constraints of the board size. So 45 is not in a board sized 3x3.
Post: Updates the game board string replacing numbers with player's symbol.
*/
void updateBoard(string& board, const string& chosenCell, const string& playerSymbol);

/*
Gen: Checks if a player has won the game.
Post: Returns a bool value equal to if a player has won or not. If a player has won, will print out a winning message.
*/
bool checkWin(const string& board, const int size, const string& player1Name, const string& player2Name);

/*
Gen: checks if the game is tied if noone has won.
Post: Will return a bool value equal to if the game has tied or not. If the game has tied will print out a message saying game has tied.
*/
bool checkTie(const string& board);

/*
Gen: prints out a goodbye message.
Post: message printed out onto the screen and program ends.
*/
void printGoodbyeMessage();

/*START*/

int main() {
	/*INITIATES GAME*/
	int playerChoice;

	string newBoard;
	string player1Cell; 
	string player2Cell;  

	string player1Name;
	string player2Name;

	bool willPlay = false;

	printWelcomeMessage();

	cout << "\nEnter name of player 1: ";
	cin >> player1Name; 
	cout << "Enter name of player 2: ";
	cin >> player2Name; 
	cout << endl;

	displayMenu();
	cin >> playerChoice;  
	cout << endl;

	switch (playerChoice) { 
	case 1:
		willPlay = true;  
		break;
	case 2:
		willPlay = true; 
		break;
	case 3:
		willPlay = true;
		break;
	case 4:
		willPlay = true;
		break;
	case 5:
		willPlay = true;
		break;
	case 6:
		willPlay = true;
		break;
	case 7:
		willPlay = true; 
		break;
	default:
		break;
	}

	/*GAME BEGINS*/
	while (willPlay == true) {
		int size = playerChoice + 2; 

		newBoard = initializeBoard(size); 

		printBoard(newBoard, size); 

		//repeats until their is a winner of a tie.
		while ((checkWin(newBoard,size,player1Name,player2Name) == false) && (checkTie(newBoard) == false)) { 
			cout << player1Name << "(SS), choose a cell: ";
			cin >> player1Cell;

			//checks valid input if within menu range and if the cell chosen is an option left on the board.
			while (stoi(player1Cell) < 1 || stoi(player1Cell) > (size * size) || (isdigit(newBoard[(stoi(player1Cell) * 2) - 1])) == false) {
				cout << player1Name << "(SS), choose a cell: "; 
				cin >> player1Cell; 
			}

			cout << endl; 
			updateBoard(newBoard, player1Cell, "SS");
			printBoard(newBoard, size);  

			//checks for win or tie again after first turn.
			if ((checkWin(newBoard,size,player1Name,player2Name) == true) || (checkTie(newBoard) == true)) {
				break;
			}

			//repeats the above with player 2.
			cout << player2Name << "(TT), choose a cell: ";
			cin >> player2Cell;

			while (stoi(player2Cell) < 1 || stoi(player2Cell) > (size * size) || (isdigit(newBoard[(stoi(player2Cell) * 2) - 1])) == false) { 
				cout << player2Name << "(TT), choose a cell: "; 
				cin >> player2Cell; 
			}

			cout << endl; 
			updateBoard(newBoard, player2Cell, "TT");
			printBoard(newBoard, size);
			
		}

		//displays menu again to give player choice to start over.
		cout << endl; 
		displayMenu();
		cin >> playerChoice;
		cout << endl;

		switch (playerChoice) {
		case 1:
			willPlay = true;
			break;
		case 2:
			willPlay = true;
			break;
		case 3:
			willPlay = true;
			break;
		case 4:
			willPlay = true;
			break;
		case 5:
			willPlay = true;
			break;
		case 6:
			willPlay = true;
			break;
		case 7:
			willPlay = true;
			break;
		default:
			willPlay = false;
			break;
		}
	}

	/*GAME ENDS*/
	printGoodbyeMessage();

	return 0;
}

/*DISPLAY FUNCTIONS*/

void printWelcomeMessage() {
	cout << "Welcome to Dynamic Tic-Tac-Toe by Evan Richard!" << endl;
	return;
}

void displayMenu() {
	cout << "Choose the size of the Tic-Tac-Toe board or Quit:\n1. 3x3 Board\n2. 4x4 Board\n3. 5x5 Board\n4. 6x6 Board\n5. 7x7 Board\n6. 8x8 Board\n7. 9x9 Board\n8. Quit the Program\nEnter your choice: ";
	return;
}

void printBoard(const string& board, const int size) {
	cout << "Current Board:" << endl;
	int ct = 0;
	for (int i = 0;i < board.length();i += 2) {
		cout << board[i] << board[i + 1] << " ";
		ct++;
		//checks if the at end of row to start new line.
		if (ct == size) {
			cout << endl;
			ct = 0;
		}
	}
	return;
}

void printGoodbyeMessage() {
	cout << "Thank you for playing, play again soon! Goodbye!" << endl;
	return;
}

/*UPDATE/INTIALIZE FUNCTIONS*/

string initializeBoard(const int size) {
	string board;
	for (int i = 1;i <= (size * size);i++) {
		//adds 0 if under 10
		if (i < 10) {
			board += to_string(0) + to_string(i); 
		}
		else {
			board += to_string(i);
		}
	}
	return board;
} 

void updateBoard(string& board, const string& chosenCell, const string& playerSymbol) {
	for (int i = 0; i < board.length(); i += 2) {
		string numCheck;
		numCheck += board[i];
		numCheck += board[i + 1];
		if (numCheck == chosenCell) {
			board[i] = playerSymbol[0];
			board[i + 1] = playerSymbol[1];
			break;
		}
	}
	return;
}

/*CHECK WIN/TIE FUNCTIONS*/

bool checkWin(const string& board, const int size, const string& player1Name, const string& player2Name) {
	bool winner = false;
	string playerWin;

	//checks each row for a horizontal win.
	for (int i = 0;i < (board.length());i += size*2) {
		if (winner == true) {
			break;
		}
		string winValue;  
		winValue += board[i];
		winValue += board[i + 1];
		for (int j = i+2;j < i+(size*2); j += 2) {   
			string nextValue; 
			nextValue += board[j]; 
			nextValue += board[j + 1]; 
			if (winValue != nextValue) { 
				winner = false; 
				break;
			}
			else {
				playerWin = winValue;  
				winner = true; 
			}
		}
	}

	//checks for winner and breaks if their is.
	if (winner == true) {
		if (playerWin == "SS") {
			cout << "Congratulations " << player1Name << ", you won." << endl;
		}
		else {
			cout << "Congratulations " << player2Name << ", you won." << endl;
		}
		return true;
	}

	//checks each column for vertical win.
	for (int i = 0;i < size*2;i += 2) {
		if (winner == true) { 
			break;
		}
		string winValue; 
		winValue += board[i]; 
		winValue += board[i + 1]; 
		for (int j = i+(size*2);j < board.length(); j += size*2) { 
			string nextValue; 
			nextValue += board[j]; 
			nextValue += board[j + 1]; 
			if (winValue != nextValue) { 
				winner = false; 
				break;
			}
			else {
				playerWin = winValue; 
				winner = true; 
			}
		}
	}
	
	//win check
	if (winner == true) {
		if (playerWin == "SS") {
			cout << "Congratulations " << player1Name << ", you won." << endl;
		}
		else {
			cout << "Congratulations " << player2Name << ", you won." << endl;
		}
		return true;
	}

	//checks diagonal win top left to bottom right.
	for (int i = 0;i < (board.length() - (size * 2 + 2));i += (size*2+2)) {
		string winValue; 
		winValue += board[i]; 
		winValue += board[i+1]; 

		string nextValue;  
		nextValue += board[i+(size*2+2)];   
		nextValue += board[(i+(size*2+2))+1]; 

		if (winValue == nextValue) {
			playerWin = winValue; 
			winner = true;
		}
		else {
			winner = false;
			break;
		}
	}

	//win check
	if (winner == true) {
		if (playerWin == "SS") {
			cout << "Congratulations " << player1Name << ", you won." << endl;
		}
		else {
			cout << "Congratulations " << player2Name << ", you won." << endl;
		}
		return true;
	}
	
	//checks diagonal win top right to bottom left.
	for (int i = (size * 2 - 2);i < board.length() - (size * 2);i += (size * 2 - 2)) { 
		string winValue;
		winValue += board[i];
		winValue += board[i + 1];

		string nextValue;
		nextValue += board[i + (size * 2 - 2)];
		nextValue += board[(i + (size * 2 - 2)) + 1];

		if (winValue == nextValue) {
			playerWin = winValue;  
			winner = true;
		}
		else {
			winner = false;
			break;
		}
	}

	//win check
	if (winner == true) {
		if (playerWin == "SS") {
			cout << "Congratulations " << player1Name << ", you won." << endl;
		}
		else {
			cout << "Congratulations " << player2Name << ", you won." << endl;
		}
		return true;
	}

	//if no winner
	return false;
}

bool checkTie(const string& board) {
	
	//checks if every value on board is not a digit.
	for (int i = 0;i < board.length();i++) {
		if (isdigit((char)board[i]) > 0) {
			return false;
		}
	}

	cout << "Sorry, it's a Tie! Try Again." << endl;

	return true;
}
