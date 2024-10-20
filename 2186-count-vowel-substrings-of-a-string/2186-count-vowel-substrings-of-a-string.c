bool isVowel(char c){
    return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
}

int countVowelSubstrings(char* word) {
    short i;
    for(i = 0; i < 5; i++)
        if(!word[i]) return 0;

    short j, distinctVow, res = 0;
    for(i = 0; word[i + 4]; i++){
        bool mark[21] = {0};
        distinctVow = 0;

        for(j = 0; word[i + j] && isVowel(word[i + j]); j++){
            distinctVow += !mark[word[i + j] - 97];
            mark[word[i + j] - 97] = 1;
            res += distinctVow == 5;
        }
    }

    return res;
}