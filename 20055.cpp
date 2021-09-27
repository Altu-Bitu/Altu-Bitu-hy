#include <iostream>
#include <vector>

using namespace std;

void moveBelt(vector<int> &durab, int &up, int &down, int n){
    if(up == 0)
        up = 2*n-1;
    else
        up--;
    if(down == 0)
        down = 2*n-1;
    else
        down--;
}

void moveRobot(vector<int> &durab, int up, int down, vector<bool> &robot, int n){
    if(down>up){
        for(int i=down-1; i>up; i--){
            if(durab[i+1] > 0 && robot[i] && !robot[i+1]){
                robot[i] = false;
                robot[i+1] = true;
                durab[i+1]--;
            }
            robot[down] = false;
        }
    }
    else if(down<up){
        for(int i=down-1; i>=0; i--){
            if(durab[i+1] > 0 && robot[i] && !robot[i+1]){
                robot[i] = false;
                robot[i+1] = true;
                durab[i+1]--;
            }
            robot[down] = false;
        }
        for(int i=2*n-1; i>up; i--){
            if(i==2*n-1){
                if(durab[0] > 0 && robot[i] && !robot[0]){
                    robot[i] = false;
                    robot[0] = true;
                    durab[0]--;
                }
            }
            else if(durab[i+1] > 0 && robot[i] && !robot[i+1]){
                robot[i] = false;
                robot[i+1] = true;
                durab[i+1]--;
            }
            robot[down] = false;
        }
    }
}

int main(){
    int n, k, count = 1;
    cin >> n >> k;

    int up = 0, down = n-1;
    vector<bool> robot(2*n, false); //로봇 유무
    vector<int> durab(2*n, 0); //내구도

    //입력
    for(int i=0; i<2*n; i++){
        cin >> durab[i];
    }

    while(true){
        //1. 내리는 위치와 올리는 위치 옮김
        moveBelt(durab, up, down, n);
        robot[down] = false; //내리는 위치 로봇 바로 내림.

        //2. 이동 가능한 로봇을 이동.
        moveRobot(durab, up, down, robot, n);

        //3. 올리는 위치에 올림
        if(durab[up] != 0){
            robot[up] = true;
            durab[up]--;
        }

        //4. 내구도 0인 칸 세기
        int zero = 0;
        for(int i=0; i<2*n; i++){
            if(durab[i] <= 0){
                zero++;
            }
        }

        //종료 조건
        if(zero >= k){
            cout << count;
            break;
        }

        count++;
    }

}