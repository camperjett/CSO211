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

int n; 
vector<int> a;

int merge(int l, int mid, int r){
	vector<int> t(r-l+1);

	int i = l,
	j = mid + 1,
	k = 0;

	while(i <= mid && j <= r){
		if(a[i] < a[j]){
			t[k] = a[i];
			i++, k++;
		}
		else{
			t[k] = a[j];
			j++, k++;
		}
	}

	while(i<=mid){
		t[k] = a[i];
		k++, i++;
	}

	while(j<=r){
		t[k] = a[j];
		k++, j++;
	}


	for (int i = l; i <= r; ++i)
	{
		a[i] = t[i-l];
	}
	
	return 0;
}

int msort(){
    int size = 1;

    while(size<=n){
    	for (int i = 0; i <= n-1; i+=2*size)
    	{
    		int l = i,
    			r =	i + 2 * size - 1,
    			mid = i + size - 1;

    		r = min(r, n-1),
    		mid = min(mid, n-1);

    		merge(l, mid, r);
    	}
    	// for (int i = 0; i < n; ++i)
    	// {
    	// 	cout<<a[i]<<" ";
    	// }
    	// cout<<el;
    	size*=2;
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
    msort();

    for (int i = 0; i < n; ++i)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}