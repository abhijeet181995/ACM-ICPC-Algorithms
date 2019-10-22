
#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node*next;
	//Constructor with Init List
	Node(int d):data(d),next(NULL){}
	~Node(){

		cout<<"Deleting "<<data<<" ";
		if(next!=NULL){
			delete next;
		}
	}
};

void insertathead(Node* &head,int d){
	if(head==NULL){
		head = new Node(d);
		return;
	}
	Node *n = new Node(d);
	n->next = head;
	head = n;
}
int len(Node* head){
  int cnt=0;
    Node * temp = head;
    while(temp != NULL)
    {
        temp=temp->next;
        cnt+=1;
    }
    cout<<"cnt "<<cnt<<endl;
    return(cnt);

}

void insertattail(Node*&head,int d){
    if (head==NULL)
    {
        head = new Node(d);
        return;
    }
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    Node*n=new Node(d);
    temp->next= n;
    return;


}
void insertatmiddle(Node* &head,int d,int p){
	if(p==0){
		insertathead(head,d);
		return;
	}
    else if (p>len(head))
    {
        insertattail(head,d);
    }
	Node*temp = head;
	for(int jump=1;jump<p-1;jump++){
		temp = temp->next;
	}
	Node*n = new Node(d);
	n->next = temp->next;
	temp->next = n;
	return;
}
void print(Node*head){

	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
}
void deleteatend(Node* &head){

    if (head ==NULL)
    return;
    Node * prev = NULL;
    Node * temp = head;
    while(temp->next!=NULL)
    {
        prev = temp;
        temp=temp->next;
    }
    delete temp;
    prev->next = NULL;
    return;
}
void search(Node* head,int d){

    if (head==NULL)
    {
        return;
    }
    while(head!= NULL)
    {
        if (head->data == d)
        {   cout<<"found"<<endl;
            return;
        }
        head=head->next;
    }
    cout<<"not found"<<endl;
}

istream& operator>>(istream &is,Node*&head){
	int data;
	while(scanf("%d",&data)!=EOF){
		insertattail(head,data);
	}
	return is;
}
ostream& operator<<(ostream &os,Node*head){
	print(head);
	cout<<endl;
	return os;
}
void reverse(Node* &head){
    Node* c = head;
    Node* p = NULL;
    Node* n;
    while (c!=NULL)
    {
        n = c->next;
        c->next = p;
        p=c;
        c=n;
     }
    head=p;
}
void kreverse(Node* &head,int k){
    Node* c = head;
    Node* p = NULL;
    Node* n;
    Node* temp1;
    Node* temp2;
    int cnt = 0;
    while (cnt<k)
    {
        cnt += 1;
        n = c->next;
        c->next = p;
        if (cnt==1)
        {
            temp1=c;
        }
        p=c;
        c=n;
     }
    head=p;
    cnt=0;
    while (c !=NULL)
    {
        cnt+=1;
        if (cnt==1)
        {
            temp2=c;
        }
        n = c->next;
        c->next = p;
        p=c;
        c=n;
        if (cnt==k)
        {   cnt=0;
            temp1->next=p;
            temp1=temp2;
        }
    }
    if (c==NULL)
    {
        temp1->next=NULL;
    }
}

Node* middle(Node* head){

if (head==NULL or head->next==NULL)
{
    return head;
}
Node* slow = head;
Node* fast = head->next;
while(fast!=NULL and fast->next!=NULL)
{ slow=slow->next;
  fast=fast->next->next;
}
return slow;
}
Node* kth_Node_end(Node* head,int k){

    if (head==NULL or head->next==NULL)
    {
        return head;
    }
    Node*slow=head;
    Node*fast=head;
    int t= k;
    while (t--)
    { if (fast==NULL) return head ;
      fast=fast->next;
    }
    while(fast!=NULL)
    {
    slow=slow->next;
    fast=fast->next;
    }
    return slow;
}
Node* Merge(Node* a,Node *b){
if (a==NULL)return b;
else if (b==NULL) return a;
Node* c;
if (a->data < b->data)
{c=a;
c->next=Merge(a->next,b);}
else
{c=b;
c->next=Merge(a,b->next);}
return c;

}
Node* Mergesort(Node*head)
{if (head==NULL or head->next==NULL)
{
return head;
}
Node* mid = middle(head);
Node* a   = head;
Node* b   = mid->next;
mid->next = NULL;
      a   = Mergesort(a);
      b   = Mergesort(b);

Node* c   = Merge(a,b);
return c;
}


int main()
{
    int t;
    while(t--)
    {   int m,n;
        cin>>m;
        Node*head1 = NULL;
        Node*head2 = NULL;
        while(m--)
        {   int k;
            cin>>k;
            insertattail(head1,k);
        }
        cin>>n;
        while(n--)
        {   int k;
            cin>>k;
            insertattail(head2,k);
        }
        Node* ans = Merge(head1,head2);
        print(ans);
    }
	return 0;
}
