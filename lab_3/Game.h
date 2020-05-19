
/* 
 * File:   Game.h
 * Author: rafal
 *
 * Created on 11 maja 2020, 17:33
 */

#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <limits>
#include "Player.h"
#include "Move.h"

#define OS "windows" // windows / linux / apple
#define ALPHA -2147483647 // alpha to -nieskonczonsc
#define BETA 2147483647 // alpha to -nieskonczonsc

using namespace std;

class Game {
	unsigned int num_players = 2, board_size = 0, how_much_wins_to_win = 1, how_much_shapes = 3;
	vector<vector < string >> data;
	vector < string > alphabet = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
	vector < string > small_alphabet = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
	vector<Player> players;
	int current_player = 0, num_moves = 0, num_rounds = 0;
	bool CPUMode = false;
public:

	Game() {
		players.reserve(2);
	}

	void showMainMenu() {
		//		clearConsole();
		int menu = -1;
		while (menu != 9) {

			cout << "-------------------------------------" << endl;
			cout << "\t" << "Menu" << endl;
			cout << "\t" << "0. Wyczyść konsole" << endl;
			cout << "\t" << "1. Graj gracz vs gracz" << endl;
			cout << "\t" << "2. Graj gracz vs CPU" << endl;
			cout << "\t" << "9. Wyjdź z gry" << endl;

			cin >> menu;
			switch (menu) {
				case 0:
					clearConsole();
					break;
				case 1:
					playerVSplayer();
					break;
				case 2:
					playerVSCPU();
					break;
				case 9:
					break;

				default:
					cout << "Nie ma takiej opcji. Spróbuj jeszcze raz";
			}
		}
	}
private:

	void playerVSCPU() {
		string name;
		string shape;
		players.clear();
		CPUMode = true;
		int size = 3;
		num_rounds = 0;

		// setup gracza numer 1
		cout << "-------------------------------------" << endl;
		cout << "Imie gracza: ";
		cin >> name;
		cout << "Kształt gracza ( O/X ): ";
		cin >> shape;
		while (shape != "O" && shape != "X") {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();
			cin.sync();
			cout << endl << "Niepoprawny kształt. Spróbuj ponownie ( O/X ):";
			cin >> shape;
		}
		players.push_back(Player(name, shape));

		// setup gracza numer 2
		shape = shape == "X" ? "O" : "X";
		players.push_back(Player("CPU", shape));

		// setup ustawień gry
		cout << endl << "Pomyślnie dodano graczy. Wybierz rozmiar kwadratowej planszy (np. 3):";
		cin >> board_size;
		while (board_size < 2) {
			cin.ignore(10000, '\n');
			cin.clear();
			cout << endl << "Niepoprawny rozmiar planszy. Spróbuj ponownie (np. 3):";
			cin >> board_size;
		}

		cout << endl << "Ile znaków pod rząd do wygranej( 2-" << board_size << " ): ";
		cin >> how_much_shapes;
		while (how_much_shapes < 2 || how_much_shapes > board_size) {
			cin.ignore(10000, '\n');
			cin.clear();
			cout << endl << "Wymagana liczba większa od 0. Spróbuj ponownie( 2-" << board_size << " ):";
			cin >> how_much_shapes;
		}

		cout << endl << "Do ilu wygranych chcesz zagrać: ";
		cin >> how_much_wins_to_win;
		while (how_much_wins_to_win < 1) {
			cin.ignore(10000, '\n');
			cin.clear();
			cout << endl << "Wymagana liczba większa od 0. Spróbuj ponownie( 2-9 ):";
			cin >> how_much_wins_to_win;
		}


		clearConsole();
		cout << endl << "Pomyślny setup gry. Gra rozpoczyna się..." << endl;
		startGame();
	}

	void playerVSplayer() {
		string name;
		string shape;
		CPUMode = false;
		players.clear();
		num_rounds = 0;

		// setup gracza numer 1
		cout << "-------------------------------------" << endl;
		cout << "Imie gracza numer 1: ";
		cin >> name;
		cout << "Kształt gracza numer 1 ( O/X ): ";
		cin >> shape;
		while (shape != "O" && shape != "X") {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();
			cin.sync();
			cout << endl << "Niepoprawny kształt. Spróbuj ponownie ( O/X ):";
			cin >> shape;
		}
		players.push_back(Player(name, shape));

		// setup gracza numer 2
		cout << "Imie gracza numer 2: ";
		cin >> name;
		shape = shape == "X" ? "O" : "X";
		players.push_back(Player(name, shape));

		// setup ustawień gry
		cout << endl << "Pomyślnie dodano graczy. Wybierz rozmiar planszy (np. 3):";
		cin >> board_size;
		while (board_size < 2) {
			cin.ignore(10000, '\n');
			cin.clear();
			cout << endl << "Niepoprawny rozmiar planszy. Spróbuj ponownie (np. 3):";
			cin >> board_size;
		}


		cout << endl << "Ile znaków pod rząd do wygranej( 2-" << board_size << " ): ";
		cin >> how_much_shapes;
		while (how_much_shapes < 2 || how_much_shapes > board_size) {
			cin.ignore(10000, '\n');
			cin.clear();
			cout << endl << "Wymagana liczba większa od 0. Spróbuj ponownie( 2-" << board_size << " ):";
			cin >> how_much_shapes;
		}


		cout << endl << "Do ilu wygranych chcecie zagrać: ";
		cin >> how_much_wins_to_win;
		while (how_much_wins_to_win < 1) {
			cin.ignore(10000, '\n');
			cin.clear();
			cout << endl << "Wymagana liczba większa od 0. Spróbuj ponownie( 2-9 ):";
			cin >> how_much_wins_to_win;
		}


		clearConsole();
		cout << endl << "Pomyślny setup gry. Gra rozpoczyna się..." << endl;
		startGame();
	}

	void startGame(int round = 1, int start_player = 1) {
		string tmp;
		clearConsole();

		generateBoard();

		if (start_player < 0)
			current_player = current_player ? 0 : 1;
		else
			current_player = start_player;
		num_moves = 0;
		num_rounds++;

		// pytaj o następny ruch aż ktoś nie wygra, lub nie skończą się miejsca na planszy
		while (!checkWin() && !checkNoResults()) {
			current_player = current_player > 0 ? 0 : 1;
			renderBoard(round);
			askForResponse();
		}
		renderBoard(round);

		// sprawdź czy ktoś mógł wygrać
		if (!checkWin() && checkNoResults()) {
			cout << endl << "Nie można rozstrzygnąć wygranej" << ". Wykonano " << num_moves << " ruchów." << endl;
		} else {
			players[current_player].win_games++;
			cout << endl << "Wygrał gracz numer " << current_player + 1 << ". Wykonano " << num_moves << " ruchów." << endl;
		}


		if (how_much_wins_to_win <= players[0].win_games) {
			cout << "Grę wygrał gracz o numerze " << 1 << endl;
			renderStatitsics();
		} else
			if (how_much_wins_to_win <= players[1].win_games) {
			cout << "Grę wygrał gracz o numerze " << 2 << endl;
			renderStatitsics();
		} else {
			cout << "Następna runda? (cokolwiek)" << endl;
			cin >> tmp;

			startGame(++round, current_player > 0 ? 0 : 1);
		}
	}

	void renderBoard(int round = 1) {
		clearConsole();
		cout << "-------------------------------------" << endl;
		cout << "\t   Runda " << round << endl;
		cout << "\t" << (players[0]).name << "\t" << "|" << "\t" << (players[1]).name << endl;
		cout << "\t" << (players[0]).win_games << "\t" << "|" << "\t" << (players[1]).win_games << endl;
		cout << "-------------------------------------" << endl;
		cout << "\t  ";
		for (int i = 0; i < board_size; i++) {
			cout << alphabet[i] << "   ";
		}
		cout << endl;
		for (int i = 0; i < board_size; i++) { // przechodzi po wierszach
			cout << "\t" << i + 1 << " ";
			for (int j = 0; j < board_size; j++) { // przechodzi po kolumnach
				cout << data[j][i];
				if (j < board_size - 1)
					cout << " | ";
			}
			cout << endl;
			if (i >= board_size - 1)
				continue;
			cout << "\t  ";
			for (int j = 0; j < board_size - 1; j++)
				cout << "- + ";
			cout << "-";
			cout << endl;
		}
	}

	void renderStatitsics() {
		cout << "-------------------------------------" << endl;
		for (int i = 0; i < players.size(); i++) {
			cout << "Gracz numer " << i + 1 << endl;
			cout << players[i].name << "\t" << players[i].win_games << " wygranych rund" << endl;
		}
	}

	void askForResponse() {
		if (current_player < 1 || !CPUMode) { // pytaj gracza
			string response;
			cout << endl << "Ruch gracza numer " << current_player + 1 << ". " << players[current_player].name;
			cout << endl << "Gdzie chcesz postawić " << players[current_player].shape << "? Np. (A1):";
			cin >> response;
			int column = findPositionInAlphabet(response.substr(0, 1));
			int row = stoi(response.substr(1, 2)) - 1;

			if (column < 0 || column >= board_size || row < 0 || row >= board_size) {
				cout << "Podano błędne współrzędne. Spróbuj jeszcze raz.";
				askForResponse();
			} else
				if (checkIfResponseExist(column, row)) {
				cout << "To miejsce nie jest puste. Spróbuj jeszcze raz";
				askForResponse();
			} else
				setMove(column, row, players[current_player].shape);

		} else {
			// pytam komputera o ruch
			Move move = getNextMove();
			setMove(move, players[current_player].shape);
		}
	}

	bool checkWin(int player = -1) {
		if (player == -1)
			player = current_player;

		return maxInOneRow(player) >= how_much_shapes//
				|| maxInOneColumn(player) >= how_much_shapes //
				|| maxInDiagonal1(player) >= how_much_shapes //
				|| maxInDiagonal2(player) >= how_much_shapes;
	}

	bool checkNoResults() {
		for (vector<string> elem : data) // kolejne kolumny
			for (int i = 0; i < elem.size(); i++) // kolejne wiersze
				if (elem[i] == " ")
					return false;
		return true;
	}

	Move getNextMove() {
		vector<Move> moves = generateAvaiableMoves();
		int best_move_value = numeric_limits<int>::min();
		Move best_move = moves[1];

		int next_player = current_player > 0 ? 0 : 1;

		for (Move move : moves) {
			setMove(move, players[current_player].shape);
			int move_value = minMax(1, next_player, ALPHA, BETA);

			if (move_value > best_move_value) {
				best_move = move;
				best_move_value = move_value;
			}

			revertMove(move);
		}

		return best_move;
	}

	int minMax(unsigned int level, int player, int alpha, int beta) {
		// 0 - user
		// 1 AI
		if (board_size < 20 && level == 10) // jesli wielkosc planszy mniejsza niz 20 to maksymalna glebokosc rekurencji wynosi 10
			return 0;
		else // w przypadku większej wielkosci planszy maksymalna glebokosc rekurencji wynosi 5
			if (board_size >= 20 && level == 5)
			return 0;

		if (checkWin(1))
			return 1;

		if (checkWin(0))
			return -1;

		if (checkNoResults())
			return 0;

		bool oposite_player_move = current_player != player;
		int best = oposite_player_move ? numeric_limits<int>::max() : numeric_limits<int>::min();
		vector<Move> moves = generateAvaiableMoves();

		if (!oposite_player_move) // gra AI
		{
			for (Move move : moves) {
				setMove(move, players[player].shape);
				int value = minMax(level + 1, 0, alpha, beta);
				revertMove(move);
				best = max(best, value);
				alpha = max(alpha, value);
				if (beta <= alpha)
					break;
			}
		} else { //gra user
			for (Move move : moves) {
				setMove(move, players[player].shape);
				int value = minMax(level + 1, 1, alpha, beta);
				revertMove(move);
				best = min(best, value);
				beta = min(beta, value);
				if (beta <= alpha)
					break;
			}
		}
		return best;
	}
	//###########################################################3

	int maxInDiagonal1(int player) {
		string shape = players[player].shape;
		int howMuch = 0;

		// skanowanie 1 przekątnej
		for (int i = 0; i < board_size; i++) { // numer kolumny
			if (data[i][i] == shape)
				howMuch++;
			else
				howMuch = 0;
		}

		return howMuch;
	}

	int maxInDiagonal2(int player) {
		string shape = players[player].shape;
		int howMuch = 0;

		// skanowanie 2 przekątnej
		howMuch = 0;
		for (int i = 0; i < board_size; i++) { // numer kolumny
			if (data[board_size - 1 - i][i] == shape)
				howMuch++;
			else
				howMuch = 0;
		}

		return howMuch;
	}

	int maxInOneColumn(int player) {
		string shape = players[player].shape;
		int howMuch = 0, max = 0;

		for (vector<string> elem : data) { // kolejne kolumny
			howMuch = 0;
			for (int i = 0; i < elem.size(); i++) { // kolejne wiersze
				if (elem[i] == shape)
					howMuch++;
				else
					howMuch = 0;
			}
			if (howMuch > max)
				max = howMuch;
		}

		return max;
	}

	int maxInOneRow(int player) {
		string shape = players[player].shape;
		int howMuch = 0, max = 0;
		for (int i = 0; i < board_size; i++) { // numer kolumny
			howMuch = 0;
			for (int j = 0; j < board_size; j++) { // numer wiersza
				if (data[j][i] == shape)
					howMuch++;
				else
					howMuch = 0;
			}
			if (howMuch > max)
				max = howMuch;
		}
		return max;
	}

	vector<Move> generateAvaiableMoves() {
		vector<Move> moves;

		for (int row = 0; row < data.size(); row++)
			for (int col = 0; col < data[row].size(); col++)
				if (data[col][row] == " ")
					moves.push_back(Move(col, row, "O"));

		return moves;
	}

	void generateBoard() {
		data.clear();
		data.reserve(board_size);

		for (int i = 0; i < board_size; i++) {
			vector < string> tmp;
			tmp.reserve(board_size);
			for (int i = 0; i < board_size; i++)
				tmp.push_back(" ");
			data.push_back(tmp);
		}
	}

	void setMove(int col, int row, string shape) {
		num_moves++;
		data[col][row] = shape;
	}

	void setMove(Move& move, string shape) {
		num_moves++;
		data[move.column][move.row] = shape;
	}

	void setMove(Move& move) {
		num_moves++;
		data[move.column][move.row] = move.shape;
	}

	void revertMove(Move& move) {
		num_moves--;
		data[move.column][move.row] = " ";
	}

	bool checkIfResponseExist(int column, int row) {
		return data[column][row] != " ";
	}

	int findPositionInAlphabet(string key) {
		for (int i = 0; i < alphabet.size(); i++)
			if (alphabet[i] == key || small_alphabet[i] == key)
				return i;
		return -1;
	}

	void clearConsole() {
		if (OS == "windows" || OS == "apple") // czy apple to nie wiem czy tak 
			system("clear");
		else if (OS == "linux")
			system("cls");
	}

};



#endif /* GAME_H */

