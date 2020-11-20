#include <bits/stdc++.h>

using namespace std;

class element
{
public:
    int col;
    int row;
    int val;
};

class sparse
{
private:
    element *ele;
    int n;
    int m;
    int nums;
public:
    sparse()
    {
        cout<<"Enter number of row : ";
        cin>>n;
        cout<<"Enter number of col : ";
        cin>>m;
        cout<<"Enter number of non-zero elements : ";
        cin>>nums;
        ele=new element[nums];
    }
    sparse (int n,int m,int nums)
    {
        this->n=n;
        this->m=m;
        this->nums=nums;
        ele=new element[nums];
    }
    ~sparse()
    {
        delete []ele;
    }
    void read()
    {
        cout<<endl<<"Enter elements : "<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>ele[i].row>>ele[i].col>>ele[i].val;
        }
    }
    void display()
    {
        cout<<endl<<"Matrix"<<endl;
        int k=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(k<nums && i==ele[k].row && j==ele[k].col)
                {
                    cout<<ele[k++].val<<" ";
                }
                else
                {
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
    }
    sparse* add(sparse obj)
    {
        sparse *ans=new sparse(obj.n,obj.m,obj.nums+nums);
        int k=0;
        int i=0;
        int j=0;
        while(i<obj.nums && j<nums)
        {
            if(ele[i].row<obj.ele[j].row)
            {
                ans->ele[k++]=ele[i++];
            }
            else if(ele[i].row>obj.ele[j].row)
            {
                ans->ele[k++]=obj.ele[j++];
            }
            else
            {
                if(ele[i].col<obj.ele[j].col)
                {
                    ans->ele[k++]=ele[i++];
                }
                else if(ele[i].col>obj.ele[j].col)
                {
                    ans->ele[k++]=obj.ele[j++];
                }
                else
                {
                    ans->ele[k]=ele[i];
                    ans->ele[k++].val=ele[i++].val+obj.ele[j++].val;
                }
            }
        }
        for(;i<nums;) ans->ele[k++]=ele[i++];
        for(;j<obj.nums;) ans->ele[k++]=obj.ele[j++];
        ans->nums=k;
        return ans;
    }
};
int this_main()
{
    sparse k,m;
    sparse *c;
    k.read();
    m.read();
    c=k.add(m);
    k.display();
    m.display();
    c->display();
    return 0;
}
