//
//  main.cpp
//  H-Index_cpp
//
//  Created by 원현식 on 2020/10/20.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), compare);
    
    for(int h = 0; h <= citations[0]; h++) {
        int temp = 0;
        for(int b: citations) {
            if (b >= h) {
                temp++;
            }
        }
        
        if (temp >= h) {
            answer = max(answer, h);
        }
        
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> citations = {3, 0, 6, 1, 5};
    
    cout << solution(citations);
}
