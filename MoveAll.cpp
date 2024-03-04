/*
    Implimentation of MoveAll class. Stores books in a vector of Books called "catalog", 
    and allows you to move Books from "catalog" to another vector of Books called "cart"
*/

#include "MoveAll.hpp"
#include "Book.hpp"

// Moves all Books in "source" with the specified keyword to "dest".
// A Book is moved if any of its keywords match the one specified in this function.
// Use iterators whenever appropriate.
// Hint: you need a const iterator for a const vector, but this will be automatically handled using "auto".


/*
  @param:   String representing a keyword associated with a book
  @param:   Vector of Books passed by reference. Our source will be the book catalog
  @param:   Vector of Books passed by reference. Our desintation is the cart

  @post:    Based on selected keyword(s), moveAll() transfers Books from the catalog vector to
            the cart vector and delete it from catalog. Records the time function takes to perform this action
            along with tallying the number of books invovled in the transfer.
*/
void moveAll (const std::string keyword, std::vector<Book> &source, std::vector<Book> &dest){  
  const auto t1_start = std::chrono::steady_clock::now();
  int books_moved=0; // counts books moved
  // DO NOT ALTER ABOVE HERE


    for (auto i = source.begin(); i != source.end();) {
        
        const auto& keywords = i->getKeywords();
        if (std::find(keywords.begin(), keywords.end(), keyword) != keywords.end()) {
            
            dest.push_back(std::move(*i));
            i = source.erase(i); 
            ++books_moved;
        } else {
            ++i;
        }
    }


  // DO NOT ALTER BELOW HERE
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "Moved " << books_moved << " books in " << t1 << " microseconds." << std::endl;
}
