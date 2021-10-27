# Week 06

## Machine Level programming : Procedures

1. Stack
    - Top to Bottom
    - pushq Src : decrement %rsp by 8 (stack pointer -8)
    - popq Src : increment %rsp by 8

2. Procedure Control Flow : 
    - Call : call, label
        - Push return address on stack
        - Jump to label
    - Return : ret
        - pop address from stack
        - Jump to address
    - 메소드를 call함 -> 함수 수행 후 return -> 복귀 후 다음 명령어 수행