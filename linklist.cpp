#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int x){
        data=x;
        next=NULL;
    }
};
 
 void insertATtail(node* &head,int x){
     node* newnode= new node(x);
     if(head==NULL){
         head=newnode;
         return;
     }
     node* temp=head;
     while(temp->next!=NULL){
         temp=temp->next;
     }
     temp->next=newnode;

 }
 
 void print(node* &head){
     node* temp=head;
     while(temp!=NULL){
         cout<<temp->data<<" ";
         temp=temp->next;
     }
 }
 
 void insertcATtail(node* &head,int val){  
      node* newnode=new node(val);
      if(head==NULL){
       insertcAthead(head,val);
          return;
      }
     node* temp=head;
     while(temp->next!=head){
         temp=temp->next;
     }
     temp->next=newnode;
     newnode->next=head;
 }
 
  void insertcAthead(node* &head,int val){
       node* newnode=new node(val);
      if(head==NULL){
          head=newnode;
          head->next=head;
      }
       node* temp=head;
     while(temp->next!=head){
         temp=temp->next;
     }
      temp->next=newnode;
      newnode->next=head;
      head=newnode;
  }

  void printc(node* head){
      node* temp=head;
      do{
          cout<<temp->data<<" ";
          temp=temp->next;
      }while(temp!=head);
  }

  void deletec(node* &head, int pos){
      node* temp=head,*prev=NULL;
      node* todelete;
      int i=0;
      while(i<pos){
          prev=temp;
          temp=temp->next;
          i++;
      }
      if(temp==head){
          todelete=temp;
          delete todelete;
      }
      if(temp->next==head){
          todelete=temp;
           prev->next=head;
           delete todelete;
      }
      else{
          todelete=temp;
          prev->next=temp->next;
          delete todelete;
      }
  }

  void deleteAthead(node* &head){
      if(head==NULL)
       cout<<"no element in linklist"<<endl;
       node* todelete;
       if(head->next==head){
           todelete =head;
           delete todelete;
       }
       node* temp=head;
       while(temp->next!=head){
           temp=temp->next;
       }
       else{
           todelete=head;
           head=head->next;
           temp=head;
           delete todelete;
       }
  }
  
  void oddevenSeg(node* &head){
      node* oddptr=head;
      node* evenptr=head->next,*firstevenptr=head->next;
      while(oddptr->next!=NULL && evenptr->next!=NULL){
          oddptr->next=evenptr->next;
          oddptr=oddptr->next;
          evenptr->next=oddptr->next;
          evevptr=even->next;
      }
      oddptr->next=firstevenptr;
      if(oddptr->next==NULL){
          evenptr->next=NULL;
          //oddptr->next=firstevenptr;
      }
  }
  
  int getlength(node* head){

      node* temp=head;
      int l=0;
      while(temp!=NULL){
         l++;
         temp=temp->next;
      }
      return l;
  }
  
  int  addlist(node* &head1,node* &head2,int s,int s1,node* &resnode){
      int carry;
      resnode=NULL;
       if(s==0 && s1==0){
           carry=0;
           return carry;
       }
       if(s>s1){
           addlist(head1->next,head2,s-1,s1);
       }
       if(s1>s){
           addlist(head1,head2->next,s,s1-1);
       }
       else{
           addlist(head1->next,head2->next,s-1,s1-1)

           int val=head1->data+head2->data+carry;
           val=val%10;
           carry=val/10;
       }
      insertATtail(resnode,val);
      return carry;
  }
  
   node* foldlist(node* &head,int turn){
       int size=getlength(head);
       if(head->next!=NULL){
           return head;
       }
       node* fleft=head;
       node* res=foldlist(head->next,size--);
       if(turn<size/2){
           res->next=fleft->next;
           fleft->next=res;
           res=res->next;
           fleft=res;

           return res;
       }

   }
  
  node* revrese(node* &head){
      if(head->next==NULL)
       return head;
      node*newhead=revrese(head->next);
      head->next->next=head;
      head->next=NULL;
      return newhead;
  }

int main(){
     node* head=NULL;
    insertATtail(head,2);
    insertATtail(head,3);
    insertATtail(head,4);
    insertATtail(head,5);
    print(head);
    return 0;

} 