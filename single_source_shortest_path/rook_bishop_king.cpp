#include <iostream>
using namespace std;

int abs(int a) {
    return a < 0 ? -a : a;
}


int main() {
    int r1, c1, r2, c2;
    int rook, bishop, king;

    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

    // first case
    if (r1 == r2 && c1 == c2) {
        rook = bishop = king = 0;
        goto end;
    }

    // rook
    if (r1 == r2 || c1 == c2) {
        rook = 1;
    } else {
        rook = 2;
    }

    // bishop
    if ((r1 + c1) % 2 != (r2 + c2) % 2) {  // on the wrong color?
        bishop = 0;

    } else if (abs(r1 - r2) == abs(c1 - c2)) {
        bishop = 1;
    } else {
        bishop = 2;
    }

    // king
    //king += abs(r1 - r2) > abs(c1 - c2) ? abs(r1 - r2) : abs(c1 - c2);
    if (abs(r1 - r2) > abs(c1 - c2)){
        king = abs(r1 - r2);
    } else {
        king = abs(c1 - c2);
    }

end:
    printf("%d %d %d\n", rook, bishop, king);
    return 0;
}