#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, char> ic;	// int, char 담는 pair 선언
const int ALPHA = 26;		// 알파벳 개수


//바퀴의 알파벳 출력 (index부터 시계방향)
string printWheel(int n, int index, vector<char>& wheel) {
	string ans = "";	// 결과 문자열

	for (int i = index + n; i > index; i--) {	// 바퀴를 돌릴 때와 반대방향으로
		ans += wheel[i % n];	// 바퀴에 적은 알파벳을 결과 문자열에 넣기
	}
	return ans;	// 결과 문자열 반환
}

//행운의 바퀴 생성
string makeWheel(int n, int k, vector<ic>& record) {

	vector<char> wheel(n, '?');			// 모두 '?'로 초기화한 벡터
	vector<bool> is_used(ALPHA, false); // 사용된 알파벳을 체크

	int index = 0; //화살표가 가리키는 글자의 index

	for (int i = 0; i < k; i++) {	// k번 반복

		int s = record[i].first; //화살표가 가리키는 몇 번 바뀌었는지
		char letter = record[i].second; //회전을 멈추었을 때 가리키던 글자

		index = (index + s) % n; //회전한 후 화살표가 가리키는 인덱스

		//해당 칸이 이미 letter로 채워진 경우
		if (wheel[index] == letter) {
			continue;	//넘어감
		}

		//다른 글자로 채워져있거나 해당 글자가 이미 사용된 알파벳인 경우 
		if (wheel[index] != '?' || is_used[letter - 'A']) {
			return "!";	//'!' 반환
		}

		wheel[index] = letter; // letter 적기
		is_used[letter - 'A'] = true; // letter가 사용되었으므로 true로 변경
	}
	return printWheel(n, index, wheel);	//출력 함수 호출
}

int main() {

	//입력
	int n, k;	// n: 바퀴의 칸 수, k: 바퀴를 돌리는 횟수 
	cin >> n >> k;	// 저장

	vector<ic> record(k);	// 기록하는 벡터 (선언한 pair 사용)
	for (int i = 0; i < k; i++) {	//k번 반복
		cin >> record[i].first >> record[i].second;	// record 벡터에 저장
	}

	//연산 & 출력
	cout << makeWheel(n, k, record);

	return 0;
}