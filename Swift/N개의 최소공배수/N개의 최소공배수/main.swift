//
//  main.swift
//  N개의 최소공배수
//
//  Created by 원현식 on 2020/08/11.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let arr = [2,3,4] 

print(solution(arr))

func lcm(_ a: Int, _ b: Int) -> Int {
    var result = 1
    var min = a < b ? a : b
    var t = 1
    
    for i in 1...min {
        if (a % i == 0) && (b % i == 0) {
            t = i
        }
    }
    
    result = (a*b)/t
    
    return result
}

func solution(_ arr:[Int]) -> Int {
    if arr.count == 1 {
        return arr[0]
    }
    
    var LCMs = arr
    var answer = 1
    
    while LCMs.count >= 2 {
        var a = LCMs.removeFirst()
        var b = LCMs.removeFirst()
        LCMs.insert(lcm(a, b), at: 0)
    }

    return LCMs[0]
}

