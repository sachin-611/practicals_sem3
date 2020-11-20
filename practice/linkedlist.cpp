#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node()
    {
        next=NULL;
        this->data=-1;
    }
};

class linkedlist
{
    node *head;
public:
    linkedlist()
    {
        head=NULL;
    }
    void create()
    {
        cout<<"Enter number of elements of linkedlist : ";
        int n;cin>>n;
        head=new node;
        cout<<"Enter data : ";
        cin>>head->data;
        node *temp=head;
        for(int i=1;i<n;i++)
        {
            node *new_node=new node;
            temp->next=new_node;
            cout<<"Enter data : ";
            cin>>new_node->data;
            temp=temp->next;
        }
        cout<<"linkedlist created";
    }
    void reverse_display()
    {
        cout<<endl;
        reverse_display(head);
        cout<<endl;
    }
    void reverse_display(node *temp)
    {
        if(temp==NULL)
            return;
        reverse_display(temp->next);
        cout<<temp->data<<" ";
    }
    void display()
    {
        cout<<endl;
        display(head);
    }
    void display(node *temp)
    {
        if(temp==NULL)
            return;
        cout<<temp->data<<" ";
        display(temp->next);
    }
    int sum()
    {
        return sum(head);
    }
    int sum(node *temp)
    {
        if(temp==NULL)
            return 0;
        return temp->data+sum(temp->next);
    }
    int count()
    {
        count(head);
    }
    int count(node *temp)
    {
        if(temp==NULL)
            return 0;
        return 1+count(temp->next);
    }
    int max()
    {
        return max(head);
    }
    int max(node *temp,int val=INT_MIN)
    {
        if(temp==NULL)
            return val;
        val=std::max(val,temp->data);
        return std::max(val,max(temp->next));
    }
    int search()
    {
        cout<<"Enter element to be searched : ";
        int n;cin>>n;
        return search(head,n);
    }
    int search(node *temp,int val)
    {
        if(temp==NULL)
            return 0;
        if(temp->data==val)
            return 1;
        return search(temp->next,val);
    }
    void improved_search()
    {
        int val;int cnt=0;
        cout<<"\nEnter value to be searched : ";
        cin>>val;
        cout<<improved_search(head,head,val,cnt)<<" in "<<cnt<<" compartions\n";
    }
    int improved_search(node *temp,node *prev,int val,int &cnt)
    {
        if(temp==NULL)
            return 0;
        cnt++;
        if(temp->data==val)
        {
            if(prev!=head)
            {
                prev->next=temp->next;
                temp->next=head;
                head=temp;
            }
            return 1;
        }
        return improved_search(temp->next,temp,val,cnt);
    }
    void insert()
    {
        int indx,val;
        cout<<"\nEnter value : ";
        cin>>val;
        cout<<"Enter Index : ";
        cin>>indx;
        if(indx<0 || indx>count(head))
        {
            cout<<"You have entered invalid index !!";
            cout<<"\nDo you want to insert at end of list?(Y/N)";
            char ans;cin>>ans;
            if(ans=='y'|| ans=='Y')
                insert(head,val,count(head)-1);
            return;
        }
        insert(head,val,(indx==0)?0:indx-1);
    }
    void insert(node *temp,int value,int index)
    {
            if(index!=0)
            {
                insert(temp->next,value,index-1);
                return;
            }
            node *new_temp=new node;
            new_temp->next=temp->next;
            temp->next=new_temp;
            new_temp->data=value;
    }
    void insert_sorted()
    {
        cout<<"Enter value to be inserted in sorted list : ";
        int val;
        cin>>val;
        if(val<=(head->data)||head==NULL)
        {
            node *new_node=new node();
            new_node->data=val;
            new_node->next=head;
            head=new_node;
        }
        else
        {
            insert_sorted(head,val);
        }
    }
    void insert_sorted(node *temp,int value)
    {
        if(temp->data<value)
        {
            if((temp->next)!=NULL && temp->next->data<value)
            {
                insert_sorted(temp->next,value);
            }
            else
            {
                node *new_node =new node;
                new_node->data=value;
                new_node->next=temp->next;
                temp->next=new_node;
            }
        }
    }
    bool isSorted()
    {
        if(head==NULL)
            return true;
        if(head->next==NULL)
            return true;
        else
            isSorted(head,head->next);
    }
    bool isSorted(node *temp,node *temp_next)
    {
        if(temp_next==NULL)
            return true;
        if(temp->data>temp_next->data)
            return false;
        return isSorted(temp_next,temp_next->next);
    }
    void delete_at_index()
    {
        int indx;
        cout<<endl<<"Enter index of the node to be deleted : ";
        cin>>indx;
        if(indx<0 || indx>count(head)-1)
        {
            cout<<"Invalid index\nDelete operation failed to delete!";
            return;
        }
        if(indx==0)
        {
            node *temp=head;
            head=head->next;
            free(temp);
            return;
        }
        delete_at_index(NULL,head,indx,0);
        cout<<endl<<"Successfully deleted element at "<<indx<<endl;
    }
    void delete_at_index(node *prev,node *temp,int index,int i)
    {
        if(i==index)
        {
            node *te=temp;
            prev->next=temp->next;
            delete te;
            return;
        }
        return delete_at_index(temp,temp->next,index,i+1);
    }
};
int main()
{
    linkedlist a;
    a.create();
    a.display();
    a.delete_at_index();
    a.display();
    a.insert_sorted();
    a.display();
    cout<<endl;
    cout<<"sum is : "<<a.sum()<<"\nCount is : " <<a.count();
    a.reverse_display();
    cout<<"Maximum element : "<<a.max()<<endl;
    cout<<"Searching"<<a.search();
    a.improved_search();
    a.display();
    if(a.isSorted())
    {
        cout<<endl<<endl<<"Sorted"<<endl;
    }
    else
    {
        cout<<endl<<endl<<"Not Sorted"<<endl;
    }
    a.insert_sorted();
    a.display();
    a.insert_sorted();
    a.display();
    a.insert_sorted();
    a.display();
    return 0;
}
