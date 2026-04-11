class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Step 1: Build Trie
        for (auto& s : strs)
            insert(s);

        // Step 2: Walk down the Trie
        string prefix = "";
        TrieNode* node = root;

        while (true) {
            int countChildren = 0;
            int childIndex = -1;

            // Count children
            for (int i = 0; i < 26; i++) {
                if (node->children[i]) {
                    countChildren++;
                    childIndex = i;
                }
            }

            // Stop if:
            // - more than one child
            // - or this node marks the end of a word
            if (countChildren != 1 || node->isEnd)
                break;

            // Move to the only child
            node = node->children[childIndex];
            prefix.push_back('a' + childIndex);
        }

        return prefix;
    }
};
