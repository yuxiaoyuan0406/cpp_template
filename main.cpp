#include <cstdio>
#include <thread>

void left_hand()
{
    putchar('a');
}

void right_hand()
{
    putchar('m'); 
    putchar('i');
    putchar('n');
}

int main(int argc, char **argv)
{
    std::thread right_hand_thread(right_hand);
    std::thread left_hand_thread(left_hand);
    left_hand_thread.join();
    right_hand_thread.join();
   
    return 0;
}
