‘19 가을학기 컴퓨터구조(스마트SW 2) 중간고사
------------------------------------------------

## 1. (하나당 2.5점) (20점) 각 질문에 대하여 간단히 설명하시오

(1) Instruction Set Architecture ?
```
    하드웨어와 저수준 소프트웨어 사이에 추상화된 인터페이스를 의미한다. 구체적으로 말하면 컴퓨터에서 사용될 명령어 set(레지스터, 메모리 access, IO)을 먼저 정의 함으로서 컴퓨터 구조를 정의 하는 방법.
```
(2) 32 bit CPU와 64 bit CPU의 차이점은 무엇인가 ? CPU안에서 무엇을 보면 32 bit인지 64 bit인지를 알 수 있나 ?
```
    한 번에 처리 할 수 있는 데이터의 길이를 의미함. CPU 안에서 레지스터의 길이 또는 data bus bandwidth 를 보면 알 수 있다.
```
(3) system software 와 application software 차이점을 설명하고 각각의 예를 하나씩 드시오.
```
    시스템소프트웨어는 하드웨어 동작을 제어하고 응용프로그램이 작동 될 수 있도록 설계되어있다. 응용소프트웨어는 시스템소프트웨어 위에서 동작하는 프로그램을 말한다.
    예를들어 Sys.sw에는 윈도우/맥/리눅스 등이 있고 App.sw에는 ms오피스, 카카오톡, 줌 등이 있다.
```
(4) assembly code와 machine code 차이점 ?
```
    assembly code는 high level lang.을 기계가 이해하기 편하게 컴파일한 코드이고 machine code는 실제로 컴퓨터가 이해하고 처리하는 코드이다.
```
(5&6) 어떤 프로그램의 CPU 수행시간=IC x CPI x Tc 으로 표현된다. 이를 풀어서 표현하면 seconds/program = A/program x B/A x seconds/B 이다. A, B는 각각 무엇인가 ? IC, CPI, Tc 에 영향을 주는 요소로는 algorithm(A), program language(P), compiler(C), instruction set architecture(I)가 있다. IC에 영향을 주는 요소들은 ? (A, P, C, I로 답하세요). CPI에 영향을 주는 요소들은 ? Tc에 영향을 주는 요소들은 ? 
```
A: instructions
B: clock cycle 수
IC: A, P, C, I
CPI: A, P, C, I
Tc: I

(Tc에는 ISA만이 영향을 준다.)
```
(7) 순차회로에서 clock triggering에는 4 종류가 있다. 그중 positive edge triggering 방식을 설명하시오.
```

```
(8) k개의 stage를 가진 명령어 pipeline에서 clock cycle time=t, n개의 명령어를 실행한다 하자. pipeline사용한 경우가 pipeline을 사용하지 않은 경우 대비 speed up 효과를 n, k, t를 사용해 표현하시오. 만일 n이 아주 커지면 speed up 효과값은 얼마인가 ? 
```
    SpeedUp = nkt / (k-1)t + nt = nkt / (k+n-1)t

    n 이 아주 커지면 SpeedUp 효과값은 k가 된다.
```
## 2. (하나당 2.5점) (10점) 다음은 ARM 명령어에 관한 것이다. 

(1) R0=0x0000, R1=0x0003, R2=0x0001 라고 하자. ADD R0, R1, R2, LSL 2 수행후 R0 값은 ? 
```
    0x0007

    (ADD R0, R1, R2, LSL 2 = ADD R0, R1, {R2, LSL 2})
```
(2)  R0=0xFFFF 라고 하자. BIC R0, R0, 1<<3 수행후 R0 값은 ? 
```
    0xFFF7

    (BIC R0, R0, 1<<3 => R0 AND NOT(1000))
```
(3) 배열 A[5]를 읽고 R2에 저장하는 명령어를 쓰시오. R0는 배열 A 시작주소를 갖고 있고 R1은 인덱스값 5를 가지고 있다고 하자.
```
    LDR R2, [R0 , R1, LSL 2]
```
(4) LDR R3, [R2, #4]!와 LDR R3, [R2], #4 의 차이점을 설명하시오. 
```
LDR R3, [R2, #4]! - R3에 R2+4 번지 값을 로드한다. R2는 4만큼 증가한다.

LDR R3, [R2], #4  - R3에 R2 번지 값을 로드한다. R2는 4만큼 증가한다.
```
## 3. (10점) 다음은 ARM 코딩 및 최적화에 관한 것이다.

(1) (3점) x |=(1<<4)를 ARM 어셈블리 코드로 표현하시오. x는  R0에 있다고 가정한다. 
```
ORR R0, R0, #1 LSL #4
```
(2)  (4점) R5=(R0 < 0)? R2: R1을 어셈블리코드로 구현하시오

 ① CMP 명령어를 이용한 어셈블리코드
 ```
CMP R0, #0
MOVLT R5, R2
MOVGE R5, R1
```
 ② CMP 명령어를 이용하지 않는 어셈블리코드 (3줄)
```
AND R3, R2, R0 ASR 31
BIC  R4, R1, R0 ASR 31
ORR R5, R3, R4
```
(3) (3점) 아래의 코드를 최적화하시오 (branch 제거)
```
CMP R3, R4
BEQ ELSE
ADD R0, R1, R2
B
EXIT
ELSE SUBR0, R1, R2
EXIT

=====>

CMP R3, R4
ADDNE R0, R1, R2
SUBEQ R0, R1, R2 
```
## 4. (15점) 그림 1은 fact(2)를 recursive call 방식으로   factorial 계산하는 어셈블리 코드이다. 어셈블리 루틴 들어가자마자 stack에 특정 값들을 저장하였다가 그 루틴의 exit 바로 직전에 그 값들을 복구한다. stack에 저장되는 값들을 추적하고자 한다.

(1) (12점) 그림 1에서 ①,②,③,④,⑤,⑥ 단계가 수행된 직후 stack의 변화 (SP값, stack에 저장된 값)된 모습을 각각 그리시오. ①,②,③단계는 각 경우에 SUB sp, sp, #8부터 3개의 명령어를 수행하는 과정을 의미한다. ④ 단계는 ADD sp, sp, #8 수행을 의미한다. ⑤,⑥ 단계는 각 경우에 LDR r0, [sp, #0]부터 3개의 명령어를 수행하는 과정을 의미한다. main 코드가 컴파일 된후 fact(2)는 메모리 2000 (10진수), 다음 명령어 printf()는 메모리 2004번지 (10진수)에 위치, 어셈블리 코드에서 fact는 메모리 3000번지(10진수)에서 시작하고 BL fact는 3040번지(10진수), 그 다음 명령어 MOV r12, r0는 3044번지(10진수)에 위치한다고 하자. ① 단계로 진입할 때 SP=7000 (10진수)라고 하자.
```
    다음 페이지 그림 참조
```
(2) (3점) fact 루틴안의 2개의 STR 명령어를 mutiple store 명령어로, 2개의 LDR 명령어를 mutiple load 명령어로 표현하시오.
```
    다음 페이지 그림 참조
```
## 5. (하나당 2.5점) (15점) 그림 2는 32 비트 CPU에서 사용하는 실제 메모리 구성도이다. 논리적으로 메인메모리 크기는 2**32 x 8 =4GB 이다. 이를 실제로는 1GB (2**30 x 8) 메모리 4개로 구성한다.  그림 2의 메모리 맨 왼쪽에 보이는 주소는 각 1GB에 제공되는 주소이다 (CPU가 제공하는 32 비트중 상위 30비트 사용). 메모리 안의 숫자는 저장된 값을 의미한다. 

(1) 4GB 메모리 하나 대신에 1GB 메모리 4개를 병렬로 구성한 이유는 ? 
```
    한번에 4 바이트가져오려고 함. 성능향상 목적
```
(2) R1=0x0000 이라고 하자. LDRB R0, [R1]을 수행한 결과의 R0값은 ? (16 진수로 표기) 
```
    0x00000010
```
(3) R1=0x0000 이라고 하자. LDRSH R0, [R1]을 수행한 결과의 R0값은 ? (16 진수로 표기) 
```
    0xFFFFF510
```
(4) R1=0x0000 이라고 하자. LDR R0, [R1]을 수행한 결과의 R0값은 ? (16 진수로 표기) 
```
    0x1234F510
```
(5) R1=0x0002 이라고 하자. LDR R0, [R1]을 수행한 결과의 R0값은 ? (16 진수로 표기) 
```
    0x67891234
```
(6) 위의 (4)를 수행하는 것과 (5)를 수행하는 것과의 차이점은 ?
```
    (4)는 메모리 한번접근, (5)는 메모리 두번 접근
```
## 6. (30점) 그림 3은 single cycle로 명령어를 수행하는 MIPS CPU 설계 블록도이다. 그림 4는 MIPS 명령어 포맷을 나타낸다.

(1) (5점) 컴퓨터는 5개의 모듈, datapath, control, memory, input, output으로 나눌 수 있다. 그림 3에서 각 component (C1~C11)는 위 5가지 모듈중 어느 것에 속하는가 ? (예: C1:control) 

|C1: datapath| C2: datapath| C3: memory| C4: control|
|-|-|-|-|
|C5: datapath| C6: datapath| C7: datapath| C8: control|
|C9: datapath| C10: datapath| C11: memory||

(2) (4점) component(C1~C11)중에 순차회로인 component를 열거하시오 

    C1, C3, C5, C11

(3)  MIPS 명령어 sw $1, 4($2) (ARM 명령어 STR R1, [R2, #4]에 해당)는 아래 4단계를 거쳐 수행된다.
```
단계 1. Fetch instruction and increment PC.
단계 2. Read two registers and generate control signals in the main control unit.
단계 3. Use ALU for an effective address calculation
단계 4. Access the memory to write data
```
① (8점)각 단계별로 사용되는 component를 열거하고 각 component에서 담당하는 기능을 설명하시오.
```
단계1: C1, C2, C3
단계2: C4, C5, C6
단계3: C8, C10
단계4: C11
```
② (2점) C6이 필요한 이유를 설명하시오.
```
32비트 CPU에서 ALU는 32비트 연산을 하기 때문. 16비트에서 32비트로 부호확장한다.
```
③ (6점)그림 3 맨 오른쪽 표에서 (ALUOp는 제외) 각 control signal값들을 쓰시오(0, 1, 또는 x). 그렇게 나온 이유를 각각 설명하시오.
```
RegDst: x
ALUsrc: 1
MemtoReg: x
Regwrite: 0
Memread: 0
Memwrite: 1
Branch: 0
```
(4) (5점)그림 3을 pipelined 방식(multi cycle)으로 구현을 변경한다면 변경내용이 무엇인가 ? 그것의 용도 및 필요한 이유를 설명하시오.
```
pipeline 레지스터 4개, IF/ID, ID/EX, EX/MEM, MEM/WB
이전 단계 연산결과 임시저장, CU의 제어신호 저장, 명령어 내용 일부저장
각 단계에서 수행되는 각 명령어가 독립적으로 수행되게 해준다
```