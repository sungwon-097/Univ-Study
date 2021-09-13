# Week1-1 (2021-2-CA-ch1-part1-intro-final-v1)

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
* Z=X+Y 의 Instruction 명령어 변환 과정
```
    - LDR R1, M[X];변수 X가 저장된 메모리값, M[X],을 R1으로 복사
    - LDR R2, M[Y]; 변수 Y가 저장된 메모리값, M[Y],을 R2로 복사
    - ADD R3, R1, R2; 레지스터 R1과 R2를 더하여 결과를 R3에 저장
    - STR M[Z], R3; R3값을 변수 Z가 저장된 메모리에 저장
    * 컴퓨터 내부에서 어떻게 수행되는지 sequential circuit분석과 timing에 근거하여 이해한다
```
* Assembly Programming
```
    고급언어 => 어셈블리언어 = > 기계어(머       신 코드, binary digit)
```
* Pipelining(프로세서 성능 개선 기법)
```
    |1|2|3|
      |4|5|6|
        |7|8|9|             > 동시에 여러 개의 명령어를 처리하므로써 처리량을 올리는 것
```
* COMPUTER COMPONENTS
```
    CPU: ALU <= ns단위 => Resister <= μs단위 => MainMemory <= ms단위 =>DiskDrive
```
* Computer Architecture
```
    Instruction Set Architecture (ISA)
        - 어세블리 프로그래머에게 중요. 1964년 IBM에서 처음 사용됨
        - 결과물 : IA-32, IA-64
        - Implementation은 486, Pentium등 하드웨어의 종류.
            *Architecture(ex> I4/V6)와 Implementation(ex> Model Name)의 차이점 중요!
```
* 추상화, 구체화 - 개발방법론
```
    ISA정의의 S/W관점 > OS개발 > 언어, 컴파일러 > 알고리즘 > 응용프로그램
    ISA정의의 H/W관점 < Microarchitecture < Gates/Register < Circuits < 트렌지스터 < Physics
    >>> 추상화 / <<< 구체화
        50-80년대 : 논리회로 ~ 컴파일러
        90년대    : Gates/Register ~ ISA
        2000년대  : OS, 컴파일러 (+병렬처리)     Circuits (+신뢰도,전력소모)
```
* Classes of Computers
```
    pc, server, Super computers(현존하는 최강), Embedded computers(내제화됨)
    pc개발이 감소하고 Embedded computers 인 스마트폰 개발이 증가하는 추세

    Cloud computing > 데이터 센터에 있는 서버(아마존, 구글)
```
## Introcuction
```
    1. 하이래벨 언어가 머신코드로 어떻게 해석/응용 되는지
    2. SW관점 -> 명령어 , HW관점 > 명령어를 수행하는 과정
    3. 프로그램의 성능에 영향을 미치는 펙터, 어떻게 효육적으로
    4. 성능개선
    5. 에너지효율성
    6. 병렬처리
    7. 모던컴퓨팅의 기본
```
* Program Performance
```
    1. 알고리즘
    2. 언어,컴파일러, 아키텍처       SW관점 메모리 참조 횟수
    3. 프로세서, 메모리 시스템
    4. OS                          HW관점 CPU Clock Rate
```
        단위 : KB 10^3, MB 10^6, GB 10^9, TB 10^12, PB 10^15, EB 10^18, ZB 10^21, YB 10^24
* Great Ideas in Computer Architecture
```
    1. 무어의법칙(반도체 집적도. 2년 2배)
    2. 추상화, 단순화
    3. Common 케이스
    4. 병렬 처리
    5. 파이프라이닝
    6. 예측
    7. 계층 구조
    8. Fault-tolerance(컴퓨터 이중구조)
```
# Week 1-2

* 프로그래밍 언어가 머신코드로 바뀌어 수행 될 때 머신코드 몇 개가 수행 됬는지. CPU Clock Rate가 얼마냐에 따라 프로그램의 실행 속도가 결정됨

* ## Performance (무어의 법칙, 2년에 2배씩 발전)

    |Year Technology| Relative |performance/unit cost|
    |-|-|-|
    1951| Vacuum tube| 1
    1965| Transistor |35
    1975| IC|900
    1995| VLSI| 2,400,000
    2013| ULSI| 250,000,000,000
```
    Response time (= execution time ) : 반응속도, 수행시간 
    Throughput (= bandwidth) : 단위시간당 처리하는 일
    Performance and execution time 은 반비례함. 성능이 높을수록 반응속도 down

    Definitions of time
         경과 시간 : Wall-clock time = Response time = Elapsed time
         CPU time = User CPU time + System CPU time
```
* CPU Clocking
```
    4 Ghz   =>     1초에 4*10^9 (Clock frequency (rate))   =>   0.25ns  (Clock period)

    CPU Time = CPU Clock Cycles * Clock Cycle Time(=1/Clock Rate)
            * 사이클 클럭 수와 사이클 타임의 곱
    Clock Cycles = IC x CPI

    CPU Time = IC * CPI (명령어당 평균 소요 사이클) * Tc
```
*  Multicore 
```
    멀티코어 활용을 위해 parallel programming 이 필요함.
```
