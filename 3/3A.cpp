#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int nNames, nCommands;

    using namespace std;

    map<string, string> names;  // ip,name

    scanf("%d %d", &nNames, &nCommands);

    char input[100], data[100];

    for (int i = 0; i < nNames; i++) {
        scanf("%s %s", input, data);

        string name(input);
        string ip(data);

        names[ip+';'] = name;
    }

    for (int i = 0; i < nCommands; i++) {
        scanf("%s %s", input, data);

        string command(input);
        string ip(data);
        // printf("%s", data);
        printf("%s %s #%s\n", command.c_str(), ip.c_str(), names[ip].c_str());
    }
}
