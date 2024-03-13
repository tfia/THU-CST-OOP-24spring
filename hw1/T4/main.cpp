#include "library.h"
#include <iostream>

using namespace std;

int main(){
    int n;
    string type;
    Library lib = Library();
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>type;
        int book_ID;
        std::cout<<"#"<<i+1<<endl;
        if(type=="ADD"){
            string name, author, publishing_house;
            std::cin>>book_ID>>name>>author>>publishing_house;
            Book new_book(book_ID, name, author, publishing_house);
            lib.add_book(new_book);
        }
        else if(type=="FIND"){
            std::cin>>book_ID;
            lib.find_book(book_ID);
        }
        else if(type=="DELETE"){
            std::cin>>book_ID;
            lib.delete_book(book_ID);
        }
        else if(type=="BORROW"){
            string borrower;
            std::cin>>book_ID>>borrower;
            lib.borrow_book(book_ID,borrower);
        }
        else if(type=="RETURN"){
            std::cin>>book_ID;
            lib.return_book(book_ID);
        }
        else{
            continue;
        } 
    }
    return 0;
}