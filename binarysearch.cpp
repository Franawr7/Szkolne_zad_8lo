#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int x;
    unordered_map <int, int> array;
    vector <int> odp;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (array.find(x) == array.end()) {
            array[x] = i + 1;
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> x;
        odp.push_back(x);
    }
    for (int i = 0; i < odp.size(); i++) {
        if (array.find(odp[i]) != array.end()) {
            cout << array[odp[i]] << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}
// binary search on unsorted array
// made with use of maps