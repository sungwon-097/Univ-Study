# 1. 아래의 문제를  5주차_학습활동_이름(학번)_1.py로 작성

#      1-1. 교재 227쪽 9번 문제를 while문으로 작성

i = 0
while True:
    i = int(input("단 수를 입력해 주세요 : "))
    if(i > 0):
        break   # i값이 자연수면 루프를 빠져나가 구구단 출력, 그렇지 않을 경우 루프를 돌며 i값을 입력받음
    print("올바른 범위가 아닙니다(1 이상의 자연수)")
j = 1
print("====%d단====" %i)
while j < 10:
    print("%d * %d = %2d" %(i, j, i*j))
    j += 1

#     1-2. 교재 227쪽 9번 문제를 for문으로 작성

l = [1]
for i in l:
    l.append(i+1) # list의 원소를 추가하며 for 무한루프를 돌도록 함
    i = int(input("\n단 수를 입력해 주세요(자연수 이외의 수를 입력하면 종료) : "))
    if i < 1:
        print("올바른 범위가 아닙니다.")
        break
    print("====%d단====" %i)
    for j in range(1, 10):
        print("%d * %d = %2d" %(i, j, i*j))