#include<bits/stdc++.h>

using namespace std;

int n, m;
bool datham[100];  
vector<int> danhsachke[100]; 
vector<int> bestPath;  //duong di ngan nhat 
vector<int> currentPath; //duong di hien tai 
void input() {
	cout<<"So o va duong: " ; cin >> n >> m;  
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        danhsachke[x].push_back(y);  
        danhsachke[y].push_back(x); 
    }  
	memset(datham, false, sizeof(datham));  
}


void dfs(int dinhbatdau, int dinhketthuc) {
    datham[dinhbatdau] = true;  
   currentPath.push_back(dinhbatdau);
	if(dinhbatdau == dinhketthuc){
		if(bestPath.empty() || currentPath.size()< bestPath.size()){
			bestPath = currentPath;
		}
	}else{
		for(int i = 0; i < danhsachke[dinhbatdau].size();i++){
			int dinhke = danhsachke[dinhbatdau][i];
			if(!datham[dinhke]){
				dfs(dinhke,dinhketthuc);
			}
		}
	}
   	currentPath.pop_back();
   	datham[dinhbatdau] = false;
}
void induongdi(){
	if(bestPath.empty()){
		cout<<"Khong co duong di tu nguon den dich"<<endl;
		return;
	}
	cout<<"Duong di ngan nhat: ";
	for (int i = 0; i < bestPath.size(); i++) {
    cout << bestPath[i] << " ";
	}
	cout<<endl; 
}
int main() {
    input();
    int batdau, ketthuc;
	cout<<"batdau ketthuc : ";cin>>batdau>>ketthuc; 
    dfs(batdau,ketthuc);
	induongdi();  
    return 0;
}