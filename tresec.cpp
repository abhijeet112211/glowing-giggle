#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<climits>
class node{

       public:
       int data;
       node* left;
       node* right;
       node(int val){
           data=val;
           left=NULL;
           right=NULL;
       }
    };

void inorder(node* root){

    if(root==NULL)
     return;
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
}
  
void swap(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;
}
void postorder(node* root){
    if(root==NULL)
     return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void preorder(node * root){
    if(root=NULL)
     return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int search(int arr[],int val, int s){
    for(int i=0;i<s;i++){
        if(arr[i]==val){
            return i;
            break;
        }
    }
    return -1;
}

node* buildTree(int inor[],int pre[],int isz,int end){

    static int ind=0;
    if(isz>end){
        return NULL;
    }
    int pos=ind;
    ind++;
     node* nwroot=new node(pre[pos]);
     if(isz==end)
      return nwroot;
     int rind=search(ind,pre[pos],end);
     nwroot->left=buildTree(inor,pre,inz,rind-1);
     nwroot->right=buildTree(inor,pre,rind+1,end);
     
}

int calNoNode(node* root){
     if(root==NULL)
      return 0;
    int ln=calNoNode(root->left);
    int rn=calNoNode(root->right);
    return(ln+rn+1);
}

int calHeNode(node* root){
    if(root==NULL)
     return 0;
    int lh=calNoNode(root->left);
    int rh=calNoNode(root->right);
    return(max(lh,rh)+1);
}

int sumOfNode(node* root){
    if(root==NULL)
     return 0;
    int lsum=sumOfNode(root->left);
    int  rsum=sumOfNode(root->right);
    return(lsum+rsum+root->data);
}

void levelTra(node* root){

    if(root==NULL)
     return;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){ 
         node* temp=q.front();
         q.pop();
        if(q.front()!=NULL){
            cout<<temp->data<<" ";
         if(temp->left!=NULL)
          q.push(temp->left);
         if(temp->right!=NULL)
          q.push(temp->right);
          q.pop();
        }
        else if(!q.empty())
         q.push(NULL);
    }
}

int calDiam(node* root int* height){ 
     
     if(root==NULL){
         *height=0;
         return 0;
     }

     int lh=0,rh=0;
     int ldia=calDiam(root->left,&lh);
     int rdia=calDiam(root->right,&rh);
    
     *height=max(lh,rh)+1;
     int currdia=lh+rh+1;
     return(max(max(ldia,rdia),currdia));

}

void sumRepl(node* &root){
    if(root==NULL)
     return;
     
     sumRepl(root->left);
     sumRepl(root->right);
    if(root->left!=NULL){
        root->data+=root->left->data;
    }
    if(root->right!=NULL){
        root->data+=root->right->data;
    }
}

bool balaHt(node* root ,int *height){  

    if(root==NULL)
     return true;

     int lh=0,rh=0;
     if(balaHt(root->left,&lh)==false)
      return false;
     if(balaHt(root->right,&rh)==false)
      return false;

    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1)
     return true;
    else{
        return false;
    }
}

void rightvw(node* root){  
    if(root==NULL)
     return ;
     queue<node*>q;
     q.push(root);
     while(!q.empty()){
         int n=q.size();
         for(int i=0;i<n;i++){
             node* temp=q.front();
             q.pop();
             if(i==n-1){
                  cout<<temp->data<<" ";
             }
        
          
         if(temp->left!=NULL)
          q.push(temp->left);
         if(temp->right!=NULL)
          q.push(temp->right);
        }
    }
}

void leftvw(node* root){
    if(root==NULL)
     return ;
     queue<node*>q;
     q.push(root);
     while(!q.empty()){
         int n=q.size();
         for(int i=1;i<=n;i++){
          node* temp=q.front();
           q.pop();
          if(i==1)
            cout<<temp->data<<" ";
          if(temp->left!=NULL)
             q.push(temp->left);
            if(temp->right!=NULL)
              q.push(temp->right);
        }
    }
}

node* LCA(node* root,int v1,int v2){



    if(root==NULL)
     return NULL;

    if(root->data==v1 || root->data==v2)
     return root;
     node*llca=LCA(root->left,v1,v2));
     node* rlca=LCA(root->right,v1,v2));
     if(llca !=NULL && rlca!=NULL)
      return root;
     if(llca==NULL && rlca==NULL)
      return NULL;
     if(llca!=NULL)
      return(LCA(root->left,v1,v2));
     else 
     return(LCA(root->right,v1,v2));
}

int findDis(node* root,int v,int dis){

      if(root==NULL)
       return -1;

       if(root->data==v){
           return dis;
       }
    int leftdis=findDis(root->left,v,dis+1);
    if(leftdis!=-1){
        return leftdis;
    }
    int rightdis=findDis(root->right,v,dis+1);
     if(rightdis!=-1){
         return rightdis;
     }
     return -1;
}

int shortdisTnode(node* root,int v1,int v2){
    node*lca= LCA(root,v1,v2);
     int d1=findDis(lca,v1,0);
     int d2=findDis(lca,v2,0);
     return d1+d2;
}

void flattenbT(node* root){


    if(root==NULL || (root->left ==NULL && root->right==NULL) )
     return NULL;
    
    if(root->left!=NULL){
        node* temp= root->right;
        flattenbT(root->left);
        root->right=root->left;
        root->left=NULL;
        node* t=root->right;
        while(t->right!=NULL){
           t=root->right;
        }
        t->right=temp;
    }
    flattenbT(root->right);
}

void printNode( node* root,int k){

    if(root==NULL || k<0)
     return;
    if(k==0){
        cout<<root->data<<" ";
    }
    printNode(root->left,k-1);
    printNode(root->right,k-1);
}
 
 int printNodeK(node* root,node* target,int k){

     if(root==NULL)
      return -1;
     if(root==taget){
         printNode(target,k);
         return 0;
     }
     int dl=printNodeK(root->left,target,k);
     if(dl!=-1){
         if(dl+1==k)
          cout<<root->data<<" ";
         else{
             printNode(root->right,k-dl-2);
           }
         return dl+1;
        }
     int dr=printNodeK(root->right,target,k);
     if(dl!=-1){
         if(dl+1==k)
          cout<<root->data<<" ";
         else{
             printNode(root->left,k-dl-2);
           }
         return dr+1;
        }
    return -1;

}

int maxsumPthAxu(node* root,int &ans){

     
    if(root==NULL)
     return 0;
    
    int ls=maxsumPthAxu(root->left,ans);
    int rs=maxsumPthAxu(root->right,ans);
    int nodemax=max((max(root->data+ls,root->data+rs),max(root->data,root->data+rs+ls)));
    ans=max(nodemax,ans);
    int singpath=max(max(ls+root->data,rs+root->data),root->data);
    return singpath;
}

void getmaxPsum(node* root){

    int ans=INT_MIN;
    maxsumPthAxu(root,ans);
    cout<<ans<<"\n";
}

node* insertBSt(node* root,int val){
    if(root==NULL)
     return new node(val);

    if(val>root->data)
     root->right=insertBSt(root->right,val);
    else
     root->left= insertBSt(root->left,val);

    return root;
}

node* searchBst(node* root,int val){

    if(root==NULL)
     return NULL;
    if(root->data==val)
     return root;
    else if(val>root->data)
     return(searchBst(root->right,val));
    else
     return(searchBst(root->left,val));
}

node* inorsuc(node* root){
    //root is root->right  therefore we search in left
    node* curr=root;
    while(curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}

node* deleBst(node* root,int val){


    if(root->data>val)
     root->left=deleBst(root->left,val);
    else if(root->data<val)
     root->right=deleBst(root->right,val);
    else{
        if(root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        
            node* temp=inorsuc(root->right);
            root->data=temp->data;
            root->right=deleBst(root->right,temp->data);
    }
   return root;
    
}

node* createBst(int preorder[],int* preindex,int key,int min,int max,int n){
    if(preindex>=n)//min will be INT_MIN and max will be INT_MAX
     return NULL;
     node* root= NULL;
     if(key> min && key<max){
         root=new node(key);
         *preindex=*preindex+1;
        if(*preindex<n);
        root->left=createBst(preorder,preindex,preorder[*preindex],min,key,n);
       if(*preindex<n)
        root->right=createBst(preorder,preindex,preorder[*preindex],key,max,n);
    }
    return root;
}

bool checkBst(node* root,node* min,node* max){
      if(root==NULL)
       return true;

    if(min!=NULL && root->data<=min->data)
     return false;
    if(max!=NULL && root->data>=max->data)
      return false;
    bool leftvalid=checkBst(root->left,min,root);
    bool rightvalid=checkBst(root->right,root,max);
    if(leftvalid && rightvalid)
     return true;
    else 
     return false;
}

node* createBstFromSortedarr(int arr[],int st,int end){
    if(st>end)//end value must be size-1;
     return NULL;
    int mid=(st+end)/2;
    node* root=new node(arr[mid]);
    root->left=createBstFromSortedarr(arr,st,mid-1);
    root->right=createBstFromSortedarr(arr,mid+1,end);
     
    return root;
}

int catalan(int n){
    
    if(n==0|| n==1)
     return 1;
     int res=0;
    for(int i=0;i<n;i++){
        res+=catalan(i)*catalan(n-i-1);
    }
    return res;
}

bool isidenti(node* root1,node* root2){
    if(root1==NULL && root2==NULL)
     return true;
     else if(root1==NULL ||root2==NULL)
       return false;
     else{
         if(root1->data!=root2->data)
           return false;
          
         bool leftTr=idenBST(root1->left,root2->left);
         bool rightTr=idenBST(root1->right,root2->right);
        if(leftTr && rightTr)
          return true;
        else
         return false;
     }
}

struct info{
    int max,min,size,ans;
    bool isBST;
};
   info LargestBSTinBT(node* root){
     if(root==NULL)
     return{INT_MAX,INT_MIN,0,0,true};
     
     if(root->left==NULL && root->right==NULL)
      return{root->data,root->data,1,1,true};
     
    info leftTr=LargestBSTinBT(root->left);
    info rightTr=LargestBSTinBT(root->right);
    
    info curr;
    curr.size=leftTr.size+rightTr.size+1;
    if(leftTr.isBST && rightTr.isBST && root->data>leftTr.max && root->data<rightTr.min){
       
        curr.isBST=true;
        curr.max=max(max(root->data,leftTr.max),rightTr.max);
        curr.min=min(min(root->data,leftTr.min),rightTr.min);
        curr.ans=curr.size;
        
        return curr;
     }
           curr.ans=max(leftTr.ans,rightTr.ans);
           curr.isBST=false;
           return curr;
 } 

void calpointer(node* root,node* &first,node* &mid,node* &last,node* &prev){
    if(root==NULL)
     return;
    calpointer(root->left,first,mid,last,prev);
    if(prev && prev->data>root->data){
        if(!first){
            first=prev;
            mid=root;
        }
        else
        last=root;
    }
    prev=root;
    calpointer(root->right,first,mid,last,prev);
}

 void restoreBST(node* root){
     if(root==NULL)
      return ;
    Node* first,*last,*mid,*prev;
    first=NULL;
    last=NULL;
    mid=NULL;
    prev=NULL;
     calpointer(root,first,mid,last,prev);
     if(first && last){
         swap(first->data,last->data);
     }
     else if(first && mid){
         swap(first->data,mid->data);
     }
 }

bool isfiseable(int arr[],int n,int k,int mid){
    int pos=arr[0],elem=1;
    for(int i=1;i<n;i++){
        if(arr[i]-pos>=mid){
            elem++;
            pos=arr[i];
        if(elem==k)
            return true;
        }
    }
    return false;
}

int maxofkpairSet(int arr[],int n,int k){
    sort(arr,arr+n);
    int result=-1;
    int first=1,last=arr[n-1];
    while(first<last){
        int mid=(first+last)/2;
        if(isfiseable(arr,n,k,mid)){
         result=max(result,mid)
         first=mid+1;
        }
        else
         last=mid;
    }
    return result;
}

int main(){



    node* root=new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->left->right =new node(5);
    root->right->left= new node(6);
    root->right->right new node(7);
    node* bstroot=NULL;
    bstroot=createBStr(bstroot,5);
    insertBSt(root,1);
    insertBSt(root,3);
    insertBSt(root,4);
    insertBSt(root,2);
    insertBSt(root,7);
    inorder(bstroot);
    return 0;
}