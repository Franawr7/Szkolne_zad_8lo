#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector <int> &array, int x) {
    int r = array.size()-1;
    int l = 0;
    int m;
    while (l <= r) {
        m = (r + l) / 2;
        if (x < array[m]) {
            r = m - 1;
        }
        else if (x > array[m]) {
            l = m+1;
        }
        else if (x == array[m]) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> array;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        array.push_back(x);
    }
    sort(array.begin(), array.end());
    for (int i = 0; i < k; i++) {
        cin >> x;
        int p = binarySearch(array, x);
        if (p == 1) {
            cout << "TAK" << "\n";
        }
        else {
            cout << "NIE" << "\n";
        }
    }

}
// binary search assigment