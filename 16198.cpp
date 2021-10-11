//
// Created by LG on 2021-10-09.
//
#include <iostream>
#include <vector>

using namespace std;

int n;
int sum, ans=0;

void energy(vector<int> weight, vector<bool> &check, int num){
    if(num==n-2){
        ans = max(ans, sum);
        return;
    }

    for(int i=1; i<n-1; i++){
        if(!check[i]) {
            check[i] = true;
            int left, right;
            for(int j=i-1; j>=0; j--){
                if(!check[j]) {
                    left = j;
                    break;
                }
            }
            for(int j=i+1; j<n; j++){
                if(!check[j]) {
                    right = j;
                    break;
                }
            }
            sum += weight[left] * weight[right];
            energy(weight, check, num+1);
            check[i] = false;
            sum -= weight[left] * weight[right];
        }
    }
}

int main(){

    cin >> n;
    vector<int> weight(n);
    vector<bool> check(n, false);
    for(int i=0; i<n; i++)
        cin >> weight[i];

    energy(weight, check, 0);
    cout << ans;
}
