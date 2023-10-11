class TrieNode:
    def __init__(self):
        self.count = 0
        self.isEnd = False
        self.children = [None, None]

    def process(self):
        self.count = int(self.isEnd)
        for i in range(2):
            if (self.children[i] is not None):
                self.children[i].process()
                self.count += self.children[i].count

    def insert(self, x, dep=30):
        if (dep == 0):
            self.isEnd = True
            return
        idx = x & 1
        if (self.children[idx] is None):
            self.children[idx] = TrieNode()
        self.children[idx].insert(x >> 1, dep - 1)

    def search(self, x, r):
        if (self.isEnd):
            return 1
        if (r & 1 ^ 1):
            if (self.children[x & 1] is None):
                return 0
            return self.children[x & 1].search(x >> 1, r >> 1)
        res = 0
        if (self.children[x & 1] is not None):
            res += self.children[x & 1].count
        if (self.children[x & 1 ^ 1] is not None):
            res += self.children[x & 1 ^ 1].search(x >> 1, r >> 1)
        return res
    
    def print(self, cur = ""):
        if (self.isEnd):
            print(cur)
        if (self.children[0] is not None):
            self.children[0].print(cur + '0')
        if (self.children[1] is not None):
            self.children[1].print(cur + '1')

def reverse_bits(x):
    res = 0
    for k in range(30):
        res |= ((x >> k) & 1) << (29 - k)
    return res

n, R = map(int, input().split())
R = reverse_bits(R)

root = TrieNode()

s = list(map(int, input().split()))
x = []
for i in range(n):
    x.append(reverse_bits(s[i]))
    root.insert(x[i])

root.process()

ans = (-1, 0)
for i in range(n):
    res = root.search(x[i], R)
    ans = max(ans, (res, -s[i]))
print(-ans[1])
