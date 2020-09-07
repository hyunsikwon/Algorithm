//
//  main.swift
//  멀리뛰기
//
//  Created by 원현식 on 2020/09/07.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

var answer = 0

func solution(_ n: Int) -> Int {
    var dp = [1,2]
    
    if n < 2 {
        return dp[n-1]
    }
    
    for i in 2...n {
        let a = (dp[i-2] + dp[i-1]) % 1234567
        dp.append(a)
    }
    
    return dp[n-1]
}


let n = 1
print(solution(n)) // RESULT: 5

// 실패코드
//func solution(_ n:Int) -> Int {
//
//    if n < 2 {
//        return 1
//    }
//
//    jump(n-2)
//    jump(n-1)
//
//    return answer
//}
//
//func jump(_ remain: Int) {
//    if remain <= 0 {
//        answer = (answer+1) % 1234567
//        return
//    }
//
//    if remain >= 2 {
//        jump(remain-2)
//        jump(remain-1)
//    } else {
//        jump(remain-1)
//    }
//
//}
