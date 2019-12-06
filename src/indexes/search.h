//
// Created by sherlock on 11/29/19.
//

#ifndef DATABASE_SEARCH_H
#define DATABASE_SEARCH_H

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <stack>
#include <map>
#include <algorithm>
#include "../DB/book.h"
using namespace std;

/*
 * 用于倒排索引的字典树
 * */
class Dictionary{
private:
    struct node{
        set<int>list;
        unordered_map<char, node*>edge;
    };
    node *rt = NULL;
public:
    /*
     * 删除整个字典树
     * */
    void clear();
    /*
     * 向字典树中插入一个单词，这个单词出现在一本书中
     * */
    void insert(string word, int book_id);
    /*
     * 查找一个单词出现在哪些书名中
     * */
    void find(string word, vector<int>& arry);
    /*
     * 从字典中删除一个单词
     */
    void erase(string word, int book_id);
};

class Search_engine{
    Dictionary dictionary;
public:
    /*
 * 在这个类中传入一个String类以后会从已有的数据库中进行搜索，然后找到最符合条件的前十本书的ID
 * 按照匹配度进行排序输出
 */
    void search(string title, vector<int>& arry);

/*
 * 初始化字典树，传入一个字典树的容器，将这些书名建立一个字典树
 */
    void init(vector<Book>& books_name);

/*
 * 如果后面有新加书籍，可以提供单本书的书名的添加
 */
    void insert(Book book);

/*
 * 当删除一本书的时候，同时从字典树中将整本书的信息删除
 */
    void erase(Book book);
};

#endif //DATABASE_SEARCH_H