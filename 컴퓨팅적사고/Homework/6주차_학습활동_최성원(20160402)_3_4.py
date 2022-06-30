# 3. 교재 202쪽 8번 : 문제 요구사항에 따라 함수를 정의하고 호출하여 풀것

def Odd_or_even(number):
    return "짝수입니다" if number % 2 == 0 else "홀수입니다" # 2로 나누어 떨어지면 짝수, 아니면 홀수

n = int(input("3. 정수를 입력하시오 : "))
print(Odd_or_even(n))

# 4. 교재 178쪽 체질량지수 계산하여 건강을 진단하는 예제를 함수를 이용하여 작성해보자.
#  1) BMI를 계산하는 부분만을 함수로 정의하고 호출하여 풀 것
#    * 1)의 방식으로 하지 않고 BMI 값을 함수의 입력값으로 하여 정상/비만 등을 판단하는 부분을 함수로 만들어도 됩니다. 

#     (교재 195쪽 sine함수 예제 참조 - 이때는 각 조건별로 return이 다르게 return '정상' , return '비만' 과 같이 문자열 리턴 형식을 활용도 가능)

def BMI(height, weight):
    height /= 100
    return weight / (height * height)

print("\n4. 체질량지수 계산")
h = int(input("키가 몇 cm 에요? : "))
w = int(input("몸무게가 몇 kg 이에요? : "))

if BMI(h, w) < 20:
    message = "저체중입니다"
elif BMI(h, w) < 25:
    message = "정상체중입니다"
elif BMI(h, w) < 30:
    message = "경도비만입니다"
elif BMI(h, w) < 40:
    message = "비만입니다"
else:
    message = "고도비만입니다"

print("BMI : %d, %s"%(BMI(h, w), message))