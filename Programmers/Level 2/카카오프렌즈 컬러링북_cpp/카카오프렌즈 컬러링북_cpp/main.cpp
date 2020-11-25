//
//  main.cpp
//  카카오프렌즈 컬러링북_cpp
//
//  Created by 원현식 on 2020/11/25.
//

#include <iostream>
#include <vector>

using namespace std;

bool visited[101][101];
int area = 0;

void check(int i, int j, int m, int n, int color, vector<vector<int>> picture) {
    if (i < 0 || i >= m || j < 0 || j >= n) {
        return;
    }
    if (visited[i][j] == true) {
        return;
    }
    
    if (picture[i][j] != color || picture[i][j] == 0) {
        return;
    }
    
    visited[i][j] = true;
    area++;
    
    check(i-1, j, m, n, color, picture);
    check(i+1, j, m, n, color, picture);
    check(i, j-1, m, n, color, picture);
    check(i, j+1, m, n, color, picture);
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
    
    visited[m][n] = {0,};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == false && picture[i][j] > 0) {
                area = 0;
                check(i, j, m, n, picture[i][j], picture);
                
                number_of_area++;
                if (area > max_size_of_one_area) {
                    max_size_of_one_area = area;
                }
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main(int argc, const char * argv[]) {
//    int m = 13, n = 16;
//    vector<vector<int>> pictures = {
//        {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
//        {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
//        {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
//        {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
//        {0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
//        {0,1,1,1,1,2,1,1,1,1,2,1,1,1,1,0},
//        {0,1,1,1,2,1,2,1,1,2,1,2,1,1,1,0},
//        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
//        {0,1,3,3,3,1,1,1,1,1,1,3,3,3,1,0},
//        {0,1,1,1,1,1,2,1,1,2,1,1,1,1,1,0},
//        {0,0,1,1,1,1,1,2,2,1,1,1,1,1,0,0},
//        {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
//        {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0}};
    
    int m = 3, n = 3;
    vector<vector<int>> pictures = {
        {1, 2, 1},
        {2, 1, 2},
        {1 ,2 ,2}
    };
    
    vector<int> answer = solution(m, n, pictures);
    
    cout << answer[0] << ' ' << answer[1] << '\n';

}
