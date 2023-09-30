#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main() {
    char s[100001], t[100001];
    int n;
    map<pair<char, char>, int> moves;
    scanf("%s %s %d", s, t, &n);

    for (int i = 0; i < n; i++) {
        char a, b;
        int w;
        cin >> a >> b >> w;

        moves[make_pair(a, b)] = w;
    }

    for (auto& move : moves) {
        // do something with pair
        printf("%c %c %d\n", move.first.first, move.first.second, move.second);
    }
}