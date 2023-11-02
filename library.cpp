/**
 * @file library.cpp
 * @author Jesse Warren
 * @date 2023-11-01
 * @brief Holds the library class functions.
 * 
 * Holds the functions that were defined within Library.h.
 */

#include "library.h"
#include "book.h"
#include <iostream>
#include <fstream>

using namespace std;

Library::Library(){
  books = list<Book>();
  //initializes the 'book' variable within the class.
}

void Library::addBook(Book book){
  books.push_back(book); 
  //insertSorted(book); //Takes the book and automatically sorts it alphabetically. 
}

void Library::deleteBook(string author, string title){
  list<Book>::iterator it = books.begin();

  while(it != books.end()){
    const Book& book = *it;
    //Iterates through the linked list and deletes the books based off author and title.
    if (book.getAuthor() == author && book.getTitle() == title){
      it = books.erase(it);
    }
    else
      it++;
  }
}

void Library::findAuthor(string author) const{ 
  for(list<Book>::const_iterator it = books.begin(); it != books.end(); it++) {
    Book book = *it;
    //Iterates through the linked list and prints the author's books.
    if(book.getAuthor() == author){
      cout << "Title: " << book.getTitle() << "  Author: " << book.getAuthor()
	   << "  Pages: " << book.getPages() << "  ISBN: " << book.getIsbn()
	   << "  Cover Price: " << book.getCoverPrice() << "  Year: " << book.getYear() << endl << endl;
    }
  }
}

void Library::findTitle(string title) const{
  for(list<Book>::const_iterator it = books.begin(); it != books.end(); it++) {
    Book book = *it;
    if(book.getTitle() == title) {
      cout << "Title: " << book.getTitle() << "  Author: " << book.getAuthor()
	   << "  Pages: " << book.getPages() << "  ISBN: " << book.getIsbn()
	   << "  Cover Price: " << book.getCoverPrice() << "  Year: " << book.getYear() << endl << endl;
    }
  }
}

void Library::printLibrary() const{
  for(list<Book>::const_iterator it = books.begin(); it != books.end(); it++){
    Book book = *it;
    cout << "Title: " << book.getTitle() << "  Author: " << book.getAuthor()
	 << "  Pages: " << book.getPages() << "  ISBN: " << book.getIsbn()
	 << "  Cover Price: " << book.getCoverPrice() << "  Year: " << book.getYear() << endl << endl;
  }
 }

 void Library::readFile(string filename){
   ifstream file;
   file.open(filename);
   
   string title, author, isbn;
   int page, year;
   float coverPrice;

   while(file >> ws && getline(file, title) && file >> ws && getline(file, author) && file >> page >> isbn >> coverPrice >> year){
     Book book(title, author, page, isbn, coverPrice, year);
     //Sorts the books alphabetically via insertSorted.
     insertSorted(book);
   }
   file.close();
}
   
void Library::insertSorted(const Book& book){
  list<Book>::iterator it = books.begin();
  while(it != books.end() && it -> getAuthor() < book.getAuthor()){ //Compares ASCI values to see if one name is higher on the alphabet than the other. 
    it++;
  }
  books.insert(it, book); //'Inserts' the book at its position.
}

void Library::writeFile(string filename) const {
  ofstream file;
  file.open(filename);

  for(list<Book>::const_iterator it = books.begin(); it != books.end(); it++){
    Book book = *it;
    file << "Title: " << book.getTitle() << endl 
	 << "Author: " << book.getAuthor() << endl 
	 << "Pages: " << book.getPages() << endl 
	 << "ISBN: " << book.getIsbn() << endl
         << "Cover Price: " << book.getCoverPrice() << endl 
	 << "Year: " << book.getYear() << endl << endl;
  }

  file.close();
}
