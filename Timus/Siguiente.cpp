#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<map>
using namespace std;
vector< pair<char,string> > C;
vector<char> A;
vector<char> L;
stack<char> P;

bool IsTerminal(char c){
	if(c >= 'A' && c <= 'Z') return 0;
	else true;
}

void ReadRules(){
	string s;
	int reglas;
	cin>>reglas;
	while(reglas--){
		cin>>s;
		int i = s.find("->");
		char D = s[0];
		string I = s.substr(i + 2);
		int a = I.find('|');
		if(a != -1){
			C.push_back(make_pair(D,I.substr(0,a)));
			C.push_back(make_pair(D,I.substr(a + 1)));
		}
		else{
			C.push_back(make_pair(D,I));
		}
		A.push_back(D);
	}

	for(int i = 0; i < C.size(); i++){
		cout<<C[i].first<<" -> "<<C[i].second<<endl;
	}
}

int Buscar(vector< pair<char,string> > V, char e){
	int in = -1;
	for(int i = 0; i < V.size(); i++){
		if(V[i].first == e){
			in = i;
			break;
		}	
	}
	return in;
}

void FindNext(char c){
	vector< pair<char,string> > Aux;
	int i;
	Aux = C;
	P.push(c);
	L.push_back('#');
	while(!P.empty()){
		i = Buscar(Aux,P.top());
		while(i != -1){
			if(Aux[i].second.size() >= 2){
				P.push(Aux[i].second[1]);
			}
			if(Aux[i].second.size() > 2 && !IsTerminal(Aux[i].second[2])){
				L.push_back(Aux[i].second[2]);
			}
			if(Aux[i].second.size())
			Aux.erase(Aux.begin() + i);
			i = Buscar(Aux,P.top());
		}
		
		if(IsTerminal(P.top())){
			L.push_back(P.top());
			P.pop();
		}
		else P.pop();
	}
}

int main(){
	char c;
	ReadRules();
	while(cin>>c){
		L.clear();
		FindNext(c);
		cout<<"Siguiente("<<c<<") = { ";
		for(int i = 0; i < L.size(); i++){
			if(i + 1 == L.size())cout<<L[i];
			else cout<<L[i]<<",";
		}
		cout<<" }"<<endl;
	}
	return 0;
}
/*
5
E->aZn|gTmD
T->ZMa|mp
Z->&
D->d
M->m
E
T
Z
D
M
*/