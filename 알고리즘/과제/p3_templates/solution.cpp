#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include "solution.h"

using namespace std;

unsigned long long int getPathSum_memories(struct TreeNode *root, unsigned long long int route_Sum){
    if (root == NULL)   
        return 0;   // Tree가 비어있을 때 0을 반환
    else    
        route_Sum = route_Sum * 10 + root -> val;   // 각 노드의 값을 10^i 자리에 배치하여 경로를 더해줌
    if (root -> left == NULL && root -> right == NULL)  // 양쪽 자식 node가 모두 NULL일 떄(더이상 경로가 없을 때) 합을 반환
        return route_Sum;
    else
        return getPathSum_memories(root -> left, route_Sum) + getPathSum_memories(root -> right, route_Sum);
        // 양쪽 방향으로 재귀호출함. 경로 끝에서 모두 더해줌
}

unsigned long long int Solution::getPathSum (struct TreeNode* root){    // 매개변수로 합을 저장 할 수 있는 getPathSum_memories()로 반환
    return getPathSum_memories(root, 0);
}

struct TreeNode *newNode(int data){     // node의 값과 자식노드를 정의
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node -> val = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

struct TreeNode* Solution::buildTree (string filename){
    int nodeSize, nodeVal; // 노드의 갯수와 노드 값을 저장
    vector<int> file;      // 노드를 받아 벡터에 저장
    ifstream tree (filename); // sample().txt
    if (tree.is_open()) {     // 파일을 읽어와 노드의 갯수를 저장하고 값을 벡터에 푸쉬
        tree >> nodeSize;
        for (int i = 0; i < nodeSize; i++){
            tree >> nodeVal;
            file.push_back(nodeVal);
        }
    }
    struct TreeNode *node = newNode(file[0]);   // root를 저장함
    for (int i = 1; i < nodeSize; i++) {        // node를 insert
        queue<TreeNode*> visited;
        visited.push(node);                     // 방문한 node를 queue에 저장
        while (!visited.empty()) {
            TreeNode *temp = visited.front();   // 방문한 node를 temp에 저장하고 queue에서 pop해줌
            visited.pop();
            if (temp -> left == NULL) {
                if (file[i] != '\0')
                    temp -> left = newNode(file[i]);    // left가 비었을 때 node를 삽입
                else
                    temp -> left = newNode('\0');
            break;
            }
            else
                visited.push(temp -> left);             //  방문한 node에 값이 존재 할 때 push해줌
            if (temp -> right == NULL) {
                if (file[i] != '\0')
                    temp -> right = newNode(file[i]);   // right가 비었을 때 node를 삽입
                else
                    temp -> right = newNode('\0');
            break;
            }
            else 
                visited.push(temp -> right);            // 방문한 node에 값이 존재 할 때 push해줌
        }
    }
    return node;            // 완성된 tree를 반환
}