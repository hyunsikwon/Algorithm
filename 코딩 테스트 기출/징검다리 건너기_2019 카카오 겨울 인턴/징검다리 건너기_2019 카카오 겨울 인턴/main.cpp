//
//  main.cpp
//  징검다리 건너기_2019 카카오 겨울 인턴
//
//  Created by 원현식 on 2020/05/06.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
bool binary_search(int n, int k, vector<int> v){
    int count = 0;
    
    for(int i = 0; i < v.size(); i++){
        if(v[i] - n <= 0)
            count++;
        else
            count = 0;
        if(count >= k)
            return true;
    }
    return false;
}
 
int solution(vector<int> stones, int k) {
    int first = 1, last = *max_element(stones.begin(), stones.end());
   
    while(first <= last){
        int mid = (first + last) / 2;
        if(binary_search(mid, k, stones))
            last = mid - 1;
        else
            first = mid + 1;
    }
    
    return first;
}


int main(int argc, const char * argv[]) {
    vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    int k = 3;

    cout << solution(stones, k);
}
