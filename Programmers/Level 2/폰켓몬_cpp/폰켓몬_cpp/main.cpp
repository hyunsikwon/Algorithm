//
//  main.cpp
//  폰켓몬_cpp
//
//  Created by 원현식 on 2020/11/26.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;



int solution(vector<int> nums) {
    int half = nums.size()/2;
    set<int> temp;
    for(int num: nums) {
        temp.insert(num);
    }
    
    if (temp.size() > half) {
        return half;
    } else {
        return temp.size();
    }
    
}

int main(int argc, const char * argv[]) {
    int answer = 0;
    vector<int> nums = {3,3,3,2,2,4};

    
    cout << solution(nums) << '\n';
    cout << "ansewr: " << 3 << '\n';
}
