int firstUniqChar(char* s) {
    int ans = 0;
    int Letters[26] = {0};      //'a' -> Letters[0], 'b' -> Letters[1], ......, 'z' -> Letters[25]
    for(int i = 0; i < strlen(s); i++){
        Letters[s[i] - 'a']++;
        if(Letters[s[ans] - 'a'] > 1){
            ans++; 
            while(ans <= i){
                if(Letters[s[ans] - 'a'] == 1)
                    break;
                else ans++;
            }
        }
    }
    if(ans == strlen(s))  
        return -1;
    else
        return ans;
}