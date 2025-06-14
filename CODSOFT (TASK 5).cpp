#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool available = true;
    string borrowerID = "";
    time_t borrowDate = 0;
};

struct Borrower {
    string name;
    string id;
};

vector<Book> books;
vector<Borrower> borrowers;

// Utility: Get current date
time_t getCurrentDate() {
    return time(0);
}

// Add a book
void addBook() {
    Book b;
    cout << "Enter Book Title: ";
    cin.ignore(); getline(cin, b.title);
    cout << "Enter Author: ";
    getline(cin, b.author);
    cout << "Enter ISBN: ";
    getline(cin, b.isbn);
    books.push_back(b);
    cout << "Book added successfully.\n";
}

// Add a borrower
void addBorrower() {
    Borrower br;
    cout << "Enter Borrower Name: ";
    cin.ignore(); getline(cin, br.name);
    cout << "Enter Borrower ID: ";
    getline(cin, br.id);
    borrowers.push_back(br);
    cout << "Borrower added successfully.\n";
}

// Search for books
void searchBooks() {
    string keyword;
    int choice;
    cout << "Search by:\n1. Title\n2. Author\n3. ISBN\nChoose: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter search keyword: ";
    getline(cin, keyword);

    bool found = false;
    for (const auto& b : books) {
        if ((choice == 1 && b.title.find(keyword) != string::npos) ||
            (choice == 2 && b.author.find(keyword) != string::npos) ||
            (choice == 3 && b.isbn.find(keyword) != string::npos)) {
            cout << "\nTitle: " << b.title << "\nAuthor: " << b.author
                 << "\nISBN: " << b.isbn
                 << "\nAvailable: " << (b.available ? "Yes" : "No") << "\n";
            found = true;
        }
    }
    if (!found) cout << "No matching books found.\n";
}

// Checkout a book
void checkoutBook() {
    string isbn, borrowerID;
    cout << "Enter ISBN of book to checkout: ";
    cin.ignore(); getline(cin, isbn);

    for (auto& b : books) {
        if (b.isbn == isbn) {
            if (!b.available) {
                cout << "Book already checked out.\n";
                return;
            }
            cout << "Enter Borrower ID: ";
            getline(cin, borrowerID);

            // Assign book
            b.available = false;
            b.borrowerID = borrowerID;
            b.borrowDate = getCurrentDate();

            cout << "Book checked out successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// Return a book
void returnBook() {
    string isbn;
    cout << "Enter ISBN of book to return: ";
    cin.ignore(); getline(cin, isbn);

    for (auto& b : books) {
        if (b.isbn == isbn && !b.available) {
            // Fine calculation
            time_t now = getCurrentDate();
            double seconds = difftime(now, b.borrowDate);
            int days = seconds / (60 * 60 * 24);
            int overdue = days - 14;
            if (overdue > 0) {
                cout << "Book is overdue by " << overdue << " days.\n";
                cout << "Fine: ₹" << overdue * 2 << "\n";
            } else {
                cout << "Book returned on time. No fine.\n";
            }

            b.available = true;
            b.borrowerID = "";
            b.borrowDate = 0;
            cout << "Book returned successfully.\n";
            return;
        }
    }
    cout << "Book not found or already available.\n";
}

// View all books
void viewAllBooks() {
    cout << "\n--- Book List ---\n";
    for (const auto& b : books) {
        cout << "Title: " << b.title
             << "\nAuthor: " << b.author
             << "\nISBN: " << b.isbn
             << "\nStatus: " << (b.available ? "Available" : "Checked out")
             << "\n----------------------\n";
    }
}

// Menu UI
void showMenu() {
    cout << "\n=== LIBRARY MANAGEMENT SYSTEM ===\n";
    cout << "1. Add Book\n";
    cout << "2. Add Borrower\n";
    cout << "3. Search Book\n";
    cout << "4. View All Books\n";
    cout << "5. Checkout Book\n";
    cout << "6. Return Book\n";
    cout << "7. Exit\n";
    cout << "Choose option: ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: addBorrower(); break;
            case 3: searchBooks(); break;
            case 4: viewAllBooks(); break;
            case 5: checkoutBook(); break;
            case 6: returnBook(); break;
            case 7: cout << "Exiting... Thank you!\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
