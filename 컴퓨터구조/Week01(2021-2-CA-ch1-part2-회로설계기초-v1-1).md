# Week 01-1(2021-2-CA-ch1-part2-회로설계기초-v1-1)

* Digital Computer
```
    1. processor수준 (ex)CPU, Memory, I/O Processor            (컴퓨터 구조 과목*)
    2. register 수준 (ex)Multiplexer, Decoder, Encoder, Register, Counter, ALU, Datapath
    3. gate 수준 (ex) AND, OR, NOT, NAND, NOR                  (디지털 회로 설계 과목)
    4. device 수준 (ex) Transistor
```
* 논리소자/기억소자
```
    논리소자
    - 트렌지스터 소자로 구성. 논리동작을 수행함.

    기억소자
    - 논리소자들로 구성, 소자들 사이에 피드백 회로 존재(메모리기능), 클럭이 지정하는 시간만 동작

    트렌지스터는 스위치, 증폭기 기능을 함
```
* 조합회로/순차회로
```
    조합회로
        -논리소자들로만 구성 -> 조합회로는 입력변화에 항상 반응
        -회로에 공급되는 클럭에 무관하게 동작
    순차회로
        -보통 논리소자들 + 기억소자들로 구성
        -기억소자 파트는 클럭에 동기화되어 클럭의 특정부분에 해당되는 짧은 시간동안만 동작
        -전체적으로 보면 기억소자 파트가 중요한 역할을 담당

    Multiplexer > D0의 값에 따라 정해짐

    Decoder > 3개의 입력 수를 이진수로 보아 011이면 D3=1
```