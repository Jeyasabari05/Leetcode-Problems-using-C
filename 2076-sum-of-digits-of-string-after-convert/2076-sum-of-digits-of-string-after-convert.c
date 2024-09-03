int getLucky(char* s, int k) {
    int sum = 0;
    int n = strlen(s);
    for(int i=0;i<n;i++){
            int num =(s[i]-'a'+1);
            while(num>0){
                sum+=num%10;
                num/=10;
            }
    }
    while(--k>0){
        int total = 0;
         while(sum>0){
            total += sum%10;
            sum/=10;
        }
         sum = total;
    }
    return sum;
}