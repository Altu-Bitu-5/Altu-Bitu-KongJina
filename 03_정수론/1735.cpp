#include <iostream>

using namespace std;

int main() {

	//입력
	int a1, a2;		//첫번째 분자와 분모
	int b1, b2;		//두번째 분자와 분모
	cin >> a1 >> a2;
	cin >> b1 >> b2;

	//연산
	int sum1 = a1 * b2 + b1 * a2;	// 두 분수 합의 분자
	int sum2 = a2 * b2;				// 두 분수 합의 분모

	int i = 2;
	while (i <= min(sum1, sum2)) {
		// 약분되는 경우 약분하기
		while (sum1 % i == 0 && sum2 % i == 0) {
			sum1 /= i;
			sum2 /= i;
		}
		i++;	// 더이상 i로 약분되지 않으면 1 증가
	}

	//출력
	cout << sum1 << " " << sum2 << "\n";
}