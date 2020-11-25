//
//  main.cpp
//  테트로미노_#14500
//
//  Created by 원현식 on 2020/11/24.
//

#include <iostream>

using namespace std;

const int MAX_CNT = 501;
int board[MAX_CNT][MAX_CNT];



int main(int argc, const char * argv[]) {
    // MARK: - 입력
    int N, M;
    int result = 0;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    // MARK: - 계산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            
        }
    }
    
    
    // MARK: - 출력
    cout << result << '\n';
}
