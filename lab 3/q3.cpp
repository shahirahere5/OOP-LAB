#include <iostream>
using namespace std;

class Library{
    private:
    string bookList[10];
    bool borrowedBooks[10];
    int totalBooks;

    public:
    Library(){
        totalBooks = 0;
    }
    
    void addBook(string bookName){
        if(totalBooks < 10){
            bookList[totalBooks] = bookName;
            borrowedBooks[totalBooks] = false;
            totalBooks++;
            cout << "Book added successfully." << endl;
        }else{
            cout << "Cannot add more books. Library is full." << endl;
        }
    }
    
    void borrowBook(string borrowerName){
        for(int i = 0; i < totalBooks; i++){
            if(!borrowedBooks[i]){
                borrowedBooks[i] = true;
                cout << "Book borrowed by " << borrowerName << ". Available copies: " << (totalBooks - i - 1) << endl;
                return;
            }
        }
        cout << "No available books." << endl;
    }
    void returnBook(string name){
        for(int i = 0; i < totalBooks; i++){
            if(bookList[i] == name && borrowedBooks[i] == true){
                borrowedBooks[i] = false;
                cout << "Book returned successfully." << endl;
                return;
            }
        }
        cout << "Book not found in the library." << endl;
    }
    void displayBooks(){
        cout << "Available books in the library:" << endl;
        for(int i = 0; i < totalBooks; i++){
            if(!borrowedBooks[i]){
                cout << bookList[i] << endl;
            }
        }
    }
    
};

int main(){
    Library myLibrary;
    
    myLibrary.addBook("To Kill a Mockingbird");
    myLibrary.addBook("1984");
    myLibrary.addBook("The Great Gatsby");
    
    myLibrary.displayBooks();
    
    myLibrary.borrowBook("John Doe");
    myLibrary.borrowBook("Jane Smith");
    
    myLibrary.displayBooks();
    
    myLibrary.returnBook("To Kill a Mockingbird");
    
    myLibrary.displayBooks();
    
    return 0;
}