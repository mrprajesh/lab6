#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <climits>
using namespace std;

void merge(int A[],int p, int q, int r){
	int L[200], R[200];	
	int n1=q-p+1;
	int n2=r-q;
	int i,j,k;
	for(i=1; i<n1; i++)
		L[i]=A[p+i-1];
	for(j=1; j<n2; j++)
		R[j]=A[q+j];
	L[i]=INT_MAX;
	R[j]=INT_MAX;
	i=1,j=1;
	for(k=p; k<=r; k++){
		if(L[i]<R[j]){
			A[k]=L[i];
			i++;		
		}else{
			A[k]=R[j];
			j++;
		}
	}
}

void merge_sort(int A[],int p,int r){
	if(p<r){
		int q=(p+r)/2;
		merge_sort(A,p,q);
		merge_sort(A,(q+1),r);
		merge(A,p,q,r);
	}
}


int main(int argc, char* args[]){
	int j,nline=0;	
	string line;	
	std::ifstream in;	
	if(argc!=2){
		cout<< "Invalid Arguments! Valid usage: " <<endl ;
		cout<<args[0]<< " -i <input_file>" <<endl;
		return -1;
	}
	string file=args[1];
	in.open(file.c_str());

	if(in.fail()) 
		cout<<"inputCase File NOT found"<<endl;		
	while (getline(in, line) && line!="") {
		nline++;
	}
	in.close();
	cout<< nline<<endl;
	in.open(file.c_str());
	while (getline(in, line) && line!="") {		
		istringstream bufStream(line);
		string key="";
		int x=-1,y=-1;
		bufStream >> x >>y ;
		cout << x << "|" << y  <<std::endl;			
	}

	in.close();
	
	return 0;
}
