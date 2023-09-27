#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> // Used for sleep function (Unix-like systems)

// Function to simulate a button press (returns true if the button is pressed).
bool isButtonPressed() {
    // In a real embedded system, you would read the actual hardware input here.
    // For the sake of this example, we use a simple counter to simulate a button press.
    static int counter = 0;
    return (counter++ % 5) == 0; // Simulate a button press every 5 iterations.
}

int main() {
    while (1) { // Infinite loop for polling
        if (isButtonPressed()) {
            printf("Button Pressed!\n");
            // Handle the button press action here.
            // In a real system, you would perform the necessary tasks in response to the button press.
        }

        // Sleep for a short period to avoid continuous polling.
        // In practice, you might use more efficient mechanisms to control the polling rate.
        usleep(100000); // Sleep for 100 milliseconds (Unix-like systems)
    }

    return 0;
}
