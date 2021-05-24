//
//  main.swift
//  OddOccurrencesInArray
//
//  Created by 원현식 on 2021/05/24.
//

import Foundation

public func solution(_ A : inout [Int]) -> Int {
  var answer = 0
  var dic: [Int: Int] = [: ]
  for i in 0..<A.count {
    let number = A[i]
    if number % 2 == 0 { continue }
    if dic[number] == nil {
      dic[number] = 1
    } else {
      dic[number]! += 1
    }
  }
  
  for (num, count) in dic {
    if count == 1 {
      answer = num
      break
    }
  }
  
  return answer
}

