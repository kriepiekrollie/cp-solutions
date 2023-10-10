#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s[1000];

map<string, string> dictionary;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    string word, sorted_word;
    while (cin >> word)
    {
        sorted_word = word;
        sort(sorted_word.begin(), sorted_word.end());
        dictionary[sorted_word] = word;
    }

    for (int k = 0; k < 26; k++)
    {
        bool works = true;
        for (int i = 0; i < n; i++)
        {
            sort(s[i].begin(), s[i].end());
            if (dictionary.find(s[i]) == dictionary.end())
            {
                works = false;
                break;
            }
        }

        if (works)
        {
            cout << k << '\n';
            for (int i = 0; i < n; i++)
                cout << dictionary[s[i]] << ' ';
            cout << '\n';
            return 0;
        }

        for (int i = 0; i < n; i++)
            for (char &letter : s[i])
                letter = (letter - 'A' + 25) % 26 + 'A';
    }
    return 0;
}
