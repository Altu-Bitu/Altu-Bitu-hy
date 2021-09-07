
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct xy{
    int x,y;
};

bool comp(const xy &i1, const xy &i2){
    if(i1.y != i2.y)
        return i1.y < i2.y;
    return i1.x < i2.x;
}

int main(){
    int n;
    vector<xy> xy;
    cin >> n;

    xy.assign(n, {});
    for(int i=0; i<n; i++){
        cin >> xy[i].x >> xy[i].y;
    }

    sort(xy.begin(), xy.end(), comp);

    for(int i=0; i<n; i++){
        cout << xy[i].x << " " << xy[i].y << '\n';
    }
}
