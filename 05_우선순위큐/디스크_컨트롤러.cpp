#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 비교 구조체
struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int current_time = 0;   // 현재시간
    int total_time = 0;     // 총 소요시간

    // 먼저 jobs를 들어온 시간이 빠른 순으로 정렬
    sort(jobs.begin(), jobs.end());

    // 최소 힙 선언 (이중 벡터)
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    int j = 0;  //jobs의 인덱스
    while (j < jobs.size() || !pq.empty()) {

        // 들어올 job이 남아있다면
        if (j < jobs.size()) {
            // 현재 시간보다 이른 시간에 들어왔는지 확인
            if (jobs[j][0] <= current_time) {
                pq.push(jobs[j++]); // 최소힙에 추가 & j 증가
                continue;           
            }
        }

        // 최소힙에 job이 있다면 해당 job 실행
        if (!pq.empty()) {
            vector<int> job = pq.top(); // 최소힙의 top의 job 가져오기
            pq.pop();

            current_time += job[1];    // 현재 시간에 job 수행시간 더하기
            total_time += current_time - job[0];   // total_time에 job이 지금까지 대기한 시간 더하기
        }
        // 최소힙이 비어있는 경우
        else
            current_time = jobs[j][0];  // 현재시간을 다음 job의 들어오는 시간으로 변경하기
    }


    // 평균 시간 계산
    answer = total_time / jobs.size();

    return answer;
}