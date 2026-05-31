# include <stdio.h>
# include <stdbool.h>

#define n 5
int board[n][n];

void board_print(){
    for(int i=0;i<n;i++){
        for( int j=0;j<n;j++){
            if(board[i][j]){
                  printf("Q ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
}

bool check(int row, int col){
    // column check
    for(int i=0;i<row;i++){
        if(board[i][col]){
            return false;
        }
    }

    //upper left diagnol

    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]){
            return false;
        }
    }

    // upper right diagnol

    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}

void solve_queen(int row){
    if(row==n){
        board_print();
    printf("\n");
    return;
    }

    for(int col=0;col<n;col++){
        if(check(row,col)){
            board[row][col]=1;

            solve_queen(row+1);

            board[row][col]=0;
        }
    }
}

int main(){
    solve_queen(0);

    return 0;
}