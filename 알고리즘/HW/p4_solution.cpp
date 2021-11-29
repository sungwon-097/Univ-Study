#include "p4Solution.hpp"
#define MAX_NUM 2000    // MAX Input
#define MIN_NUM 2

vector<vector<int>> Difference(MAX_NUM, vector<int>(MAX_NUM, 0));  // 각 stones 사이의 모든 거리 저장
vector<vector<int>> Jumped(MAX_NUM, vector<int>(MAX_NUM, false));  // 점프한 stones 확인

void Solution::build_array(vector<int> v, int len){ // 각 stones 사이의 모든 거리를 계산하여 vector에 저장

    for(int i = 0 ; i < len - 1 ; i++){
        for(int j = i + 1 ; j < len ; j++)
            if(i!=j) Difference[i][j] = v[j] - v[i];
    }
}
bool Solution::check_possible(int data, int k, int len, bool flag){  // 재귀하여 수행, 마지막까지 도달한 case가 한 가지라도 존재하면 true 반환

    if (data < len - 1 ){
        if (Jumped[data][k] == true)   return false;   // 방문 체크
        else
            Jumped[data][k] = true;
        for(int i = data + 1 ; i < len ; i++){
            if ( abs(Difference[data][i]) <= k+2 )
                flag = max(flag, check_possible(i, Difference[data][i], len, flag));
        }
    }
    else
        return true;
    return flag;
}
bool Solution::IsPossible(vector<int> &stones){   

    int len = stones.size();
    if(len < MIN_NUM || len > MAX_NUM)      // input size check
        std::cout << "input Size Error";
    else{
        int firstVal = stones[0], k = 0;    // 처음 위치와 이동 거리
        bool flag = false;
        build_array(stones, len);
        return check_possible(firstVal, k, len, false);
    }
    return false;
}

// bool check[2000][2000];
// int dp[2000][2000];

// bool func(int len, int i, int j) {

//     bool visited = check[i][j];
//     if (visited)
// 		return false;
//     else
//         check[i][j] = true;

//     for(int k = j + 1 ; k < len ; k++)
//         if( -2 <= dp[j][k] - dp[i][j] && dp[j][k] - dp[i][j] <= 2 )
//             if(k == len -1 || func(len, j, k) == true)
//                 return true;
// 	return false;
// }

// bool Solution::IsPossible(vector<int> &stones){

//     int M = stones.size();

// 	for (int i = 0; i < M-1; i++) {
//         for(int j = i + 1 ; j < M ; j++){
//             check[i][j] = false;
//             dp[i][j] = stones[j] - stones[i];
//         }
// 	}
// 	return func(M, 0, 1);
// }