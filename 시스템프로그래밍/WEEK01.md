# Week01-02

## Bits Bytes Integers

1. Bits
    - 컴퓨터는 Triggering(Electronic Implementation) 을 통해 0과 1을 나타냄

2. Bytes
    - 8bits = Byte

|C Data type|32bit|64bit|x86-64|
|-|-|-|-|
|char|1|1|1|
|short|2|2|2|
|int|4|4|4|
|long|4|8|8|
|float|4|4|4|
|double|8|8|8|
|long double|-|-|10/16|
|pointer|4|8|8|
* long, pointer Data Type에서 64bit와 32bit architecture의 차이가 발생

3. Bit Swap
>>    - xor 연산으로 swap을 구현 가능

```c
    void swap(int *x, int *y){

        *x=*x^*y;
        *y=*x^*y;
        *x=*x^*y;
    }
```
- Operations
    - intersection  -   &
    - union -   |
    - symmetric difference  -   ^
    - complement    -   ~
- Logical Operators
    - &&
    - ||
    - !
    * return value는 True or False
- Shift
    - '<<' to Left
    - '>>' to Right

4. Integers
    - Signed일 경우 MSB는 Sign bit
    - Negative는 2's Complement로 표현
    - Casting시 표현가능 비트가 낮은 자료형으로 변환하면 값의 손실이 생김
    - >> Unsigned와 Signed 값을 연산시 반환값은 Unsigned Value(중요)
    - Signed값을 shift right하거나 확장 시 MSB로 expanding함

5. Unsigned Addition

    - Operands : w bits
    - True Sum : w+1 bits
    - Discard Carry : w bits(u + v mod 2^w)

|   u|-|x|x|x|x|x|x||
|-|-|-|-|-|-|-|-|-|
|  +v|-|x|x|x|x|x|x|
|u +v|x|x|x|x|x|x|x|
|uAdd|-|x|x|x|x|x|x|Disard Carry|

6. Signed Addition
```c
int s, t, u, v;
s = (int) ( (unsigned) u + (unsigned) v );
t = u + v;
// s == t
```
|   u|-|x|x|x|x|x|x||
|-|-|-|-|-|-|-|-|-|
|  +v|-|x|x|x|x|x|x|
|u +v|x|x|x|x|x|x|x|
|Tadd|-|x|x|x|x|x|x|Disard Carry|

7. Multiplication
    - Operands : w bits
    - True Sum : w + w bits
    - Discard w bits : w bits
        - UMult(w) (u, v) = u * v mod 2^w
- Shift 연산을 통해서도 구현 가능 2^k 만큼 곱할 경우 << k

8. Byte Ordering
    - Little Endian, Big Endian

```c

    typedef unsigned char *pointer;
    int a = 15213;
    printf("int a = 15213;\n");
    show_bytes((pointer) &a, sizeof(int));

    void show_bytes(pointer start, size_tlen){
        size_t i;
        for (i= 0; i< len; i++)
            printf(”%p\t0x%.2x\n", start+i, start[i]);printf("\n");
    }
```
- Result (Linux x86-64):
- int a = 15213;
1. 0x7fffb7f71dbc 6d
2. 0x7fffb7f71dbd 3b
3. 0x7fffb7f71dbe 00
4. 0x7fffb7f71dbf 00