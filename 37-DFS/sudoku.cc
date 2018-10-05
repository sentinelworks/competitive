#include <iostream>
using namespace std;
int a[9][9];

bool isvalid(int x, int y, int v)
{
    for (int i=0; i<9; ++i) {
        if(a[x][i] == v) return false;
        if(a[i][y] == v) return false;
    }

    x = x-x%3;
    y = y-y%3;
    for (int i=x; i<x+3; i++)
    for (int j=y; j<y+3; j++)
        if (a[i][j] == v) return false;


    return true;
}

bool solve(int x)
{
    for (; x<81; ++x) {
        int k, i = x/9, j = x%9;
        if(a[i][j] >0) continue;
        for (k=1; k<=9;++k) {
            if(isvalid(i, j, k)) {
                a[i][j] = k;
                if(solve(x+1)) return true;
                a[i][j] = 0;
            }
        }

        if(k>9) return false;
    }

    return true;
}


int main(){
    char ch;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> ch;
            a[i][j] = ch-'0';
        }
    }
    
    bool b = solve(0);
    cout << b << endl;
}
