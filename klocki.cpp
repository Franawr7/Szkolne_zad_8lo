#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> array;
    int x;
    int sum = 0;
    int j = 0;
    int score = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
        array.push_back(sum);
    }
    for(int i =0; i < n; i++){
        if(j!=0){
            if(array[i] - array[j-1] == m){
              score++;  
            }else if(array[i] - array[j-1] > m){
                j++;
                i--;
            }
        }else if(array[i] == m){
            score++;
        }else if(array[i]>m){
            j++;
            i--;
        }
    }
    cout << score; 
}