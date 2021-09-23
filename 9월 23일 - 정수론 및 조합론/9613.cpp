#include <iostream>
#include <set>
#include <vector>

using namespace std;

int getGcd(int a, int b){
    if(b == 0)
        return a;
    return getGcd(b, a%b);
}

int main(){
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int n, sum = 0;
        cin >> n;
        vector<int> num(n, 0);
        for(int j=0; j<n; j++){
            cin >> num[j];
        }
        for(int j=0; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                sum += (getGcd(num[j], num[k]));
            }
        }

        cout << sum << '\n';
    }
}
