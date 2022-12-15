#include<iostream>
#include<string.h>
#include<string>
#include<sstream> 
using namespace std;

int main()  
{

	// o<<" create table table_vpkrqbodqu (mgdamrxojaoDET BIGINT(8) unsigned, rfrdwhfllxoOPE BIGINT(8) unsigned,"; 
    // o<<" hhpgahqxytoAGG VARBINARY(256), cdb_saltvsztqivrcn BIGINT(8) unsigned not null, ";
    // o<<" owwfzuoghboDET VARBINARY(32), dqkuyncpkcoOPE BIGINT(8) unsigned, cdb_saltmlboolflcp BIGINT(8) unsigned not null) ENGINE=InnoDB ";
  string query="select (`t1` + `t2`) AS `t1+t2` from `cryptdb`.`test_num`";
      int pos=0,pos1=0;
        while(query.find('`')!=std::string::npos&&query.find('`')<query.find('from'))
        {
				pos=query.find('`');
           pos1=query.find('`',pos+1);
		    std::string it=query.substr(pos+1,pos1-pos-1);
                query.replace(pos,pos1-pos+1,it);
            }
           
	std::cout<<query<<"\n";
	// while(o)
	// {
	// 	o>>q;
	// 	std::
	// }
    
   return 0;
}