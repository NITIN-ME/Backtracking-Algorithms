#include<iostream>
using namespace std;

bool isSafe(int x, int y, int maze[4][4]){
	return (x >= 0 && x < 4 && y >= 0 && y < 4 && maze[x][y] == 1);
}

bool printSolution(int sol[4][4]){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout<<sol[i][j]<<"  ";
		}
		cout<<endl;
	}
}

bool solveMazeUtil(int maze[4][4], int x, int y, int sol[4][4]){
	if(x == 3 && y == 3){
		sol[3][3] = 1;
		return true;
	}
	
	if(isSafe(x, y, maze) == true){
		sol[x][y] = 1;
		
		if(solveMazeUtil(maze, x+1, y, sol) == true){
			return true;
		}
		
		if(solveMazeUtil(maze, x, y + 1, sol) == true){
			return true;
		}
		
		sol[x][y] = 0;
		return false;
	}
	return false;
}

void solveMaze(int maze[4][4]){
	int sol[4][4];
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			sol[i][j] = 0;
		}
	}
	
	if(solveMazeUtil(maze, 0, 0, sol) == false){
		cout<<"No solution!"<<endl;
		return;
	}
	else{
		printSolution(sol);
		return;
	}
}

int main(){
	int maze[4][4] = {{1,0,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,1}};
	solveMaze(maze);
	return 0;
}
