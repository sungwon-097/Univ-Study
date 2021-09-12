# 컴퓨터 구조

Grading

``` 
 Mid-term exam 35% 
 Final exam 35% 
 Homework 25%
 Participation 5%

 정규식 교수님은 예를 드는 것을 좋아하심.
```

## Week1-1 (2021-2-CA-ch1-part1-intro-final-v1)

* 컴구조를 배워야 하는 이유
```
    1. 성능이 최적화된 소프트웨어 개발에 도움
    2. 하드웨어 설계에 도움
    3. OS동작 이해에 도움(3-1과목)  
        프로그램의 상태는 레지스터, 메모리 값으로 구성 / OS처리에 중요한 인터럽트처리 / VM

    컴구조 : 코딩 => 1 : 3 비율로 공부 / IT기술의 트렌드에 대한 이해 중요
```
* 컴퓨터 내부 구조 및 동작원리
```
    H/W 메인 컴포넌트3 : CPU(Register, ALU, Central Unit), 메인메모리, 디스크드라이브
    S/W 측면으로 컴퓨터는 하나의 Instruction set 으로 정의 할 수 있는 Machine
        Instruction :  컴퓨터가 해독하여 수행할 수 있도록 설계된 명령어(2진수 표현)
            컴퓨터를 제어        => CPU,        
            CPU를 제어          => CU,
            CU를 제어           => Instruction,  
            Instruction을 제어 => 프로그래머가 만든 프로그램에 의해
```