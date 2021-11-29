# 1 algorithm
```
    void Solution::build_array(vector<int> v, int len)
    
    : 각 stones사이의 모든 거리값을 저장하는 function이다. 각 input 값들간의 차이를 모두
    확인해야 하므로 최대 input array ^ 2 만큼 순회하게 된다.

    bool Solution::check_possible(int data, int k, int len, bool flag)

    : 재귀하여 모든 경로를 탐색하도록 했다. Difference에 저장된 부분 경로는
    한 번씩만 참조하기 때문에 최대 input array ^ 2 만큼 순회한다.

    bool Solution::IsPossible(vector<int> &stones)

    : 2 <= len (input array) <= 2000의 input array check 후에 위 함수를 실행한다.
    처음 위치는 배열의 첫 값, 이동위치는 0으로 가정한다.

```
# 2-1 correctness
```
    1. Inductive Hypothesis
        : 이전 이동거리를 k라 할 때, 다음 이동거리는 {k-2, k-1, k, k+1, k+2}를 만족하여
        목적지까지 도착하는 경로가 존재하면 true를 반환해야 한다.

    2. Base Case
        : input array={0,1,2}일 때, (0,1,2), (0,2)의 두 가지 경로가 True로 반환된다.

    3. Inductive Step
        : 모든 stones 사이의 거리를 저장하는 배열과 ,그 거리를 점프했는지 확인하는 배열을
        전역으로 생성하여 참조한다. check_possible에서 모든 경로를 탐색하게 되는데
        {k-2, k-1, k, k+1, k+2}의 조건에 맞다면 재귀, 방문한 부분경로거나 조건에 맞지
        않다면 false를 반환한다.

        따라서 input array가 n일 때, Arr[0]부터 Arr[n-1] 까지의 Subseqeunce들을
        참조하며 진행하고 Arr[i]가 Arr[n-1]에 도달하게 되면 True를 반환한다.

    4. Conclusion 
        : input array의 첫 번째 값부터 시작하여 마지막 값까지 도착하는 경로가 존재하면
        true, 존재하지 않으면 false를 반환한다.
```
# 2-2 efficiency
```
    input size = n이라 할 때,

    - Subseqeunce 생성 : 두 stones간의 차이를 모두 저장 O(n^2)
    - 경로 탐색 : Subseqeunce들을 한 번씩만 참조하여 경로 진행 O(n^2)

    진행 가능한 경로를 한 번에 찾을 경우 경로를 탐색하는 과정은 O(n)이 된다.
    그러나 Subseqeunce를 생성하는 과정에서 O(n^2)의 시간이 소요되기 때문에
    Average Case 일 때 O(n^2), Worst Case 일 때도 O(n^2)의 Runtime을 
    보장함을 예상 할 수 있다.
```