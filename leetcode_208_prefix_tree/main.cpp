/**
 * Submission using maps
 * Author Eduardo Villalpando Mello
**/

#include <bits/stdc++.h>
using namespace std;

class PrefixTreeNode {
public:
    char value;
    map<char, PrefixTreeNode*> children;
    bool endOfWord;
    PrefixTreeNode() : value(' '), endOfWord(false) {}
    PrefixTreeNode(char value) : value(value), endOfWord(false) {}

    void insert(string value){
        // Get first char
        if(this->children[value[0]] == nullptr) {
            this->children[value[0]] = new PrefixTreeNode(value[0]);
        }
        // If only one char remaining mark as end of word
        if(value.size() == 1){
            this->children[value[0]]->endOfWord = true;
            return;
        }
        // Trim string
        string newString = "";
        for(int i = 1; i < value.size(); i++) newString+=value[i];
        // Insert recursively
        return this->children[value[0]]->insert(newString);
    }

    bool search(string value, bool checkEndOfWord){
        if(value.size() == 0) return false;
        // False if no suitable children
        if( this->children[value[0]] == nullptr ) return false;
        // True when single char and suitable children
        if( value.size() == 1 && this->children[value[0]] != nullptr ){
            if(!checkEndOfWord) return true;
            else return this->children[value[0]]->endOfWord;
        }
        // Trim string
        string newString = "";
        for(int i = 1; i < value.size(); i++) newString+=value[i];
        // Search recursively
        return this->children[value[0]]->search(newString, checkEndOfWord);
    }

    bool search(string value){
        return search(value, true);
    }

    bool searchPrefix(string value){
        return search(value, false);
    }

};

int main(){
    PrefixTreeNode trie;
    trie.insert("apple");
    cout<<trie.search("apple")<<endl;
    cout<<trie.search("app")<<endl;
    cout<<trie.searchPrefix("app")<<endl;
    return 0;
}