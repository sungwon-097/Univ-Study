# Week 4

+ Trade off : 선택

+ 조합회로(Combinational logic)와 최적화(Optimization)

1. Standard Representation : Truth Table

    - Canonical Form, Sum of Minterm : 모든 항 나열. 불대수식 이용
    - Sum of Minterms Repersentation : Sigma를 이용해 minterms 의 합으로 표현

2. Combinational Logic Design Process

    - 1 Capture the function (Truth Table or Equation)
    - 2-1 Create equation(SoP, SoM)
    - 2-2 Implementas a gate-based circuit

    - Completeness : NAND와 NOR는 기본 로직 세가지를 모두 만들 수 있다(and, or, not)

3. Number of Possible Boolean Functions 문제(?)

4. Decode : 간략한 정보를 펼쳐서 구체적인 정보로 만들어 주는 것

5. Decoder : 출력을 내는 신호를 선택해줌. Code를 통해 구체적인 신호로 변경해준다 (입력<출력, 적은 수의 입력단자로 많은 표현이 가능함)

6. Mux : 몇 번째 입력으로 출력을 낼 것인지 결정함. 구체적인 신호가 코드로 정보화된다 (입력>출력)