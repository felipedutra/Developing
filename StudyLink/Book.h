#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

    class Book {
        public:
            Book(string bookname,string authorname);
            virtual ~Book();

        protected:

        private:
          string bookname;
          string authorname;
    };

    #endif // BOOK_H
