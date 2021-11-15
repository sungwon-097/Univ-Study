#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include "solution.h"

using namespace std;

/* Fill free to implement any function on here */
struct TreeNode *newNode(int item)//노드 생성
{
    struct TreeNode *temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp -> val = item;
    temp -> left = temp -> right = NULL;
    return temp;
}

void insert(struct TreeNode **root, int nodeVal)//노드 삽입
{
    queue<TreeNode*> q;
    q.push(*root);
    while (q.size()) {
        TreeNode *temp = q.front();
        q.pop();
        if (temp -> left == NULL) {//왼쪽 자식 노드가 없다면 왼쪽 자식 노드에 값을 삽입한다.
            if (nodeVal != '\0')
                temp -> left = newNode(nodeVal);
            else
                temp -> left = newNode('\0');
            return;
        }
        else {
            q.push(temp -> left);
        }

        if (temp -> right == NULL) {//오른쪽 자식 노드가 없다면 오른쪽 자식 노드에 값을 삽입한다.
            if (nodeVal != '\0')
                temp -> right = newNode(nodeVal);
            else
                temp -> right = newNode('\0');
            return;
        }
        else {
            q.push(temp -> right);
        }
    }
}

unsigned long long int Root2LeafSum(struct TreeNode *root, unsigned long long int sum)
{
    if (root == NULL)//서브트리에서 루트의 값이 NULL이라면 0을 반환한다.
        return 0;

    sum = sum * 10 + root -> val;//이전의 sum에 10을 곱하고 현재 노드의 값을 더한다. 즉 부모 노드의 값에 10을 곱하는 것과 같다.

    if (root -> left == NULL && root -> right == NULL)//왼쪽 자식 노드 값과 오른쪽 자식 노드 값이 NULL이라면 sum을 반환한다.
        return sum;
    
    return Root2LeafSum(root -> left, sum) + Root2LeafSum(root -> right, sum);//현재 루트의 왼쪽/오른쪽 자식 노드를 서브트리의 루트로, 현재 sum값을 인자로 넘겨주어 재귀호출을 하여 루트에서 리프까지의 경로 합을 반환한다.
}

unsigned long long int Solution::getPathSum (struct TreeNode* root)
{
    /* Fill up with your own codes */
    return Root2LeafSum(root, 0);//초기의 경로 합은 0이기 때문에 인자로 0을 넘겨준다.
}

struct TreeNode* Solution::buildTree (string filename)
{
    /* Fill up with your own codes */
    int nodeNum;//파일에서 노드의 개수를 읽어오기 위한 변수
    int nodeVal;//파일에서 노드의 값을 읽어오기 위한 변수
    vector<int> v;//읽어온 노드의 값을 저장하기 위한 벡터 변수

    ifstream tree (filename);
    if (tree.is_open()) {
        tree >> nodeNum;
        if (nodeNum >= 1 && nodeNum <= 16000) {//노드의 개수 조건 검사
            for (int i = 0; i < nodeNum; i++) {
                tree >> nodeVal;
                v.push_back(nodeVal);
            }
        }
    }

    struct TreeNode *root = newNode(v[0]);//제일 처음 값을 루트로 지정
    for (int i = 1; i < nodeNum; i++) {
        if (v[i] >= 0 && v[i] <= 9)//노드의 값 조건 검사
            insert(&root, v[i]);
        else
            continue;
    }
    return root;
}