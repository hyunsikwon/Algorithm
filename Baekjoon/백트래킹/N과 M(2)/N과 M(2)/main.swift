//
//  main.swift
//  N과 M(2)
//
//  Created by 원현식 on 2020/09/19.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

func backTracking(_ depth: Int, _ start: Int){
    if depth == M {
        for j in 0..<M {
            print(arr[j], terminator: " ")
        }
        print()
        return
    }
    
    for i in start..<N {
        arr[depth] = i+1
        backTracking(depth+1, i+1)
        
    }
    
}

let input = readLine()!.split(separator: " ")


var arr = [Int](repeating: 0, count: 9)
let N = Int(input[0])!
let M = Int(input[1])!

backTracking(0,0)


