//
// Created by LG on 2021-10-09.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void two(vector<vector<int>> &matrix, int n){
    if(n==1)
        return;

    for(int i=0; i<n; i+=2){
        for(int j=0; j<n; j+=2){
            vector<int> temp(4);
            temp[0] = matrix[i][j];
            temp[1] = matrix[i][j+1];
            temp[2] = matrix[i+1][j];
            temp[3] = matrix[i+1][j+1];
            sort(temp.begin(), temp.end());
            matrix[i/2][j/2] = temp[2];
        }
    }

    two(matrix, n/2);
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin >> matrix[i][j];
    }
    two(matrix, n);
    cout << matrix[0][0];
}
