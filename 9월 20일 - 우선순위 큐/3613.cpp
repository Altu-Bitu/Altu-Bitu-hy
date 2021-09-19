
#include <iostream>

using namespace std;

string from_cpp(int i, string answer, string str){
    for(int j=i; j<str.length(); j++){
        char c = str[j];
        //c++인데 대문자 있으면 에러
        if('A' <= c && c <= 'Z')
            return "Error!";
        //_이 연속을 나오면 에러
        if(c == '_'){
            if(str[j-1] == '_')
                return "Error!";
        }
        else{
            //소문자라면 이전 문자가 _이면 대문자 입력
          if(str[j-1] == '_')
              answer += toupper(c);
          else
              answer += c;
        }
    }

    return answer;
}

string from_java(int i, string answer, string str){
    for(int j=i; j<str.length(); j++){
        char c = str[j];
        //자바인데 _ 입력받으면 에러
        if(c == '_')
            return "Error!";
        //대문자이면 _와 소문자 입력
        if('A' <= c && c <= 'Z'){
            answer += '_';
            answer += tolower(c);
        }
        else
            answer += c;
    }
    return answer;
}

int main(){
    string str;
    cin >> str;

    string answer = "";
    //첫글자가 _, 대문자이거나 마지막이 _이면 에러
    if(str[0] == '_' || ('A' <= str[0] && str[0] <= 'Z') || str[str.length()-1] == '_'){
        cout << "Error!";
        return 0;
    }
    else{
        answer += str[0];
    }

    for(int i=1; i<str.length(); i++){
        char c = str[i];
        if('a' <= c && c <= 'z'){
            answer += c;
        }
        if(c == '_') { //_을 입력받으면 c++
            answer = from_cpp(i, answer, str);
            break;
        }
        if('A' <= c && c <= 'Z') { //대문자 입력받으면 java
            answer = from_java(i, answer, str);
            break;
        }
    }

    cout << answer;
}

