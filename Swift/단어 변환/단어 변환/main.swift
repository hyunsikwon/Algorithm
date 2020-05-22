//
//  main.swift
//  단어 변환
//
//  Created by 원현식 on 2020/05/22.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

// Input:
let begin = "hit"
let target = "cog"
let words = ["hot", "dot", "dog", "lot", "log"]
// Output: 4
print(solution(begin, target, words))
//print(check("hot","dot"))

var answer = 51

func dfs(_ count: Int,_ current: String, _ target: String, _ words: [String], usedWords: [String]) {
    if current == target {
        if count < answer {
            answer = count
        }
        return
    }
    var used = usedWords
    used.append(current)
    
    for i in 0..<words.count {
        if !used.contains(words[i]) {
            if check(current, words[i]) {
                dfs(count+1, words[i], target, words, usedWords: used)
                used.append(words[i])
            }
        }
    }
}

func check(_ a: String, _ b: String) -> Bool {
    var diff = 0
    var str1 = a
    var str2 = b
    for _ in  0..<a.count {
        if str1.first != str2.first {
            diff += 1
        }
        str1.removeFirst()
        str2.removeFirst()
    }
    return false
}


func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
    let usedWords = [String]()
    if !words.contains(target) {
        return 0
    }
    dfs(0, begin, target, words, usedWords: usedWords)
    return answer
}

