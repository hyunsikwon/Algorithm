//
//  main.swift
//  숫자 야구
//
//  Created by 원현식 on 2020/07/13.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let baseball = [[123, 1, 1], [356, 1, 0], [327, 2, 0], [489, 0, 1]]
// 130, 102, 320, 023, 203, 013, 300, 050, 006, 320, 307, 027, 040, 004, 800, 008, 900, 090

// OUTPUT: 2
print(solution(baseball))

func check(_ value: Int, _ number: Int, _ s: Int, _ b: Int) -> Bool {
    var strike = 0
    var ball = 0
    var v = value
    var n = number
    var valueArr = [Int]()
    var numberArr = [Int]()
    
    while v > 0 {
        let a = v % 10
        v /= 10
        valueArr.insert(a, at: 0)
    }
    
    if valueArr.contains(0) || valueArr[0] == valueArr[1] ||
        valueArr[0] == valueArr[2] || valueArr[1] == valueArr[2] {
        return false
    }
    
    
    while n > 0 {
        let a = n % 10
        n /= 10
        numberArr.insert(a, at: 0)
    }
    
    // strike 검사
    for i in 0..<3 {
        if valueArr[i] == numberArr[i] {
            strike += 1
        }
    }
    
    // ball 검사
    for i in 0..<3 {
        for j in 0..<3 {
            if i != j && valueArr[i] == numberArr[j] {
                ball += 1

            }
        }
    }
    
    return (strike == s && ball == b)
}


func solution(_ baseball:[[Int]]) -> Int {
    var answer = 0
    var results = [Int]()
    
    for i in 123...987 {
        var isProper = false
        for arr in baseball {
            if check(i, arr[0], arr[1], arr[2]) == true {
                isProper = true
            } else {
                isProper = false
                break
            }
        }
        if isProper {
            answer += 1
            results.append(i)
        }
    }
    print(results)
    return answer
}

