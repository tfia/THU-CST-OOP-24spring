#include"library.h"

void Library::add_book(Book book)
{
    Books.push_back(book);
    cout << "Added:" << book.get_name() << endl;
}

void Library::delete_book(int book_ID)
{
    bool flag = 0;
    for(auto it = Books.begin(); it != Books.end(); ++it)
    {
        if(it->get_ID() == book_ID)
        {
            cout << "Deleted:" << it->get_name() << endl;
            Books.erase(it);
            flag = 1;
            break;
        }
    }
    if(!flag) cout << "Delete Failed" << endl;
}

void Library::find_book(int book_ID)
{
    bool flag = 0;
    for(auto it = Books.begin(); it != Books.end(); ++it)
    {
        if(it->get_ID() == book_ID)
        {
            it->print_message();
            flag = 1;
            break;
        }
    }
    if(!flag) cout << "Find Failed" << endl;
}

void Library::borrow_book(int book_ID, string borrower)
{
    bool flag = 0;
    for(auto it = Books.begin(); it != Books.end(); ++it)
    {
        if(it->get_ID() == book_ID)
        {
            it->change_state(borrower);
            cout << "Borrowed:" << it->get_name() << endl;
            flag = 1;
            break;
        }
    }
    if(!flag) cout << "Borrow Failed" << endl;
}

void Library::return_book(int book_ID)
{
    bool flag = 0;
    for(auto it = Books.begin(); it != Books.end(); ++it)
    {
        if(it->get_ID() == book_ID)
        {
            it->change_state();
            cout << "Returned:" << it->get_name() << endl;
            flag = 1;
            break;
        }
    }
    if(!flag) cout << "Return Failed" << endl;
}