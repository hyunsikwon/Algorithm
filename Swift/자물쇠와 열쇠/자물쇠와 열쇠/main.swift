//
//  main.swift
//  자물쇠와 열쇠
//
//  Created by 원현식 on 2020/05/22.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

// Input
let key = [[0, 0, 0], [1, 0, 0], [0, 1, 1]]
let lock = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]
// Output: true
print(solution(key, lock))

func solution(_ key:[[Int]], _ lock:[[Int]]) -> Bool {
    
    var rotatedKey = key
    for _ in 0..<4 {
        // sum
        // check - return true
        
        rotatedKey = rotate(rotatedKey)
    }
    
    return false
}

func rotate(_ key: [[Int]]) -> [[Int]]{
    let n = key.count
    var rotated = [[Int]](repeating: Array(repeating: 0, count: n), count: n)
  
    for i in 0..<n {
        for j in 0..<n {
            rotated[i][j] = key[n-j-1][i]
        }
    }
    return rotated
}

func check(_ lock: [[Int]]) -> Bool {
    
    for line in lock {
        if line.contains(0) || line.contains(2) {
            return false
        }
    }
    return true
}
