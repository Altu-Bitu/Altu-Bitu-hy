
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int b, c;
    cin >> b >> c;

    long long count = 0;
    for(int i=0; i<n; i++){

        arr[i] -= b;
        count++;

        if(arr[i] > 0){
            count += arr[i]/c;
            if(arr[i]%c > 0){
                count++;
            }
        }
    }

    cout << count;
}
