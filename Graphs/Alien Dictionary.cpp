
/*
Problem:Alien Dictionary

Platform:GeeksforGeeks

Link:https://www.geeksforgeeks.org/problems/alien-dictionary/1

Difficulty:Hard

Approach:
1. Compare every pair of adjacent words to determine the first differing character.
2. Create a directed edge from the first differing character in the first word
   to the corresponding character in the second word.
3. Handle the invalid prefix case where a longer word appears before its prefix.
4. Compute the indegree of every character.
5. Apply Kahn's Algorithm (BFS Topological Sort) to generate the character order.
6. If all unique characters are processed, return the ordering.
   Otherwise, a cycle exists and no valid ordering is possible.

Time Complexity:
O(N * L + K + E)

where:
N = Number of words
L = Average length of a word
K = Number of unique characters
E = Number of edges

Space Complexity:
O(K + E)

Tags:
Graph, Topological Sort, Kahn's Algorithm, BFS
*/

class Solution {
public:

    pair<char, char> f(string &a, string &b) {

        int i = 0;

        while (i < a.size() && i < b.size()) {

            if (a[i] != b[i])
                return {a[i], b[i]};

            i++;
        }

        if (a.size() > b.size() && i == b.size())
            return {'&', '&'};

        return {'-1', '-1'};
    }

    string findOrder(vector<string> &words) {

        unordered_map<char, set<char>> m;
        unordered_map<char, bool> z;

        for (int i = 0; i < words.size() - 1; i++) {

            pair<char, char> temp = f(words[i], words[i + 1]);

            if (temp.first == '&')
                return "";

            if (temp.first != '-1' && temp.second != '-1')
                m[temp.first].insert(temp.second);
        }

        for (auto &word : words) {
            for (char c : word)
                z[c] = true;
        }

        int u = z.size();

        unordered_map<char, int> indegree;

        for (auto i : z)
            indegree[i.first] = 0;

        for (auto i : m) {
            for (auto j : i.second)
                indegree[j]++;
        }

        queue<char> q;

        for (auto i : indegree) {

            if (i.second == 0)
                q.push(i.first);
        }

        int count = 0;
        string ans;

        while (!q.empty()) {

            char node = q.front();
            q.pop();

            count++;

            ans += node;

            for (auto next : m[node]) {

                indegree[next]--;

                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        if (count != u)
            return "";

        return ans;
    }
};