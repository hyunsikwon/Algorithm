//
//  main.swift
//  FrogRiverOne
//
//  Created by 원현식 on 2021/05/24.
//

import Foundation

public func solution(_ X : Int, _ A : inout [Int]) -> Int {
    // write your code in Swift 4.2.1 (Linux)
    var log = Set<Int>()

    for i in 0..<A.count {
        log.insert(A[i])
        if log.count == X { return i}
    }

    return -1
}
