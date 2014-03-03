#include <iostream>
#include <fstream>
using namespace std;

int main() {

	ifstream input("tictactoeboards.txt");

	string board[99][3];
	int count=0;
	while (!input.eof()) {
		input >> board[count];
		count++;
	}

	int xrow;
	int orow;
	int diag1;
	int diag2;

	for(int i=0;i<count;i++) {
		for(int r=i*3;r<i*3+3;r++) {
			for(int c=0;c<3;c++) {
				if(board[r][c] == 'x') {
					xrow += 1;
				} else if(board[r][c] == 'o') {
					orow += 1;
				}

				if(board[i*3][0] == board[i*3+1][1] && board[i*3][0] == board[i*3+2][2]) {
					diag1 = 1;
					winner = board[i*3][0];
				}

				if(board[i*3][2] == board[i*3+1][1] && board[i*3][2] == board[i*3+2][0]) {
					diag2 = 1;
					winner = board[i*3][2];
				}
			}
		}
		if (xrow == 3 && orow == 3) {
			cout << "This game is invalid." << endl;
		}else if (xrow == 3) {
			cout << "X wins this round." << endl;
		}else if (orow == 3) {
			cout << "O wins this round." << endl;
		}else if (diag1 == 1 || diag2 == 1) {
			cout << winner << " wins this round." << endl;
		}else if (xrow != 3 && orow != 3 && diag1 != 1 && diag2 != 1) {
			cout << "This game has not been completed yet."
		}
	}

}
