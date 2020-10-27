//
//  main.swift
//  풍선 터뜨리기
//
//  Created by 원현식 on 2020/10/25.
//

import Foundation

func solution(_ a:[Int]) -> Int {
    var answer = 2
    var leftMin = a[0], rightMin = a[a.count-1]
    
    for i in 1..<a.count-1 {
        if a[i] < leftMin {
            leftMin = a[i]
            answer += 1
        }
        
        if a[a.count - 1 - i] < rightMin {
            rightMin = a[a.count - 1 - i]
            answer += 1
        }
        
        if leftMin == rightMin {
            answer -= 1
            break
        }
    }
    return answer
}

let a = [-16,27,65,-2,58,-92,-71,-68,-61,-33] // a의 수는 모두 다르다.
print(solution(a)) // 6

// 맨 끝 숫자는 무조건 남을 수 있다. -> 큰 수 제거, 작은 수 제거 모두 사용 가능하기 때문.
// 맨 끝 숫자보다 작으면 맨 끝을 제외한 숫자도 남을 수 있다.






