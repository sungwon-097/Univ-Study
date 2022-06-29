# 1. 아래의 문제를  5주차_학습활동_이름(학번)_1.py로 작성

#      1-1. 교재 227쪽 9번 문제를 while문으로 작성

while True: # 0을 입력받기 전까지 계속 실행
    i = int(input("\n1. 단 수를 입력해 주세요(2<=n<=9 ,0 입력 시 종료) : "))
    if(2 <= i <= 9):
        j = 1
        print("====%d단====" %i)
        while j < 10:
            print("%d * %d = %2d" %(i, j, i*j)) # 구구단 계산
            j += 1
    elif i == 0:
        print("종료")   # 0 입력 시 종료
        break
    else:
        print("올바른 범위가 아닙니다. 다시 입력해 주세요. ")   # 다시 입력받음

#     1-2. 교재 227쪽 9번 문제를 for문으로 작성

l = [1]
for iterator in l:  # 0을 입력받기 전까지 계속 실행
    l.append(iterator+1)    # for 무한루프를 사용하기 위함

    i = int(input("\n2. 단 수를 입력해 주세요(2<=n<=9 ,0 입력 시 종료) : "))
    if(2 <= i <= 9):
        print("====%d단====" %i)
        for j in range(10):
            print("%d * %d = %2d" %(i, j, i*j)) # 구구단 계산
    elif i == 0:
        print("종료")   # 0 입력 시 종료
        break
    else:
        print("올바른 범위가 아닙니다. 다시 입력해 주세요. ")   # 다시 입력받음