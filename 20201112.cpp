#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int puzzle[9][9];
int zero[81][2];
int cnt = 0;

void printSudoku() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
}

int promissing(pair<int, int> xy, int val) {
    for(int i = 0; i < 9; i++) {
        if(puzzle[xy.fi][i] == val && i != xy.se) return 0;
        if(puzzle[i][xy.se] == val && i != xy.fi) return 0;
    }
    for(int i = xy.fi / 3 * 3; i < xy.fi / 3 * 3 + 3; i++) {
        for(int j = xy.se / 3 * 3; j < xy.se / 3 * 3 + 3; j++) {
            if(puzzle[i][j] == puzzle[xy.fi][xy.se] && (i != xy.fi || j != xy.se)) return 0;
        }
    }
    return 1;
}

void SolveSudoku(pair<int, int> curr) {
    if(curr.fi == 10 && curr.se == 10) {
        printSudoku();
        return;
    }
    for(int i = 1; i <= 9; i++) {
        if(promissing(curr, i)) {
            puzzle[curr.fi][curr.se] = i;
            SolveSudoku({zero[cnt][0], zero[cnt][1]});
            puzzle[curr.fi][curr.se] = 0;
        }
    }
    cnt++;
}

int main(void)
{
    int cnt=0;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            scanf("%d", &puzzle[i][j]);
            if(puzzle[i][j]==0)
            {
                zero[cnt][0]=i;
                zero[cnt][1]=j;
                cnt++;
            }
        }
    }
    cnt = 0;
    SolveSudoku({zero[0][0], zero[0][1]});
}
