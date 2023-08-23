#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main() {
	int N;	// 집합 S에 포함된 문자열의 개수
	int M;	// 검사할 문자열의 개수
	string input;			// 검사할 문자열
	map<string, bool> set_list;	// 집합 S
	int count = 0;


	//입력
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> input;
		set_list[input] = true;		// 입력된 N개의 문자열을 집합 S에 삽입
	}


	// 연산
	for (int i = 0; i < M; i++) {	// M번 반복
		cin >> input;

		if (set_list[input] ) {		// 검사할 문자열이 집합 S의 원소와 같으면 count++
			count++;
		}
		
	}

	// 출력
	cout << count;
}