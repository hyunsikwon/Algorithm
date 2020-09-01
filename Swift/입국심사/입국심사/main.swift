//
//  main.swift
//  입국심사
//
//  Created by 원현식 on 2020/08/28.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let n = 10
let times = [3, 8 ,3 ,6 ,9 ,2 ,4]

//let n = 6
//let times = [7, 10] // OUTPUT : 28

// OUTPUT: 8
print(solution(n, times))

func solution(_ n:Int, _ times:[Int]) -> Int64 {

    guard let maxTime = times.max() else { return 0 } // 가장 오래걸리는 입국심사대
    
    var left: Int64 = 0
    var right: Int64 = Int64(maxTime*n) // 가장 오래걸리는 입국심사대에서 모든 인원을 처리한 경우.
    
    var mid: Int64 = (left+right)/2
    var answer: Int64 = right
    
    while left <= right {
        mid = (left + right)/2
        var possible: Int64 = 0
        
        for time in times {
            possible = possible + Int64(Int(mid)/time) // 주어진 시간내에 각 심사대에서 심사할 수 있는 사람의 수
        }
        
        if possible >= n {
            answer = mid
            right = mid - 1
        } else {
            left = mid + 1
        }
    }
    return answer
}
