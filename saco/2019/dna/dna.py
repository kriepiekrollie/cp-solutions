import sys
sys.setrecursionlimit(10**9)
N, M = map(int, input().split())

dna = input()

dp = [float("inf") for i in range(N + 1)]
dp[N] = 0

class TrieNode:
    def __init__(self):
        self.children = {
            "A" : None,
            "C" : None,
            "G" : None,
            "T" : None
        }
        self.isEnd = False
    def add(self, s, i = 0):
        if (i == len(s)):
            self.isEnd = True
            return
        if (s[i] not in self.children) or (self.children[s[i]] is None):
            self.children[s[i]] = TrieNode()
        self.children[s[i]].add(s, i + 1)

root = TrieNode()
for i in range(M):
    x = int(input())
    root.add(input())

for k in range(N-1, -1, -1):
    dp[k] = float("inf")
    p = root
    for i in range(k + 1, N + 1):
        if (dna[i-1] not in p.children) or (p.children[dna[i-1]] is None):
            break
        p = p.children[dna[i-1]]
        if (p.isEnd):
            dp[k] = min(dp[k], dp[i] + 1)

if dp[0] == float("inf"):
    print(-1)
else: 
    print(dp[0])
