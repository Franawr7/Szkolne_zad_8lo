#include <iostream>
#include <vector>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long sum[2]{};
    long long n;
    cin >> n;
    long long x;
    vector <long long> arr;
    for(long long i =0; i <n; i++){
        cin >> x;
        arr.push_back(x);
    }
    long long i =0;
    long long q = 0;
    long long j =n-1;
    long long fp;
    long long sp;
    while(j-i>=3){
        fp = arr[i] - arr[i+1];
        sp = arr[j] - arr[j-1];
        if(sp > fp){
            sum[q] += arr[j--];
        }else if(fp > sp){
            sum[q] += arr[i++];
        }else if(sp==fp){
            if(arr[j]>arr[i]){
                sum[q]+=arr[j--];
            }else{
                sum[q]+=arr[i++];
            }
        }
        if(q==0){
            q++;
        }else{
            q--;
        }
    }
    while(j-i >=0){
        if(arr[j]>arr[i]){
            if(q==0){
                sum[q++]+=arr[j--];
            }else{
                sum[q--]+=arr[j--];
            }
        }else{
            if(q==0){
                sum[q++]+=arr[i++];
            }else{
                sum[q--]+=arr[i++];
            }
        }
    }
    cout << sum[0];
}
