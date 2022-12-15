#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
/////////////////////////////////////////////////////////////////
// NOTE:
// If running locally, you may want to replace the "hardcoded" DATAFOLDER with
// the DATAFOLDER location below which gets the current working directory
/////////////////////////////////////////////////////////////////
// char buff[1024];
// std::string DATAFOLDER = std::string(getcwd(buff, 1024));
class FHE_CKKS {
 public:
    void Init();
    std::string Encrypt(double c);
    double Decrypt(std::string c1);
    std::string Mul(std::string c1,std::string c2);
    std::string Add(std::string c1,std::string c2);
    std::string Sub(std::string c1,std::string c2);
    int Compare(std::string c1,std::string c2);
 private:
    const int multDepth    = 5;
    const int scaleModSize = 40;
    const uint batchSize  = 32;
    int k=0;
};

