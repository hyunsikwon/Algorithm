//
//  main.swift
//  [카카오] 키패드 누르기
//
//  Created by 원현식 on 2021/05/28.
//

import Foundation

func check(_ target: Int,
           _ left: Int,
           _ right: Int,
           _ hand: String) -> String {
    
    let position: [(row: Int, col: Int)] = [(0,0), (0,0), (0,1), (0,2),
                                             (1,0), (1,1), (1,2),
                                             (2,0), (2,1), (2,2),
                                             (3,0), (3,1), (3,2)]
    
    let leftP = position[left]
    let rifhtP = position[right]
    let targetP = position[target]
    
    let leftDis = abs(leftP.col - targetP.col) + abs(leftP.row - targetP.row)
    let rightDis = abs(rifhtP.col - targetP.col) + abs(rifhtP.row - targetP.row)
    
    if leftDis == rightDis { return hand == "right" ? "R" : "L" }

    if leftDis < rightDis { return "L" }

    return "R"
}

func solution(_ numbers:[Int], _ hand:String) -> String {
    var result = ""
    var leftHandPosition = 10
    var rightHandPosition = 12
    
    for i in 0..<numbers.count {
        let number = numbers[i] == 0 ? 11 : numbers[i]
        if [1, 4, 7].contains(number) {
            leftHandPosition = number
            result += "L"
            continue
        }
        
        if [3, 6, 9].contains(number) {
            rightHandPosition = number
            result += "R"
            continue
        }
        
        
        let ch = check(number, leftHandPosition, rightHandPosition, hand)
        result += ch
        if ch == "L" {
            leftHandPosition = number
        } else {
            rightHandPosition = number
        }

    }
    
    return result
}
