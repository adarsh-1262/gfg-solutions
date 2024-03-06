// Search Pattern (Rabin-Karp Algorithm)
// Solution:
// CODE:

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            vector<int> indexes;
        int M = pattern.length();
        int N = text.length();
        int d = 256; // Number of characters in the input alphabet
        int q = 101; // A prime number

        int p = 0; // hash value for pattern
        int t = 0; // hash value for text
        int h = 1;

        // The value of h would be "pow(d, M-1)%q"
        for (int i = 0; i < M - 1; i++)
            h = (h * d) % q;

        // Calculate the hash value of pattern and first window of text
        for (int i = 0; i < M; i++) {
            p = (d * p + pattern[i]) % q;
            t = (d * t + text[i]) % q;
        }

        // Slide the pattern over text one by one
        for (int i = 0; i <= N - M; i++) {
            // Check the hash values of current window of text
            // and pattern. If the hash values match then only
            // check for characters one by one
            if (p == t) {
                bool match = true;
                for (int j = 0; j < M; j++) {
                    if (text[i + j] != pattern[j]) {
                        match = false;
                        break;
                    }
                }
                if (match)
                    indexes.push_back(i + 1); // 1-based index
            }

            // Calculate hash value for next window of text: Remove
            // leading digit, add trailing digit
            if (i < N - M) {
                t = (d * (t - text[i] * h) + text[i + M]) % q;
                // We might get negative value of t, converting it
                // to positive
                if (t < 0)
                    t = (t + q);
            }
        }
        return indexes;
        }
     
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
