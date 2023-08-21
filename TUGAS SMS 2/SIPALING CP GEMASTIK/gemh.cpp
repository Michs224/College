#include <bits/stdc++.h>
using namespace std;

int findMaxDistinct(vector<int> numbers, int n, int k) {
    set<int> distinctNumbers;
    int left = 0, right = 0;

    while (right < k) {
        distinctNumbers.insert(numbers[right]);
        right++;
    }
    right--;

    int maxDistinct = distinctNumbers.size();

    while (right < n) {
        distinctNumbers.erase(numbers[left]);
        left++;
        distinctNumbers.insert(numbers[right]);
        right++;
        if(right == n) break;
        distinctNumbers.insert(numbers[right]);
        maxDistinct = max(maxDistinct, (int)distinctNumbers.size());
    }

    maxDistinct = max(maxDistinct, (int)distinctNumbers.size());

    return maxDistinct;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> numbers;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        numbers.push_back(x);
    }

    int maxDistinct = findMaxDistinct(numbers, n, k);
    cout << maxDistinct << endl;

    return 0;
}
