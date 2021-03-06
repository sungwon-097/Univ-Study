# 1 algorithm
```
    struct TreeNode* Solution::buildTree (string filename)
    
    : 트리에 BFS로 탐색하였을 때와 동일한 순서로 노드값이 입력되므로 queue 자료구조를 사용해
    방문 확인을 해줌. left부터 체크하며 root로부터 같은 거리에 있는 node에 값을 차례로 할당
    해주고 탐색하고 있는 level의 node가 포화돼있을 경우 다음 level의 좌측값을 체크하게 된다.

    unsigned long long int Solution::getPathSum (struct TreeNode* root)

    : 재귀하여 각 경로의 값을 더해나가야 한다. 위의 함수는 매개변수가 하나이기 때문에 경로의 
    합을 매개변수를 갖는 함수를 추가로 생성해 반환만 해주도록 했다. 

    unsigned long long int getPathSum_memories(struct TreeNode *root, unsigned long long int route_Sum)

    : 이전 경로의 합에 10을 곱한 다음 현재의 경로를 더해준다(각 노드의 값을 10^i 자리에 배치).
    자식노드가 모두 비어있을 경우에는 경로 탐색이 끝났다는 뜻 이므로 현재 경로의 합을 반환하고
    그렇지 않다면 양쪽으로 재귀해 경로의 합을 계속 더해나가도록 한다.

    재귀가 끝나면 경로의 합을 반환하므로 각 경로의 끝 값을 모두 더하게 된다.
```
# 2-1 correctness
```
    1. Inductive Hypothesis
        : 루트에서 출발하여 리프에 도달하는 모든 경로의 값을 더한 값을 계산하여 출력해야한다.

    2. Base Case
        : .txt파일에 1,0이 저장되어 있을 경우 node가 1개인 트리가 생성된다. 경로합은 0

    3. Inductive Step
        : .txt.파일의 첫 줄엔 nodesize, 두 번째 줄부터 nodeSize만큼의 node가 저장 되어
        있을 때, 첫 번째 node를 꺼내 queue에 저장한다. queue의 front값을 pop한 후
        이 값의 child를 확인하여 빈 곳이 있다면 node를 생성하고 그렇지 않은 곳은 push
        한다. 이 과정을 nodeSize * log2(nodeSize)만큼 반복한다.

        .txt파일의 모든 값을 프로그램에 할당하였고 TreeNode *node 는 linked list를 
        이용한 완전이진트리로 생성되었다. 트리의 각 경로의 값을 산출하기 위해 child가
        존재하지 않을 때 까지 양 쪽으로 경로를 탐색하며 경로가 끝난시점에서 서로 
        더해주게 된다. 반환값은 모든 경로의 합으로 나온다

    4. Conclusion 
        : 루트에서 출발하여 리프에 도달하는 모든 경로의 값을 더한 값을 계산하여 출력
```
# 2-2 efficiency
```
    nodeSize = n이라 할 때,

    - 파일 입력 : 입력값을 모두 가져와서 저장 O(n)
    - 트리 생성 : n의 값을 logn 레벨만큼 할당 O(n * nlogn)
    - 경로 탐색 : logn 레벨 만큼 탐색한 2^lognO개의 값을 더해줌 (logn * 2^logn)

    완전이진트리이므로 어떠한 입력을 받더라도 유사한 Tree의 형태를 띈다. 따라서 
    Average Case 일 때 O(n * logn), Worst Case 일 때도 O(n * logn)의 Runtime을 
    보장함을 예상 할 수 있다.
```