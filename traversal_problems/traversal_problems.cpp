/*
 * This code uses union find to solve the problem.
 * https://www.youtube.com/watch?v=ayW5B2W9hfo
 */
#include <iostream>
#include <map>
#include <cstring>
using namespace std;




map<char, bool> visited;
map<char, char> parent;

/*
 * This function initializes the union find data structure.
 * It sets the parent of each node to itself.
 */
void initUnionFind() {
    for (char i = 'a'; i <= 'z'; i++) {
        parent[i] = i;
    }
}

/*
 * This function finds the root of a node.
 * It uses recursion to find the root.
 */
char findRoot(char a) {
    if (parent[a] != a) {
        return findRoot(parent[a]);
    }
    return a;
    
}

/*
 * This function merges two trees.
 * It finds the root of each tree and sets the parent of the root of the first tree to the root of the second tree.
 */
void mergeTree(char a, char b) {
    char pA = parent[a];
    char pB = parent[b];
    if (pA != pB) {
        parent[pA] = pB;
    }
}

int main() {
    int n; 
    char str[51];
    initUnionFind();
    scanf("%d", &n);
    
    while(n--){
        scanf("%s", str); // read each password
        int len = strlen(str);
        visited[str[0]] = true; // mark the first character as visited
        for (int i = 1; i < len; i++) { // for each character in the password
            visited[str[i]] = true; // mark the character as visited
            mergeTree(str[i], str[i-1]); // merge the current character with the previous character
        }

    }

    int count = 0;
    for (char i = 'a'; i <= 'z'; i++) { // count the number of connected components
        if (visited[i] && parent[i] == i) {
            count++;
        }
    }
    
    //print the number of connected components
    printf("%d\n", count);
    
}