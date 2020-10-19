//
//  main.swift
//  네트워크
//
//  Created by 원현식 on 2020/05/22.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

// Input:
let n = 3
let computers = [[1, 1, 0], [1, 1, 0], [0, 0, 1]]

// Output: 2
print(solution(n,computers))

func dfs(_ i: Int, _ computers: [[Int]], _ visited: inout [Bool]){
    if visited[i] == true {
        return
    }
    visited[i] = true
    
    for j in 0..<computers[i].count {
        if visited[j] == false && computers[i][j] == 1 {
            dfs(j, computers, &visited)
        }
    }
    
}

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
    var networks = 0
    var visited = [Bool](repeating: false, count: n)
    for i in 0..<n {
        if visited[i] == false {
            dfs(i,computers, &visited)
            networks+=1
        }
    }
    
    return networks
}
