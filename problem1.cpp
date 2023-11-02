/*Bankrupt! (Public Contest: CodeRush October'23)
Time Limit: 2, Memory Limit: 128000
Alice is in a tough place! She has recently declared bankruptcy and owes the bank a substantial sum of money. To help repay her loan, the bank is interested in acquiring her valuable assets, which include two precious metals: gold and silver.
Alice possesses A grams of gold and B grams of Silver. The current market conditions indicate that gold costs X rupees per gram, while silver is valued at Y rupees per gram. Alice is well aware of these prices and is ready to part with her precious metals.
The bank's primary goal is to retrieve K rupees from Alice's assets to recover the loan. To do this, they are interested in acquiring either gold or silver, or both, to reach the desired amount.
Can she repay the loan?

Input
Input:
Then only line of the input contains 5 integers, A, B, X, Y, K.

Constraints:

1<=A, B, X, Y<=100
1<=K<=10000
Output
Output:
Output "YES" if she can repay the loan, "NO" otherwise.
Example
Input:
5 4 2 7 32

Output:
YES

Since Alice can sell her assets and obtain 5*2 + 4*7 = 38 rupees, she can pay her loan back.*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;



int main() {
    int A, B, X, Y, K;
    
   
    cin >> A >> B >> X >> Y >> K;
    
    
    int totalGoldValue = A * X;
    int totalSilverValue = B * Y;
    
    
    if (totalGoldValue + totalSilverValue >= K) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
