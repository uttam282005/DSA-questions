#include <bits/stdc++.h>
using namespace std;

#define ff first
#define db double
#define ss second
#define si set<int>
#define mp make_pair
#define ll long long
#define pb push_back
#define um unordered_map
#define vi vector <ll int>
#define vs vector <string>
#define gcd(a,b) __gcd(a,b)
#define pii pair <int, int>
#define find(v, a) find(v.begin(), v.end(), a)
#define all(x) (x.begin(), x.end())
#define umii unordered_map <int, int>
#define sorta(arr) sort(begin(arr), end(arr))
#define sortv(vec) sort(vec.begin(), vec.end())
#define itr(container) for(auto &it : container)
#define debug(x) cout << #x << '=' << x << endl
#define rep(i, a, b) for (int i = a; i < b; i++)
#define acc(v) accumulate(v.begin(), v.end(), 0)
#define cnt(v, a) count(v.begin(), v.end(), a)
#define rev(v) reverse(v.begin(), v.end())
#define maxe(v) *max_element(v.begin(), v.end())
#define mine(v) *min_element(v.begin(), v.end())
#define repe(i, a, b) for (int i = a; i <= b; i++)

auto print_con = [](auto v){itr(v) cout << it << " ";};
auto print_arr = [](auto arr[], int n){rep (i, 0, n) cout << arr[i] << " ";};
// don't forget long long

int findLongestCommonSubstring(string str1, string str2) {
    string longestSubstring = "";

    for (int i = 0; i < str1.size(); i++) {
        for (int j = 0; j < str2.size(); j++) {
            string substring = "";
            int x = i;
            int y = j;

            while (x < str1.size() && 
                   y < str2.size() && 
                   str1[x] == str2[y]) {
                substring += str1[x];
                x++;
                y++;
            }

            if (substring.size() > longestSubstring.size()) {
                longestSubstring = substring;
            }
        }
    }

    return longestSubstring.size();
}
void solve () {
	string a, b;
	cin >> a >> b;
	int ans = findLongestCommonSubstring(a, b);
	cout << a.size() - ans + b.size() - ans << endl;
	
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
