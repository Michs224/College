#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int main() {
    string input;
    cin >> input;

    int n = input.length();

    int dp[6];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        int prev = dp[5];

        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' ||
            input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') {

            dp[5] = (dp[4] + prev + 1) % MOD;
            dp[4] = (dp[3] + prev) % MOD;
            dp[3] = (dp[2] + prev) % MOD;
            dp[2] = (dp[1] + prev) % MOD;
            dp[1] = prev;
        } else {
            dp[5] = dp[4];
            dp[4] = dp[3];
            dp[3] = dp[2];
            dp[2] = dp[1];
            dp[1] = prev;
        }
    }

    cout << dp[5] << endl;

    return 0;
}

