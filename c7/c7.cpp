#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <iterator>

using std::vector;
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

string int2str(int i){
	//Q1: turn int into string: itos mimicry
	bool neg = false;
	string s;
	if(i == 0){
		return string("0");
	}
	else if(i < 0){
		i*=-1;
		neg = true;
		s.reserve(int(log10(i))+2);
	}
	else{
		s.reserve(int(log10(i))+1);
	}

	while(i>0){
		s.insert(0, 1, '0' + (i%10));
		i/=10;
	}
	if(neg == true){
		s.insert(0, 1, '-');
	}

	return s;
}

string& rep_et_rem(string& s, int cur_size){
	//Q2: replace a's using dd, remove b's
	int i = 0;
	int j = 0;
	while(j<cur_size){
		if(s[j]=='b'){		
			++j;
		}
		else{
			s[i] = s[j];
			++i;
			++j;	
		}
	}
	
	int z = s.size() -1;
	for(int k = i-1; k>=0; --k){
		if(s[k] == 'a'){
			s[z] = 'd';
			s[z-1] = 'd';
			z-=2;
		}
		else{
			s[z] = s[k];
			--z;
		}
	}
	s.erase(0, z+1);
	return s;
}

bool palin(string& s){
	// Q3
	int i = 0;
	while(i < s.size()-1-i){
		if(s[i]!=s[s.size()-1-i]){
			return false;
		}
		++i;
	}
	return true;
}

void wordrev_aux(string& s, int i, int j){
	//Q4
	while(i < j ){
		std::swap(s[i], s[j]);
		++i;
		--j;
	}
}

void wordrev(string& s){
	// Q4
	int i = 0;
	while(i < s.size() - 1 -i){
		std::swap(s[i], s[s.size() - 1 -i]);
		++i;
	}
	
	int k = 0;
	for(int j = 0; j <= s.size(); ++j){
		if(s[j] == ' ' || j == s.size()){
			wordrev_aux(s, k, j-1);
			k = j+1;
		}
	}
}

const char* m[] = {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"}; 
vector<string> mapping(m, std::end(m));

void drive_aux(vector<string>& results, string result, const string& n, int s, vector<string>& mapping){
	// Q5
	if(s == n.size()){
		results.push_back(result);
	}	
	
	const string& letters = mapping[n[s] - '0'];
	for(const char& letter: letters){
		result.push_back(letter);
		drive_aux(results, result, n, s+1, mapping);
		result.pop_back();
	}
}

void drive(const string& n, vector<string>& mapping){
	// Q5
	vector<string> results;
	drive_aux(results, string(""), n, 0, mapping);	

	for(string result: results){
		cout<<result<<endl;
	}
}

int main(){
	/** Q1
	cout<<str2int("-231")<<endl;
	cout<<str2int("99")<<endl;
	cout<<str2int("0")<<endl;

	cout<<int2str(-231)<<endl;
	cout<<int2str(0)<<endl;
	cout<<int2str(99)<<endl;
	**/
	
	/** Q2
	string s ("abcd");
	string s1 ("pettep");
	string s2 ("aaa   ");
	string s3 ("bbba");
	string s4("b");
	cout<<rep_et_rem(s, 4)<<","<<rep_et_rem(s1, 6)<<","<<rep_et_rem(s2, 3)<<","<<rep_et_rem(s3, 4)<<","<<rep_et_rem(s4, 1)<<endl;
	**/
	
	/** Q3
	string s("abcd");
	string s1("aa");
	cout<<palin(s)<<endl;
	cout<<palin(s1)<<endl;
	**/

	/** Q4
	string s("Alice likes Bob");
	wordrev(s);
	cout<<s<<endl;
	**/
	
	/** Q5
	string n("69");
	drive(n, mapping);
	**/

	return 0;	
}
