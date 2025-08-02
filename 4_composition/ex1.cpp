#include <iostream>
using namespace std;
// how to represent composition relation in system design in code C++. take example of chair(wheel,seat, arms)
// Component 1: Wheel
class Wheel {
public:
    Wheel() {
        cout << "Wheel created." << endl;
    }
    ~Wheel() {
        cout << "Wheel destroyed." << endl;
    }
};

// Component 2: Seat
class Seat {
public:
    Seat() {
        cout << "Seat created." << endl;
    }
    ~Seat() {
        cout << "Seat destroyed." << endl;
    }
};

// Component 3: Arm
class Arm {
public:
    Arm() {
        cout << "Arm created." << endl;
    }
    ~Arm() {
        cout << "Arm destroyed." << endl;
    }
};

// Composite class: Chair
class Chair {
private:
    Wheel wheels[4];  // Chair has 4 wheels
    Seat seat;        // Chair has 1 seat
    Arm arms[2];      // Chair has 2 arms

public:
    Chair() {
        cout << "Chair assembled." << endl;
    }

    ~Chair() {
        cout << "Chair destroyed." << endl;
    }
};

int main() {
    Chair c;  // Creating a chair (composition)

    return 0; // When main ends, all parts are automatically destroyed
}
