#include <termios.h>
#include <unistd.h>

void enableRawMode() {
    struct termios raw;
    // read current attributes into a struct
    tcgetattr(STDIN_FILENO, &raw);
    // modify the struct by hand
    raw.c_lflag &= ~(ECHO);
    // write new terminal attributes out
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
    enableRawMode();
    char c;
    // `read` will read in 1 byte from stdin into `c` until nothing left to read
    // `read` returns the number of bytes that it read, returns 0 when nothing left
    // options exit by typing 'q'
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
    return 0;
}
