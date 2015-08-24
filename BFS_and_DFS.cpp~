/*
Amit Jain
BFS and DFS Implentation
*/


// Solution of www.spoj.com/problems/TDBFS


#include<iostream>
#include<stack>
#include<vector>
#include<queue>

using namespace std;

class graph						// graph class
{
private:
    vector<vector<int> >adjacent;
    int size;

public:
    graph(int n);
    void bfs(int);
    void dfs(int);
    void add_adj(int,int);
};

graph::graph(int n){
    n++;
    size=n;
    adjacent.resize(n);
}

void  graph::add_adj(int v,int n){
    adjacent[v].push_back(n);
}


void graph::dfs(int root){

        vector<int> visited;
        visited.resize(size,0);

    stack<int>s;
    s.push(root);
    int temp,l,i;

    while(!s.empty()){
        temp=s.top();
        s.pop();
        if(visited[temp]==1)
            continue;

        visited[temp]=1;
        cout<<temp<<" ";
        l=adjacent[temp].size();

        for(int i=l-1;i>=0;i--){
            s.push(adjacent[temp][i]);
        }
    }

    cout<<endl;
}

void  graph::bfs(int root){

          vector<int> visited;
        visited.resize(size,0);

        queue<int> q;
        q.push(root);

           int temp,l;
        while(!q.empty()){
            temp=q.front();
            q.pop();

             if(visited[temp]==1)
            continue;

            visited[temp]=1;

            cout<<temp<<" ";

            l=adjacent[temp].size();

             for(int i=0;i<l;i++){
                q.push(adjacent[temp][i]);
            }
        }

        cout<<endl;
}

int main(){

ios_base::sync_with_stdio(false);

int t,n,temp,temp2,m;

cin>>t;
for(int f=0;f<t;f++){
        cin>>n;
        graph g(n);

        for(int i=1;i<=n;i++){
                cin>>temp2;
            cin>>m;
            while(m--){
                cin>>temp;
                g.add_adj(temp2,temp);
            }
        }
        cout<<"graph "<<f+1<<endl;



        while(1){
            cin>>temp;
            cin>>temp2;

            if(temp==0)
                break;

            if(temp2==1){
                g.bfs(temp);			// bfs call from temp
            }
            else{
                g.dfs(temp);			// dfs call from temp
            }
        }
}

return 0;
}
