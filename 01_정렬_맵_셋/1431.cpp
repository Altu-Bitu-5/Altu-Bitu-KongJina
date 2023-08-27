#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 시리얼번호 중 숫자만 더한 sum을 리턴
int getSum(string s) {

	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9')	// 각 자리가 숫자일 때 sum에 더한다
			sum += (int)(s[i] - '0');
	}

	return sum;
}

// 비교함수 cmp
bool cmp(string s1, string s2) {
	int sum1 = 0;
	int sum2 = 0;

	// [조건1] A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
	if (s1.length() != s2.length())			
		return s1.length() < s2.length();

	// [조건2] (길이가 같다면) A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
	sum1 = getSum(s1);		
	sum2 = getSum(s2);

	if (sum1 != sum2)				
		return sum1 < sum2;

	// [조건3] (조건 1,2가 같다면) 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
	else									
		return s1 < s2;
}



int main() {
	int N;					// 기타 수
	vector<string> input;	// 기타 시리얼번호


	//입력
	cin >> N;

	input.assign(N, {});
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	// 정렬
	sort(input.begin(), input.end(), cmp);	// 비교함수 cmp 사용

	// 출력
	for (int i = 0; i < N; i++) {
		cout << input[i] << '\n';
	}
}