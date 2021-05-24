//
//  main.swift
//  CyclicRotation
//
//  Created by 원현식 on 2021/05/24.
//

import Foundation

// write your code in Swift 4.2.1 (Linux)
public func move(_ arr: inout [Int]) {
  var temp = Array(repeating: 0, count: arr.count)
  
  for i in 0..<arr.count {
    if i == arr.count-1 {
      temp[0] = arr[i]
    } else {
      temp[i+1] = arr[i]
    }
  }
  arr = temp
}

public func solution(_ A : inout [Int], _ K : Int) -> [Int] {
  guard A.count != K else { return A }
  
  var answer = A
  for _ in 0..<K {
    move(&answer)
  }
  return answer
}
