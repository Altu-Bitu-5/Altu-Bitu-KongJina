#include <iostream>
#include <climits>

using namespace std;

// 최종 time과 height를 계산하는 메소드
void calculateOptimalTimeAndHeight(int b, int initial_height[257], long long answer[2]) {
    answer[0] = LLONG_MAX;  // time: 우선 최댓값으로 설정 (climits 헤더파일)
    answer[1] = 0;          // height

    // 목표 높이인 target_height를 0부터 256까지 증가시키며 최적 높이 찾기
    int target_height = 0;
    while (target_height <= 256) {

        int plus = 0; // 쌓을 블록 수 
        int minus = 0; // 제거할 블록 수

        // 1. 목표 높이보다 낮은 땅에서는 블록을 plus하기
        int h = 0;
        while (h < target_height) {
            plus += (target_height - h) * initial_height[h];
            h++;
        }

        // 2. 목표 높이보다 높은 땅에서는 블록을 minus하기
        h = target_height + 1;
        while (h < 257) {
            minus += (h - target_height) * initial_height[h];
            h++;
        }

        // 인벤토리에 있는 블록 수 b보다 더 쌓지 않는지 확인
        if (b >= plus - minus) {
            // 소요시간 계산
            long long time = plus + minus * 2;  // long long으로 설정

            // 소요시간이 더 적다면 answer 업데이트
            if (answer[0] >= time) {
                answer[0] = time;
                answer[1] = target_height;
            }
        }
        target_height++;
    }
}

int main() {
    // 입력
    int n, m;   // n개의 줄, 각 m개의 정수
    int b;      // 인벤토리에 가지고 있는 블록의 개수
    cin >> n >> m >> b;

    // 땅의 높이를 height 배열에 저장(위치가 상관 없으므로)
    int initial_height[257] = { 0 };
    int x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            initial_height[x]++;
        }
    }

    // 연산
    long long answer[2];
    calculateOptimalTimeAndHeight(b, initial_height, answer);

    // 출력
    cout << answer[0] << ' ' << answer[1] << '\n';

    return 0;
}
