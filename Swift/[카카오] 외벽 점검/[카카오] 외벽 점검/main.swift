//
//  main.swift
//  [카카오] 외벽 점검
//
//  Created by 원현식 on 2020/09/08.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

func solution(_ n:Int, _ weak:[Int], _ dist:[Int]) -> Int {
    var distance = dist.sorted {$0 > $1}
    
    for i in 1...dist.count {
        
        let dis = distance[i-1]
        
        
        
        
    }
    
    return 0
}

let n = 12 // 외벽의 길이
let weak = [1, 5, 6, 10] // 외벽의 취약 지점 - 원의 형태
let dist = [1, 2, 3, 4] // 1시간 안에 움직일 수 있는 거리

print(solution(n, weak, dist)) // RESULT: 2

