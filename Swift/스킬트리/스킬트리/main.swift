//
//  main.swift
//  스킬트리
//
//  Created by 원현식 on 2020/05/11.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

var skill: String = "CBD"
var skill_trees: [String] = ["BACDE", "CBADF", "AECB", "BDA"]
print(solution(skill, skill_trees))

func solution(_ skill:String, _ skill_trees:[String]) -> Int {
    var tempArr = [String]()
    var answer = 0
    
    for element in skill_trees {
        var tempString: String = ""
        for char in element {
            if skill.contains(char) {
                tempString += String(char)
            }
        }
        
        tempArr.append(tempString)
    }
    
    for char in skill {
        for i in 0..<tempArr.count {
            if !tempArr[i].contains(char) {
                tempArr[i] += String(char)
            }
        }
    }
    
    for a in tempArr {
        if a == skill {
            answer+=1
        }
    }
    return answer
}


