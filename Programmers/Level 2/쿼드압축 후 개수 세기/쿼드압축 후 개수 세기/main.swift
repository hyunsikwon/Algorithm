//
//  main.swift
//  쿼드압축 후 개수 세기
//
//  Created by 원현식 on 2020/10/27.
//

import Foundation

var count0 = 0
var count1 = 0

func check(_ i: Int, _ j: Int, _ n: Int, _ m: Int, _ arr: [[Int]]) -> Bool {
    let value = arr[i][j]
    for x in i..<n {
        for y in j..<m {
            if value != arr[x][y] {
                return false
            }
        }
    }
    return true
}

func devide(_ i: Int, _ j: Int, _ n: Int, _ m: Int, _ arr: [[Int]]) {
    
    // 더 이상 나눠지지 않음
    if n-i <= 1 {
        if arr[i][j] == 0 {
            count0 += 1
        } else {
            count1 += 1
        }
        return
    }

    // 압축 가능
    if check(i, j, n, m, arr) {
        if arr[i][j] == 0 {
            count0 += 1
        } else {
            count1 += 1
        }
        return
    }


    let move = (n-i)/2

    devide(i, j, n-move, m-move, arr)
    
    devide(i, j+move, n-move, m, arr)

    devide(i+move, j, n, m-move, arr)
        
    devide(i+move, j+move, n, m,  arr)
    
}

func solution(_ arr:[[Int]]) -> [Int] {
    let size = arr.count
    
    devide(0, 0, size, size, arr)
    
    return [count0, count1]
}


let arr = [[1,1,0,0],
           [1,0,0,0],
           [1,0,0,1],
           [1,1,1,1]]

print(solution(arr)) // [4, 9]
