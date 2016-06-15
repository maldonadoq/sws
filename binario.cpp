#include <iostream>

using namespace std;


int num_bits(int x){
	int cont = 0;
	int asd = 0;
	int y;

	while(x>=1){	
		y = x%2;
		if(y==1) ++cont;
		asd = 10*asd + y;
		x = x/2;
	}
	return cont;
}

int main(int argc, char const *argv[])
{
	
	int x;
	cout << "numero: "; cin >> x;
	
	int f = x-1;
	bool t=true;

	int asd = num_bits(x);

	while(t){
		if(asd == num_bits(f) or (asd - 1) == num_bits(f)){
			cout << num_bits(f) << endl;
			t = false;
		}
		else
			f--;
	}

	cout << x << endl;
	cout << f << endl;

	return 0;
}