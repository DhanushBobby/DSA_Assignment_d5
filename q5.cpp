#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int optimalStrategy(int arr[], int n) {
    memset(dp, 0, sizeof(dp));
    for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {
            int x = ((i + 2) <= j) ? dp[i + 2][j] : 0;
            int y = ((i + 1) <= (j - 1)) ? dp[i + 1][j - 1] : 0;
            int z = (i <= (j - 2)) ? dp[i][j - 2] : 0;

            dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
        }
    }

    return dp[0][n - 1];
}

int main() {
    int arr[] = { 8, 15, 3, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum possible amount the user can win: " << optimalStrategy(arr, n);

    return 0;
}
