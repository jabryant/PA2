#include <iostream>
#include <fstream>
using namespace std;

int main() {

	ifstream input("sudokuboard.txt");

	string board[9];
	for(int i=0;i<9;i++) {
		input >> board[i];
	}

	int rowrepeat[9] = {0};
	for(int r=0;r<9;r++) {
		for(int i=0;i<9;i++) {
			for(int j=1;j<10;j++) {
				if (board[r][i] == j) {
					rowrepeat[j-2] += 1;
				}
			}
		}
	}

	int valid = 1;

	for(int i=0;i<9;i++) {
		if (rowrepeat[i] != 1) {
			valid = 0;
			break;
		}
	}

	int colrepeat[9] = {0};
	for(int c=0;c<9;c++) {
	    for(int i=0;i<9;i++) {
	        for(int j=1;j<10;j++) {
	        	if (board[i][c] == j) {
	        		rowrepeat[j-2] += 1;
	            }
	        }
	    }
    }

	for(int i=0;i<9;i++) {
		if (colrepeat[i] != 1) {
			valid = 0;
			break;
		}
	}

	int boxrepeat[9] = {0};
	for(int x=0;x<3;x++) {
		for(int y=0;y<3;y++) {
			for(int r=0;r<3;r++) {
				for(int c=0;c<3;c++) {
					for(int j=1;j<10;j++) {
						if (board[r][c] == j) {
							boxrepeat[j-2] +=1;
						}
					}
				}
			}
		}
	}

	for(int i=0;i<9;i++) {
		if (boxrepeat[i] != 1) {
			valid = 0;
			break;
		}
	}

	if (valid == 1) {
		cout << "This is a valid sudoku board." << endl;
	}else {
		cout << "This is not a valid sudoku board." << endl;
	}

	input.close();
}
