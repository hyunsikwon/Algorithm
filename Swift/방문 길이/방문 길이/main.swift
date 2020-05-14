//
//  main.swift
//  방문 길이
//
//  Created by 원현식 on 2020/05/14.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let dirs = "LULLLLLLU"
let dirs2 = "ULURRDLLU"
print(solution(dirs))
print(solution(dirs2))

func solution(_ dirs:String) -> Int {
    var routes = Set<String>()
    var currentPostion = (0,0)
    
    for char in dirs {
        let direction = String(char)
        if direction == "U" {
            if currentPostion.1 == 5 { continue }
            let toGo = (currentPostion.0,(currentPostion.1)+1)
            routes.insert("\(currentPostion.0)\(currentPostion.1)\(toGo.0)\(toGo.1)")
            routes.insert("\(toGo.0)\(toGo.1)\(currentPostion.0)\(currentPostion.1)")
            
            currentPostion.1 += 1
            
        } else if direction == "D" {
            if currentPostion.1 == -5 { continue }
            let toGo = (currentPostion.0,(currentPostion.1)-1)
            
            routes.insert("\(currentPostion.0)\(currentPostion.1)\(toGo.0)\(toGo.1)")
            routes.insert("\(toGo.0)\(toGo.1)\(currentPostion.0)\(currentPostion.1)")
            currentPostion.1 -= 1
            
        } else if direction == "L" {
            if currentPostion.0 == -5 { continue }
            let toGo = ((currentPostion.0)-1,currentPostion.1)
            
            routes.insert("\(currentPostion.0)\(currentPostion.1)\(toGo.0)\(toGo.1)")
            routes.insert("\(toGo.0)\(toGo.1)\(currentPostion.0)\(currentPostion.1)")
            currentPostion.0 -= 1
            
        } else if direction == "R" {
            if currentPostion.0 == 5 { continue }
            let toGo = ((currentPostion.0)+1,currentPostion.1)
            
            routes.insert("\(currentPostion.0)\(currentPostion.1)\(toGo.0)\(toGo.1)")
            routes.insert("\(toGo.0)\(toGo.1)\(currentPostion.0)\(currentPostion.1)")
            currentPostion.0 += 1
        }
    }
    return routes.count/2
}
