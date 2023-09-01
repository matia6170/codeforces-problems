#include <stdio.h>

#include <string>
#include <unordered_set>

using namespace std;

// nQueens, Col, Row
int k = 2, n = 8, m = 8;

int currRow = 0, currCol = 0, queenCnt = k;

string board = "";
unordered_set<string> prevBoards;

void printBoard() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", board[m * i + j]);
        }
        printf("\n");
    }
    printf("\n");
}
void printBoard(string &argBoard) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", argBoard[m * i + j]);
        }
        printf("\n");
    }
    printf("\n");
}
bool isQueenHere(int row, int col) { return board[m * row + col] == 'Q'; }
bool isQueenHere(int index) { return board[index] == 'Q'; }
void placeQueen(int row, int col) { board[m * row + col] = 'Q'; }
void placeChar(int row, int col, char c, string &argBoard = board) {
    argBoard[m * row + col] = c;
}
int indexToCol(int index) { return index % n; }
int rcToIndex(int row, int col) { return m * row + col; }
bool canPlace(int row, int col) {
    bool ret = true;
    // Check COL
    for (int i = 0; i < n; i++) {
        if (isQueenHere(row, i)) ret = false;
    }


    
    // // Check the left-to-right diagonal (top-left to bottom-right)
    // for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    //     if (isQueenHere(i, j)) {
    //         return false; // Queen found on the left-to-right diagonal
    //     }
    // }

    // Check the right-to-left diagonal (top-right to bottom-left)
    for (int i = row, j = col; (i >= 0 || i < m) && (j>= 0 || j ); i++, j--) {
        if (isQueenHere(i, j) || rcToIndex(i, j) <= m*n) {
            return false; // Queen found on the right-to-left diagonal
        }
    }

    return ret;
}

bool checkBoard(int col) {
    if (col == n) {
        printBoard();
        return true;
    }

    bool result = false;
    for (int row = 0; row < m; row++) {
        if (canPlace(row, col)) {
            placeQueen(row, col);

            result = checkBoard(col + 1);

            placeChar(row, col, '-');
        }
    }

    return result;
}

int main() {
    string copyBoard, emptyBoard;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            board += ' ';
            copyBoard += ' ';
            emptyBoard += ' ';
        }
    }

    printBoard(copyBoard);

    int x = 0, y = 0;
    while (x != -1 || y != -1) {
        for (int i = 0; i < m * n; i++) {
            board[i] = '-';
        }
        printf("Place QUeen where??: ");
        scanf("%d %d", &x, &y);
        printf("%s \n", canPlace(x, y) ? "true" : "false");
        placeQueen(x, y);
        copyBoard = board;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!canPlace(i, j)) {
                    printf("Cannot place queen at %d, %d\n", i, j);
                    placeChar(i, j, '0', copyBoard);
                }
            }
        }
        printBoard(copyBoard);
    }
}