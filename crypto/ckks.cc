#include <seal.h>
#include <ckks.hh>
#include <example.h>
using namespace std;
using namespace seal;
#include <vector>
#define N 3
//本例的目的是计算x，y，z的乘积


//构建参数容器 parms
/*CKKS有三个重要参数：
1.poly_module_degree(多项式模数)
2.coeff_modulus（参数模数）
3.scale（规模）
下一小节会详细解释*/

//构建各模块
//首先构建keygenerator，生成公钥、私钥和重线性化密钥
Ciphertext CKKS:
Encrypt_HOM(vector<double> x)
{
	
//对向量x、y、z进行编码
	Plaintext xp;
	// yp, zp;
	encoder.encode(x, scale, xp);
	// encoder.encode(y, scale, yp);
	// encoder.encode(z, scale, zp);
//对明文xp、yp、zp进行加密
	Ciphertext xc;
	// yc, zc;
	encryptor.encrypt(xp, xc);
	// encryptor.encrypt(yp, yc);
	// encryptor.encrypt(zp, zc);
	return xc;
}

/*对密文进行计算，要说明的原则是：
1.加法可以连续运算，但乘法不能连续运算
2.密文乘法后要进行relinearize操作
3.执行乘法后要进行rescaling操作
4.进行运算的密文必需执行过相同次数的rescaling（位于相同level）
*/
//基于上述原则进行运算

//至此，客户端将pk、CKKS参数发送给服务器，服务器开始运算
//服务器的视角：先设中间变量
Ciphertext CKKS:
HOM_MUL(Ciphertext xc,Ciphertext yc,char compute)
{
	Ciphertext temp;
	Ciphertext result_c;
	size_t xc_chain=context->get_context_data(xc.parms_id())->chain_index();
	size_t yc_chain=context->get_context_data(yc.parms_id())->chain_index();
    if(xc_chain>yc_chain)
	{
		size_t d_value=xc_chain-yc_chain;
		while (d_value--)
		{
			Plaintext wt;
	        encoder.encode(1.0, scale, wt);
			evaluator.multiply_plain_inplace(yc, wt);
	        evaluator.rescale_to_next_inplace(yc);
		}	
	}
	else {
		size_t d_value=yc_chain-xc_chain;
		while (d_value--)
		{
			Plaintext wt;
	        encoder.encode(1.0, scale, wt);
			evaluator.multiply_plain_inplace(xc, wt);
	        evaluator.rescale_to_next_inplace(xc);
		}	

	}
	evaluator.multiply(xc,yc,temp);
	evaluator.relinearize_inplace(temp, relin_keys);
	evaluator.rescale_to_next_inplace(temp,result_c);
	return result_c;

}
//计算完毕，服务器把结果发回客户端
vector<double> CKKS:
Decrypt_Ckks(Ciphertext result_c)
{

	//客户端进行解密和解码
	Plaintext result_p;
	decryptor.decrypt(result_c, result_p);
//注意要解码到一个向量上
	vector<double> result;
	encoder.decode(result_p, result);
	return result;
}

