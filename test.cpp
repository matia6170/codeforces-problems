#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <utility>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;


typedef pair<char, int> pci;
typedef vector<int> vi;

#define mp(a, b) make_pair(a, b)

const int NUM_CHARS = 26;
const int ASCII_OFF = 'a';

void dijkstra(vector<vi>& adj, vector<vi>& graph, int idx) {
    vector<bool> sptSet(NUM_CHARS, false);
    vi dist(NUM_CHARS, INT_MAX);
    dist[idx] = 0;

    for (int j = 0; j < NUM_CHARS - 1; ++j) {
        int min = INT_MAX, min_idx = 0;
        for (int i = 0; i < NUM_CHARS; ++i) {
            if (sptSet[i] == false && dist[i] <= min) {
                min = dist[i];
                min_idx = i;
            }
        }

        sptSet[min_idx] = true;

        for (int i = 0; i < NUM_CHARS; ++i) {
            if (!sptSet[i] && graph[min_idx][i] && dist[min_idx] != INT_MAX
                && dist[min_idx] + graph[min_idx][i] < dist[i])
                    dist[i] = dist[min_idx] + graph[min_idx][i];
        }
    }

    adj[idx] = dist;
}

int main() {
    string one, two; cin >> one >> two;

    if (one.length() != two.length()) {
        cout << -1 << endl;
        return 1;
    }

    int n; cin >> n;

    vector<vi> graph(NUM_CHARS, vi(NUM_CHARS, 0));
    char c1, c2;
    int w;
    for (int i = 0; i < n; ++i) {
        cin >> c1 >> c2 >> w;
        if (graph[c1 - ASCII_OFF][c2 - ASCII_OFF]) {
            graph[c1 - ASCII_OFF][c2 - ASCII_OFF] = graph[c1 - ASCII_OFF][c2 - ASCII_OFF] < w ? graph[c1 - ASCII_OFF][c2 - ASCII_OFF] : w;
        } else {
            graph[c1 - ASCII_OFF][c2 - ASCII_OFF] = w;
        }
    }

    vector<vi> adj(NUM_CHARS, vi{});
    for (int i = 0; i < NUM_CHARS; ++i) {
        dijkstra(adj, graph, i);
    }

    int weight = 0;
    for (int i = 0; i < one.length(); ++i) {
        int ch1 = one[i] - ASCII_OFF;
        int ch2 = two[i] - ASCII_OFF;
        if (ch1 != ch2) {
            if (adj[ch1][ch2] < adj[ch2][ch1] && adj[ch1][ch2] != INT_MAX) {
                one[i] = two[i];
                weight += adj[ch1][ch2];
            } else if (adj[ch2][ch1] != INT_MAX) {
                two[i] = one[i];
                weight += adj[ch2][ch1];
            } else {
                cout << -1 << endl;
                break;
            }
        }
    }

    cout << weight << endl;
    cout << one << endl;
}


/*

// void replace(char from, char to, string& target, string& other, ) {
//     for (int i = 0; i < target.)
// }

// int mst(unordered_map<char, vector<pci>>& graph, string& one, string& two) {
//     unordered_set<char> visited;
//     priority_queue<pci, vector<pci>, greater<pci>> pq;

//     char cur_char = graph.begin()->first;
//     pci edge = mp(cur_char, 0);

//     pq.push(edge);
//     visited.insert(cur_char);
//     int w = 0;
//     while(!pq.empty()) {
//         pci cur = pq.top(); pq.pop();

//         if (visited.find(cur.first) != visited.end()) continue;
//         w += cur.second;
//         visited.insert(cur.first);

//         one

//         for (auto pair : graph[cur.first]) {
//             pq.push(pair);
//         }
//     }

//     return w;
// }
*/