# Week 05

## Machine Level programming : Control

1. Compare
    - cmpq Src2, Src1 : Src1 - Src2 의 condition code를 저장
    - SF, ZF, CF ,OF를 Update
    - CF : setif carry out from most significant bit (unsigned overflow)
    - OF : setif two’s-complement 
        - (signed) overflow(a>0 && b>0 && t<0) || (a<0 && b<0 && t>=0)

2. Test
    - testq src2, src1 : after a & b, changes Condition Codes
    - ZF : a&b == 0
    - SF : a&b < 0

3. SetX
    - Condition Code 확인 후 명령을 실행할지 결정