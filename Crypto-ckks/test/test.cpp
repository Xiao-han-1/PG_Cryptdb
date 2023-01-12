#include<ckks.hh>
#include<string>
#include<sstream>
using namespace std;

 int main()
 {
   //  int a,b;
   //  std::cin>>a>>b;
    FHE_CKKS CKKS;
    CKKS.Init();
    std::string Encrypt1="/home/demoData/ciphertext4.txt";
    std::string Encrypt2="/home/demoData/ciphertext5.txt";

    //  int EncryptCmp=CKKS.Compare(Encrypt1,Encrypt2);
    //  std::cout<<EncryptCmp<<"\n";
    // EncryptCmp=CKKS.Compare(Encrypt2,Encrypt1);
    // std::cout<<EncryptCmp<<"\n";
  //  std::string c1="/home/demoData/ciphertext1.txt";
  //  std::string c2="/home/demoData/cipherAddLocation.txt";
  //  std::cout<<"a+b:"<<CKKS.Decrypt(c1)<<"+"<<CKKS.Decrypt(c2)<<"="<<CKKS.Decrypt(CKKS.Add(c1,c2))<<"\n";
   //  std::string Encrypt1=CKKS.Encrypt((double)a);
   //  std::string Encrypt2=CKKS.Encrypt((double)b);
   //  int c=a-b;
   //   std::string Encrypt3=CKKS.Encrypt((double)c);
    std::string EncryptMul=CKKS.Mul(Encrypt1,Encrypt2);
    double res=CKKS.Decrypt(EncryptMul);
    std::cout<<"a*b:"<<res<<"\n";
   //  std::string EncryptAdd=CKKS.Add(Encrypt1,Encrypt2);
   //  res=CKKS.Decrypt(EncryptAdd);
   //  std::cout<<"a+b:"<<res<<"\n";
   //  std::string EncryptSub=CKKS.Sub(Encrypt1,Encrypt2);
   //  res=CKKS.Decrypt(EncryptSub);
   //  std::cout<<"a-b:"<<res<<"\n";
   //  int EncryptCmp=CKKS.Compare(Encrypt1,Encrypt2);
   //  std::cout<<"a>b:"<<EncryptCmp<<"\n";
   //   EncryptCmp=CKKS.Compare(Encrypt3,Encrypt2);
   //  std::cout<<"a-2>b:"<<EncryptCmp<<"\n";
 }