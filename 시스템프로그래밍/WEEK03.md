# Week 03

## Floating Point

- IEEE floating point standard: Definition

1. float
    - Numerical Form : (-1)^s M 2^e
    - s : sign bit 
    - M : fraction Value
    - E : exponent

- 32 bits (10^-7자리까지 표현 가능)

|s|exp|frac|
|-|-|-|
|1|8-bits|23-bits|

- 64 bits (10^-15자리까지 표현 가능)

|s|exp|frac|
|-|-|-|
|1|11-bits|52-bits|
```
ex) float F = 15213.0;

- 15213(10) = 11101101101101(2)
            = 1.1101101101101(2) * 2^13
- M    = 1.1101101101101
- frac =   1101101101101 
- E = 13
- Bias = 127
- Exp = E + Bias = 140 = 10001100(2)
```
Result:

|s|exp|frac|
|-|-|-|
|0|10001100|1101101101101|

* Denormalized values

|EXP|Frac|Values|ex|
|-|-|-|-|
|000...0| 000...0|Represents zero value|+0 and –0|
|000...0|! 000...0|Numbers closest to 0.0|-|
|111...1| 000...0|Represents value ¥ (infinity)|1.0 / 0.0 = −1.0 / −0.0 = +¥, 1.0 / −0.0 = −¥|
|111...1|! 000...0|Not-a-Number (NaN)|sqrt(–1), ¥ − ¥, ¥  ́ 0|

2. Round
    - Nearest Even 방식을 사용(default) : 가까운 2의 배수쪽으로 반올림

3. FP Add
    - (–1)^s1 M1 2^E1 * (–1)^s2 M2 2^E2
    - Exact Result: (–1)^s M 2^E

    1. Sign s: s1^s2
    2. Significand M: M1 x M2
    3. Exponent E: E1+E2

- 비교 시 결합법칙이 성립하지 않을 수 있으며 Overflow경우 항상 고려

4. FP Multiplication

- 교환/분배법칙 성립하지 않을 수 있음

5. Abelian Group
    - Closure : a, b가 A에 속했을때 둘의 연산은 A에 속해있다(닫혀있다)
    - Associativity : 결합법칙
    - Identity element : 항등원
    - Inverse element : 역원

6. Great Reality

    - is x * x >= 0 ?
        - float : Ture
        - int : consider Overflow cases
    - is (x + y) + z = x + (y + z) ?
        - Unsigned & Signed int : True
        - float : consider Rounding cases

7. Casting
    - double/float -> int
        - out of range or NaN 일 경우 not defined
    - int -> double
        - Yes(4Byte -> 8Byte)
    - int -> float
        - round 고려