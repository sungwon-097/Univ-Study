# Week 07

## Machine Advance

1. x86-64 Linux Memory Layout

    - Stack : 함수를 사용하기 위해서 저장하는 모든 value(local var)
    - Heap : Dyanamic Data(pointer)
    - Data : static하게 저장된 Data(global)
    - Text / Shared library : instructon / Read Only

2. Buffer Overflow
    - 할당된 버퍼의 크기 이상으로 값을 저장하는 경우 발생
    - Segmentation Falut : 할당되지 않은 메모리에 접근하는 경우
    - strcpy, strcat, scanf....

3. Avoid overflow vulnerabilities Code
    - fget, strncpy, %ns -> input값을 명시해줌
    - Randomize stack offset
        - 스택 주소를 random 하게 부여해 코드가 심어지는 부분을 예측 할 수 없도록 만든다
    - Non-Excutable Code
        - stack은 non-excute code로 mark함(Read-Only)
    - Stack Canaries
        - xor %fs: 로 canary와 값을 비교. je 로 점프 else일 때 Error를 표시함