# Week 02-1(2021-2-CA-ch2-part1-instruction-v1)

* ARM Assembly Language

    |명령어|의미|비고|
    |-|-|-|
    |ADD r1, r2, r3 |r3 = r1 + r2|레지스터 피연산자 3개|
    |AND r1, r2, r3 |r3 = r1 & r2|피연산자 3개, 비트간 AND|

* Bubble Sort in C
``` C
    void sort (int v[], int n)
    {
    int i, j;
    for (i = 0; i < n; i ++ ) {
        for (j = i – 1;j >= 0; j --) {
            if (v[j] > v[j + 1]) swap(v,j);
            }
        }
    }
```
* 고급언어 프로그램 코드 수행 과정
```
    1. 메모리에서 컴파일러/인터프리터 이용하여 이진수 변환, 저장장치에(하드) 저장 
        //text와 data 영역으로 나눠짐
    2. 저장장치에서 해당 기계코드(수행파일)를 메모리에 로드함
    3.  메모리에 저장된 기계코드를 대상으로 CPU는 명령어를 하나씩 읽어와서(fetch) 순차적으로 수행(execute)한다.
    4. 최종결과값 출력 // 코드수행 종료

    고급언어프로그램에서 변수는 존재하지 않음
        //어셈블리, 기계코드로의 변환 과정에서 메인메모리 주소로 대체됨
```
* Byte/Word
```
    - 1 byte = 8 bits
    - 64 비트 CPU에서의 1 Word = 64 bits = 8 Byte

    - 32 비트 CPU와 64 비트 CPU의 차이점
        레지스터 길이와 메모리 -> CPU 최대 데이터 길이 다름. 각 64 / 32bits

    - 명령어(instruction) 길이 // CPU와 직접적인 관련 X
        ARM: 32 비트 CPU 16 또는 32 bits, 64 비트 CPU 경우 32 bits
        Intel: 32 비트 CPU 8 ~ 120 bits, 64 비트 CPU 경우 41 bits
```
* 