int removeElement(int* a, int n, int val) {
    int c=0,t;
    for(int i=0;i<n;i++){
        if(a[i]==val){
            c++;
        }
        else{a[i-c]=a[i];}}
        return (n-c);
}