#include "p4Solution.hpp"
#include <cmath>

bool Solution::IsPossible(vector<int>& stones) {
    int len = stones.size();
    int last_diff = 0, current_diff = 0;

    if ( stones[0] > 2 || stones[0] < 0) // 첫 점프는 0, 1, 2 가능.
        return false;

    for(int i=1; i < len; i++){
        current_diff = stones[i] - stones[i-1]; // 점프한 거리
        if( abs(current_diff-last_diff) > 2 | current_diff <= 0) // 현재 이동한 거리와 이전 이동했던 거리의 차이가 2가 넘거나 현재 이동한 거리가 0이하일 경우 false
            return false;
        // cout << i << ": "<<stones[i]<< "\t" << current_diff << " - " << last_diff << " = " << current_diff - last_diff << endl;
        last_diff=current_diff; // 현재 이동거리를 이전 이동거리에 저장
    }
    return true;
}