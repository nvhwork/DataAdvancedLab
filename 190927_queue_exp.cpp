// Example of Queue

#include<list>
#include<iostream>
using namespace std;

int main(){
	list<int> Q;
	for (int i = 1; i <= 10; i++)
		Q.push_back(i);
	while (!Q.empty()){
		int i = Q.front();
		Q.pop_front();
		cout << i << endl;
	}
}
