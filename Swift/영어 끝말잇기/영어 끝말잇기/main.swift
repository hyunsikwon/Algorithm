//
//  main.swift
//  영어 끝말잇기
//
//  Created by 원현식 on 2020/05/13.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let words = ["tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"]
let n = 3

print(solution(n,words))

func solution(_ n:Int, _ words:[String]) -> [Int] {
    var answer = [Int]()
    var usedWords = [String]()
    
    usedWords.append(words[0])
    var lastChar = words[0].last!
    
    for i in 1..<words.count {
        let currentWord = words[i]
        if currentWord.first! != lastChar {
            answer.append(i%n + 1)
            answer.append(i/n + 1)
            break
        }
        
        if !usedWords.contains(currentWord) {
            usedWords.append(currentWord)
            
        } else {
            let failedPerson = (i%n + 1)
            let failedNum = i/n + 1
            answer.append(failedPerson)
            answer.append(failedNum)
            break
        }
        lastChar = currentWord.last!
    }
    
    if answer.isEmpty {
        answer.append(0)
        answer.append(0)
    }
    
    return answer
}
