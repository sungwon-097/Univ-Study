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

4. Jump
    - Condition Code 확인 후 Branch.

5. Goto statement
    - pipeline의 Comtrol Hazard를 피하기 위해(PC값이 가변적으로 변해 명령어 수행 중단) 조건을 모두 수행 후 사용
    - val= Test? Then_Expr: Else_Expr;
    - Bad cases
        - Expensive Computations : 연산이 많을 시
        - Risky Computations : Null pointer Error
        - Data Hazard : T case/false가 같은 값을 참조

6. Loop
    - for > while > do while > goto 형으로 변환이 가능. Assembly Code에선 goto문을 활용

7. Switch
    - Jump Table Structure를 사용하기 때문에 if문 사용 시보다 대체로 효율적임(if는 pipeline에서 비효율적, Control Hazard)
    - D (, Ri, S)형태로 JTS에서 명령어를 실행함
    - Empty Case는 다음 Case와 같은 Ri를 사용