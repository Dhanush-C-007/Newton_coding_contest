/*Make it Max (Public Contest: CodeRush October'23)

Ash is on a quest when he is encountered by Team Rocket. To escape from them, he must answer this question!
He has to choose a set of K distinct numbers from the range 1 to N to maximize the greatest common divisor (GCD) of those K numbers. The GCD of a set of numbers is the largest number that divides all the numbers in the set.
Can you help Ash find the maximum possible GCD that can be achieved by selecting K distinct numbers from the range 1 to N?

Input
Input:
The first line contains T, the number of test cases.
The next T lines contains 2 integers N and K.

Constraints

1<=T<=50
1<=K<=N<=10^9
Output
Output:
For each test case, output a single integer in each line, the max possible GCD.
Example
Input:
2
4 2
89 7

Output:
2
12

For the first test case, we can choose numbers 2 and 4.
For the second test case, we can choose numbers 60, 84, 72, 12, 36, 24 and 48.*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int main() {
	// Your code here
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        int ans = n/k;
        cout << ans << endl;
    }
    return 0;
}