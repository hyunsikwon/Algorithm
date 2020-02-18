//
//  main.cpp
//  단지번호붙이기_#2667
//
//  Created by 원현식 on 2020/02/18.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[26][26]; // 행렬
bool check[26][26]; // 방문여부
vector<int> countArr; // 단지별 집의 수
int N; // 지도의 크기
string data; // 자료
int countHouse; // 집의 수 counting
int apartComplex = 1; // 단지 counting

void dfs(int i,int j) {
    countHouse++;
    check[i][j] = true;
    a[i][j] = apartComplex;
    
    if (i < N-1 && check[i+1][j] == false && a[i+1][j] >= 1 ) {
        dfs(i+1, j);
    }
    
    if (i > 0 && check[i-1][j] == false && a[i-1][j] >= 1) {
        dfs(i-1, j);
    }
    
    if (j < N-1 && check[i][j+1] == false && a[i][j+1] >= 1) {
        dfs(i, j+1);
    }
    
    if (j > 0 && check[i][j-1] == false && a[i][j-1] >= 1) {
        dfs(i, j-1);
    }
    
}

int main(int argc, const char * argv[]) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> data;
        for (int j = 0; j < data.length(); j++) {
            a[i][j] = data[j] - '0';
        }
    }
    
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            countHouse = 0;
            if (a[i][j] >= 1 && !check[i][j]) {
                dfs(i,j);
                apartComplex++;
                countArr.push_back(countHouse);
            }
        }
        
    }

    sort(countArr.begin(), countArr.end());
    
    cout << countArr.size() << '\n';
    for (int i = 0; i < countArr.size(); i++) {
        cout << countArr[i] << '\n';
    }
    
// MARK: - 확인용 출력
//    cout << '\n';
//
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cout << a[i][j];
//        }
//        cout << '\n';
//    }
}
