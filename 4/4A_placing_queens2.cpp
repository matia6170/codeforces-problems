#include <stdio.h>

#include <vector>

using namespace std;

int k = 2, n = 3, m = 4;
int qCnt = k, possibleBoards = 0;

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
bool solveNQueens(vector<vector<bool> > &vvb, int c, int qCnt) {
    if (c >= n || qCnt <= 0) {
        // printBoard(vvb);
        possibleBoards++;

        return false;  // end of recursion
    }
    for (int row = 0; row < m; row++) {
        // add for loop for columsn
        for (int col = c; col <= n - qCnt; col++) {
            if (canPlace(vvb, row, col)) {
                vvb[row][col] = true;

                if (solveNQueens(vvb, col + 1, qCnt - 1)) {
                    return true;
                }
                vvb[row][col] = false;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<bool> > vvb;
    scanf("%d %d %d", &k, &n, &m);

    for (int i = 0; i < m; i++) {
        vector<bool> vb;
        for (int j = 0; j < n; j++) {
            vb.push_back(false);
        }
        vvb.push_back(vb);
    }

    

    solveNQueens(vvb, 0, k);
    printf("%d\n", possibleBoards);
}