
#include <iostream>
#include <vector>
using namespace std;

int main(){
    string a;
    string b;

    cin >> a >> b;

    //자릿수 큰 수가 a
    if(a.length() < b.length()){
        swap(a, b);
    }

    int a_len = a.length();
    int b_len = b.length();
    int sum = 0;
    int carry = 0;
    vector<int> res(a_len+1, {}) ;

    //b의 가장 높은 자릿수까지 덧셈하기
    while(b_len > 0){
        sum = a[a_len-1]-'0' + b[b_len-1]-'0' + carry;

        if(sum > 9){
            sum -= 10;
            carry = 1;
        }
        else
            carry = 0;
        res[a_len] = sum;
        a_len--;
        b_len--;
    }

    //a의 가장 높은 자릿수까지 덧셈하기
    while(a_len>0){
        sum = a[a_len-1]-'0' + carry;
        if(sum>9){
            sum -= 10;
            carry = 1;
        }
        else
            carry = 0;
        res[a_len] = sum;
        a_len--;
    }

    //출력
    if(carry !=0) { //마지막에 반올림된 수가 있을 때
        res[0] = carry;
        for (int i = 0; i <= a.length(); i++)
            cout << res[i];
    }
    else{
        for(int i = 1; i <= a.length(); i++)
           cout << res[i];
    }
}
