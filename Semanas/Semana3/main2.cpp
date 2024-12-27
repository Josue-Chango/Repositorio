#include <algorithm>
#include <cmath>
#include <vector>//añadido
#include <iostream>//añadido
using namespace std;
int main(int argc, char** argv) {
	vector<int> data = {3,4,-1,-10,0};
	auto comp =[](int a, int b){ return a < b;};
	sort(data.begin(),data.end(),comp);
	for(int i=0;i<5;++i){
		cout<< "data [" << i << "]: " << data[i]<< "\n";
	}
	return 0;
}
