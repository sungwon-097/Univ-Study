# 1. 교재 181쪽 7번 

quiz = int(input("퀴즈점수 입력 : "))*0.2
midterm = int(input("중간고사 점수 입력 : "))*0.3
final = int(input("기말고사 점수 입력 : "))*0.5

score = quiz + midterm + final
if score < 70 :
    print("Your Score is Fail")
else:
    print("Your Score is Pass")

# 2. 교재 181쪽 8번 

temp = int(input("현재 기온을 입력하시오('C) : "))

if temp < 11:
    print("날씨가 춥습니다\n두꺼운 외투를 챙기세요.")
elif temp < 16:
    print("날씨가 선선하네요\n가벼운 외투를 챙기세요.")
elif temp < 20:
    print("생활하기 좋은 기온입니다\n가볍게 입으세요.")
else:
    print("덥게 느껴지는 날씨입니다\n반팔티도 괜찮습니다")