//
// Created by LG on 2021-09-26.
//
#include <iostream>

using namespace std;

int triangle(int t, int* tri){

    for(int i=0; i<45; i++){
        for(int j=0; j<45; j++){
            for(int k=0; k<45; k++){
                if(tri[i] + tri[j] + tri[k] == t)
                    return 1;
            }
        }
    }
    return 0;
}

int main(){
    int n;
    cin >> n;

    int start = 1;
    int tri[45];
    for(int i=2; i<47; i++){
        tri[i-2] = start;
        start += i;
    }

    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        cout << triangle(t, tri) << '\n';
    }
}
