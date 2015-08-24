/*
Amit Jain
Min query in an interval
Segment Tree
*/


#include<iostream>

#define INT_MAX 2000000000

using namespace std;

int n,m;
int a[100001];					//Array
int seg[400005];				//Segment tree

int mid(int a,int b){
    return a+(b-a)/2;
}

int mini(int a,int b){
return (a<b)?a:b;
}

void cons(int index,int st,int se){
        if(st==se){
            seg[index]=a[st];
            return ;
        }

        int m=mid(st,se);

        cons(2*index+1,st,m);
        cons(2*index+2,m+1,se);

        seg[index]=mini(seg[2*index+1],seg[2*index+2]);

        return;
}


void construct(int n){
    int index=0,st=0,se=n-1;

    cons(index,st,se);
}

int qu(int index,int st,int se,int a,int b){

    if(a<=st&&b>=se)
        return seg[index];

    if(se<a||st>b)
        return INT_MAX;

    int m=mid(st,se);

    return mini(qu(2*index+1,st,m,a,b),qu(2*index+2,m+1,se,a,b));

}


int query(int a,int b){
    if(a<0||b>=n)
        return -1;

    int index=0,st=0,se=n-1;
    return qu(index,st,se,a,b);
}


int main(){

int q,i,x,y;

cin>>n>>q;

for(i=0;i<n;i++){
    cin>>a[i];
}
m=4*n;

for(i=0;i<m;i++)
{
    seg[i]=INT_MAX;
}

construct(n);


while(q--){
        cin>>x>>y;				// Zero based indexing query(otherwise do x--;y--;)

        cout<<query(x,y)<<endl;
}

return 0;
}
