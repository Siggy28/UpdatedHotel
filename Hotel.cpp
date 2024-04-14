#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

class Room {
private:
    int roomNumber;
    bool isOccupied;
    string guestName;

public:
    Room(int number) : roomNumber(number), isOccupied(false), guestName("") {}

    int getRoomNumber() const {
        return roomNumber;
    }

    bool getIsOccupied() const {
        return isOccupied;
    }

    string getGuestName() const {
        return guestName;
    }

    void bookRoom(const string& guest) {
        isOccupied = true;
        guestName = guest;
        cout << "Room " << roomNumber << " has been booked by " << guest << endl;
    }

    void checkout() {
        isOccupied = false;
        guestName = "";
        cout << "Room " << roomNumber << " has been checked out." << endl;
    }
};

class Hotel {
private:
    vector<Room> rooms;

public:
    Hotel(int numRooms) {
        for (int i = 0; i < numRooms; ++i) {
            rooms.push_back(Room(i + 1)); 
        }
    }

    void displayRooms() const {
        cout << "Room\tOccupied\tGuest" << endl;
        for (const auto& room : rooms) {
            cout << room.getRoomNumber() << "\t"
                 << (room.getIsOccupied() ? "Yes" : "No") << "\t\t"
                 << room.getGuestName() << endl;
        }
    }

    void bookRoom(int roomNumber, const string& guest) {
        if (roomNumber >= 1 && roomNumber <= rooms.size()) {
            if (!rooms[roomNumber - 1].getIsOccupied()) {
                rooms[roomNumber - 1].bookRoom(guest);
            } else {
                cout << "Room " << roomNumber << " is already occupied." << endl;
            }
        } else {
            cout << "Invalid room number." << endl;
        }
    }

    void checkoutRoom(int roomNumber) {
        if (roomNumber >= 1 && roomNumber <= rooms.size()) {
            if (rooms[roomNumber - 1].getIsOccupied()) {2
                ;rooms[roomNumber - 1].checkout();
            } else {
                cout << "Room " << roomNumber << " is not occupied." << endl;
            }
        } else {
            cout << "Invalid room number." << endl;
        }
    }
};

int main() {
    Hotel hotel(10); 
    int choice;
    do {
        cout << "\nHotel Management System\n";
        cout << "1. Display Rooms\n";
        cout << "2. Book Room\n";
        cout << "3. Checkout Room\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (choice < 1 || choice > 4) {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                hotel.displayRooms();
                break;
            case 2: {
                int roomNumber;
                string guestName;
                cout << "Enter room number: ";
                cin >> roomNumber;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number." << endl;
                    continue;
                }
                cout << "Enter guest name: ";
                cin >> guestName;
                hotel.bookRoom(roomNumber, guestName);
                break;
            }
            case 3: {
                int roomNumber;
                cout << "Enter room number: ";
                cin >> roomNumber;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number." << endl;
                    continue;
                }
                hotel.checkoutRoom(roomNumber);
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}