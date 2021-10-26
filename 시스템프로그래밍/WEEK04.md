# Week 04

## Machine Level programming

>> Backward Compatibility : 이전 기능을 지원( < 호환성)

1. CISC / RISC

|-|CISC|RISC|
|-|-|-|
|Instruction|Many|Simply|
|Performance|Relatively slow|Fast (But Intel CISC is more Fast)|
|Power|High|Low|

2. Definition
    - ISA : Instruction Set Architecture(arch에서 사용하는 명령어의 집합을 정의)
    - Machine Code : Byte level의 언어
    - Assembly Code : A text representation of machine code

3. CPU - MEM
    - CPU : Regs + PC + Condition Codes ....
    - Memory : Code + Data + Stack ....
    - CPU to MEM : Addresses
    - MEM to CPU : Data, Instruction
    - 레지스터에는 PC, 범용레지스터, CPRS가 있다

4. C into Obj Code

- Build:

|text|C program(*.c, *.c)|
|-|-|
||> Compiler (gcc -Og -s)|
|text|Assembly program(*.s, *.s)|
||> Assembler (gcc or as)|
|binary|Object program(*.o, *.o)|
||> Linker (gcc or ld)|
|binary|Executable program(p)|

5. Instruction
    - Opcode Operand(src, dest)
    - '( )'는 메모리
    - *dest는 dest 값을 담고있는 레지스터가 가리키는 메모리 주소

6. Disassemble
    - Dump 또는 Disas를 통해 Machine Code 를 Assembly 코드로 변환 가능
    - objdump -d [shell]
    - Reverse Engineering을 하기 위해 사용하기도 함

7. 16 Registers

    - Backward Compatibility를 위해 32bit, 16bit register 지원
    - %rax( %eax( %ax ( %ah, %al ) ) )

|x86-64|32|origin|x86-64|32|
|-|-|-|-|-|
|%rax|%eax|accumulate|%r8|%r8d|
|%rbx|%ebx|base|%r9|%r9d|
|%rcx|%ecx|counter|%r10|%r10d|
|%rdx|%edx|data|%r11|%r11d|
|%rsi|#esi|src index|%r12|%r12d|
|%rdi|%edi|dest index|%r13|%r13d|
|%rsp|%esp|stack pointer|%r14|%r14d|
|%rbp|%ebp|base pointer|%r15|%r15d|

8. Moving data

    - movq Source, Dest:
    - Operand types
        - immediate : const int data ($)
        - register : 16 int reg (%)
        - memory : 8bytes of memory at address given by register ( (%rax) )
    - src가 메모리 일 때, dest는 레지스터만 올 수 있다
    - movzbl : 레지스터의 크기 상이 등의 이유로 무부호확장을 하기 위해 사용

9. Memory Addressing Mode
    - General Form : D ( Rb, Ri, S) = Mem[ Reg[rb] + S * Reg[ri] + D]
    - Special Cases : (Rb. Ri) / D(Rb, Rs) / (Rb, Ri, S)

10. Address Computation Instruction
    - leaq Src, Dest : Src is address '(rax)'
    - salq, sarq : arithmetic logical shift (Unsigned)
    - shlq, shrq : logical shift (Signed)
    - addq, subq, imulq, andq, orq, xorq....

11. One operand Instruction
    - incq, decq : increase 1, decrease 1
    - negq : (-1)Dest
    - notq : ~Dest

12. imul의 복잡도를 극복하기 위해 컴파일러는 shift연산으로 바꿀 수 있는 명령어는 최대한 변환함