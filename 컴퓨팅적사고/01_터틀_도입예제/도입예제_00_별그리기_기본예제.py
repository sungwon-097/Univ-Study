# import turtle
# shape / shapesize : turtle

from turtle import *

speed(0) 
color('red', 'yellow')
begin_fill() # 채우기
while True:
    forward(200)
    left(170)
    if abs(pos()) < 1: # 현재 좌표
        break
end_fill() # begin_fill()과 pair로 사용
done()
