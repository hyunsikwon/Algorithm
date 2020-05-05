//
//  main.cpp
//  조이스틱
//
//  Created by 원현식 on 2020/05/05.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool visit[21];
int result = 0;

int findFastestWay(int current, vector<int> toGoList, int length) {
    int min = 999;
    int minIndex;
    
    for (int i = 0; i < toGoList.size(); i++) {
        if (visit[toGoList[i]] == false) {
            int straight;
            int reverse;
            if(current > toGoList[i]) {
                straight = current - toGoList[i];
                reverse = length - current + toGoList[i];
            } else {
                straight = toGoList[i] - current;
                reverse = current - 0 + length - toGoList[i];
            }

            int distance = 0;
            
            if (straight < reverse) distance = straight;
            else distance = reverse;
            
            if (distance < min) {
                min = distance;
                minIndex = i;
            }
        }
    }
    
    visit[toGoList[minIndex]] = true;
    result += min;

    return toGoList[minIndex];
}

int solution(string name) {
    int answer = 0;
    
    string temp = "";
    int length = name.length();
    vector<int> notAIndexList;

    for (int i = 0; i < name.length(); i++) {
        temp += "A";
        if (name[i] != 'A') {
            visit[i] = false;
            notAIndexList.push_back(i);
        }
    }
    
    int currentNameIndex = 0;
    while (temp != name) {
        // 커서 이동 로직

        currentNameIndex = findFastestWay(currentNameIndex, notAIndexList, length);
        
        // 알파벳 이동 로직 무조건 A부터 시작이니 편함.
        temp[currentNameIndex] = name[currentNameIndex];
        int straight = (name[currentNameIndex] - 0) - 65;
        int reverse = 90 - (name[currentNameIndex] - 0) + 1;
        if (straight < reverse) result += straight;
        else result += reverse;
        
    }
    
    
    answer = result;
    return answer;
}

int main(int argc, const char * argv[]) {
    string name = "AAAZZZ"; // 56

    cout << solution("JEROEN") << '\n';

}
