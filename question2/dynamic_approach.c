unsigned int dynamicProgrammingFibonacci(unsigned int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    unsigned int* fibArray = (unsigned int*)malloc((n + 1) * sizeof(unsigned int));
    fibArray[0] = 0;
    fibArray[1] = 1;
    fibArray[2] = 2;

    for (unsigned int i = 3; i <= n; i++)
        fibArray[i] = fibArray[i - 3] + fibArray[i - 2];

    unsigned int result = fibArray[n];
    free(fibArray);
    return result;
}
