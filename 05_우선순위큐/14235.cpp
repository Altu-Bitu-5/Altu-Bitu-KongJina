#include <iostream>
#include <queue>    //큐

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;      //아이들, 거점지를 방문한 횟수
    int a;      // a개의 선물 충전 (0이면 아이들을 만난 것)
    int value;  // 각 선물의 가치

    priority_queue<int> pq; // 우선순위 큐 (최대 힙)

    //입력
    cin >> N;

    //연산 및 출력
    while (N--) {

        cin >> a;

        // a가 0이 아니면 a개의 선물 충전
        if (a != 0) {
            while (a--) {
                cin >> value;
                pq.push(value); // 최대 힙에 추가
            }
        }
        // a가 0이면 pq에서 가치가 가장 큰 선물 출력 및 제거 
        else {
            if (pq.empty()) { // pq가 비어있다면 -1 출력
                cout << "-1" << '\n';
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
    return 0;
}
