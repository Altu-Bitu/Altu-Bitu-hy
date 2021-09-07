#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool check = true;
    int count = 0;

    for(int i=0; i<n; i++){
        check = true;
        string s;
        cin >> s;
        int len = s.length();

        for(int j=0; j<len; j++){
            char ch = s.at(j);

            while(j<len-1 && s.at(j+1) == ch){
                j++;
            }

            for(int k=j+1; k<len; k++){
                if(s.at(k) == ch){
                    check = false;
                }
            }
        }
        if(check)
            count++;
    }

    cout << count;
}
