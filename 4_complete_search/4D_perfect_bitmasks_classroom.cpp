#include <iostream>

int validate(int x) {
    int y = 1;

    // // if (((x & y) > 0) && ((x ^ y) > 0)) return 0;

    // // y = 1;
    // while (!(((x & y) > 0) && ((x ^ y) > 0))) {
    //     y++;

    // }

    while(!(y & x) && y <= x) {
        y <<= 1;
    }
    if (y< x ){
        return y;
    }

    int index = 1; 
    while (index <=x && (x& index)) {
        index <<= 1;
    }


    return y + index;
}

int main() {
    int t, x, y = 1;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &x);


        printf("%d\n", validate(x));
    }
}