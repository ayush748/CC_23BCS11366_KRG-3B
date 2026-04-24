#include <bits/stdc++.h>
using namespace std;
 
vector<string> tokens;
int idx = 0;
string result;
 
bool build() {
    if (idx >= tokens.size()) return false;
 
    if (tokens[idx] == "int") {
        result += "int";
        idx++;
        return true;
    }
 
    if (tokens[idx] == "pair") {
        result += "pair<";
        idx++;
 
        if (!build()) return false;
 
        result += ",";
 
        if (!build()) return false;
 
        result += ">";
        return true;
    }
 
    return false;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    string word;
    while (cin >> word) {
        tokens.push_back(word);
    }
 
    if (build() && idx == tokens.size()) {
        cout << result << "\n";
    } else {
        cout << "Error occurred\n";
    }
}