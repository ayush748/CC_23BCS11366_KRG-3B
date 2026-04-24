#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    map<long long, long long> events;
 
    for (int i = 0; i < n; i++) {
        long long l, r;
        cin >> l >> r;
        events[l] += 1;
        events[r + 1] -= 1;
    }
 
    vector<long long> cnt(n + 1, 0);
 
    long long prev = -1;
    long long coverage = 0;
 
    for (auto &[x, delta] : events) {
        if (prev != -1 && coverage > 0) {
            long long len = x - prev;
            cnt[coverage] += len;
        }
 
        coverage += delta;
        prev = x;
    }
 
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << " ";
    }
    cout << "\n";
 
    return 0;
}