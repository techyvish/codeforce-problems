//
// Created by Vishal Patel on 4/20/16.
//

#include <iostream>

using namespace std;
namespace FF {

    int dr[] = {1,1,0,-1,-1,-1, 0, 1};
    int dc[] = {0,1,1, 1, 0,-1,-1,-1};

    int R,C ;
    int grid[51][51] = {};

    int floodFill(int r, int c , char c1, char c2){

        if ( r < 0 || r >= R || c < 0 || c >= C )
            return 0;

        if (grid[r][c] != c1)
            return  0;

        int ans = 1;
        grid[r][c] = c2;

        for ( int d = 0 ; d < 8 ; d++ ){
            ans += floodFill(r + dr[d], c+ dc[d], c1 ,c2);
        }

        return  ans;
    }

    void scanInput() {

        R = 50;
        C = 50;

        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                grid[i][j] = '.';
            }
        }
    }

    void run(){
        scanInput();
        for ( int i = 0 ; i < 50 ; i++) {
            for (int j = 0; j < 50; j++) {
                cout << (char)grid[i][j];
            }
            cout << endl;
        }

        int ans = floodFill(0,0,'.','W');

        cout << "Area is : " << ans/50 << endl;
        for ( int i = 0 ; i < 50 ; i++) {
            for (int j = 0; j < 50; j++) {
                cout << (char)grid[i][j];
            }
            cout << endl;
        }
    }
};

int main() {

    FF::run();

    return  0;
}
