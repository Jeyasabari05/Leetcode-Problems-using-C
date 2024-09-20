char* shortestPalindrome(char* s) {
    int d = strlen(s); 
    int e = d - 1; 
    int f = 0;
    int g = d - 1; 
    char* h = (char *)malloc((2 * d + 1) * sizeof(char));
    h[0] = '\0'; 

    while (f < g) {
        if (s[f] == s[g]) {
            f++; 
            g--;
        } else {
            int i = strlen(h); 
            h[i] = s[e]; 
            h[i + 1] = '\0'; 
            e--; 
            f = 0; 
            g = e; 
            if (g == 0) {
                break; 
            }
        }
    }   
    strcat(h, s); 
    return h; 
}
