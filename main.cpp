// This program demonstrates the use of Windows functions
// for positioning the cursor.  It displays a series of nested
// boxes near the center of the screen.

#include <iostream>
#include <windows.h>        // Needed to set cursor positions & call Sleep
using namespace std;

void placeCursor(HANDLE, int, int);     // Function prototypes
void printStars(int);

int main()
{
    const int   midRow = 12,
                midCol = 40,
                numBoxes = 3;
    int width, startRow, endRow;

    // Get the handle to standard output device (the console)
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

    // Each loop prints on box
    for (int box = 1, height = 1; box <= numBoxes; box++, height+=2)
    {
        startRow = midRow - box;
        endRow = midRow + box;
        width = box * 5 + (box + 1)%2; // Adds 1 if box*5 is an even number

        // Draw box top
        placeCursor(screen, startRow, midCol - width/2);
        printStars(width);

        // Print box sides
    }
}