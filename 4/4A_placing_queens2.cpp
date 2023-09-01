#include <stdio.h>

#include <vector>

using namespace std;

int k = 5, n = 8, m = 8;
int qCnt = k, possibleBoards = 0;

vector<vector<bool> > vvb;

void printBoard(vector<vector<bool> > &vvb) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", vvb[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}
bool canPlace(vector<vector<bool> > &vvb, int row, int col) {
    bool ret = true;
    // Check COL
    for (int i = 0; i < n; i++) {
        if (vvb[row][i]) ret = false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (vvb[i][j]) ret = false;
    }
    for (int i = row, j = col; i < m && j >= 0; i++, j--) {
        if (vvb[i][j]) ret = false;
    }

    return ret;
}
bool solveNQueens(vector<vector<bool> > &vvb, int col) {
    if (col >= n || qCnt == 0) {
        printBoard(vvb);
        possibleBoards++;
        return true;  // end of recursion

    }
    for (int row = 0; row < m; row++) {
        if (canPlace(vvb, row, col)) {
            vvb[row][col] = true;
            qCnt--;
            if (solveNQueens(vvb, col + 1)) {
                return true;


            }
            vvb[row][col] = false;
            qCnt++;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < m; i++) {
        vector<bool> vb;
        for (int j = 0; j < n; j++) {
            vb.push_back(false);
        }
        vvb.push_back(vb);
    }

    solveNQueens(vvb, 0);
    printf("Possible boards: %d\n", possibleBoards);
}