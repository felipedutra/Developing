#ifndef BOOKS_H
#define BOOKS_H
#include <string>
#include "Book.h"
#include <iostream>
using namespace std;


    class Books {
        public:
            Books(string name);
            virtual ~Books();
            void addBook(Book *b);
            Book** getBooks();
        protected:


        private:
          string name;
          int bookCount; //64bits
          Book** books;
    };

    #endif // BOOKS_H
