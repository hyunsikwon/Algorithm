//
//  main.swift
//  TieRopes
//
//  Created by 원현식 on 2021/05/25.
//

import Foundation

public func solution(_ K : Int, _ A : inout [Int]) -> Int {
    // write your code in Swift 4.2.1 (Linux)
    var answer = 0
    var sum = 0
    
    for length in A {
        if length >= K {
            answer += 1
            sum = 0
            continue
        }

        if sum + length >= K {
            answer += 1
            sum = 0
            continue
        } else {
            sum += length
        }
    }

    return answer
}
