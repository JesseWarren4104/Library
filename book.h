/**
 * @file book.h
 * @author Jesse Warren
 * @date 2023-11-01
 * @brief The book class.
 * 
 * Holds the data for the linked list and allows it to be easily called within the library class and functions.
 */

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book {
 public:
  
  Book(string title, string author, int pages, string isbn, float price, int year);
  /* Description
   *     Takes in a book's information and sets it to the class's variables.
   */
 
  string getTitle() const;
  /* Description
   *     Returns the current iteration's title for usage.
   */
  string getAuthor() const;
  /* Description
   *     Returns the current iteration's author for usage.
   */
  int getPages() const;
  /* Description
   *     Returns the current iteration's amount of pages for usage.
   */
  string getIsbn() const;
  /* Description
   *     Returns the current iteration's ISBN for usage.
   */
  float getCoverPrice() const;
  /* Description
   *     Returns the current iteration's cover price for usage.
   */
  int getYear() const;
  /* Description
   *     Returns the current iteration's year for usage.
   */

private:

  string title;
  string author;
  int pages;
  string isbn;
  float coverPrice;
  int year;
};

#endif
