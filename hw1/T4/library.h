#pragma once
#include "book.h"
#include <iostream>
#include <vector>
using namespace std;

class Library
{
private:
    vector<Book> Books;
public:
    void add_book(Book book);
    void delete_book(int book_ID);
    void find_book(int book_ID);
    void borrow_book(int book_ID, string borrower);
    void return_book(int book_ID);
};

