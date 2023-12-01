#include <iostream>
#include <thread>
#include <chrono>
#include <curses.h>

// Globale Variablen für die Eingaben
int inputLSU = 0;
int inputLSD = 0;
int inputT = 0;

void getInput() {
    std::cout << "Set Inputs\n";
    std::cout << "General Input (0 or 1): ";
    std::cin >> inputT;
    std::cout << "LSU Input (0 or 1): ";
    std::cin >> inputLSU;
    std::cout << "LSD Input (0 or 1): ";
    std::cin >> inputLSD;

}

typedef enum {
    DB_STATE_OFF = 0,
    DB_STATE_UP = 1,
    DB_STATE_DOWN = 2,
    DB_STATE_MAX
} DebounceState_t;

DebounceState_t state = DB_STATE_OFF;

void stateMachine() {
    switch (state) {
        case DB_STATE_OFF:
            if ((1==inputLSU) && (1==inputT)) {
                state = DB_STATE_UP;
            } else if ((1==inputLSD) && (1==inputT)) {
                state = DB_STATE_DOWN;
            }
            break;

        case DB_STATE_UP:
            if (1==inputT) {
                state = DB_STATE_DOWN;
            } else if (1==inputLSU) {
                state = DB_STATE_OFF;
            }
            break;

        case DB_STATE_DOWN:
            if (1==inputT) {
                state = DB_STATE_UP;
            } else if (1==inputLSD) {
                state = DB_STATE_OFF;
            }
            break;

        default:
            state = DB_STATE_OFF;
            break;
    }
}

int main(void) {
   

    while (1) {
        stateMachine();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    return 0;
    }
}
