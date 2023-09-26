#include <iostream>
#include <queue>    //큐

using namespace std;

//비교 구조체
struct cmp {
    bool operator()(const int& a, const int& b) {

        return a > b;
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int x;  // n*n번 주어지는 숫자

    // 우선순위 큐 (최소 힙)
    priority_queue<int, vector<int>, cmp> pq;

    //입력
    cin >> N;

    //연산
    for (int i = 0; i < N; i++) {

        // 입력받아 pq에 넣기
        for (int j = 0; j < N; j++) {
            cin >> x;
            pq.push(x);
        }
        // pq에 N개만 남기고 작은 수들 삭제 (메모리 제한 때문)
        while (pq.size() > N) {
            pq.pop();
        }
    }

    //츌력
    cout << pq.top(); // N번째로 큰 수


    return 0;
}
