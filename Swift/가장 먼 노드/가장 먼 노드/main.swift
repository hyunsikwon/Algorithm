//
//  main.swift
//  가장 먼 노드
//
//  Created by 원현식 on 2020/08/25.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let n = 6
let vertex = [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]


//OUTPUT: 3
print(solution(n, vertex))

func solution(_ n:Int, _ edge:[[Int]]) -> Int {
    var vertex = Array(repeating: [Int](), count: n)
    var visited = Array(repeating: false, count: n)
    var count =  0
    
    for a in edge {
        let node1 = a[0]-1
        let node2 = a[1]-1
        vertex[node1].append(node2)
        vertex[node2].append(node1)
        
    }
    
    var result = Array(repeating: 0, count: n)
    
          // 노드 정보, 방문기록.  노드1부터 각 노드까지의 거리
    bfs(0, &vertex, &visited, &result)
    print(result)
    
    let max = result.max()!
    for value in result {
        if value == max {
            count += 1
        }
    }
    
    return count
}

func bfs(_ start: Int,
         _ board: inout [[Int]],
         _ visited: inout [Bool],
         _ result: inout [Int] ) {
    
    var queue = [Int]()
    queue.append(start)
    visited[start] = true
    
    var current = 0
    while current < queue.count {
        let front = queue[current]
        current += 1
        
        for i in 0..<board[front].count {
            let next = board[front][i]
            
            guard visited[next] == false else { continue }
            
            queue.append(next)
            result[next] = result[front] + 1
            visited[next] = true
            
        }
        
    }
    
}


