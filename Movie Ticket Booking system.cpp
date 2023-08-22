#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 6;
const double TICKET_PRICE = 10.0;

// Define a typedef for the nested vector type
typedef vector<bool> SeatRow;

class MovieTicketBookingSystem {
private:
    vector<SeatRow> seats;

public:
    MovieTicketBookingSystem() {
        seats = vector<SeatRow>(NUM_ROWS, SeatRow(NUM_COLS, true));
    }

    

    void displaySeating() {
        cout << "Current Seating:" << endl;
        for (int row = 0; row < NUM_ROWS; ++row) {
            for (int col = 0; col < NUM_COLS; ++col) {
                cout << (seats[row][col] ? "O" : "X") << " ";
            }
            cout << endl;
        }
    }

    bool isSeatAvailable(int row, int col) {
        return seats[row][col];
    }

    bool bookSeat(int row, int col) {
        if (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS && seats[row][col]) {
            seats[row][col] = false;
            return true;
        }
        return false;
    }

    double calculateTotalCost(int numTickets) {
        return numTickets * TICKET_PRICE;
    }
};

int main() {
    MovieTicketBookingSystem bookingSystem;

    cout << "Welcome to Movie Ticket Booking System!" << endl;
    cout << "--------------------------------------" << endl;

    while (true) {
        int choice;
        cout << "1. View Seating" << endl;
        cout << "2. Book Tickets" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            bookingSystem.displaySeating();
        } else if (choice == 2) {
            int row, col, numTickets;
            cout << "Enter row and column (starting from 0) for the seat: ";
            cin >> row >> col;

            if (!bookingSystem.isSeatAvailable(row, col)) {
                cout << "Seat is already booked or invalid." << endl;
                continue;
            }

            cout << "Enter the number of tickets: ";
            cin >> numTickets;

            if (bookingSystem.bookSeat(row, col)) {
                double totalCost = bookingSystem.calculateTotalCost(numTickets);
                cout << "Tickets booked successfully. Total cost: $" << totalCost << endl;
            } else {
                cout << "Invalid seat or booking failed." << endl;
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}

