#include <iostream>
#include <string>
#include <math.h>

using std::string;
using std::cout;
using std::endl;

int str2int(string s){
	//Q1: turn string into int: stoi mimicry
	int result = 0;
	for(int i = s.size()-1; i>=1; --i){
		result += (s[i] - '0')*pow(10, s.size()-1-i);
	}

	if(s[0] == '-'){
		return -1*result;
	}
	else{
		result += (s[0]-'0')*pow(10, s.size()-1);
		return result;
	}
}

string& rep_et_rem(string& s, int cur_size){
	//Q2: replace a's using dd, remove b's
	int pos = s.size() -1 ;
	for(int i = cur_size -1; i>=0; --i){
		if(s[i] == 'a'){
			s[pos] = 'd';
			s[pos-1] = 'd';
			pos -= 2;
		}
		else if(s[i] == 'b'){
			//
		}
		else{
			s[pos] = s[i];
		}
	}
	return s;
}


int main(){
	/** Q1
	cout<<str2int("-231")<<endl;
	cout<<str2int("99")<<endl;
	cout<<str2int("0")<<endl;
	**/
	
	string& s = "abcd";
	string& s1 = "pettep";
	string& s2 = "aaa   ";
	string& s3 = "bbba";
	cout<<rep_et_rem(s, 4)<<" , "<<rep_et_rem(s1, 6)<<" , "<<rep_et_rem(s2, 3)<<" , "<<rep_et_rem(s3, 4)<<endl;


	return 0;	
}
