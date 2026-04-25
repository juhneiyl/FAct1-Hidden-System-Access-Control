/****************************************************************
* Group Number: #4
* Group Members: Janelle Rhian Barrera, Humphrey Barcon, Koby Bongat, Alexander Paul Jimenez, John Paul Macario
* FSw1 - Player Secret Location System
****************************************************************/

#include <iostream>
using namespace std;

class Player {
private:
    int x, y;             
    int secretX, secretY;  

public:
    Player() {
        x = 0;
        y = 0;
        secretX = 99;
        secretY = 88;
    }

    void setLocation(int a, int b) {
        x = a;
        y = b;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    // Friend function declaration
    friend void showSecretLocation(Player p);
};

// Friend function 
void showSecretLocation(Player p) {
    cout << "Secret location: " << p.secretX << " " << p.secretY << endl;
}

int main() {
    Player player;

    player.setLocation(10, 20);

    cout << "Player location: "
        << player.getX() << " "
        << player.getY() << endl;

    // Display secret location using friend function
    showSecretLocation(player);

    return 0;
}
