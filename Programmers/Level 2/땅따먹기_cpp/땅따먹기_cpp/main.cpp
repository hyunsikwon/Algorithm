//
//  main.cpp
//  땅따먹기_cpp
//
//  Created by 원현식 on 2020/10/23.
//

#include <iostream>
#include <vector>
using namespace std;


int solution(vector<vector<int> > land) {
    int answer = 0;
    int n = land.size();
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            int max = 0;
            for (int k = 0; k < 4; k++) {
                if (j == k) continue;
               
                if (land[i-1][k] > max) {
                    max = land[i-1][k];
                }
            }
            
            land[i][j] += max;
        }
    }
    
    
    for(int a: land[n-1]) {
        if (a > answer) {
            answer = a;
        }
    }

    return answer;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> land = {{1,2,3,5},{5,6,7,8},{4,3,2,1}};
    
    cout << solution(land);
}
