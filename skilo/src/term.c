#include <termios.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "term.h"

static struct termios orig;

static void die(const char* s) {
    cleanup();
    perror(s);
    exit(1);
}

void enableRawMode() {
    if (tcgetattr(STDIN_FILENO, &orig) == -1)
        die("tcgetattr");

    struct termios raw = orig;
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_cc[VMIN] = 0;  // min bytes read() needs to return
    raw.c_cc[VTIME] = 1; // max wait time before read() returns, 10th of sec

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
        die("tcsetattr");
}

void disableRawMode() {
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig) == -1)
        die("tcsetattr");
}

void cleanup() {
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);
}
