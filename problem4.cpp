/*Fruit Ninja (Public Contest: CodeRush October'23)

The Fruit Ninja faces an intriguing challenge.
There are N fruits laid out before him, with each fruit initially placed in its respective basket. Additionally, each fruit is of a specific type.
He receives a series of Q queries in a specific order:
1 a b: The basket containing Fruit a and the basket containing Fruit b merge. If they are already in the same basket, no changes occur.
2 x y: Determine the number of fruits of type y that are already in the same basket as Fruit x at the time of this query, including Fruit x.
Help Fruit Ninja with this challenge, and the fruit salad shall be yours!

Input
The first line of the input contains two integers N and Q, The number of fruits and queries respectively.
The next line contains N integers, ith of which (T[i]) denotes the type of ith fruit.
The next Q lines contain 1 query. The first integer of each line denotes the type of query.
The queries are in the following format.
1 a b: Merge the baskets containing fruit a and fruit b, if they are in different baskets. Else, do nothing.
2 x y: Determine the number of fruits of type y that are already in the same basket as fruit x at the time of this query, including fruit x.

Constraints

1<=N, Q<=100000
1<=a, b, x, y, T[i]<=N
Output
Output:
For each query of type 2, print a single integer in a single line, the answer for the query.
Example
Input:
5 6
1 1 1 2 2
2 1 1
2 1 2
1 5 1
2 1 2
1 2 1
2 1 1

Output:
1
0
1
2

For the first 2 queries, only the fruit 1 remains in its basket.
After executing the third query, fruit 1 and 5 are grouped in the same basket.
For the fourth query, number of fruits of type 2 in the basket of fruit 1 is 1, i. e. 5th fruit.
After executing the fifth query, fruit 1, 2 and 5 are grouped in the same basket.
For the sixth query, number of fruits of type 1 in the basket of fruit 1 is 2, i. e. 1st and 2nd fruit.*/

/*----------------------------------------------------------------------------------------------------------------------------------------------*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define MOD 1000000007

static const int N = 200200;
int a[N], f[N];
vector<unordered_map<int, int>> rn(N);

int find(int u){
	if(f[u] != u){
		return find(f[u]);
	}

	return u;
}

void un(int a, int b){
	a = find(a);
	b = find(b);

	if(a > b){
		swap(a, b);
	}

	f[b] = a;
	for(auto i: rn[b]){
		rn[a][i.first] += i.second;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	for(int i = 1; i <= n; i++){
		cin >> a[i - 1];
		rn[i][0] = 1;
		rn[i][a[i - 1]] = 1;
		f[i] = i;
	}

	while(q--){
		int ch, b, c;
		cin >> ch >> b >> c;

		if(ch == 1){
			un(b, c);
		}

		else{
			
			int x = find(b);
			cout << rn[x][c] << "\n";
		}
	}

	// for(int i = 0; i < n; i++){
	// 		cout << find(i) << " ";
	// 	}
	// cout << "\n";

	return 0;
}