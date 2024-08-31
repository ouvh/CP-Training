#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100010
 
char T[100300],P[1000];
int n, m, n1;
string out;
int RA[MAX_N], tempRA[MAX_N], LCP[MAX_N], PLCP[MAX_N], Phi[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
 
void countingSort(int k) {
    int i, sum, maxi = max(300, n);
    memset(c, 0, sizeof c);
    for (i = 0; i < n; i++)
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    for (i = 0; i < n; i++)
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)
        SA[i] = tempSA[i];
}
 
void constructSA() {
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];
    for (i = 0; i < n; i++) SA[i] = i;
    for (k = 1; k < n; k <<= 1) {
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;
        for (i = 1; i < n; i++)
            tempRA[SA[i]] =
            (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
        for (i = 0; i < n; i++)
            RA[i] = tempRA[i];
        if (RA[SA[n - 1]] == n - 1) break;
    }
}
 
void computeLCP() {
    int i, L;
    Phi[SA[0]] = -1;
    for (i = 1; i < n; i++)
        Phi[SA[i]] = SA[i - 1];
    for (i = L = 0; i < n; i++) {
        if (Phi[i] == -1) { PLCP[i] = 0; continue; }
        while (T[i + L] == T[Phi[i] + L]) L++;
        PLCP[i] = L;
        L = max(L - 1, 0);
    }
    for (i = 0; i < n; i++)
        LCP[i] = PLCP[SA[i]];
}
 
pair<int,int> stringMatching() { // string matching in O(m log n)
    int lo = 0, hi = n-1, mid = lo; // valid matching = [0..n-1]
    while (lo < hi) { // find lower bound
        mid = (lo + hi) / 2; // this is round down
        int res = strncmp(T + SA[mid], P, m); // try to find P in suffix ’mid’
        if (res >= 0) hi = mid; // prune upper half (notice the >= sign)
        else lo = mid + 1; // prune lower half including mid
    } // observe ‘=’ in "res >= 0" above
    if (strncmp(T + SA[lo], P, m) != 0) return pair<int,int>(-1, -1); // if not found
    pair<int,int> ans; ans.first = lo;
    lo = 0; hi = n - 1; mid = lo;
    while (lo < hi) { // if lower bound is found, find upper bound
        mid = (lo + hi) / 2;
        int res = strncmp(T + SA[mid], P, m);
        if (res > 0) hi = mid; // prune upper half
        else lo = mid + 1; // prune lower half including mid
    } // (notice the selected branch when res == 0)
    if (strncmp(T + SA[hi], P, m) != 0) hi--; // special case
    ans.second = hi;
    return ans;
} // return lower/upperbound as first/second item of the pair, respectively
int main() {
    long long count,k;
    n = (int)strlen(gets(T)); // input T as per normal, without the ‘$’
    T[n++] = '$'; // add terminating character
    cin >> k;
    constructSA();
    computeLCP();
    count = 0;
    for(int i=1;i<n;i++) {
        count -=  LCP[i];
        if(count + n-SA[i] -1 >= k) {
            string p;
            p = T + SA[i];
            p = p.substr(0,k-count);
            cout << p;
            break;
        }
        else
            count += n-SA[i] -1;
    }
    return 0;
}
