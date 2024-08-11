
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node *links[26];
    bool terminal=false;
    bool containskey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node *node){
       links[ch-'a'] = node;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    bool setend(){
        terminal=true;
    }
    bool isend(){
        return terminal;
    }
};
void insert(char ch){

}

int main()
{

   Node *root =new Node();
   Node *node=root;
   string word = "amniket";
   int n=word.size();

// insert
   for(int i=0;i<n;++i){
     if(!node->containskey(word[i])){
             node->put(word[i],new Node());
     }
     node=node->get(word[i]);

   }
   node->setend();

// search 
  node=root;
    for(int i=0;i<n;++i){
     if(!node->containskey(word[i])){
             return false;
     }
     node = node->get(word[i]);

   }
   return node->isend();

   // startwith
   node= root;
   for(int i=0;i<n;++i){
     if(!node->containskey(word[i])){
             return false;
     }
     node = node->get(word[i]);

   }
   return true;


    return 0;
}