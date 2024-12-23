/**
 * Project One: Chada Tech Clocks
 * CS 210
 * Alejandro Ramirez
 * Nov. 17, 2024
 **/

#include <iostream>
#include <iomanip>

class Clock {
    protected:
        int hrs;
        int min;
        int sec;

    public:
        Clock(int hours = 0, int minutes, int seconds) : hrs(hours), min(minutes), sec(seconds) {}

        /* 
         * This method is for setting the limit of the clock for 24 hours
         */
        void addHr(int hours) {
            hrs = (hrs + hours) % 24;
        }

        /* 
         * This method increments the hour
         */
        void addMin(int minutes){
            min = (min+minutes) % 60;
            if (min <  0) {
                addHr(min / 60 - 1);
                min = 60 + (min % 60);
            }
            else {
                addHr(min/60);
            }
        }
        
        /*
         * This method increments the seconds
         */
        void addSec(int seconds) {
            sec = (sec+seconds) % 60;
            if (sec < 0) {
            addMin(sec / 60 - 1);
            sec = 60 + (sec % 60);
        } else {
            addMin(sec / 60);
        }
        }

        /*
         * This method displays the 24 hour clock
         */
        void display24Hour() const {
            std::cout << std::setfill('0') << std::setw(2) << hrs << ':'
                << std::setw(2) << min << ':'
                << std::setw(2) << sec << std::endl;
        }        
        
        /* 
         * This method displays the 12 hour clock
         */
        void display12Hour() const {
            int display = (hrs % 12 == 0) ? 12: hrs % 12;
            std::string period = (hrs >= 12) ? 'P.M.' : 'A.M.';
            std::cout << std::setfill('0') << std::setw(2) << display << ":"
                << std::setw(2) << min << ':'
                << std::setw(2) << sec << ' ' << period << std::endl;
        }
};

/*
 * This method displays both the 24 hour and 12 hour clocks
 */
void displayClocks(const Clock& clock) {
    std::cout << "12-Hour Clock\t24-Hour Clock" << std::endl;
    clock.display24Hour();
    clock.display12Hour();
    std::cout << std::endl;
}

/*
 * This is the main where the user interacts with the clock display
 */
int main() {
    /*
     * This makes the clock start at 12:00:00
     */
    Clock clock(12, 0, 0); 

    while (true) {
        displayClocks(clock);

        std::cout << "Add One Hour (Enter 1)" << std::endl;
        std::cout << "Add One Minute (Enter 2)" << std::endl;
        std::cout << "Add One Second (Enter 3)" << std::endl;
        std::cout << "To Exit Enter the number 4" << std::endl;
        std::cout << "Please enter your choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 4) {
            break;
        }

        /*
         * This switch case updates the clock with the user's input
         */
        switch (choice) {
            int amount;
        
            case 1:
                std::cout << "Enter the hour: ";
                std::cin >> amount;
                clock.addHr(amount);
                break;
        
            case 2:
                std::cout << "Enter the minute(s): ";
                std::cin >> amount;
                clock.addMin(amount);
                break;
        
            case 3:
                std::cout << "Enter second(s): ";
                std::cin >> amount;
                clock.addSec(amount);
                break;

            default:
                std::cout << "Sorry, this option is invalid!!!" << std::endl;
                break;
        }

    }

    return 0;
}