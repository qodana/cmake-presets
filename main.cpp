#include <iostream>

#ifdef USE_ALT_LOGIC
int calculate() {
    std::cout << "Alt logic\n";
    int* ptr = nullptr;
    return *ptr; // Nullptr dereference
}
#else
int calculate() {
    std::cout << "Default logic\n";
#ifdef BUGS
    int* danglingPointer = new int(10);
    delete danglingPointer;
    return *danglingPointer;
#else
    return 42;
#endif
}
#endif

#ifdef EXTRA_ANALYSIS
void foo() {
    int buffer[100];

    for (int i = 0; i <= 100; i ++)
        buffer[i] = 0; // buffer overflow when i is equal to 100
}
#endif

int main() {
    std::cout << "Result: " << calculate() << std::endl;
    return 0;
}