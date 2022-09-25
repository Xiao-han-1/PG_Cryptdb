#include "seal/ckks.h"
#include <algorithm>
#include <chrono>
#include <cstddef>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <mutex>
#include <numeric>
#include <random>
#include <sstream>
#include <vector>
#include <string>
#include <thread>
#include <vector>
#include <seal/seal.h>
#include <seal/ciphertext.h>

class CKKS
{
public:
 CKKS();
 EncryptionParameters parms(scheme_type::CKKS);
/*CKKS有三个重要参数：
1.poly_module_degree(多项式模数)
2.coeff_modulus（参数模数）
3.scale（规模）
下一小节会详细解释*/

size_t poly_modulus_degree = 8192;
parms.set_poly_modulus_degree(poly_modulus_degree);
parms.set_coeff_modulus(CoeffModulus::Create(poly_modulus_degree, { 60, 40, 40, 60 }));
//选用2^40进行编码
double scale = pow(2.0, 40);

//用参数生成CKKS框架context
auto context = SEALContext::Create(parms);
double scale = pow(2.0, 40); 
	KeyGenerator keygen(context);
	auto public_key = keygen.public_key();
	auto secret_key = keygen.secret_key();
	auto relin_keys = keygen.relin_keys();

//构建编码器，加密模块、运算器和解密模块
//注意加密需要公钥pk；解密需要私钥sk；编码器需要scale
	Encryptor encryptor(context, public_key);
	Evaluator evaluator(context);
	Decryptor decryptor(context, secret_key);

	CKKSEncoder encoder(context);
 void build_parms();
 Ciphertext Encrypt_HOM(std::vector<double> x);
 Ciphertext HOM_MUL(Ciphertext xc,Ciphertext yc,char compute);
 std::vector<double> Decrypt_Ckks(Ciphertext result_c);
 
}



