#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
void bfs(vector<vector<int>>& network, int v, vector<int>& visited, int n, vector<int>& rev) {
    queue<int> q;
    q.push(v);
    visited[v] = 1;
    int s = 0;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (auto ver : network[v]) {
            if (visited[ver] == -1) {
                q.push(ver);
                rev[ver] = v;
                visited[ver] = visited[v] + 1;
            }
        }
    }
}
 
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> network(n + 1);
    vector<int> visited(n + 1, -1);
    vector<int> rev(n + 1);
    vector <int> d;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        network[a].push_back(b);
        network[b].push_back(a);
    }
    bfs(network, 1, visited, n, rev);
    if (visited[n] == -1) {
        cout << "IMPOSSIBLE";
    }
    else {
        cout << visited[n] << endl;
        int v = n;
        d.push_back(n);
        while (v > 1) {
            d.push_back(rev[v]);
            v = rev[v];
        }
        for (int i = d.size() - 1; i >= 0; i--) {
            cout << d[i] << " ";
        }
    }
}
/*Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.
Input
The first input line has two integers n and m: the number of computers and connections. The computers are numbered 1,2,\dots,n. Uolevi's computer is 1 and Maija's computer is n.
Then, there are m lines describing the connections. Each line has two integers a and b: there is a connection between those computers.
Every connection is between two different computers, and there is at most one connection between any two computers.
Output
If it is possible to send a message, first print k: the minimum number of computers on a valid route. After this, print an example of such a route. You can print any valid solution.
If there are no routes, print "IMPOSSIBLE".
Constraints

2 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5*/