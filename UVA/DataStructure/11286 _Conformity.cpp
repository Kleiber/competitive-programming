#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int main(){
	int n;
	while(cin>>n && n){

		map<string, int> M;

		for(int i = 0; i < n; i++){
			vector<string> courses(5);
			for(int j = 0; j < 5; j++) cin>>courses[j];
			sort(courses.begin(), courses.end());

			string key = "";
			for(int j = 0; j < 5; j++) key += courses[j];
			M[key]++;
		}

		vector< pair<string,int> > sortCourses(M.begin(), M.end());

		int popular = 0;
		int ans = 0;
		for(int i = 0; i < sortCourses.size(); i++) popular = max(popular, sortCourses[i].second);
		for(int i = 0; i < sortCourses.size(); i++){
			if(popular == sortCourses[i].second) ans += sortCourses[i].second;
		}

		cout<<ans<<endl;

	}
	
}