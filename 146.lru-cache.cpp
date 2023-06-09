/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start

class Node{
public:
    int val,key;
    Node *next, *prev;
    Node(int key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};




class LRUCache {
    int n, currSize = 0;
    Node *last, *head;
    unordered_map<int,Node*> mp;
    // unordered_map<int,int> mi;
    // unordered_map<int,Node*> mn;
public:
    LRUCache(int capacity) {
        n = capacity;
    }
    
    void remove(Node* t){
        // cout<<"{"<<t->key<<","<<t->val<<"} del ";
        if(t == head and t == last){
            head = NULL;
            last = NULL;
        }
        else if(t == head){
            head = head->next;
            head->prev = NULL;
        }
        else if(t == last){
            last = last->prev;
            last->next = NULL;
        }
        else{
            t->next->prev = t->prev;
            t->prev->next = t->next;
        }
        mp.erase(t->key);
        currSize--;
    }

    void add(Node* t){
        // cout<<"{"<<t->key<<","<<t->val<<"} add hua ";
        if(currSize == 0){
            // cout<<"Only 1"<<endl;
            mp.clear();
            head = t;
            last = t;
            mp[t->key] = t;
            currSize++;
            return;
        }
        // cout<<"ye"<<endl;
        last->next = t;
        mp[t->key] = t;
        t->prev = last;
        last = last->next;
        currSize++;
    }


    int get(int key) {
        if(mp.find(key) == mp.end()){
            // cout<<"key : "<<key<<" nhi mili "<<endl;
            return -1;
        }
        Node* temp = mp[key];
        int ans = temp->val;
        remove(temp);
        add(temp);
        return ans;
    }
    



    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            Node* temp = new Node(key, value);
            add(temp);
        }
        else{
            Node* temp = mp[key];
            Node* newTemp = new Node(key,value);
            remove(temp);
            add(newTemp);
        }
        // cout<<currSize<<endl;
        if(currSize>n){
            // cout<<"ghusa "<<head->val<<" ";
            remove(head);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

