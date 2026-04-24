#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
long long solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long max_h = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_h = max(max_h, a[i]);
    }
 
    auto check = [&](long long days) {
        long long odd_days = (days + 1) / 2;
        long long even_days = days / 2;
        long long needed1 = 0, needed2 = 0;
        
        for (int i = 0; i < n; ++i) {
            long long diff = max_h - a[i];
            needed2 += diff / 2;
            needed1 += diff % 2;
        }
        
        if (needed1 > odd_days) return false;
        
        // Convert excess needed2 to needed1 if necessary
        long long remaining_odd = odd_days - needed1;
        long long total_available = remaining_odd + even_days * 2;
        
        return total_available >= needed2 * 2;
    };
 
    auto check_target = [&](long long target) {
        long long odd_days = 0, even_days = 0;
        long long n1 = 0, n2 = 0;
        for(int i=0; i<n; ++i) {
            long long diff = target - a[i];
            n2 += diff / 2;
            n1 += diff % 2;
        }
        
        // Greedy: Use +2 for n2, +1 for n1
        // If n1 > odd days, need to use even days for +1s
        if (n1 > n2) {
            return n1 * 2 - 1;
        }
        
        // If n2 > n1, balance it
        long long diff = n2 - n1;
        long long days = n1 * 2 + (diff / 3) * 4;
        if (diff % 3 == 0) return days;
        if (diff % 3 == 1) return days + 2;
        return days + 3;
    };
 
    long long ans = min(check_target(max_h), check_target(max_h + 1));
    return ans;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}