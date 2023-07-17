unsigned int recursiveFibonacci(unsigned int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return recursiveFibonacci(n - 3) + recursiveFibonacci(n - 2);
}
