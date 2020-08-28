//
//  main.swift
//  섬 연결하기
//
//  Created by 원현식 on 2020/08/27.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let n = 4
let costs = [[0,1,1], [0,2,2], [1,2,5], [1,3,1], [2,3,8]]

// OUTPUT: 4
print(solution(n, costs))

var parent = (0...101).compactMap { $0 }

func getParent(a: Int) -> Int {
    if parent[a] == a {
        return a
    } else {
        return getParent(a: parent[a])
    }
    
}

func unionParent(a: Int, b: Int) {
    let pa = getParent(a: a)
    let pb = getParent(a: b)
    if pa < pb {
        parent[b] = pa
    } else {
        parent[a] = pb
    }
    
}

func solution(_ n:Int, _ costs:[[Int]]) -> Int {
    var answer = 0
    
    let sortedNodes = costs.sorted { $0[2] < $1[2] }
    
    for a in sortedNodes {
        let node1P = getParent(a: a[0])
        let node2P = getParent(a: a[1])
        let cost = a[2]
        
        if node1P != node2P  {
            unionParent(a: node1P, b: node2P)
            answer += cost
        }
    }
        
    return answer
}

