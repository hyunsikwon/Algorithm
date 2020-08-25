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
    
    let range = -(key.count - 1)..<lock.count
    
    var rotatedKey = key
    for _ in 0..<4 {
        for row in range {
            for col in range {
                if check(key: rotatedKey, lock: lock, to: (row: row, col: col)) {
                    return true
                }
            }
        }
        
        rotatedKey = rotate(rotatedKey)
    }
    
    return false
}

func check(key: [[Int]], lock: [[Int]], to index: (row: Int, col: Int) ) -> Bool {
    
    var tempLock = lock
    for r in 0..<key.count {
        for c in 0..<key.count {
            let lockRow = index.row + r
            let lockCol = index.col + c
            
            guard lockRow >= 0, lockCol >= 0, lockRow < lock.count, lockCol < lock.count else {
                continue
            }
            
            if key[r][c] == 1 && lock[lockRow][lockCol] == 1 { return false }
            
            guard key[r][c] == 1 &&  lock[lockRow][lockCol] == 0 else { continue }

            
            tempLock[lockRow][lockCol] = 1
                        
        }
    }

    return isOpen(tempLock)
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

func isOpen(_ lock: [[Int]]) -> Bool {
    
    for row in lock {
        if row.contains(0){
            return false
        }
    }
    
    return true
}
