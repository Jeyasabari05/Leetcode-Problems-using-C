bool isPalindrome(int x){long long int rev=0;
if(x < 0)
{return false;}
int n = x;
while(x){
    rev =rev*10 + x%10;
    x /= 10;
}return(n==rev)?true:false;

}