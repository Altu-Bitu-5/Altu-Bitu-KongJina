#include <iostream>
#include <string>

using namespace std;

int getTitle(int N) {
    int i = 666;    //0�� �ƴ� 666���� ����
    int count = 0;  //���° �ø��� �������� ī��Ʈ


    while (true) {
        // ���������� �ٲٱ�
        string title = to_string(i);

        for (int j = 0; j < title.length() - 2; j++) {
            //�������� 6�� ���� ������
            if (title[j] == '6' && title[j + 1] == '6' && title[j + 2] == '6') {
                //count ������Ű�� i ����
                count++;
                if (count == N) {
                    return i;
                }
                // 6�� ���� ���� �ڿ��� �ٽ� ã�� �ʰ� break ('666'6�� �� �� 6'666'�� ���� �ʵ���)
                break;
            }
        }
        i++;
    }
}

int main() {
    //�Է�
    int N;
    cin >> N;

    //���� �� ���
    cout << getTitle(N);

    return 0;
}