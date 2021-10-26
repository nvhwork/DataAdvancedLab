#include <iostream>
#include<list>
#define MAX 901
using namespace std;
int N, M;   // number of row and col
int i0, j0; // start position
int ans;
 
list<int> Qx; // Queue for x coor
list<int> Qy; // Queue for y coor
 
int matrix[MAX][MAX] = {0};
int level[MAX][MAX] = {0}; // level[i][j] is the shortest distance from state (i0,j0) to state (i,j)
 
int goal(int x, int y){
	return (matrix[x][y] == 0 && (x == 1 || y == 1 || x == N || y == M));
}
 
int mov(int x, int y, int addX, int addY){
	if (goal(x + addX, y + addY)){
		ans = level[x][y] + 1;
		return 1;
	}
	if (matrix[x + addX][y + addY]) return 0;
	Qx.push_back(x + addX);
	Qy.push_back(y + addY);
	matrix[x + addX][y + addY] = 1;
	level[x + addX][y + addY] = level[x][y] + 1;
	return 0;
}
 
 
int main(){
	cin >> N >> M >> i0 >> j0;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			cin >> matrix[i][j];
		}
	}
	
	ans = -1;
	Qx.push_back(i0);
	Qy.push_back(j0);
	level[i0][j0] = 1;
	matrix[i0][j0] = 1;
 
	while (!Qx.empty()){
		int x = Qx.front(); Qx.pop_front();
		int y = Qy.front(); Qy.pop_front();
	
		if (mov(x, y, -1, 0)) break;
		if (mov(x, y, 1, 0)) break;
		if (mov(x, y, 0, -1)) break;
		if (mov(x, y, 0, 1)) break;
	}
	cout << ans;
}
