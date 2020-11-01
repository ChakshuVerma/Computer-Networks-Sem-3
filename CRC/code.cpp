#include<bits/stdc++.h>
using namespace std;

void division(int temp[],int gen[],int n,int r)
{
    for(int i=0;i<n;i++)
        {
        if (gen[0]==temp[i])
        {
            for(int j=0,k=i;j<r+1;j++,k++)
                if(!(temp[k]^gen[j]))
                    temp[k]=0;
                else
                    temp[k]=1;
        }
    }
}

int main()
{
    int n,r,msg[50],gen[50],temp[50];

    cout<<"GIVE SPACE AFTER EACH BIT "<<endl<<endl;
    cout<<"AT SENDER'S END "<<endl;
    cout<<"\nEnter the number of message bits : ";
    cin>>n;
    cout<<"Enter the number of generator bits : ";
    cin>>r;

    cout<<"\nEnter the message : ";
    for(int i=0;i<n;i++)
        cin>>msg[i];
    cout<<"Enter the generator : ";
    for(int i=0;i<r;i++)
        cin>>gen[i];

    r--;
    for(int i=0;i<r;i++)
        msg[n+i] = 0;

    for(int i=0;i<n+r;i++)
        temp[i] = msg[i];
    division(temp,gen,n,r);
    cout<<"\nCRC : ";
    for(int i=0;i<r;i++)
    {
        cout<<temp[n+i]<<" ";
        msg[n+i] = temp[n+i];
    }

    cout<<endl<<"\nTransmitted Message : ";
    for(int i=0;i<n+r;i++)
        cout<<msg[i]<<" ";
    cout<<endl<<endl<<"\nAT RECIEVER'S END "<<endl;
    cout<<"\nEnter the received message : ";
    for(int i=0;i<n+r;i++)
        cin>>msg[i];
    for(int i=0;i<n+r;i++)
        temp[i] = msg[i];
    division(temp,gen,n,r);
    for(int i=0;i<r;i++)
    {
        if(temp[n+i])
        {
            cout<<"\nError detected in received message.";
            return 0;
        }
    }
    cout<<"\nNo error in received Message";
    return 0;
}
