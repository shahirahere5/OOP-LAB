#include <iostream>
#include <string>
using namespace std;

struct Book{
    string title;
    string author;
    int year;
};

int main(){
    int n;
    cout << "Enter the number of books: ";
    cin >> n;

    Book *books = new Book[n];

    for(int i = 0; i < n; i++){
        cout << "Enter title, author, and year of book " << i+1 << ": ";
        cin.ignore();
        getline(cin, books[i].title);
        getline(cin, books[i].author);
        cin >> books[i].year;
        cin.ignore();
    }

    int year;
    cout << "Enter the year to display the books published after: ";
    cin >> year;
    cout << "\nBooks published after " << year << ":\n";
    for(int i = 0; i < n; i++){
        if(books[i].year > year){
            cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Year: " << books[i].year << endl;
        }
    }

    delete[] books;
    return 0;
}