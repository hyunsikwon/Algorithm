//
//  main.cpp
//  라면공장
//
//  Created by 원현식 on 2020/04/25.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    
    int date = 0;
    int supplyDay = 0;
    int supplyCount = supplies.size();
    priority_queue<int> pq(supplies.begin(),supplies.end());
    
    while (date < k) {
        date++;
        stock--;
        
        // 해외 공급일.
        if (date == dates[supplyDay] && date < k) {
            if (stock == 0) {
                stock += pq.top();
                pq.pop();
                answer++;
                
            } else {
                // 다음번 공급일이 존재하는데
                if (supplyDay + 1 < supplyCount) {
                    // 현재 재고로 다음번 공급일까지 버틸 수 있다면 공급 받을 필요가 없고,
                    if (stock > dates[supplyDay + 1] - dates[supplyDay]) {
                        
                    } else { // 재고가 모자르면 받아야하는데,
                        // 현재 재고로 k날까지 버틸 수 있다면 공급을 받지 않고,
                        if (stock + date >= k) {
                            
                        // k날까지도 못버티면 당장 공급을 받아야 함.
                        } else {
                            stock += pq.top();
                            pq.pop();
                            answer++;
                        }
                    }
                    
                    // 다음번 공급일이 없는데,
                } else {
                    // 현재 재고로 k날까지 못버티면
                    if (date + stock < k) {
                        stock += pq.top();
                        pq.pop();
                        answer++;
                    }
                }
                
                
            }
            
            supplyDay++;
        }
        
        
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    int stock = 4;
    vector<int> dates = {4, 10, 15};
    vector<int> supplies = {20, 5, 10};
    int k = 30;
    
    cout << solution(stock, dates, supplies, k);
}
