#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct number{
	int value;
};

struct smaller{
	bool operator()(const number& a, const number& b){
		return a.value > b.value;
	}
};

struct bigger{
	bool operator()(const number& a, const number& b){
		return a.value < b.value;
	}
};

int main(){


	int n;
	while(cin>>n){

		priority_queue<number, vector<number>, smaller> PQS;
		priority_queue<number, vector<number>, bigger> PQB;
		stack<number> S;
		queue<number> Q;

		vector<int> I(n);
		vector<number> V(n);
		for(int i = 0; i < n; i++){
			int a,b;
			cin>>a>>b;
			I[i] = a;
			V[i] = (number){b};
		}

		int isPriorityS = 1;
		int isPriorityB = 1;
		int isStack = 1;
		int isQueue = 1;

		for(int i = 0; i < n; i++){
			if(I[i] == 1) Q.push(V[i]);
			else{
				if(Q.empty() || Q.front().value != V[i].value){
					isQueue = 0;
					break;
				}
				Q.pop();
			} 
		}


		for(int i = 0; i < n; i++){
			if(I[i] == 1) S.push(V[i]);
			else{
				if(S.empty() || S.top().value != V[i].value){
					isStack = 0;
					break;
				}
				S.pop();
			} 
		}

		for(int i = 0; i < n; i++){
			if(I[i] == 1) PQS.push(V[i]);
			else{
				if(PQS.empty() || PQS.top().value != V[i].value){
					isPriorityS = 0;
					break;
				}
				PQS.pop();
			} 
		}

		for(int i = 0; i < n; i++){
			if(I[i] == 1) PQB.push(V[i]);
			else{
				if(PQB.empty() || PQB.top().value != V[i].value){
					isPriorityB = 0;
					break;
				}
				PQB.pop();
			} 
		}

		if(isPriorityB + isStack + isQueue == 0) cout<<"impossible"<<endl;
		else{
			if(isPriorityB + isStack + isQueue > 1) cout<<"not sure"<<endl;
			else{
				if(isPriorityB) cout<<"priority queue"<<endl;
				if(isQueue == 1) cout<<"queue"<<endl;
				if(isStack == 1) cout<<"stack"<<endl;
			}
		}
	}
	
	return 0;
}