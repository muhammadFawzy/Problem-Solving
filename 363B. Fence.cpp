//https://codeforces.com/contest/363/problem/B
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k;
    vector<int> p;
    cin >> n >> k;
    vector<pair<int, int>> sum(n, make_pair(0, 0));


    int c = n;
    while (c--) {
        int h;
        cin >> h;
        p.push_back(h);
    }

    int round = 0;
    for (int i = k - 1; i < n; i++) {
        if (i == k - 1) {
            int i1 = k;
            while (i1--) {
                sum[i].first += p[i1];
            }
        } else {
            sum[i].first += p[i] + sum[i - 1].first - p[round];
            round++;
        }
        sum[i].second = i - (k - 1);
    }


    stable_sort(sum.begin(), sum.end());

    cout << sum[k - 1].second + 1 << endl;


    return 0;

}
