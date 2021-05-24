//
//  main.swift
//  TapeEquilibrium
//
//  Created by 원현식 on 2021/05/24.
//

import Foundation

public func solution(_ A : inout [Int]) -> Int {
  
  var sum = 0
  for num in A {
    sum += num
  }
  
  var leftSide = A[0]
  var answer = Int.max
  for i in 1..<A.count {
    let splits = abs(leftSide - (sum-leftSide))
    leftSide += A[i]
    answer = min(splits, answer)
  }
  
  return answer
}

