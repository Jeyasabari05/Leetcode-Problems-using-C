char ** fizzBuzz(int n, int* returnSize)
{
    int i;
    *returnSize = n;
    char **answer;
    char str[5];
    i = 1; 
    answer = NULL;
    answer = malloc(sizeof(*answer) * n); 
    if (!answer)
        return (answer); 
    while (i <= n)
    {
        if (i % 15 == 0)
            answer[i - 1] = strdup("FizzBuzz");
        else if (i % 3 == 0)
            answer[i - 1] = strdup("Fizz");
        else if (i % 5 == 0)
            answer[i - 1] = strdup("Buzz");
        else
        {
            sprintf(str, "%d", i); 
            answer[i - 1] = strdup(str);
        }
        i++;
    }
    return (answer);
}