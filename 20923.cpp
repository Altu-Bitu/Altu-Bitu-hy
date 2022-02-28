#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int cnt = 0;
    deque<int> dodo;
    deque<int> su;
    deque<int> do_gr;
    deque<int> su_gr;

    //입력
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        dodo.push_front(a);
        su.push_front(b);
    }

    int win = 0;
    while(true){
        //도도가 카드 옮김.
        do_gr.push_front(dodo.front());
        dodo.pop_front();
        //도도 덱이 비었다면 수가 이김.
        if(dodo.empty()){
            win = 1;
            break;
        }
        //도도가 5를 내면 도도가 가져감
        if(do_gr.front() == 5){
            while(!su_gr.empty()){
                dodo.push_back(su_gr.back());
                su_gr.pop_back();
            }
            while(!do_gr.empty()){
                dodo.push_back(do_gr.back());
                do_gr.pop_back();
            }
        }
        //빈 그라운드가 없고 합이 5라면 수가 가져감.
        else if(!do_gr.empty() && !su_gr.empty() && do_gr.front() + su_gr.front() == 5){
            while(!do_gr.empty()){
                su.push_back(do_gr.back());
                do_gr.pop_back();
            }
            while(!su_gr.empty()){
                su.push_back(su_gr.back());
                su_gr.pop_back();
            }
        }
        cnt++;
        //전체 턴이 끝났다면 종료함.
        if(cnt == m)
            break;

        //수가 카드 옮김.
        su_gr.push_front(su.front());
        su.pop_front();
        //수 덱이 비었다면 도도가 이김.
        if(su.empty()){
            win = 2;
            break;
        }
        //수가 5를 내면 도도가 가져감.
        if(su_gr.front() == 5){
            while(!su_gr.empty()){
                dodo.push_back(su_gr.back());
                su_gr.pop_back();
            }
            while(!do_gr.empty()){
                dodo.push_back(do_gr.back());
                do_gr.pop_back();
            }
        }
        else if(!do_gr.empty() && !su_gr.empty() && do_gr.front() + su_gr.front() == 5){
            while(!do_gr.empty()){
                su.push_back(do_gr.back());
                do_gr.pop_back();
            }
            while(!su_gr.empty()){
                su.push_back(su_gr.back());
                su_gr.pop_back();
            }
        }
        cnt++;
        if(cnt == m)
            break;
    }

    if(win == 1)
        cout << "su";
    else if(win == 2)
        cout << "do";
    else{
        if(dodo.size() > su.size())
            cout << "do";
        else if( dodo.size() < su.size())
            cout << "su";
        else
            cout << "dosu";
    }

}
