//
// Created by sherlock on 11/29/19.
//

#include "search.h"


void pre_string_process(string title, vector<string>& words){
    /*统一书名的格式*/
    string tmp;
    words.clear();
    for(auto x: title){
        if(x >= 'A' && x <= 'Z')x = x - 'A' + 'a';
        /*将大写字母转换为小写字母*/
        if((x >= 'a' && x <= 'z') || x == '-' || x == '\'' || x == ',' || (x >= '0' && x <= 9))tmp.push_back(x);
        else{
            if(tmp.empty())continue;
            words.push_back(tmp);
            tmp.clear();
        }
        /*剔除无用字符*/
    }
    if(!tmp.empty())words.push_back(tmp);
}
bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    return a > b;
}

void Search_engine::init(vector<Book>& books_name){
    /*搜索引擎初始化*/
    dictionary.clear();
    vector<string>tmp;
    for(int i = 0; i < books_name.size(); i++){
        tmp.clear();
        pre_string_process(books_name[i].get_name(), tmp);
        for(auto x: tmp){
            dictionary.insert(x, books_name[i].get_ID());
        }
    }
}

void Search_engine::insert(Book book){
    /*搜索引擎插入一本书*/
    vector<string>tmp;
    pre_string_process(book.get_name(), tmp);
    for(auto x: tmp){
        dictionary.insert(x, book.get_ID());
    }
}

void Search_engine::erase(Book book){
    /*搜索引擎删除一本书*/
    vector<string> tmp;
    pre_string_process(book.get_name(), tmp);
    for(auto x: tmp){
        dictionary.erase(x, book.get_ID());
    }
}

void Search_engine::search(string title, vector<int>& arry){
    /*搜索引擎查找一本书*/
    vector<string> words;
    pre_string_process(title, words);
    map<int, int>count;
    vector<int> appear_in_books_ID;
    for(auto word: words){
        dictionary.find(word, appear_in_books_ID);
        for(int ID: appear_in_books_ID){
            count[ID]++;
        }
    }
    vector<pair<int, int>>ans;
    for(auto x: count){
        ans.push_back(make_pair(x.second, x.first));
    }
    sort(ans.begin(), ans.end(), cmp);
    while(ans.size() > 10)ans.pop_back();
    arry.clear();
    for(auto x: ans){
        arry.push_back(x.second);
    }
}

void Dictionary::clear() {
    /*清空字典树*/
    if(!rt)
        return;
    queue<Dictionary::node*>q;
    q.push(Dictionary::rt);
    while(!q.empty()){
        node* u = q.front();
        q.pop();
        for(const auto& x: u->edge){
            q.push(x.second);
        }
        delete u;
    }
}
void Dictionary::insert(string word, int book_id) {
    /*插入一本书到字典树中*/
    if(rt == NULL)rt = new node();
    node* now = rt;
    for(const auto& x:word){
        if(!now->edge[x])now->edge[x] = new node();
        now = now->edge[x];
    }
    bool ok = true;
    now->list.insert(book_id);
}

void Dictionary::find(string word, vector<int>&arry){
    /*查找字典树中的一本书*/
    node* now = rt;
    arry.clear();
    if(!now)return;
    for(const auto& x: word){
        if(!now->edge[x])return;
        now = now->edge[x];
    }
    for(const auto& x: now->list){
        arry.push_back(x);
    }
    return;
}

void Dictionary::erase(string word, int book_id) {
    /*删除字典树中的一本书*/
    stack<pair<node*, char> >s;
    node* now = rt;
    if(!now)return;
    for(auto x: word){
        if(!now->edge[x])return;
        s.push(make_pair(now, x));
        now = now->edge[x];
    }
    now->list.erase(book_id);
    bool ok = true;
    while(ok && !s.empty()){
        node* u = s.top().first;
        char c = s.top().second;
        node* v = u->edge[c];
        s.pop();
        if(!v->list.empty() || !v->edge.empty())ok = false;
        else{
            delete v;
            u->edge.erase(c);
        }
    }
}