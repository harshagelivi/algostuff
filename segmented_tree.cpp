/*
	IMPLEMENTATION OF SEGMENT TREE
	
	OPERATIONS ARE:
		S I J ==> RETURN SUM FROM I TO J... BOTH INCLUSIVE
		G I X ==> SUBTRATCT X FROM TREE AT INDEX I AND UPDATE THE TREE
		T I X ==> ADD X TO TREE AT INDEX I AND UPDATE THE TREE
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long int dt;

#define FOR(i,a,b) for(i=a;i<b;i++)
#define nl "\n"
#define TEN5 100000
#define MOD 1000000007
#define tb "\t"
dt height,size,n;
dt construct(vector<dt>&, vector<dt>&, dt, dt, dt);
dt getsum(vector<dt>& tree, dt l, dt r, dt qs, dt qe, dt ind);
void update(vector<dt>& tree, dt l, dt r, dt i, dt diff, dt ind);

int main(){
	cout.sync_with_stdio(false);
	cin.sync_with_stdio(false);
	dt q,i,j,diff,k;
	cin>>n>>q;
	vector<dt> arr(n);
	FOR(i,0,n)
		cin>>arr[i];
	height=(dt)ceil(log2(n));
	size=pow(2,height+1)-1;
	vector<dt> tree( size );
	construct( arr, tree, 0, n-1, 0 );
	char ch;
	FOR(k,0,q){
		cin>>ch>>i>>j;
		if(ch=='S'){
			cout<<getsum( tree, 0, n-1, i, j, 0 )<<nl;
		}
		if(ch=='G'){
			diff=j;
			arr[i]=j+arr[i];
			update( tree, 0, n-1, i, diff, 0 );
		}
		if(ch=='T'){
			diff=(-1)*j;
			arr[i]=arr[i]-j;
			update( tree, 0, n-1, i, diff, 0 );
		}
	}
	return 0;
}
// CONSTRUCT SEGMENT TREE tree FROM THE VECTOR arr BETWEEN l AND r... M IS THE NODE
dt construct( vector<dt>& arr, vector<dt>& tree, dt l, dt r, dt m ){
	if( l == r){
		tree[m] = arr[l];
		return arr[l];
	}
	dt mid=( l + r )/2;
	tree[m] = construct(arr, tree, l, mid, m*2+1) + construct(arr, tree, mid+1, r, m*2+2);
	return tree[m];
}
// GET THE SUM FROM QS TO QJ
dt getsum(vector<dt>& tree, dt l, dt r, dt qs, dt qe, dt ind){
	if (qs <= l && qe >= r)
		return tree[ind];
	if (r < qs || l > qe)
		return 0;
	dt mid = ( l + r )/2;
	return getsum(tree, l, mid, qs, qe, 2*ind+1) + getsum(tree, mid+1, r, qs, qe, 2*ind+2);
}
// UPADTE THE TREE WHEN AN ELEMENT IS CHANGED... AT i WITH A DIFFERENCE diff
void update(vector<dt>& tree, dt l, dt r, dt i, dt diff, dt ind){
	if (i < l || i > r)
		return;
	tree[ind] = tree[ind] + diff;
	if (l != r){
		dt mid = ( l + r )/2;
		update(tree, l, mid, i, diff, 2*ind + 1);
		update(tree, mid+1, r, i, diff, 2*ind + 2);
	}
}
