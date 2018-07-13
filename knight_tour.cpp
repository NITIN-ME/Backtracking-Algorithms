#include<iostream>
using namespace std;

bool isSafe(int x, int y, int arr[8][8]){
	return (x >= 0 && x < 8 && y >= 0 && y < 8 && arr[x][y] == -1);
}

void showSolution(int arr[8][8]){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cout<<arr[i][j]<<"  ";
		}
		cout<<endl;
	}
}

bool solveKTUtil(int x, int y, int movei, int arr[8][8], int xMove[8], int yMove[8]){
	int next_x, next_y;
	if(movei == 64){
		return true;
	}
	for(int k = 0; k < 8; k++){
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if(isSafe(next_x, next_y, arr)){
			arr[next_x][next_y] = movei;
			if(solveKTUtil(next_x, next_y, movei + 1, arr, xMove, yMove) == true){
				return true;
			}
			else{
				// backtracking step
				arr[next_x][next_y] = -1;
			}
		}
	}
	return false;
}

void solveKT(){
	int arr[8][8];
	
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			arr[i][j] = -1;
		}
	}
	
	int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    arr[0][0] = 0;
    
    if(solveKTUtil(0, 0, 1, arr, xMove, yMove) == false){
    	cout<<"Solution doesn't exists"<<endl;
	}
	else{
		showSolution(arr);
	}
	
}


int main(){
	solveKT();
	return 0;
}
