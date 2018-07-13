#include<iostream>
#define N 8
using namespace std;

void printSolution(int board[N][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout<<board[i][j]<<"  ";
		}
		cout<<endl;
	}
}

bool isSafe(int board[N][N], int row, int col){
	for(int i = 0; i < col; i++){
		if(board[row][i]){
			return false;
		}
	}
	int i, j;
	
	for(i = row, j = col; i >= 0 && j >= 0; i--, j--){
		if(board[i][j]){
			return false;
		}
	}
	
	for(i = row, j = col; i < N && j >= 0; i++, j--){
		if(board[i][j]){
			return false;
		}
	}
	
	return true;
}

bool solveNQUtil(int board[N][N], int col){
	if(col >= N){
		return true;
	}
	for(int i = 0 ; i < N; i++){
		if(isSafe(board, i, col)){
			board[i][col] = 1;
			
			if(solveNQUtil(board, col + 1) == true){
				return true;
			}
			
			board[i][col] = 0;
		}
	}
	return false;
}

void solveNQ(){
	int board[N][N];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			board[i][j] = 0;
		}
	}
	
	if(solveNQUtil(board, 0) == false){
		cout<<"No Solution!"<<endl;
		return;
	}
	else{
		printSolution(board);
		return;
	}
}


int main(){
	solveNQ();
	return 0;
}
