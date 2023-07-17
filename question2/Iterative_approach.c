unsigned int iterativeFibonacci(unsigned int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    unsigned int prevPrev = 0;
    unsigned int prev = 1;
    unsigned int current = 2;

    for (unsigned int i = 3; i <= n; i++) {
        unsigned int temp = current;
        current += prev;
        prevPrev = prev;
        prev = temp;
    }

    return current;
}
