
#include <iostream>

using namespace std;

int main(){
    int n, k, ans = 1;
    cin >> n >> k;

    for(int i=0; i<k; i++){
        ans *= n;
        n--;
    }

    int temp = k;
    for(int i=0; i<k; i++){
        ans /= temp;
        temp--;
    }

    cout << ans;
}
