//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
#include <vector>
const int MOD = 1e9 + 7;

class Solution {
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        vector<long long> a;
        long long ans = 1;
        a.push_back(ans);

        for (int i = 1; i < n; i++) {
            ans = (ans * (n - i)) % MOD;
            ans = (ans * modInverse(i)) % MOD;
            a.push_back(ans);
        }

        return a;
    }

private:
    long long modInverse(long long a) {
        long long m = MOD;
        long long m0 = m;
        long long y = 0, x = 1;

        if (m == 1)
            return 0;

        while (a > 1) {
            long long q = a / m;
            long long t = m;

            m = a % m;
            a = t;
            t = y;

            y = x - q * y;
            x = t;
        }

        if (x < 0)
            x += m0;

        return x;
    }
};



//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends