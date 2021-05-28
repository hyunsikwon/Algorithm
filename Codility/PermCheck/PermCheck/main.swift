//
//  main.swift
//  PermCheck
//
//  Created by 원현식 on 2021/05/24.
//

import Foundation

public func solution(_ A : inout [Int]) -> Int {
    // write your code in Swift 4.2.1 (Linux)
    A.sort()
    for i in 0..<A.count {
        if A[i] != i+1 {
            return 0
        }
    }
    return 1
}
