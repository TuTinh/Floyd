
#include<iostream>

using namespace std;

void Floyd(int n,int a[][6],int s,int e){
	int i,j,k;
	int d[n][n];
	int p[n][n];
	// khoi tao bang
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			d[i][j] = a[i][j];
			p[i][j]=0;
		}
	}
	// tinh toan
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			// khac vo cung
			if(d[i][k]>0 && d[i][k]<1000){				
				for(j=0;j<n;j++){
					// khac vo cung
					if(d[k][j]>0 && d[k][j]<1000){
						if(d[i][k]+d[k][j] < d[i][j]){
							d[i][j]=d[i][k]+d[k][j];
							p[i][j]=k+1;
						}						
					}
				}
			}
		}
	}
	// output
	cout<<"Table d:";
	for(i=0;i<n;i++){
		cout<<"\n\t";
		for(j=0;j<n;j++){
			cout<<d[i][j]<<" ";
		}		
	}
	cout<<"\nTable p:";
	for(i=0;i<n;i++){
		cout<<"\n\t";
		for(j=0;j<n;j++){
			cout<<p[i][j]<<" ";
		}
	}
	
	// truy vet
	cout<<endl;	
	int arr[n];
	arr[0]=s;
	i=1;
	int sum=0;
	
	int tem=s;
	cout<<"The shortest way is: "<<s<<"->";
	while(tem != 0){

		tem = p[tem-1][e-1];
		
		if(tem!=0){
			cout<<tem<<"->";
			arr[i]=tem;
			i++;
		}
		arr[i]=e;
				
	}
	cout<<e<<endl;
	
	for(j=0;j<i;j++){
		sum+=d[arr[j]-1][arr[j+1]-1];
	}
	
	
	cout<<"\nTotal weight is: "<<sum;	
}


int main(){
	int n=6;
	int a[n][6]={
		{0,20,15,1000,80,1000},
		{40,0,1000,1000,10,30},
		{20,4,0,1000,1000,10},
		{36,18,15,0,1000,1000},
		{1000,1000,90,15,0,1000},
		{1000,1000,45,4,10,0}
	};
	int s,e;
	cout<<"Point start: "; cin>>s;
	cout<<"Point end: ";cin>>e;
	
	Floyd(n,a,s,e);
	return 0;
}
