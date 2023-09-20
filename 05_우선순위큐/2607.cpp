#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 문자열의 알파벳 빈도수를 계산하여 반환하는 함수
vector<int> getFrequency(const string& str) {
    vector<int> frequency(26, 0);   // 각 알파벳의 빈도수 저장하는 벡터

    for (char c : str) {
        frequency[c - 'A']++;
    }
    return frequency;
}

// 두 문자열이 비슷한지 여부 반환하는 함수
bool areStringsSimilar(const string& base, const string& s) {
    // 두 문자열의 길이
    int baseLength = base.size();
    int sLength = s.size();

    // 두 문자열의 알파벳 빈도수 계산
    vector<int> baseFrequency = getFrequency(base);
    vector<int> sFrequency = getFrequency(s);

    // 두 문자열의 공통 알파벳 빈도수 계산
    int commonFrequency = 0;
    for (int j = 0; j < 26; j++) {
        commonFrequency += min(baseFrequency[j], sFrequency[j]);
    }

    // 비슷한지 여부 반환
    // 두 문자열의 길이가 같으면, 공통 빈도수가 첫번째 문자열 길이와 같거나 1 작아야 한다
    if (baseLength == sLength) {
        return (commonFrequency == baseLength || commonFrequency == baseLength - 1);
        // 입력받은 문자열이 1 길면, 공통 빈도수가 첫번째 문자열 길이보다 1 작아야 한다
    }
    else if (baseLength == sLength + 1) {
        return (commonFrequency == baseLength - 1);
        // 입력받은 문자열이 1 짧으면, 공통 빈도수가 첫번째 문자열 길이와 같아야 한다
    }
    else if (baseLength == sLength - 1) {
        return (commonFrequency == baseLength);
    }
    // 모두 해당하지 않으면 false 반환
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    string base;    // 첫번째 단어
    string s;       // 주어지는 단어들
    int result = 0;  // 비슷한 단어 수

    // 입력
    cin >> N;
    cin >> base;

    // 연산
    for (int i = 0; i < N - 1; i++) {
        cin >> s;
        // 두 단어가 비슷하다면, result ++ 
        if (areStringsSimilar(base, s)) {
            result++;
        }
    }

    // 출력
    cout << result << '\n';

    return 0;
}