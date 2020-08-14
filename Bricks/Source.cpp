#include<iostream>
using namespace std;
const int N = 25;
int  n, m, num[N];
char map[N][N];

void fall(int a, int b, int i) {
    //base case.
    if (map[1][i] != '.' || b == 0) return;
    //recurrence case.
    if (map[a + 1][i] != '.' || a == n) {
        map[a][i] = '#';
        fall(a - 1, b - 1, i);
    }
    else {
        fall(a + 1, b, i);
    }
    return;
}

int main() {
    scanf_s("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf_s("%d", &num[i]);
        fall(1, num[i], i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}