#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int minivan_road_trip(vector<int>& times, int k) {
  int n = times.size();
  vector<int> dp(n, 0);

  for (int i = 0; i <= k; i++) {
    dp[i] = times[i];
  }

  for (int i = k + 1; i < n; i++) {
    int min_val = numeric_limits<int>::max();
    for (int j = i - k - 1; j < i; j++) {
      min_val = min(min_val, dp[j]);
    }
    dp[i] = times[i] + min_val;
  }

  int result = numeric_limits<int>::max();
  for (int i = n - k; i < n; i++) {
    result = min(result, dp[i]);
  }

  return result;
}

int main() {
  // Example1
  vector<int> times1 = {8, 1, 2, 3, 9, 6, 2, 4};
  int k1 = 2;
  cout << minivan_road_trip(times1, k1) << endl;

  // Example2
  vector<int> times2 = {8, 1, 2, 3, 9, 6, 2, 4};
  int k2 = 3;
  cout << minivan_road_trip(times2, k2) << endl;

  return 0;
}
