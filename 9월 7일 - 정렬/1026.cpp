
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], b[n];
    bool check[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }

    sort(a, a+n);

    sort(b, b+n);

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += a[i]*b[n-i-1];
    }

    cout << sum;
}

