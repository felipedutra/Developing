#include "Books.h"
#define MAXVAL 1000
#include <string>

Books::Books(string name) {
      this->name = name;
      books = new Book*[MAXVAL];
}
Books::~Books() {

}

void Books::addBook(Book *b) {
  books[bookCount] = b;
  bookCount++;

}

Book** Books::getBooks() {
    return(books);
}
