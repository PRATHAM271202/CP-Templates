//Sieve Of Erathosthanes for Primes O(n log log n)
const int N = 10000;
#define SIEVE
int primes[N];
vector<int> pr;
void sieve(){
    for(int i=2;i<N;i++){
        if(primes[i]==0){
            pr.pb(i);
            for(int j=i*i;j<N;j+=i){
                primes[j]=1;
            }
        }
        primes[i]^=1;
    }
}

//GCD  O(max(a,b)) Considering that the b>a (inbuild function : __gcd(a,b))
int gcd(int a,int b){
    if(a==0) return b;
    return gcd(b%a,a);
}

//binary exponentiation (finding the power) O(log b)
int pw(int a,int b,int m){
    if(b==0) return 1;
    if(b%2 ==0){
        int t = pw(a,b/2,m);
        return (1ll*t*t) % m;
    }
    else {
        int t = pw(a,(b-1)/2,m);
        t=(1ll*t*t) %m;
        return (1ll*a*t)%m;
    }
   
}

//div modulas Only valid if m is prime  O(log m) and a%b==0
int div_modulas(int a,int b,int m){
    return ((a%m)*pw(b,m-2,m))%m;
}

//combinatorics for ncr TC : O(1) ,For fact O(n),For Invfact O(n+logn)
const int N=100005;
int fact[N],invfact[N];
void init(){
    int p =MOD1;
    fact[0]=1;
    int i;
    for(i=1;i<N;i++){
        fact[i]=1ll*i*fact[i-1]%p;
    }
    i--;
    invfact[i]=pw(fact[i],p-2,p);
    for(i--;i>=0;i--){
        invfact[i]=1ll*invfact[i+1]*(i+1)%p;
    }
}
int ncr(int n,int r){
      if(r>n || n<0 || r<0) return 0;
     return 1ll*fact[n]*invfact[r]%MOD1*invfact[n-r]%MOD1;
}
