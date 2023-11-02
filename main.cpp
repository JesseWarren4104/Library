/**
 * @file main.cpp
 * @author Jesse Warren
 * @date 2023-11-01
 * @brief The main function.
 * 
 * The interactive menu. Takes users inputs and throws them into the library class functions.
 */

#include <iostream>
#include "library.h"
#include "book.h"
#include <string>
#include <fstream>

using namespace std;

int main() {
  Library library;
  int answer;
  
  while(answer != 8){
    cout << "\nWelcome to the library. Use the following options to search for a book, or alter the library: " << endl
	 << "1. Read in the library from a file" << endl
	 << "2. Write the library to a file" << endl
	 << "3. Find a book by their author" << endl
	 << "4. Find books by their title" << endl
	 << "5. Print the library" << endl
	 << "6: Add a book" << endl
	 << "7. Delete a book" << endl
	 << "8. Quit the program" << endl
	 << "Answer: ";
    cin >> answer; cout << endl;
    
    if(answer == 1){
      string filename;
      cout << "\nEnter filename: ";
      cin >> filename;
      library.readFile(filename);
      cout << "\nLibrary loaded." << endl;
    }
    else if(answer == 2){
      string filename;
      cout << "Please enter the filename: ";
      cin >> filename;
      library.writeFile(filename);
    }
    else if(answer == 3){
      string author;
      cout << "\nEnter author: ";
      cin.ignore();
      getline(cin, author);
      library.findAuthor(author);
    }
    else if(answer == 4){
      string title;
      cout << "Enter the book title: ";
      cin.ignore();
      getline(cin, title);
      library.findTitle(title);
    }
    else if(answer == 5){
      library.printLibrary();
    }
    else if(answer == 6){
      string title, author, isbn;
      int pages, year;
      float coverprice;

      cout << "Enter the book title: ";
      cin.ignore();
      getline(cin, title);
      cout << "Enter the author's name: ";
      getline(cin, author);
      cout << "Enter the number of pages: ";
      cin >> pages;
      cout << "Enter the ISBN: ";
      cin >> isbn;
      cout << "Enter the cover price: ";
      cin >> coverprice;
      cout << "Enter the publication year: ";
      cin >> year;

      Book newBook(title, author, pages, isbn, year, coverprice);
      library.addBook(newBook);
    }
    else if(answer == 7){
      string title, author;
      cout << "\nEnter the book title: ";
      cin.ignore();
      getline(cin, title);
      cout << "Enter the author's name: ";
      getline(cin, author);
      library.deleteBook(author, title);
    }
    else if(answer == 8 or answer != 1 or 2 or 3 or 4 or 5 or 6 or 7 or 8)
      break;
  }
  return 0;
}
