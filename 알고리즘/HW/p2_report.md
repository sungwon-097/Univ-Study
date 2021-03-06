# 1 algorithm
```
    : linear-time-algorithm을 구현하기 위해 counting-sort(계수정렬)의 구현을 떠올림.
    하지만 계수정렬은 항상 max_element만큼의 메모리를 할당해야 하고 이에 따른 메모리
    낭비가 심하다는 단점을 보완하기 위해 key:value의 형태로 값을 저장하는 map 자료구조를
    사용하기로 함.(원소는 key, 원소의 갯수는 value라 칭함)

     map보다 빠른 탐색이 가능한 unordered_map 에 arr의 원소를 <원소, 갯수>의 pair 로
     저장. 하지만 unordered_map은 index로 접근이 불가하고 우선으로 참조해야 하는 값이
     원소의 갯수이기 때문에 반대인 <갯수, 원소>의 pair로 이차원 vector에 다시 저장함.

     이차원 vector에 값을 저장하는 과정에서 가장 많은 수의 갯수(maxNumber)를 찾고 
     이 수가 k=1일 때의 value가 됨. 
     
     따라서 maxNumber를 첫번째 인자로 갖는 이차원 배열부터 maxNumber를 감소시키며
     k번째까지 모두 검색한 후에 나오는 key가 이 문제에서 요구하는' K번째로 많은 원소'가 된다.
```
# 2-1 correctness
```
    1. Inductive Hypothesis
        : kMost는 길이가 len인 vector에서 k번째로 많은 원소를 찾아야 한다.

    2. Base Case
        : vector의 SIZE가 1일 경우, k = 1 만 가능하다.

    3. Inductive Step
        : kMost는 arr의 원소들을 차례로 unordered_map에 <원소, 갯수> 형태로 저장한다.
        갯수를 우선으로 참조하기 위해 <갯수, 원소> 의 형태로 다시 이차원 vector에 저장하면서
        arr 원소중 중복이 가장 많이 되는 횟수를 찾아 maxNumber에 저장한다. MaxNumber부터
        인덱스를 참조하며 가장 많은 원소들, 두번쨰로 많은 원소들, ˑˑˑˑˑˑ 차례대로 변수
        ans 에 저장을 하고 최총적으로 k번째로 많은 수를 반환하게 된다. 

    4. Conclusion 
        : kMost는 길이가 len인 vector내의 k번쨰로 많은 원소를 반환한다.
```
# 2-2 efficiency
```
    L10의 unordered_map 초기화 구문에서 O(n)의 시간 소요
    L16의 vector<vector> 초기화 구문에서 O(n)의 시간 소요
    L22의 루프는 이중으로 선언되어 있지만 바깥의 루프에서 인덱스를 정해주고, (O(1))
    안쪽의 루프에서 순차적으로 count를 실행, 총 (O(1) * O(n))의 Time Complexty이므로
    O(n)의 시간 소요

    따라서 Average Case 일 때 O(n), Worst Case 일 때도 O(n)의 Runtime을 보장함을
    예상 할 수 있다.
```