#1. 교재 33쪽 8번, 한국돈을 중국돈으로 변경하기

won = 1500000
won_to_yuan = won / 163.42

print(won_to_yuan, "yuan")

# 2. 교재 34쪽 13번, 피자 크기 차이 계산하기

#   - 주의 : 넓이를 구하고 몇 배인지 고려

from math import *
regular_r = 8 / 2
large_r = 12 / 2

regular = regular_r * regular_r * pi
large = large_r * large_r * pi

print(large / regular, "배")

# 3. 강의자료 1(컴사_2주1강_Turtle그래픽)에서 27페이지 사각형과 삼각형을 이용해 집 모양 그리기 (힌트 2개의 for문을 사용)

import turtle as t

t.shape('turtle')
t.shapesize(3)

t.home()
t.clear()

for i in range(3):
    t.fd(100)
    t.left(360/3)

for i in range(4):
    t.fd(100)
    t.right(360/4)

# 4. 강의자료 1(컴사_2주1강_Turtle그래픽)에서 29페이지 한변의 길이가 300인 별 그림 그려보기

t.shape('turtle')
t.shapesize(3)

t.home()
t.clear()

for i in range(5):
    t.fd(300)
    t.right(144)