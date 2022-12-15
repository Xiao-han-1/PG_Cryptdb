#include<ckks.hh>
#include<string>
#include<sstream>
#include "openfhe.h"
#include <iomanip>
#include <tuple>
#include <unistd.h>
// header files needed for serialization
#include "ciphertext-ser.h"
#include "cryptocontext-ser.h"
#include "key/key-ser.h"
#include "scheme/ckksrns/ckksrns-ser.h"
#include "key/keypair.h"
using namespace lbcrypto;
using namespace std;
/////////////////////////////////////////////////////////////////
// NOTE:
// If running locally, you may want to replace the "hardcoded" DATAFOLDER with
// the DATAFOLDER location below which gets the current working directory
/////////////////////////////////////////////////////////////////
// char buff[1024];
// std::string DATAFOLDER = std::string(getcwd(buff, 1024));
inline bool exists_test (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}
// Save-Load locations for keys
const std::string DATAFOLDER = "/home/demoData";
std::string ccLocation       = "/cryptocontext.txt";
std::string pubKeyLocation   = "/key_pub.txt"; 
std::string secKeyLocation   = "/key_sec.txt";   // Pub key
std::string multKeyLocation  = "/key_mult.txt";  // relinearization key
std::string rotKeyLocation   = "/key_rot.txt";   // automorphism / rotation key

// Save-load locations for RAW ciphertexts
std::string cipherOneLocation = "/ciphertext";
std::string cipherTwoLocation = "/ciphertext2.txt";
// Save-load locations for evaluated ciphertexts
std::string cipherMultLocation   = "/ciphertextMult";
std::string cipherAddLocation    = "/ciphertextAdd";
std::string cipherRotLocation    = "/ciphertextRot";
std::string cipherRotNegLocation = "/ciphertextRotNegLocation.txt";
std::string clientVectorLocation = "/ciphertextVectorFromClient.txt";
void FHE_CKKS::Init()
{
    if(exists_test(DATAFOLDER+ccLocation)==false)
    {
    CCParams<CryptoContextCKKSRNS> parameters;
    parameters.SetMultiplicativeDepth(multDepth);
    parameters.SetScalingModSize(scaleModSize);
    parameters.SetBatchSize(batchSize);
    CryptoContext<DCRTPoly> serverCC ;
    serverCC = GenCryptoContext(parameters);

    serverCC->Enable(PKE);
    serverCC->Enable(KEYSWITCH);
    serverCC->Enable(LEVELEDSHE);

    KeyPair<DCRTPoly> serverKP = serverCC->KeyGen();
    serverCC->EvalMultKeyGen(serverKP.secretKey);
    serverCC->EvalRotateKeyGen(serverKP.secretKey, {1, 2, -1, -2});
     if (!Serial::SerializeToFile( DATAFOLDER + ccLocation, serverCC, SerType::BINARY)) {
        std::cerr << "Error writing serialization of the crypto context to "
                     "cryptocontext.txt"
                  << std::endl;
        std::exit(1);
    }

    if (!Serial::SerializeToFile( DATAFOLDER + pubKeyLocation, serverKP.publicKey, SerType::BINARY)) {
        std::cerr << "Exception writing public key to pubkey.txt" << std::endl;
        std::exit(1);
    }
    if (!Serial::SerializeToFile( DATAFOLDER +secKeyLocation, serverKP.secretKey, SerType::BINARY)) {
        std::cerr << "Exception writing public key to pubkey.txt" << std::endl;
        std::exit(1);
    }
    std::ofstream multKeyFile( DATAFOLDER + multKeyLocation, std::ios::out | std::ios::binary);
    if (multKeyFile.is_open()) {
        if (!serverCC->SerializeEvalMultKey(multKeyFile, SerType::BINARY)) {
            std::cerr << "Error writing eval mult keys" << std::endl;
            std::exit(1);
        }
        multKeyFile.close();
    }
    else {
        std::cerr << "Error serializing EvalMult keys" << std::endl;
        std::exit(1);
    }

    std::ofstream rotationKeyFile( DATAFOLDER + rotKeyLocation, std::ios::out | std::ios::binary);
    if (rotationKeyFile.is_open()) {
        if (!serverCC->SerializeEvalAutomorphismKey(rotationKeyFile, SerType::BINARY)) {
            std::cerr << "Error writing rotation keys" << std::endl;
            std::exit(1);
        }
    }
    else {
        std::cerr << "Error serializing Rotation keys" << std::endl;
        std::exit(1);
    }
    }
    
 }
int k_init()
{
 std::string name ="/k.txt";
//  if(!exists_test( DATAFOLDER + name))
//  {
//     ofstream fout( DATAFOLDER + name);
//     fout<<0;
//    fout.close();
//  }
int k;
  ifstream readFile( DATAFOLDER + name);
  readFile >> k;
  readFile.close();
  k++;
   ofstream fout( DATAFOLDER + name);
    fout<<k;
   fout.close();
  return k;
}
std::string FHE_CKKS::Encrypt(double c)
{
  std::vector<std::complex<double>> vec;
  vec.push_back(c);
  CryptoContext<DCRTPoly> serverCC;
  lbcrypto::CryptoContextFactory<lbcrypto::DCRTPoly>::ReleaseAllContexts();
    if (!Serial::DeserializeFromFile( DATAFOLDER + ccLocation, serverCC, SerType::BINARY)) {
        std::cerr << "I cannot read serialized data from: " << DATAFOLDER << "/cryptocontext.txt" << std::endl;
        std::exit(1);
    }

    KeyPair<DCRTPoly> serverKP;  // We do NOT have a secret key. The client
    // should not have access to this
    PublicKey<DCRTPoly> serverPublicKey;
    if (!Serial::DeserializeFromFile( DATAFOLDER + pubKeyLocation, serverPublicKey, SerType::BINARY)) {
        std::cerr << "I cannot read serialized data from: " << DATAFOLDER << "/cryptocontext.txt" << std::endl;
        std::exit(1);
    }

    Plaintext serverP1 = serverCC->MakeCKKSPackedPlaintext(vec);
    auto serverC1 = serverCC->Encrypt(serverPublicKey, serverP1);
    int k=k_init();
    std::string num_str=std::to_string(k);
    std::string store= DATAFOLDER + cipherOneLocation+num_str+".txt";
      if (!Serial::SerializeToFile(store, serverC1, SerType::BINARY)) {
        std::cerr << " Error writing ciphertext 1" << std::endl;
    }   
    std::ifstream file(store, std::ios::in | std::ios::binary);
    std::stringstream re;
    re<<file.rdbuf();
    // return re.str();
    // re<<DATAFOLDER <<cipherOneLocation<<num_str<<".txt";
    std::cout<<re.str().length()<<"\n";
    return store;
}
double FHE_CKKS::Decrypt(std::string c1)
{
  
  CryptoContext<DCRTPoly> serverCC;
  lbcrypto::CryptoContextFactory<lbcrypto::DCRTPoly>::ReleaseAllContexts();
    if (!Serial::DeserializeFromFile( DATAFOLDER + ccLocation, serverCC, SerType::BINARY)) {
        std::cerr << "I cannot read serialized data from: " << DATAFOLDER << "/cryptocontext.txt" << std::endl;
        std::exit(1);
    }
    KeyPair<DCRTPoly> serverKP;  // We do NOT have a secret key. The client
    // should not have access to this
    PrivateKey<DCRTPoly> serverSecretKey;
    if (!Serial::DeserializeFromFile( DATAFOLDER + secKeyLocation, serverSecretKey, SerType::BINARY)) {
        std::cerr << "I cannot read serialized data from: " << DATAFOLDER << "/cryptocontext.txt" << std::endl;
        std::exit(1);
    }
     Ciphertext<DCRTPoly> EncryptC1;
     if (!Serial::DeserializeFromFile( c1, EncryptC1, SerType::BINARY)) {
        std::cerr << "Cannot read serialization from " << c1 << std::endl;
        std::exit(1);
    }
    Plaintext PlaintextC1;
    serverCC->Decrypt(serverSecretKey,EncryptC1, &PlaintextC1);
    PlaintextC1->SetLength(32);
  const std::vector<double> myVec = PlaintextC1->GetRealPackedValue();
  double er=(double)myVec[0];
  return er;
}
std::string FHE_CKKS::Mul(std::string c1,std::string c2)
{
    Ciphertext<DCRTPoly> clientC1;
    Ciphertext<DCRTPoly> clientC2;
    CryptoContext<DCRTPoly> serverCC;
    lbcrypto::CryptoContextFactory<lbcrypto::DCRTPoly>::ReleaseAllContexts();
    
    if (!Serial::DeserializeFromFile( DATAFOLDER + ccLocation, serverCC, SerType::BINARY)) {
        std::cerr << "I cannot read serialized data from: " << DATAFOLDER << "/cryptocontext.txt" << std::endl;
        std::exit(1);
    }
    std::ifstream multKeyIStream( DATAFOLDER + multKeyLocation, std::ios::in | std::ios::binary);
    if (!multKeyIStream.is_open()) {
        std::cerr << "Cannot read serialization from " << DATAFOLDER + multKeyLocation << std::endl;
        std::exit(1);
    }
    if (!serverCC->DeserializeEvalMultKey(multKeyIStream, SerType::BINARY)) {
        std::cerr << "Could not deserialize eval mult key file" << std::endl;
        std::exit(1);
    }
    if (!Serial::DeserializeFromFile( c1, clientC1, SerType::BINARY)) {
        std::cerr << "Cannot read serialization from " << c1 << std::endl;
        std::exit(1);
    }

    if (!Serial::DeserializeFromFile( c2, clientC2, SerType::BINARY)) {
        std::cerr << "Cannot read serialization from " << c2 << std::endl;
        std::exit(1);
    }
    auto clientCiphertextMult   = serverCC->EvalMult(clientC1, clientC2);
    int k=k_init();
    std::string num_str=std::to_string(k);
     std::string str= DATAFOLDER + cipherMultLocation+num_str+".txt";
     Serial::SerializeToFile(str, clientCiphertextMult, SerType::BINARY);
     return str;

}
std::string FHE_CKKS::Add(std::string c1,std::string c2)
{
  Ciphertext<DCRTPoly> clientC1;
    Ciphertext<DCRTPoly> clientC2;
    CryptoContext<DCRTPoly> serverCC;
    lbcrypto::CryptoContextFactory<lbcrypto::DCRTPoly>::ReleaseAllContexts();
    if (!Serial::DeserializeFromFile( DATAFOLDER + ccLocation, serverCC, SerType::BINARY)) {
        std::cerr << "I cannot read serialized data from: " << DATAFOLDER << "/cryptocontext.txt" << std::endl;
        std::exit(1);
    }
    if (!Serial::DeserializeFromFile( c1, clientC1, SerType::BINARY)) {
        std::cerr << "Cannot read serialization from " << DATAFOLDER + cipherOneLocation << std::endl;
        std::exit(1);
    }

    if (!Serial::DeserializeFromFile( c2, clientC2, SerType::BINARY)) {
        std::cerr << "Cannot read serialization from " << DATAFOLDER + cipherTwoLocation << std::endl;
        std::exit(1);
    }
    auto clientCiphertextAdd    = serverCC->EvalAdd(clientC1, clientC2);
    std::string cipherAddLocation="/cipherAddLocation";
    int k=k_init();
    std::string num_str=std::to_string(k);
     std::string str= DATAFOLDER + cipherAddLocation+num_str+".txt";
     Serial::SerializeToFile(str, clientCiphertextAdd, SerType::BINARY);
     return str;
     
}
std::string FHE_CKKS::Sub(std::string c1,std::string c2)
{
  Ciphertext<DCRTPoly> clientC1;
    Ciphertext<DCRTPoly> clientC2;
    CryptoContext<DCRTPoly> serverCC;
    lbcrypto::CryptoContextFactory<lbcrypto::DCRTPoly>::ReleaseAllContexts();
    if (!Serial::DeserializeFromFile( DATAFOLDER + ccLocation, serverCC, SerType::BINARY)) {
        std::cerr << "I cannot read serialized data from: " << DATAFOLDER << "/cryptocontext.txt" << std::endl;
        std::exit(1);
    }
    if (!Serial::DeserializeFromFile( c1, clientC1, SerType::BINARY)) {
        std::cerr << "Cannot read serialization from " << DATAFOLDER + cipherOneLocation << std::endl;
        std::exit(1);
    }

    if (!Serial::DeserializeFromFile( c2, clientC2, SerType::BINARY)) {
        std::cerr << "Cannot read serialization from " << DATAFOLDER + cipherTwoLocation << std::endl;
        std::exit(1);
    }
    auto clientCiphertextSub = serverCC->EvalSub(clientC1, clientC2);
    std::string cipherSubLocation="/cipherSubLocation";
    int k=k_init();
    std::string num_str=std::to_string(k);
     std::string str= DATAFOLDER + cipherSubLocation+num_str+".txt";
     Serial::SerializeToFile(str, clientCiphertextSub, SerType::BINARY);
     return str;
}
int FHE_CKKS::Compare(std::string c1,std::string c2)
{
  
    std::string EncryptSub=Sub(c1,c2);
    double res=Decrypt(EncryptSub);
    if(res<0) return -1;
    if(res>0) return 1;
    else return 0;
}