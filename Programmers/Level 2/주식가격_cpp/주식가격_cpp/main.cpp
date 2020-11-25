//
//  main.cpp
//  주식가격_cpp
//
//  Created by 원현식 on 2020/11/25.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int i = 0; i < prices.size() ; i++) {
        int price = prices[i];
        int cnt = 0;
        for (int j = i+1; j < prices.size() ; j++) {
            if (prices[j] >= price) {
                cnt++;
            } else {
                cnt++;
                break;
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> prices = {1, 2, 3, 2, 3};
    vector<int> answer = solution(prices);
    
    for (int a: answer) {
        cout << a << ' ';
    }
    cout << '\n' << "4 3 1 1 0";
}
