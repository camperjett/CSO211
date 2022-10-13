// Jai shiv shambhu !!
 
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

int n; 
vector<int> a;

int swap(int& x, int& y){
	int t = x;
	x = y;
	y = t;

	return 0;
}

int partition(int l, int h){
	int p = a[l];

	int i = l,
		j = h;

	while(i < j){
		do{
			i++;
		}while(a[i] <= p);

		do{
			j--;
		}while(a[j] > p);

		if(i < j){
			swap(a[i], a[j]);
		}
	}
	swap(a[j], a[l]);
	return j;

}

int qsort(int l, int h){
	vector<pair<int, int>> callstack;

	callstack.push_back(make_pair(l, h));

	while(!callstack.empty()){

		auto itr = callstack.back();
		callstack.pop_back();

		int l = itr.first,
			h = itr.second;

		int p = partition(l, h);
		
		if(p>l)	callstack.push_back(make_pair(l, p));
		if(h>p+1)	callstack.push_back(make_pair(p+1, h));
	}

	return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);      cout.tie(0);

    cin>>n;
    
    for (int i = 0; i < n; ++i)
    {
        int b; cin>>b;
        a.push_back(b);
    }
    //	Reference Largest element 
    a.push_back(INT_MAX);
    
    qsort(0, n);

    for (int i = 0; i < n; ++i)
    {
        cout<<a[i]<<" ";
    }
 
    return 0;
}
