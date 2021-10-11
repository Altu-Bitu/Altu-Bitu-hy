//
// Created by LG on 2021-10-08.
//
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<bool> swtch(n+1, 0);

void flip(int sex, int num){
    if(sex == 1){
        for(int i=num; i<=n; i++){
            if(i%num == 0)
                swtch[i] = !swtch[i];
        }
    }
    else{
        swtch[num] = !swtch[num];
        for(int i=1; i<=n/2+1; i++){
            if(num-i < 1 || num+i > n)
                break;
            if(swtch[num-i] == swtch[num+i]){
                swtch[num-i] = !swtch[num-i];
                swtch[num+i] = !swtch[num+i];
            }
            else
                break;
        }
    }
}

int main(){
    int m;
    cin >> n;
    //입력
    for(int i=1; i<=n; i++){
        bool temp;
        cin >> temp;
        swtch[i] = temp;
    }

    cin >> m;
    while(m--){
        int sex, num;
        cin >> sex >> num;
        flip(sex, num);
    }

    for (int i = 1; i <= n; i++){
        cout << swtch[i] << ' ';
        if(i%20==0)
            cout << '\n';
    }
}
