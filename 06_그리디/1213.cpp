#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// 팰린드롬으로 만들어 반환하는 메소드
string generatePalindrome(int alphabet_num[], int odd_index) {
    string str;
    string str_reverse;

    // 각 알파벳 개수로 팰린드롬의 앞쪽 문자열 str 만들기
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < alphabet_num[i] / 2; j++) {
            str.push_back(i + 'A'); //각 알파벳 개수의 절반만큼만 str 뒤에 붙임
        }
    }

    str_reverse = string(str.rbegin(), str.rend());  // str을 역순으로 한 str_reverse 만들기

    // str 뒤에 홀수 개수인 알파벳 추가
    if (odd_index <= 26) {
        str.push_back(odd_index + 'A');
    }

    // str 뒤에 str_reverse 붙이기
    str += str_reverse;

    // 반환
    return str;
}

// 팰린드롬이 가능한지 확인해서 string 반환하는 메소드
string makePalindrome(string name) {

    int alphabet_num[26] = { 0 }; // name에 포함된 각 알파벳 개수 저장
    int odd_cnt = 0;        // 알파벳 개수가 홀수이면 cnt
    int odd_index = 27;      // 알파벳 개수가 홀수인 알파벳의 index

    // name의 각 알파벳 개수를 alphabet_num 배열에 저장
    for (int i = 0; i < name.length(); i++) {
        int index = name[i] - 'A';
        alphabet_num[index]++;
    }

    // 팰린드롬인지 확인하기
    for (int i = 0; i < 26; i++) {

        // 알파벳 개수가 홀수이면
        if (alphabet_num[i] % 2 != 0) {
            odd_cnt++;      // odd_cnt +1
            odd_index = i;  // odd_index로 저장

            // 알파벳 개수가 홀수인 알파벳이 2개 이상이면 팰린드롬이 될 수 없음
            if (odd_cnt >= 2) {
                return "I'm Sorry Hansoo\n";
            }
        }
    }

    // 팰린드롬이 될 수 있다면, 팰린드롬으로 만들기
    string result = generatePalindrome(alphabet_num, odd_index);

    return result;
}

int main() {
    string name;    // 입력받는 영어 이름 (알파벳 대문자)

    //입력
    cin >> name;

    // 연산 및 출력
    cout << makePalindrome(name);

    return 0;
}
