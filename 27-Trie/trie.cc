#define ENG_LET 26

class Trie {
    class TrieNode {
    public:
        TrieNode* sons[ENG_LET];
        int strsInBranch;
        bool isEndOfStr;

        void print() {
            cout << "----------------" << endl;
            cout << "sons..";
            for(int i=0; i<ENG_LET; ++i) {
                if(sons[i] != NULL)
                    cout << " " << (char)('a'+i);
            }
            cout << endl;
            cout << "strsInBranch = " << strsInBranch << endl;
            cout << "isEndOfStr = " << isEndOfStr << endl;
            for(int i=0; i<ENG_LET; ++i) {
                if(sons[i] != NULL)
                    sons[i]->print();
            }

        }
        TrieNode(bool _isEndOfStr = false):isEndOfStr(_isEndOfStr), strsInBranch(0) {
            for(int i=0; i<ENG_LET; ++i) {
                sons[i] = NULL;
            }
        }
        ~TrieNode() {
            for(int i=0; i<ENG_LET; ++i) {
                delete sons[i];
                sons[i] = NULL;
            }
        }
    };

    TrieNode* head;
public:
    Trie() { head = new TrieNode();}
    ~Trie() { delete head; }
    void print() {
        cout << "Preorder Print : " << endl;
        head->print();
    }
    bool isExists(const string s) {
        TrieNode* curr = head;
        for(int i=0; i<s.size(); ++i) {
            int letIdx = s[i]-'a';
            if(curr->sons[letIdx] == NULL) {
                return false;
            }
            curr = curr->sons[letIdx];
        }

        return curr->isEndOfStr;
    }
    void addString(const string& s) {
        if(isExists(s))
            return;
        TrieNode* curr = head;
        for(int i=0; i<s.size(); ++i) {
            int letIdx = s[i]-'a';
            if(curr->sons[letIdx] == NULL) {
                curr->sons[letIdx] = new TrieNode();    
            }
            ++curr->strsInBranch;
            curr = curr->sons[letIdx];
        }
        ++curr->strsInBranch;
        curr->isEndOfStr = true;
    }
    void removeString(const string& s) {
        if(!isExists(s))
            return;
        TrieNode* curr = head;
        for(int i=0; i<s.size(); ++i) {
            int letIdx = s[i]-'a';

            if(curr->sons[letIdx] == NULL) {
                assert(false);
                return; //string not exists, will not reach here
            }
            if(curr->strsInBranch==1) {    //just 1 str that we want remove, remove the whole branch
                delete curr;
                return;
            }
            //more than 1 son
            --curr->strsInBranch;
            curr = curr->sons[letIdx];
        }
        curr->isEndOfStr = false;
    }

    void clear() {
        for(int i=0; i<ENG_LET; ++i) {
            delete head->sons[i];
            head->sons[i] = NULL;
        }
    }

};
