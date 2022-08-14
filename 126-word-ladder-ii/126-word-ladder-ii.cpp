struct Trie {
    Trie* child[26];
    int visited;
    Trie() : visited(-1) {}
};

class Solution {
public:
    
void set_null(Trie* t)  {
    for (int i=0; i<26; ++i)
        t->child[i] = nullptr;
}

void insert_in_trie(string &word, Trie* t) {
    for (auto c: word)  {
        if (t->child[c-'a'])    {
            t = t->child[c-'a'];
        }
        else    {
            t->child[c-'a'] = new Trie();
            t = t->child[c-'a'];
            set_null(t);
        }
    }
}

Trie* build_trie (vector<string> &words)    {
    Trie* t = new Trie();
    set_null(t);
    for (auto &word: words)
        insert_in_trie(word, t);
    return t;
}

char search_trie(string &word, Trie* t, int nt)   {
    for (auto c: word)  {
        if (t->child[c-'a'])
            t = t->child[c-'a'];
        else
            return -1;
    }
    if (t->visited == -1)   {
        t->visited = nt;
        return 2;
    }
    else if (t->visited == nt)
        return 1;
    return 0;
}

void answer_maker(vector<vector<string>> &ans, vector<string> &tmp, unordered_map<string, vector<string>> &parents, string cur)  {
    if (cur.empty())    {
        ans.push_back(tmp);
        return;
    }
    tmp.push_back(cur);
    for (auto &s: parents[cur])
        answer_maker(ans, tmp, parents, s);
    tmp.pop_back();
}

vector<vector<string>> findLadders(string src, string dst, vector<string> &words)   {
    // make trie for faster searching and shit
    Trie* t = build_trie(words);

    // look for end word in the trie. if not present, return
    if (!search_trie(dst, t, -1))
        return {};
    search_trie(src, t, 0);
    // do bfs
    queue<pair<string, string>> q;
    q.push({src, ""});
    q.push({"", ""});
    unordered_map<string, vector<string>> parents;
    parents[src].push_back("");
    int n = src.size(), nt = 0;
    bool dst_found = 0;
    vector<vector<string>> ans;

    while (q.size() > 1)    {
        auto [word, parent] = q.front();
        if (word.empty())   {
            if (dst_found)
                goto k;
            q.push({"", ""});
            q.pop();
            ++nt;
            continue;
        }
        q.pop();
        if (word == dst)
            dst_found = 1;
        // all transformations possible
        parent = word;
        for (int i=0; i<n; ++i) {
            char c = word[i];
            for (char j='a'; j<='z'; ++j)   {
                if (j==c)
                    continue;
                word[i] = j;
                switch (search_trie(word, t, nt))   {
                    case 1:
                    parents[word].push_back(parent);        
                    break;
                    case 2:
                    q.push({word, parent});
                    parents[word].push_back(parent);
                    break;
                }
            }
            word[i] = c;
        }
    }
    k:
    if (!dst_found)
        return ans;
    // recursive answer maker
    vector<string> tmp;
    answer_maker(ans, tmp, parents, dst);
    for (auto &a: ans)
        reverse(a.begin(), a.end());
    return ans;
}
};