//
//  main.swift
//  삼각 달팽이
//
//  Created by 원현식 on 2020/10/26.
//

import Foundation

func solution(_ n:Int) -> [Int] {
    var temp = Array(repeating: Array(repeating: 0, count: n), count: n)
    var x = 0, y = 0
    var value = 1
    
    var direction = 0
    
    for i in stride(from: n, to: 0, by: -1) {
        direction = direction % 3
        
        if direction == 0 { // down
            for _ in 0..<i {
                temp[x][y] = value
                value+=1
                x += 1
            }
            x -= 1
            y += 1
            
        } else if direction == 1 { // right
            for _ in 0..<i {
                temp[x][y] = value
                value+=1
                y += 1
            }
            
            x -= 1
            y -= 2
            
        } else { // up
            for _ in 0..<i {
                temp[x][y] = value
                value+=1
                x -= 1
                y -= 1
            }
            
            x += 2
            y += 1
            
        }
        
        direction += 1
    }
    var ansewr = [Int]()
    
    for arr in temp {
        for value in arr {
            if value != 0 {
                ansewr.append(value)
            }
        }
        
    }
    
    return ansewr
}

let n = 4 // [1,2,9,3,10,8,4,5,6,7
print(solution(n))
