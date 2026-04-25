/****************************************************************
 * Group Number: [Your Group Number]
 * Group Members: Janelle Rhian Barrera, Humphrey Barcon, Koby Bongat, Alexander Paul Jimenez, John Paul Macario
 * FAct1 - Hidden System Access Control
 ****************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Owner; // kay owner

class HiddenBox { // si owner lang pwede d2
private:
    int gold;
    int silver;
    int bronze;

public:
    HiddenBox(int g, int s, int b) : gold(g), silver(s), bronze(b) {}

    // si owner lang pwede may access sa private members
    friend class Owner;
};

class Message { //normal, secret message
private:
    string secretMessage;

public:
    static string normalMessage; //lahat makakaaccess sa normal message
    Message(const string& secret) : secretMessage(secret) {}

    friend class Owner; // si owner lang makakakita ng secret message
};

string Message::normalMessage = ""; //static member initialization

class Owner {
public:
    void displayGold(const HiddenBox& box) const {
        cout << "Gold: " << box.gold << endl;
    }

    void displaySecretMessage(const Message& msg) const {
        cout << "Secret Message: " << msg.secretMessage << endl;
    }

    void displayNormalMessage() const {
        cout << "Normal Message: " << Message::normalMessage << endl;
    }
};

int main() {
    HiddenBox box(10, 5, 3);

    Owner owner;

    owner.displayGold(box);

    Message msg("Hello Owner");
    Message::normalMessage = "Hello Everyone";

    owner.displaySecretMessage(msg);
    owner.displayNormalMessage();

    return 0;
}
