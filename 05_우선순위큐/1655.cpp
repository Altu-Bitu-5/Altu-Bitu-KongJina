#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;


//비교 구조체
struct cmp {
    bool operator()(const int& a, const int& b) {

        return a > b;
    }
};

// max_heap의 값들을 min_heap의 값들보다 작게 만드는 메소드
void balanceHeaps(priority_queue<int>& max_heap, priority_queue<int, vector<int>, cmp>& min_heap) {

    //'작은값들 중 최댓값'이 '큰값들 중 최솟값'보다 크면 swap 
    if (max_heap.top() > min_heap.top()) {
        int big = min_heap.top();
        int small = max_heap.top();

        max_heap.pop();
        min_heap.pop();

        max_heap.push(big);
        min_heap.push(small);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;      // 외치는 정수의 개수
    int x;      // 외치는 정수
    priority_queue<int> max_heap;   // 최대 힙
    priority_queue<int, vector<int>, cmp> min_heap;   // 최소 힙


    //입력
    cin >> N;
    while (N--) {
        cin >> x;

        // max_heap의 크기가 더 작으면 max_heap에 추가
        if (max_heap.size() <= min_heap.size()) {
            max_heap.push(x);
        }
        // 그렇지 않으면 min_heap에 추가
        else {
            min_heap.push(x);
        }

        // 연산
        // max_heap의 값들이 min_heap의 값들보다 작게 하기
        if (!max_heap.empty() && !min_heap.empty()) {
            balanceHeaps(max_heap, min_heap);
        }

        //출력
        cout << max_heap.top() << '\n'; //작은값들 중 최댓값 출력 -> 중간값
    }

    return 0;
}