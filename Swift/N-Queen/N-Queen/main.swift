//
//  main.swift
//  N-Queen
//
//  Created by 원현식 on 2020/09/10.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

var answer = 0

func solution(_ n:Int) -> Int {
    if n == 1 {return 1}
    if n > 1, n < 4 { return 0 }
    
    for col in 0..<n {
        var temp = [Int]()
        temp.append(col) // 첫 행의 col 위치
        queen(n, 1, &temp)
    }
    
    return answer
}

func queen(_ size: Int, _ row: Int, _ arr: inout [Int]) { // arr는 i번째 row의 col
    if row == size {
        answer += 1
        return
    }
    
    for col in 0..<size {
        var flag = true
        
        for i in 0..<arr.count { // 현재 행의 위의 행들과 비교
            if arr[i] == col { // 위의 행과 같은 열이면
                flag = false
                break
            }
            
            if arr[i] - (row - i) == col || arr[i] + (row - i ) == col { // 위의 행의 대각선 방향이면
                flag = false
                break
            }
        }
        
        guard flag == true else { continue }
        
        arr.append(col)
        queen(size, row + 1, &arr)
        arr.removeLast()
        
    }
    
}

let n = 5 // Queen의 수, 체스 판의 가로와 세로 길이.  1 <= n <= 12
print(solution(n)) // RESULT: 2

