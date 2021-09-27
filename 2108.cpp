#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;

    double sum = 0; //float은 틀린다.
    int max = -4000, min = 4000;
    int mid[n];
    int mode[8001] = {0, };

    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        sum += t;
        if(t > max)
            max = t;
        if(t < min)
            min = t;
        mid[i] = t;
        mode[t+4000]++;
    }

    cout << round(double(sum/n)) << '\n';

    sort(mid, mid+n);
    cout << mid[n/2] << '\n';

    int k = -1;
    int index = 0, count = 0;
    for(int i=0; i<8001; i++){
        if(mode[i] > k){
            k = mode[i];
            index = i;
            count = 0;
        }
        else if(mode[i] == k && count<1){
            count++;
            index = i;
        }
    }
    cout << index-4000 << '\n';

    cout << max-min;

}
