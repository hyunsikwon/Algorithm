//
//  main.swift
//  [카카오] 파일명 정렬
//
//  Created by 원현식 on 2020/08/22.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let files = ["img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"]

// OUTPUT: img1.png, IMG01.GIF, img02.png, img2.JPG, img10.png, img12.png
print(solution(files))

func solution(_ files:[String]) -> [String] {
    var result = files
    
    result.sort { (a: String, b: String) -> Bool in
        
        var headA = ""
        var numA = ""
        var flag = false
        for char in a {
            let str = String(char)
            if flag == true && Int(str) == nil { // tail은 무시
                break
            }
            
            if Int(str) == nil {
                headA += str
            } else {
                flag = true
                numA += str
            }
        }
        
        var headB = ""
        var numB = ""
        flag = false
        for char in b {
            let str = String(char)
            if flag == true && Int(str) == nil {
                break
            }
            
            if Int(str) == nil {
                headB += str
            } else {
                flag = true
                numB += str
            }
        }
      
        
        if headA.lowercased() == headB.lowercased() {
            if Int(numA)! == Int(numB)! {
                return false
            } else {
                return Int(numA)! < Int(numB)!
            }
            
        } else {
            return headA.lowercased() < headB.lowercased()
        }
        
    }
    
    return result
}

