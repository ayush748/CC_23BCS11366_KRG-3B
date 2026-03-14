#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;

        for (long long b : batteries)
            sum += b;

        long long low = 0;
        long long high = sum / n;
        long long ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;
            long long power = 0;

            for (long long b : batteries) {
                power += min(b, mid);
            }

            if (power >= mid * n) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    int n, m;

    cout << "Enter number of computers: ";
    cin >> n;

    cout << "Enter number of batteries: ";
    cin >> m;

    vector<int> batteries(m);

    cout << "Enter battery capacities:\n";
    for (int i = 0; i < m; i++) {
        cin >> batteries[i];
    }

    Solution obj;
    cout << "Maximum Run Time: " << obj.maxRunTime(n, batteries) << endl;

    return 0;
}