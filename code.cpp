
#include <bits/stdc++.h>
using namespace std; 

// int N, m, Q; 
// unordered_map<string, int> indexOf; // To get index of node by name
// vector<string>node;
// unordered_map<string, int>isLocked; // this is a map that stores if a specific node is locked or not
// unordered_map<string, set<string> >lockedChildList; // this variable stores list of descendents of a node that are locked

const int N = 1000005;
map<string, int> status;
vector<string> nodes;
int n, m, apis, ind;

int getParent(int i){
	if(i==0) return -1;
	return (i-1)/m;
}

/*
Lock: 
	1. if it is already locked then return false
	2. if its descendents is locked return false
	3. if any of its ancestors is locked return false
*/
string lock(string X, int id) {
	ind = find(nodes.begin(), nodes.end(), X) - nodes.begin() + 1;
	int p = ind/2 - 1;
	int c1 = ind*2 - 1;
	int c2 = ind*2;
	if(status[X]){
	    return "false";
	}
	else if(status[nodes[p]]){
	    return "false";
	}
	else if((c1>=0 && c1<n) && (c2>=0 && c2<n) && (status[nodes[c1]]) && (status[nodes[c2]])){
	    return "false";
	}
	status[X] = id;
	return "true";
}

/*
Unlock:
	1. if X is not locked return false
	2. if X is locked by some differen id, then return false
	3. otherwise unlock and return true
*/
string unlock(string X, int id) {
	// If X is not locked
	if(status[X]==0) return "false"; 
	// If X is not locked by id
	int lockedByID = status[X]; 
	if(lockedByID != id) return "false"; 

	// else unlock it
	status[X] = 0;
	return "true";
}

// /*
// Upgrade Lock:
// 	1. If X is locked return false
// 	2. If it has no locked descendents return false
// 	3. If it has locked descendents by more than one id then return false
// 	4. If above condition doesn't satsify then unlock every locked descendents and lock X
// */
string upgrade(string X, int id) {
// 	int i = indexOf[X];
    ind = find(nodes.begin(), nodes.end(), X) - nodes.begin() + 1;
	int p = ind/2 - 1;
	int c1 = ind*2 - 1;
	int c2 = ind*2;
	
	if(status[X]) 
	{
	    int lockedByID = status[X];
	    if(lockedByID != id) return "false";
	}
	
	else if((c1>=1 && c1<n) && (c2>=2 && c2<n) && status[nodes[c1]]==0 && status[nodes[c2]]==0) return "false";
	
	else{
	    if((c1>=1 && c1<n) && (c2>=2 && c2<n)){
	        status[nodes[c1]]=0;
	        status[nodes[c2]]=0;
	        status[X]=id;
	        return "true";
	    }
	}
	return "false";
}

int main() {
	n = 3;
//     m = 2;
//     apis = 5;
    // nodes = { "World", "Asia", "Africa", "China", "India", "SouthAfrica", "Egypt" };
      nodes = { "World", "China", "India"};
    // vector<pair<int,pair<string,int>>> queries = { { 1, {"China",9} },
                                            // { 1, {"India",9} },
                                            // { 3, {"Asia",9} },
                                            // { 2, {"India",9} },
                                            // { 2, {"Asia",9} } };
    vector<pair<int,pair<string,int>>> queries = { { 3, {"India",1} },
                                            { 1, {"World",9} } };
 
    // cout<<queries[0].first<<" "<<queries[0].second.first<<" "<<queries[0].second.second<<endl;
    for (auto q : queries)
        status[q.second.first] = 0;
        
    
    // cout<<lock("China",9)<<endl;
    // cout<<lock("India",9)<<endl;
    // cout<<upgrade("Asia",9)<<endl;
    // cout<<unlock("India",9)<<endl;
    // cout<<unlock("Asia",9)<<endl;
    
    cout<<upgrade("India",1)<<endl;
    cout<<lock("World",9)<<endl;
    
    // cout<<unlock("Asia",9)<<endl;
    // for (auto q : queries)
    //     if(q.first == 1){
    //         cout<<lock(q.second.first,q.second.second);
    //     }
    //     else if(q.first == 2){
    //         cout<<unlock(q.second.first,q.second.second);
    //     }
    //     else if(q.first == 3){
    //         cout<<upgrade(q.second.first,q.second.second);
    //     }
	return 0;
}
