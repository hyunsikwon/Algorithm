//
//  main.swift
//  Binary Gap
//
//  Created by 원현식 on 2021/05/24.
//
import Foundation

// you can write to stdout for debugging purposes, e.g.
// print("this is a debug message")

public func solution(_ N : Int) -> Int {
  let binary = String(N, radix: 2)
  print(binary)

  var answer = 0
  var length = 0
  for char in binary {
    let str = String(char)
    
    if str == "0" {
      length += 1
    } else {
      answer = max(answer, length)
      length = 0
    }
    
  }
   
  return answer
}

print(solution(32))


