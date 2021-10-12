#include <iostream>
#include <vector>
#include <unordered_map>
//#include "p2_solution.h"
using namespace std;

int kMost(std::vector<int> &arr, int len, int k)
{
    unordered_map <int,int> unOrdMap; // <값, 갯수>형태로 저장 될 수 있도록 초기화
    for (int i = 0; i < len; i++) unOrdMap[arr[i]]++; 
    int maxNumber = 0; // 가장 많은 수의 갯수
    int countUpToK = 0; // k까지의 과정을 count 함
    int eachElement = unOrdMap.size(); // unique한 수의 갯수
    vector<vector<int>> frequent(eachElement); // 갯수를 우선으로 참조하기 위해 저장

    for (pair<int, int> x : unOrdMap){// 찾고자 하는 값이 갯수이므로 갯수를 first인자로 초기화
        frequent[x.second].push_back(x.first);
        if(maxNumber < x.second)
            maxNumber = x.second;
    }
    unOrdMap.clear();
    //cout << "Max : " << maxNumber << "\tMax K : " << newLen << endl;
    for(int i = maxNumber ; i >= 0; i--) // 갯수가 많은 인자를 선택해야 하므로 frequent.end()부터 탐색
        for(int ans : frequent[i]) // 몇 번째로 많은 값인지 확인
        {
            countUpToK++;
            //cout << countK << "\tNum : "<< ans << "\tVar : " << i << endl;
            if (countUpToK == k)
                return ans;
        }
    //cout << "Unipue Numbers : "; // k가 unique한 갯수를 초과했을 경우 unique한 갯수 출력
    return countUpToK;
}