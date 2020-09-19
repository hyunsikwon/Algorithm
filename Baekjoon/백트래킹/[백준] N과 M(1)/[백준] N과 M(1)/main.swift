//
//  main.swift
//  [백준] N과 M(1)
//
//  Created by 원현식 on 2020/09/19.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation


func backTracking(_ arr: inout [Int]) {
    if arr.count == M {
        for i in 0..<arr.count {
            print(arr[i], terminator: " ")
        }
        
        print()
        return
    }
    
    for i in 1...N {
        guard !arr.contains(i) else {continue}
        arr.append(i)
        backTracking(&arr)
        arr.removeLast()
    }
}

var arr = [Int]()
let a = readLine()!.split(separator: " ")

let N = Int(a[0])!
let M = Int(a[1])!
   
backTracking(&arr)


