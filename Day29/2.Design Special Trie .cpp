#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:

    char ch;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        this->ch=ch;

        for(int i=0;i<26;i++)children[i]=NULL;
        isTerminal=false;
    }


};


class WordDictionary {
    private:
    TrieNode* root;
public:

    WordDictionary() {

        root=new TrieNode('\0');
        
    }

    void addHelper(TrieNode* root,string word)
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

        addHelper(temp,word.substr(1));
    }
    
    void addWord(string word) {
        addHelper(root,word);
    }
    
    bool searchHelper(TrieNode* root,string word)
    {
        if(word.size()==0)
        {
            return root->isTerminal;
        }
        if(word[0]!='.')
        {
              int index=word[0]-'a';
        TrieNode* temp;
        if(root->children[index]==NULL)return false;
        else
        {
            temp=root->children[index];
        }

        return searchHelper(temp,word.substr(1));
        }
        else
        {
            bool check=false;
            for(auto i:root->children)
            {
                if(i!=NULL)
                {
                    TrieNode* temp=i;
                    check=searchHelper(temp,word.substr(1));
                }
                if(check)return true;
            }

            return false;
        }
      
    }

    bool search(string word) {
        return searchHelper(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */