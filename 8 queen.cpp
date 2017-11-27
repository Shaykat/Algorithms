#include<bits/stdc++.h>
using namespace std;
int board[10][10],row,col,N,cnt;


void printSolution(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool safe(int row, int col){
    int i, j;
    for (i = 0; i < col; i++){
        if (board[row][i])
        return false;
    }

    for (i=row, j=col; i>=0 && j>=0; i--, j--){
        if (board[i][j])
        return false;
    }
    for (i=row, j=col; j>=0 && i<N; i++, j--){
        if (board[i][j])
        return false;
    }
    return true;
}

bool N_Queen(int col){
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++){
        if ( safe(i, col) ){
            board[i][col] = 1;
            if ( N_Queen(col + 1)) // cnt++; //number of solution
                return true; // one solution
            board[i][col] = 0; // BACKTRACK
        }
    }
    return false;
}

int main(){
    cout << "Enter Number of Queen: ";
    cin >> N;
    /*for number of solution
    N_Queen(0);

    cout << cnt << endl;
    */

    if (N_Queen(0) == false ){ // this is for one solution
        printf("Solution does not exist");
        return 0;
    }
    printSolution();
    return 0;
}
