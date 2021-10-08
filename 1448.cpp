#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int triangle(int n, vector<int> straw){
    for(int i=n-1; i>=2; i--){
        if(straw[i-1] + straw[i-2] > straw[i])
            return straw[i] + straw[i-1] + straw[i-2];
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> straw(n);

    for(int i=0; i<n; i++){
        cin >> straw[i];
    }
    sort(straw.begin(), straw.end());
    cout << triangle(n, straw);

}