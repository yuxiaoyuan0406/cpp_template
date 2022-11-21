#include <cstdio>
#include <thread>

// void left_hand()
// {
//     putchar('a');
// }

// void right_hand()
// {
//     putchar('m');
//     putchar('i');
//     putchar('n');
// }

void hand(char *s)
{
    for (; *s; s++) {
        putchar(*s);
    }
}

int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "too less arguments\n");
        return 0;
    }
    std::thread right_hand_thread([argv]() {
        hand(argv[1]);
    });
    std::thread left_hand_thread([argv]() {
        hand(argv[2]);
    });
    left_hand_thread.join();
    right_hand_thread.join();

    return 0;
}
