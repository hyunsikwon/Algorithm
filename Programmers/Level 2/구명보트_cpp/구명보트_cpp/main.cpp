//
//  main.cpp
//  구명보트_cpp
//
//  Created by 원현식 on 2020/11/25.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> people, int limit) {
    if (people.size() == 1) return 1;
   
    int answer = 0;
    int left = 0;
    int right = people.size()-1;
    
    sort(people.begin(), people.end());

    
    while (left < right) {
        if (people[left] + people[right] <= limit) {
            left++;
        }
        right--;
        answer++;
    }
    
    if (left == right) {
        answer++;
    }

    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> people = {50,50,70,80};
    int limit = 100;
    
    cout << solution(people, limit) << '\n';
    cout << 3 << '\n';
    
}
// 효율성 실패
//int solution(vector<int> people, int limit) {
//    if (people.size() == 1) return 1;
//    int answer = 0;
//
//    sort(people.begin(), people.end());
//
//    int total = 0;
//
//    while (!people.empty()) {
//        total = people.back(); // 남아있는 사람들 중 가장 몸무게가 많이 나가는 사람
//        people.pop_back(); // 배에 탑승
//
//        stack<int> tempStack;
//        int remain = people.size();
//
//        while (!people.empty()) {
//            if (people.back() + total <= limit) {
//                people.pop_back();
//                break;
//            } else {
//                tempStack.push(people.back());
//                people.pop_back();
//            }
//        }
//
//        while (!tempStack.empty()) {
//            people.push_back(tempStack.top());
//            tempStack.pop();
//        }
//
//        answer++;
//    }
//
//    return answer;
//}
