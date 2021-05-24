//
//  main.swift
//  FrogJmp
//
//  Created by 원현식 on 2021/05/24.
//

import Foundation

public func solution(_ X : Int, _ Y : Int, _ D : Int) -> Int {
  // write your code in Swift 4.2.1 (Linux)
  
  let distance = Double(Y-X)
  let answer  = Int(ceil(distance/Double(D)))
  
  return answer
}

