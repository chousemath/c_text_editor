#include <unistd.h>

int main() {
    char c;
    // `read` will read in 1 byte from stdin into `c` until nothing left to read
    // `read` returns the number of bytes that it read, returns 0 when nothing left
    // options exit by typing 'q'
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
    return 0;
}
