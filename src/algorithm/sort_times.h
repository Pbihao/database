//
// Created by pbihao on 11/23/19.
//

#ifndef DATABASE_SORT_TIMES_H
#define DATABASE_SORT_TIMES_H

#include "../DB/DB.h"
/**
 * 传入一个数据库的类，将数据库类中的所有的图书按照被借阅的次数从大到小
 * 从大到小地进行排序
 * @param database
 */
void sort_times(DB* database);


#endif //DATABASE_SORT_TIMES_H
