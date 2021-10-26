// Water Jug - BFS problem

// FIND A WAY TO PRINT OUT EACH STEP OF ACTION TO DO THE ACTIONS!!!

#include<stdio.h>
#include<list>
#define MAX 901
using namespace std;

int a, b;	// The maximum amount of the jugs
int c;		// The goal amount
int ans;

list<int> Qx; // Queue for 1st Jug
list<int> Qy; // Queue for 2nd Jug

int visited[MAX][MAX] = {0}; // visited[i][j] = 1 indicates that cell(i,j) has been visited
int level[MAX][MAX]; // level[i][j] is the shortest distance from state (0,0) to state (i,j)

int goal(int x, int y){
	return (x == c || y == c);
}

int fillJug1(int x, int y){
	if (goal(a, y)){
		ans = level[x][y] + 1;
		printf("(%d, %d)\n", a, y);
		return 1;
	}
	if (visited[a][y]) return 0;
	
	Qx.push_back(a);
	Qy.push_back(y);
	visited[a][y] = 1;
	level[a][y] = level[x][y] + 1;
	return 0;
}

int fillJug2(int x, int y){
	if (goal(x, b)){
		ans = level[x][y] + 1;
		printf("(%d, %d)\n", x, b);
		return 1;
	}
	if (visited[x][b]) return 0;
	
	Qx.push_back(x);
	Qy.push_back(b);
	visited[x][b] = 1;
	level[x][b] = level[x][y] + 1;
	return 0;
}

int emptyJug1(int x, int y){
	if (goal(0, y)){
		ans = level[x][y] + 1;
		printf("(%d, %d)\n", 0, y);
		return 1;
	}
	if (visited[0][y]) return 0;
	
	Qx.push_back(0);
	Qy.push_back(y);
	visited[0][y] = 1;
	level[0][y] = level[x][y] + 1;
	return 0;
}

int emptyJug2(int x, int y){
	if (goal(x, 0)){
		ans = level[x][0] + 1;
		printf("(%d, %d)\n", x, 0);
		return 1;
	}
	if (visited[x][0]) return 0;
	
	Qx.push_back(x);
	Qy.push_back(0);
	visited[x][0] = 1;
	level[x][0] = level[x][y] + 1;
	return 0;
}

int pourJug1toJug2(int x, int y){
	int Nx, Ny;
	if (x + y > b){
		Nx = x + y - b;
		Ny = b;
	} else {
		Nx = 0;
		Ny = x + y;
	}
	
	if (goal(Nx, Ny)){
		ans = level[x][y] + 1;
		printf("(%d, %d)\n", Nx, Ny);
		return 1;
	}
	if (visited[Nx][Ny]) return 0;
	
	Qx.push_back(Nx);
	Qy.push_back(Ny);
	visited[Nx][Ny] = 1;
	level[Nx][Ny] = level[x][y] + 1;
	return 0;
}

int pourJug2toJug1(int x, int y){
	int Nx, Ny;
	if (x + y > a){
		Nx = a;
		Ny = x + y - a;
	} else {
		Nx = x + y;
		Ny = 0;
	}
	
	if (goal(Nx, Ny)){
		ans = level[x][y] + 1;
		printf("(%d, %d)\n", Nx, Ny);
		return 1;
	}
	if (visited[Nx][Ny]) return 0;
	
	Qx.push_back(Nx);
	Qy.push_back(Ny);
	visited[Nx][Ny] = 1;
	level[Nx][Ny] = level[x][y] + 1;
	return 0;
}

int main(){
	scanf("%d %d %d", &a, &b, &c);
	
	Qx.push_back(0);
	Qy.push_back(0);
	level[0][0] = 0;
	visited[0][0] = 1;
	ans = -1;
	
	while (!Qx.empty()){
		int x = Qx.front(); Qx.pop_front();
		int y = Qy.front(); Qy.pop_front();
		printf("(%d, %d)\n", x, y);
		if (fillJug1(x, y)) break;
		if (fillJug2(x, y)) break;
		if (emptyJug1(x, y)) break;
		if (emptyJug2(x, y)) break;
		if (pourJug1toJug2(x, y)) break;
		if (pourJug2toJug1(x, y)) break;
	}
	
	printf("%d", ans);
	return 0;
}
