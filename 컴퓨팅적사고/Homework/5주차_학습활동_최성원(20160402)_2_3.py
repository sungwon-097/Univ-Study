# 2.  아래의 문제를 5주차_학습활동_이름(학번)_2_3.py로 작성

#   2-1. 교재 228쪽 11번  - 교재문제의 요구상을 만족하도록 작성 (while문 이용)

A = int(input("A를 입력하세요 : "))
B = int(input("B를 입력하세요 : "))

A_copy = A
result = 0
while A_copy <= B:
    result += A_copy
    A_copy+=1
print("%d 부터 %d 까지의 합은 %d 입니다." %(A, B, result))

#   2-2. 교재 228쪽 14번  - 교재문제의 요구상을 만족하도록 작성 (for문 사용)

result = 0
for i in range(50, 101):
    if (i % 3 == 0) | (i % 5 == 0):
        result += i
        print(i, end = " ")
print("\n50부터 100까지의 정수 중에서 3 또는 5로 나누어 떨어지는 수들의 합 : ", result)