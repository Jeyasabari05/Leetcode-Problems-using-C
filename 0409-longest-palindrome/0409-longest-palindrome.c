int longestPalindrome(char* s) {
    int hash[52] = {0}; 
    int len = strlen(s); 
    int sum = 0; 
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            hash[s[i] - 'A']++;
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            hash[s[i] - 'a' + 26]++; 
        }
    }

    int flag = 0;
    for (int i = 0; i < 52; i++) {
        if (hash[i] % 2 == 0) {
            sum += hash[i]; 
        }
        if (hash[i] % 2 == 1) {
            sum += hash[i] - 1;
            flag = 1;  
        }
    }
    return sum + flag;
}