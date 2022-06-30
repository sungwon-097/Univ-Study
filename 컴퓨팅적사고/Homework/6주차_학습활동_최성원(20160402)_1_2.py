# 1. 교재 202쪽 5번 : 문제 요구사항에 따라 함수를 정의하고 호출하여 풀것

def F(x):
    return 3*x**2 + 5*x + 7

print("1. f(x) = 3*x**2 + 5*x + 7")
X = [15, 20, 25]
for x in X:
    print("f(%d) = %d"% (x ,F(x)))
# 2. 교재 202쪽 6번 : 문제 요구사항에 따라 함수를 정의하고 호출하여 풀것

def Area_of_triangle(base_len, height_len):
    return base_len * height_len / 2

print("\n2. 삼각형의 넓이 = 밑변 * 높이 / 2")
base = int(input("밑변을 입력하시오 : "))
height = int(input("높이를 입력하시오 : "))

print("삼각형의 넓이는 %d 입니다." %(Area_of_triangle(base, height)))