/*Optimal Arrangement (Public Contest: CodeRush October'23)

You are given N holes and some balls. The goal of this game is to make the balls line up. The game is described by a string of length N, consisting of the characters '0' (empty holes) and '1' (holes containing balls). In one move, you can move any ball one square to the left or one square to the right, if the corresponding square exists and is empty. The game ends as soon as the balls are lined up, that is, there should be no empty cells between any balls.
Determine the minimum number of moves required to line up the balls.
Input
Input:
The first line of the input contains a single integer N.
The next line contains a binary string of length N, representing the state of the game.


Constraints

1<=N<=100000
Output
Output:
Output a single integer, the minimum number of moves required to line up the balls.
Example
Input:
5
11011

Output:
2

Input:
7
1000001

Output:
5

Attaining configuration 11110 and 0110000 will require the 2 and 5 moves respectively for the above test cases.*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((ll)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define endl '\n';
#define fi first
#define popcount(x) __builtin_popcountll(x)
#define se second
#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)
 /*vector<int> primes, is_prime, spf;

 void sieve(int n) {
     primes.clear();
     is_prime.assign(n + 1, 1);
     spf.assign(n + 1, 0);
     is_prime[0] = is_prime[1] = false;
     for(ll i=2;i<=n;i+=2){
         spf[i]=2;
         if(i!=2)is_prime[i]=false;
     }
     for (ll i = 3; i*i <= n; i++) {
         if (is_prime[i]) {
             spf[i] = i;
             for (ll j = i * i; j <= n; j += i) {
                 is_prime[j] = false;
                 spf[j] = i;
             }
         }
     }
 }
*/

/* struct cmp{
    bool operator()(const pair<int,int>& v1,const pair<int,int>& v2) const{
    	
    }};*/
 ll cntBits(ll n,ll k){
    n++;
    ll ans=0;
    ans= ((n>>(k+1)) << k);
    if ((n >> k) & 1)ans += n & ((1ll << k) - 1);
    return ans;
}
 long long binpow(long long a, long long b) {
    a %=MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    res=res%MOD;
    return res;
}

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll>pos;
    for(ll i=0;i<n;i++){
        if(s[i]=='1')pos.push_back(i);
    }
    ll ans=0;
    if(pos.size()==0){
        cout<<0<<endl;
        return;
    }
    ll mid = pos[pos.size()/2];
    ll sm = 0,gr = 0;
    for(auto x : pos){
        if(x<=mid)sm++;
        else gr++;
    }
    ll start = mid - sm + 1;
    for(auto x:pos){
        if(x>mid)break;
        ans+=abs(start-x);
        start++;
    }
    start = mid + gr;
    reverse(pos.begin(),pos.end());
    for(auto x:pos){
        if(x<=mid)break;
        ans+=abs(start-x);
        start--;
    }
    cout<<ans<<endl;
    
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int tc=1; //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
}