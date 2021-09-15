#include <iostream>
#include <queue>

using namespace std;
const int SIZE = 10001;

int front_pointer = 0, rear_pointer = 0;
vector<int> deque_vec(SIZE);

bool empty(){
    return front_pointer == rear_pointer;
}

void push_front(int k){
    front_pointer = (front_pointer+1) % SIZE;
    deque_vec[front_pointer] = k;
}

void push_back(int k){
    rear_pointer = (rear_pointer+1) % SIZE;
    deque_vec[rear_pointer] = k;
}

int pop_front(){
    front_pointer = (front_pointer + 1) % SIZE;
    return deque_vec[front_pointer];
}

int pop_back(){
    rear_pointer = (rear_pointer + 1) % SIZE;
    return deque_vec[rear_pointer];
}

int size(){
    int tmp = (rear_pointer - front_pointer);
    if(tmp < 0){
        tmp += SIZE;
    }
    return tmp;
}

int front() {
    int tmp = (front_pointer + 1) % SIZE;
    return deque_vec[tmp];
}

int back() {
    return deque_vec[rear_pointer];
}

int main(){
    int n, k;
    string cmd;
    deque<int> dq;

    cin >> n ;
    while(n--){
        cin >> cmd;
        if(cmd == "push_front"){
            cin >> k;
            dq.push_front(k);
            continue;
        }
        if(cmd == "push_back"){
            cin >> k;
            dq.push_back(k);
            continue;
        }
        if(cmd == "pop_back"){
            if(dq.empty())
                cout << -1 << '\n';
            else{
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            continue;
        }
        if(cmd == "pop_front"){
            if(dq.empty())
                cout << -1 << '\n';
            else{
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            continue;
        }
        if(cmd == "size"){
            cout << dq.size() << '\n';
            continue;
        }
        if(cmd == "empty"){
            cout << dq.empty() << '\n';
            continue;
        }
        if(cmd == "front"){
            if(dq.empty())
                cout << -1 << '\n';
            else{
                cout << dq.front() << '\n';
            }
            continue;
        }
        if(cmd == "back"){
            if(dq.empty())
                cout << -1 << '\n';
            else{
                cout << dq.back() << '\n';
            }
            continue;
        }
    }

}