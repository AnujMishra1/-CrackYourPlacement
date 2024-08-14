#include<bits/stdc++.h>
using namespace std;


class TrieNode
{
       public:
    char data;
    TrieNode* children[26];
    bool isTerminal;


    TrieNode(char ch)
    {
        data=ch;

        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root=new TrieNode('\0');
    }
    
    void UtilInsert(TrieNode* root,string word)
    {
        if(word.size()==0)
        {
            root->isTerminal=true;
            return;
        }

        int index=word[0]-'a';
        TrieNode* temp;

        if(root->children[index]!=NULL)
        {
            temp=root->children[index];
        }
        else
        {
            temp=new TrieNode(word[0]);
            root->children[index]=temp;
        }
        UtilInsert(temp,word.substr(1));
    }

    void insert(string word) {
         UtilInsert(root,word);
    }
    
    bool UtilSearch(TrieNode* root,string word)
    {
        if(word.size()==0)
        {
            return(root->isTerminal);
        }

        int index=word[0]-'a';

        TrieNode* temp;
        if(root->children[index]==NULL)return false;
        else
        {
            temp=root->children[index];
        }

        return UtilSearch(temp,word.substr(1));
    }

    bool search(string word) {
        return UtilSearch(root,word);
    }

    bool UtilStarts(TrieNode* root,string word)
    {
        if(word.size()==0)return true;

        int index=word[0]-'a';
        TrieNode* temp;
        if(root->children[index]==NULL)return false;
        else
        {
            temp=root->children[index];
        }

        return UtilStarts(temp,word.substr(1));
    }
    
    bool startsWith(string prefix) {
        return UtilStarts(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */