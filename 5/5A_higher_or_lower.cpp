#include <iostream>
#include <string>
int main() {
    using namespace std;

    unsigned long long int left = 1, right = 1000000000000000000, mid;

    string input;

    while (left <= right) {
        mid = (left+right)/2;


        cout << mid << endl;
        cin >> input;

        

        if (input[0] == 'C') {
             break;
        }else if (input[0] == 'H') {
            left = mid+1;
        } else if (input[0] == 'L') {
            right = mid-1;
        }
    }
}