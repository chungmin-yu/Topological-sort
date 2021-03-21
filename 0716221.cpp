#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<fstream>
using namespace std;

vector<int> v;
int getVertexIndex(int k){
	vector<int>::iterator iter;
	iter=find(v.begin(),v.end(),k); 
	return iter-v.begin();
}

int main(){
	int vertex;
	int n,m,ans_vertex; 
	int x,y,a,b;
	char c; 
		
	fstream filein;
	filein.open("sample data.txt", ios::in);
	fstream fileout;
	fileout.open("TP_Sort_Result.txt", ios::out);
	
	if(!filein){
		cout<<"The file does not exist!"<<endl;
	}
	
	else{
		while(filein>>n){
			v.clear();
			for(int i=0;i<n;i++){
				filein>>vertex;
				v.push_back(vertex);
			}
			int degin[n];
		  	vector<int> G[n];
		    ans_vertex=0;
		  	for(int i=0;i<n;i++){
		    	G[i].clear(); 	
			} 
		    memset(degin,0,sizeof(degin));
		    filein>>m;
		  	for(int i=0;i<m;i++){
		  		filein >> b >> c >> a;
		  		x=getVertexIndex(a);
      			y=getVertexIndex(b);
		  		G[x].push_back(y);
		  		degin[y]++;
		    }
		  	for(int i=0;i<n;i++){
		  		if (degin[i]==0){
			        ans_vertex++;
			        degin[i]=-1;
			        cout << v[i] << " ";
			        fileout << v[i] << " ";
			        for(int j=0;j<G[i].size();j++){ 
			          degin[G[i][j]]--;			          
			        }  	
			  	}
			  	if(ans_vertex==n){
			  		break;	
				} 
			  	else if (i==(n-1)){ 
			        i=-1;
			  	}
		    } 
		    cout << endl;
			fileout << endl;		
		}
	}
		filein.close();
		fileout.close();		
}



	
	


