//
//  main.cpp
//  삼각 달팽이_cpp
//
//  Created by 원현식 on 2020/10/22.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int temp[1001][1001] = {0,};
    
    int value = 1;
    int direction = 0;
    int x = 1, y = 1;
    for (int i = n; i > 0; i--) {
        direction = direction % 3; // 0아래로, 1은 오른쪽, 2는 위로
        if (direction == 0) {
//            cout << "----↓----" << '\n';
            for (int j = 0; j < i; j++) {
                temp[x][y] = value++;
                cout << x << ' ' << y << '\n';
                x++;
            }
            x--;
            y++;
        } else if (direction == 1) {
//            cout << "----->----" << '\n';
            for (int j = 0; j < i; j++) {
                temp[x][y] = value++;
                cout << x << ' ' << y << '\n';

                y++;
            }
            x--;
            y -= 2;
            
        } else {
//            cout << "----↑----" << '\n';
            for (int j = 0; j < i; j++) {
                temp[x][y] = value++;
                cout << x << ' ' << y << '\n';

                x--;
                y--;
            }
            x+=2;
            y++;
        }
        
        direction++;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (temp[i][j] != 0) {
                answer.push_back(temp[i][j]);
            }
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    int n = 4;
    
    vector<int> answer = solution(n);
    
    for(int a: answer) {
        cout << a << ' ';
    }
    
}
