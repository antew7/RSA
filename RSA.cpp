#include<bits/stdc++.h>
using namespace std;

int modular(int base, unsigned int exp, unsigned int mod)
{
    int x = 1;
    int i;
    int power = base % mod;

    for (i = 0; i < sizeof(int) * 8; i++) {
        int least_sig_bit = 0x00000001 & (exp >> i);
        if (least_sig_bit)
            x = (x * power) % mod;
        power = (power * power) % mod;
    }

    return x;
}

int modInverse(int a, int m) 
{ 
    int m0 = m; 
    int y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
       
        int q = a / m; 
        int t = m; 
  
       
        m = a % m, a = t; 
        t = y; 
  
       
        y = x - q * y; 
        x = t; 
    } 
  
    
    if (x < 0) 
       x += m0; 
  
    return x; 
} 


int gcd(int a, int b)  
 {  
   
    if (a == 0 || b == 0)  
        return 0;  
   
       
    if (a == b)  
        return a;  
   
   
    if (a > b)  
        return gcd(a-b, b);  
    return gcd(a, b-a);  
 } 
  
   

  int lcm(int a, int b)  
 {  
    return (a*b)/gcd(a, b);  
 }  


int isPrime(int n){
  int flag = 1;
  for(int i=2;i<=sqrt(n);i++)
  {
      if(n%i==0)
      {
          flag = 0;
          return flag;
      }
  }
  return flag;
}

int main(){
    int message;
    char m;
    cout<<"enter the message to be encrypted: ";
    cin>>m;
    message = (int)m;
    cout<<"The corresponding ASCII value: "<<message<<endl;
    int p,q;
    int random;
    srand (time(NULL));
    int i=0;
    int a[2];
    generate:
    while(i<2){
        random = rand() % 40 + 3;
        if(isPrime(random)){
            a[i]=random;
            i++;
        }
      
    }
    i=0;
    p=a[0];
    q=a[1];
    if(p==q){
        goto generate;
    }

    cout<<"The two random prime numbers are: "<<p<<" and "<<q<<endl;
    int n;
    n = p*q;
    int phi = (p-1)*(q-1);
    int lambda = lcm(p-1,q-1);
    int e;
    vector<int> tot;
    for(int i=3;i<lambda;i++)
    {
        
        if(gcd(i,lambda) == 1){
            tot.push_back(i);
            
        }
    }
    int size = tot.size();
    int ran = rand() % size;
    e = tot[ran];
   
    cout<<"The modulus is: "<<n<<endl;
    cout<<"The phi(n) is: "<<phi<<endl;
    cout<<"The lambda(n) is:"<<lambda<<endl;
    cout<<"The toitient is: "<<e<<endl;
    cout<<"The public key is: ("<<n<<","<<e<<")"<<endl;
    long long int encrypt;
    encrypt = modular(message,e,n);
    cout<<"The Encrypted text is: "<<(char)encrypt<<endl;
    cout<<"The Encrypted text in ASCII value is: "<<encrypt<<endl;
    long long int d = modInverse(e,lambda);
    if(d==e){
        cout<<endl<<endl<<"aborting......"<<endl<<endl<<"Restarting the process"<<endl<<endl;
        goto generate;
    }
    cout<<"The private key is: "<<d<<endl;
    long long int decrypted;
    decrypted = modular(encrypt,d,n);
    cout<<"The Decrypted text is : "<<(char)decrypted<<endl;
    cout<<"The Decrypted text in ASCII value is: "<<decrypted<<endl;
 
return 0;}