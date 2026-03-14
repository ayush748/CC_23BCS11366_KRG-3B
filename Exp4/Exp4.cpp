#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int nthMagicalNumber(int N, int A, int B) {
        long long L = min(A, B);
        long long R = (long long)N * L;
        long long lcmAB = lcm((long long)A, (long long)B);
        long long ans = 0;

        while (L <= R) {
            long long mid = L + (R - L) / 2;
            long long count = mid / A + mid / B - mid / lcmAB;

            if (count < N)
                L = mid + 1;
            else {
                ans = mid;
                R = mid - 1;
            }
        }

        return ans % MOD;
    }
};

int main() {
    Solution obj;

    int N, A, B;
    cout << "Enter N, A, B: ";
    cin >> N >> A >> B;

    cout << "Nth Magical Number: " << obj.nthMagicalNumber(N, A, B) << endl;

    return 0;
}
