#include <iostream>

using namespace std;

int main() {
    int r, b;
    cin >> r >> b;
    int area = r + b;

    int w=0, l=0;
    for(int i=1; i<area/2; i++){
        if(area%i == 0){
            w = i;
            l = area/i;
        }
        int temp = (w-1)*2+(l-1)*2;
        if(temp == r && area-temp == b){
            cout << max(w, l) << ' ' << min(w, l);
            break;
        }
    }
}
