
#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    //피연산자의 값 입력
    double t;
    map<char, double> value;
    for (int i = 0; i < n; i++) {
        cin >> t;
        value['A' + i] = t;
    }

    stack<double> st;

    for(int i=0; i<s.length(); i++){
        double a, b;
        char c = s[i];
        if(c >= 'A' && c <='Z'){
            st.push(value[c]);
        }
        else if(c == '*'){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(a*b);
        }
        else if(c == '+'){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(a+b);
        }
        else if(c == '/'){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b/a);
        }
        else if(c == '-'){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b-a);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << st.top();

}