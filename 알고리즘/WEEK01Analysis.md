# Week 01

## Sort

|7|1|5|6|2|8|4|3|Input|
|-|-|-|-|-|-|-|-|-|
|1|2|3|4|5|6|7|8|Output|

 * Corettness를 확인
```
    - 귀납적증명 i=0,P(0) 그리고 i=k, P(k)가 성립함을 증명
    - A[i] -> A[:i+1] 루프불변성 확인

        1. Induction Hypothesis : 루프불변성이 모든 i번째 이터레이션에서 성립
        2. Base Case : 첫번째 이터레이션에서 성립하는지(초기화 과정)
        3. Induction Step : i번째 이터레이션에서 존재하면 i+1에서도 존재함
        4. Conclution : 가장 마지막 이터레이션에서도 성립함
```
* 시간복잡도를 확인

## Insertion Sort (삽입정렬)

```C++
    void sort(int I[], int N)
    {
        for(int i=1 ; i < N ; i++)
        {
            int key = I[i];
            int j = i - 1;
            while(j >= 0 && I[i] > key)
            {
                I[j+1] = I[j];
                j--;
            }
            I[j+1] = key;
        }
    }
    // 앞에서부터 한칸씩 Growing Sort를 키워가며 정렬함.
    // 시간복잡도는 O(n^2)
```

# Week 02

* Runtime Analysis
```
    - Worst-Case : Upper Bound 개념이기 때문에 가장 중요함.
    - Best-Case
    - Average-Case
```
* Asymtotic Analysis(점근적 분석법)
```
    Real World Time 을 직접 측정함
    하드웨어나 개발 환경에 큰 영향을 받음
    Time Complexity 를 측정하기 위한 방법

    // 증가 추세에 초점을 맞춘 분석. input size : N에 무관하게 알고리즘이 빠르게 작동하는지가 중요하다(N의 증가에 비해 런타임증가가 덜할 경우 빠른 알고리즘임
    )
    장점 : 증가추세에 따라 추상화가 가능하고 다루기 쉽다
    단점 : N이 충분히 큰 수일 경우에만 성립할 경우가 있다
```
* Big-O notation
```
    함수의 증가율을 상한하는 표기법

    - T(n)과 g(n)은 Increase
    - T(n)이 O(g(n))이라고 하려면, g(n)이 최소한 T(n)보다 빠르게 증가 할 경우 곧 T(n)이 g(n)보다는 느리게 증가한다.
```
* Big Omega notation
```
     lower bound(하한값)을 정의하는 표기법
    - T(n)과 g(n)은 Increase
    - n이 증가 할 때 g(n)이 아무리 많이 증가해도 T(n)보다는 빠르게 증가하지 않는 경우, 곧 T(n)이 g(n)보다는 빠르게 증가한다.
```
* Big Theta notation
```
    Lower and Upper Bound
    T(n)=O(n) And, T(n) is Ohm(g(n))
```