#include <iostream>
#include <string>

using namespace std;

int getTitle(int N) {
    int i = 666;    //0이 아닌 666부터 시작
    int count = 0;  //몇번째 시리즈 제목인지 카운트


    while (true) {
        // 문자형으로 바꾸기
        string title = to_string(i);

        for (int j = 0; j < title.length() - 2; j++) {
            //연속으로 6이 세번 나오면
            if (title[j] == '6' && title[j + 1] == '6' && title[j + 2] == '6') {
                //count 증가시키고 i 리턴
                count++;
                if (count == N) {
                    return i;
                }
                // 6이 세번 나온 뒤에는 다시 찾지 않고 break ('666'6을 센 후 6'666'도 세지 않도록)
                break;
            }
        }
        i++;
    }
}

int main() {
    //입력
    int N;
    cin >> N;

    //연산 및 출력
    cout << getTitle(N);

    return 0;
}
