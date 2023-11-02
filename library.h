/**
 * @file library.h
 * @author Jesse Warren
 * @date 2023-11-01
 * @brief The library class.
 * 
 * The library class and the functions definitions, and linked list that is within library.cpp.
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <list>
#include "book.h"

using namespace std;

class Library {
public:
  Library();
  /* Description
   *    Constructor that initializes a data variable as a linked list. 
   */
  void readFile(string filename);
  /* Description
   *     Reads in data from a file and puts them into the linked list.
   */
  void addBook(Book book);
  /* Description
   *     Adds a user-inputted book into the linked list.
   */
  void deleteBook(string author, string title);
  /* Description
   *     Deletes a book based on a user-inputted author and title.
   */
  void findAuthor(string author)const;
  /* Description
   *     Provides information on books that were made by the user inputted author.
   */
  void findTitle(string title)const;
  /* Description
   *     Provides information on books with the given title that the user inputs.
   */
  void printLibrary()const;
  /* Description
   *     Prints the contents of the linked list library.
   */
  void insertSorted(const Book& book);
  /* Description
   *     Sorts the linked list alphabetically
   */
  void writeFile(string filename) const;
  /* Description
   *     Writes the linked list to a requested filename.
   */
  
private:
  list<Book> books; 
};

#endif
  
