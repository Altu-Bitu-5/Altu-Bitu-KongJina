#include <iostream>
#include <string>

using namespace std;

// king과 stone을 이동시키는 메소드
void move(string cmd, int& kingX, int& kingY, int& stoneX, int& stoneY) {

    // cmd에 따라 이동할 위치 설정
    int dx = 0; 
    int dy = 0; 

    if (cmd == "R") {
        dx = 0;
        dy = 1;
    }
    else if (cmd == "L") {
        dx = 0;
        dy = -1;
    }
    else if (cmd == "B") {
        dx = 1;
        dy = 0;
    }
    else if (cmd == "T") {
        dx = -1;
        dy = 0;
    }
    else if (cmd == "RT") {
        dx = -1;
        dy = 1;
    }
    else if (cmd == "LT") {
        dx = -1;
        dy = -1;
    }
    else if (cmd == "RB") {
        dx = 1;
        dy = 1;
    }
    else {
        dx = 1;
        dy = -1;
    }

    // 일단 명령에 따라 king temp를 이동시키기
    int kingTempX = kingX + dx;
    int kingTempY = kingY + dy;


    // 단, king이 체스판을 넘어가면 종료
    if (!(kingTempX >= 0 && kingTempX < 8 && kingTempY >= 0 && kingTempY < 8)) {
        return;
    }

    // king이 stone이 있는 곳으로 이동한 경우
    if (kingTempX == stoneX && kingTempY == stoneY) {
        int stoneTempX = stoneX + dx;
        int stoneTempY = stoneY + dy;
        
        // 단, stone이 체스판을 넘어가면 종료
        if (!(stoneTempX >= 0 && stoneTempX < 8 && stoneTempY >= 0 && stoneTempY < 8)) {
            return;
        }
        // 체스판을 넘어가지 않으면 stone 옮기기
        else {
            stoneX = stoneTempX;
            stoneY = stoneTempY;
        }
    }

    // 마지막으로 king 옮기기
    kingX = kingTempX;
    kingY = kingTempY;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    char ky, sy;    // 알파벳 A~H
    int kx, sx;     // 숫자 1~8
    int n;  // 명령 수
    
    cin >> ky >> kx >> sy >> sx >> n;

    int kingX = 8 - kx;
    int kingY = ky - 'A';
    int stoneX = 8 - sx;
    int stoneY = sy - 'A';


    string cmd; // 각 이동 명령
    for (int i = 0; i < n; i++) {
        // 명령 입력
        cin >> cmd;

        // 이동시키기
        move(cmd, kingX, kingY, stoneX, stoneY);
    }

    // 출력
    cout << char('A' + kingY) << 8 - kingX << '\n';
    cout << char('A' + stoneY) << 8 - stoneX;

    return 0;
}
