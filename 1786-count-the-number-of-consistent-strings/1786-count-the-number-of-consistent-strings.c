int countConsistentStrings(char * allowed, char ** words, int wordsSize) {
    char a[26] = {0}; 
    while (*allowed) a[(unsigned char)*allowed++ - 'a'] = 1;
    int b = 0;  
    uint16_t c = 0; 
    while (c < wordsSize) {
        int d = 0; 
        int e = 1;        
        while (words[c][d] && e) {
            e = a[words[c][d] - 'a'];  
            d++;
        }
        if (e) b++;  
        c++;
    }
    return b;
}