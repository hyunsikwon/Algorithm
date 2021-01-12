//
//  main.swift
//  스킬트리
//
//  Created by 원현식 on 2020/05/11.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

func solution(_ skill: String, _ skill_trees: [String]) -> Int {
    var answer = 0
    var tempArr = [String]()
    
    for skill_tree in skill_trees {
        var tempStr = ""
        for char in skill_tree {
            if skill.contains(char) {
                tempStr += char.description
            }
        }
        tempArr.append(tempStr)
    }
    
    for s in skill {
        for i in 0..<tempArr.count {
            if !tempArr[i].contains(s) {
                tempArr[i] = tempArr[i] + s.description
            }
        }
        
    }
    
    for skill_tree in tempArr {
        if skill_tree == skill {
            answer += 1
        }
    }
    
    return answer
}

let skill_trees = ["BACDE", "CBADF", "AECB", "BDA"]
let skill = "CBD"
print(solution(skill, skill_trees))
print(2)
