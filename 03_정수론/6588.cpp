#include <iostream>
#include <vector>

using namespace std;

vector<bool> getPrimes(int size) {

    vector<bool> is_prime(size + 1, true); //소수인지 판단한 여부를 배열에 저장
    int count = 0; //지운 개수

    for (int i = 2; i * i <= size; i++) {  // i*i <= n 일때까지 반복
        if (!is_prime[i]) { //이미 지운 수인지 확인 
            continue;
        }
        for (int j = i * i; j <= size; j += i) { // i*i부터 n까지 반복
            if (!is_prime[j]) { // 이미 지운 수인지 확인
                continue;
            }
            is_prime[j] = false; //현재 수 지우기
        }
    }
    return is_prime;
}


int main() {

    //입력
    int N = 0;
    vector<int> numbers;

    while (true) {
        cin >> N;

        if (N == 0) {
            break;
        }
        numbers.push_back(N);
    }

    //연산 및 출력
    vector<bool> is_primes = getPrimes(1000000);    // 소수 여부를 저장한 배열

    for (int i = 0; i < numbers.size(); i++) {
        int N = numbers[i];
        bool is_found = false;

        for (int j = 3; j < N; j += 2) {   // 홀수를 구하기 위해 +2
            if (is_primes[j] && is_primes[N - j]) {   // 두 홀수 소수의 합으로 나타낼 수 있는 경우
                cout << N << " = " << j << " + " << N - j << '\n';  // 출력

                is_found = true;
                break;
            }
        }

        if (!is_found) {    // 두 홀수 소수의 합으로 나타낼 수 없는 경우
            cout << "Goldbach's conjecture is wrong.";
        }
    }

    return 0;
}