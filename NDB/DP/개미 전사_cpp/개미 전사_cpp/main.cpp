//
//  main.cpp
//  개미 전사_cpp
//
//  Created by 원현식 on 2020/09/24.
//

#include <iostream>

using namespace std;


int main(int argc, const char * argv[]) {
    int K;
    int warehouse[1001];
    cin >> K;
    
    for (int i = 0; i < K; i++) {
        cin >> warehouse[i];
    }
    
    int dp[K+1];

    dp[0] = warehouse[0];
    dp[1] = max(warehouse[0], warehouse[1]);
    dp[2] = warehouse[2] + warehouse[0];
    
    for (int i = 3; i < K; i++) {
        dp[i] = max(dp[i-2], dp[i-3]) + +warehouse[i];
        
    }
    
    for (int i = 0; i < K; i++) {
        cout << dp[i] << ' ';
    }
    

    
}

//int main(int argc, const char * argv[]) {
//    int K;
//    int warehouse[1001];
//    cin >> K;
//
//    for (int i = 0; i < K; i++) {
//        cin >> warehouse[i];
//    }
//
//    int dp[K+1];
//
//    dp[0] = warehouse[0];
//    dp[1] = max(warehouse[0], warehouse[1]);
////    dp[2] = warehouse[2] + warehouse[0];
//
//    for (int i = 2; i < K; i++) {
//        dp[i] = max(dp[i-1], dp[i-2]+warehouse[i]);
//
//    }
//
//    for (int i = 0; i < K; i++) {
//        cout << dp[i] << ' ';
//    }
//
//
//
//}
