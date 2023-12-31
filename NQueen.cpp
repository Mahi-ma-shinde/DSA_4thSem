#include<math.h>
#include<iostream>
using namespace std;

int a[20];
void queen(int);
int place(int);
void print_sol(int);

int place(int pos){
	int i;
	for(i=1;i<pos;i++){
		if(a[pos]==a[i] || (abs(a[i]-a[pos])==abs(i-pos)))
		return 0;
	}return 1;
}

void print_sol(int n){
	cout<<"******Solution******"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==j)
				cout<<i<<"\t";
			else
				cout<<"-\t";
		}cout<<"\n";
	}
}

void queen(int n){
	int k=1;
	a[k]=0;
	while(k!=0){
		a[k]=a[k]+1;
		while((a[k]<=n) && !place(k)){
			a[k]++;
		}
		if(a[k]<=n){
			if(k==n){
				print_sol(n);
			}
			else{
				k++;
				a[k]=0;
			}
		}
		else
			k--;
	}
}

int main(){
	int n;
	cout<<"Enter the number of queens: ";
	cin>>n;
	queen(n);
}
