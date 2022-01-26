// Har Har Mahadev
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long           ll;
typedef unsigned long long  ull;
 
#define el                  '\n' 
#define take(i)             int i; cin>>i
#define pb                  push_back
#define mp                  make_pair
#define ub                  upper_bound
#define lb                  lower_bound
#define ff                  first
#define ss                  second
#define iter                iterator
#define huge                10e9+7

int thanoi(int n, int start, int end, int via){
	if(n==1){
		cout<<start<<" "<<end<<el;
		return 0;
	}

	thanoi(n-1, start, via, end);
	cout<<start<<" "<<end<<el;
	thanoi(n-1, via, end, start);
	return 0;
}

int itr_thanoi(int n, int start, int end, int via){
	stack<pair<int, pair<int,int>>> s;
	pair<int, pair<int,int>> root= make_pair(n, make_pair(start, end));
	pair<int, pair<int,int>> curr = root;

	while(true){

		while(curr.ff>1){
			//	PUSH LEFT CHILD
			s.push(curr);

			int x = 6 - curr.ss.ff - curr.ss.ss;
			//	TAKE ITS LEFT CHILD
			curr = make_pair(curr.ff-1, make_pair(curr.ss.ff, x));;
		}

		while(curr.ff==1){
			//	LEFT CHILD
			cout<< curr.ss.ff << " " << curr.ss.ss<<el;
			if(s.empty()) return 0;
			curr = s.top();
			s.pop();
		}
		//	PARENT
		cout<< curr.ss.ff << " " << curr.ss.ss<<el;

		int x = 6 - curr.ss.ff - curr.ss.ss;
		//	MOVE TO RIGHT SUB-TREE
		curr = make_pair(curr.ff-1, make_pair(x, curr.ss.ss));

	}
	return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);      cout.tie(0);

    int n; cin>>n;

    int ans = (1<<n)-1;
    cout<<ans<<el;
    itr_thanoi(n,1,3,2);
 
    return 0;
}