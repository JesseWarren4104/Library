/**
 * @file book.cpp
 * @author Jesse Warren
 * @date 2023-11-01
 * @brief Holds book class functions.
 * 
 * Holds the functions that are defined within the library class, and also sets the variables up within it. 
 */

#include <iostream>
#include "book.h"

Book::Book(string title, string author, int pages, string isbn, float coverPrice, int year)
  : title(title), author(author), pages(pages), isbn(isbn), coverPrice(coverPrice), year(year) {}

string Book::getTitle() const{
  return title;
}

string Book::getAuthor() const{
  return author;
}

int Book::getPages() const{
  return pages;
}

string Book::getIsbn() const{
  return isbn;
}

float Book::getCoverPrice() const{
  return coverPrice;
}

int Book::getYear() const{
  return year;
}
