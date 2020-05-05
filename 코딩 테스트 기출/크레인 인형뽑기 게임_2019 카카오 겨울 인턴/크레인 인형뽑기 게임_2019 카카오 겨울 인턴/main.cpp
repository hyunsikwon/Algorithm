//
//  main.cpp
//  크레인 인형뽑기 게임_2019 카카오 겨울 인턴
//
//  Created by 원현식 on 2020/05/05.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    
    for (int i = 0; i < moves.size(); i++) {
        int move = moves[i]-1; // 1, 5, 3, 5, 1 ...
        
        for (int j = 0; j < board.size(); j++) {
            if (board[j][move] != 0) {
                if (!st.empty() && st.top() == board[j][move]) {
                    st.pop();
                    answer += 2;
                } else {
                    st.push(board[j][move]);
                }
                board[j][move] = 0;
                break;
            }
        }
    }
    
    return answer;
}


int main(int argc, const char * argv[]) {
    vector<vector<int>> board {{0,0,0,0,0}, {0,0,1,0,3}, {0,2,5,0,1}, {4,2,4,4,2}, {3,5,1,3,1} };
    vector<int> moves {1, 5, 3, 5, 1, 2, 1, 4};
    
    cout << solution(board, moves);
}
