//NOTE: The Event Of Loosing An ACK Or Data Packet Depends On Random Function Present In Line 54 and Line 82.

#include<bits/stdc++.h>
#include<windows.h>                     //For Sleep() and system() function calls
using namespace std;

int srand();
int SeqNo,flag=-1,x;


class Recieving
{
  public:

     //Sending Side Physical Layer
    void RecievingPhysical(string data)
    {
        cout<<endl<<endl;
        cout<<"RECIEVER SIDE  "<<endl;
        cout<<"=============="<<endl;
        cout<<endl<<endl;
        cout<<"[PHYSICAL LAYER] "<<endl<<endl;
        cout<<"Signal Recieved via Communication Channel"<<endl;
        cout<<"Demodulating Data ";
        for(int i=0;i<4;i++)
        {
            Sleep(500);
            cout<<".";
        }
        cout<<"\nPacket Sent To Data Link Layer "<<endl;
        system("pause");
        RecievingDataLink(data);
        return ;
    }


    //Sending Side Data Link Layer
    void RecievingDataLink(string data)
    {
        cout<<endl<<endl;
        cout<<"[DATA LINK LAYER]"<<endl<<endl;
        cout<<"Packet With SeqNo. "<<SeqNo<<" And Data '"<<data<<"' Recieved From Physical Layer "<<endl;
        cout<<"Making Frame";
        for(int i=0;i<4;i++)
        {
            Sleep(500);
            cout<<".";
        }
        cout<<"\nFrame Sent To Network Layer "<<endl;
        system("pause");
        cout<<endl<<"------ACK SENT------"<<endl<<endl<<endl;

        //If x comes out to be 0 then we say packet has been lost
        x=rand()%2;
        if(!x)
            flag=0;
        return;
    }

}R;


class Sending
{
    public:
    //Sending Side Physical Layer
    void SendingPhysical(string data)
    {
        cout<<endl<<endl;
        cout<<"[PHYSICAL LAYER]"<<endl<<endl;
        cout<<"Packet Recieved From Data Link Layer "<<endl;
        cout<<"Modulating Data ";
        for(int i=0;i<4;i++)
        {
            Sleep(500);
            cout<<".";
        }
        cout<<"\nSignal Transmitted via Communication Channel "<<endl;
        system("pause");

        //If x comes out to be 0 then we say packet has been lost
        x=rand()%2;
        if(x)
            R.RecievingPhysical(data);
        else
            flag=0;
        return ;
    }


    //Sending Side Data Link Layer
    void SendingDataLink(string data)
    {
        cout<<endl<<endl;
        cout<<"[DATA LINK LAYER]"<<endl<<endl;
        cout<<"Packet Recieved From Network Layer "<<endl;
        cout<<"Making Frame With Seq no. "<<SeqNo<<" ";
        for(int i=0;i<4;i++)
        {
            Sleep(500);
            cout<<".";
        }
        cout<<"\nFrame Sent To Physical Layer "<<endl;
        system("pause");
        SendingPhysical(data);
        return;
    }


    //Sending Side Network Layer
    void SendingNetwork(string data)
    {
        SeqNo=0;
        cout<<"\nSending Datagram To Data Link Layer";
        for(int i=0;i<4;i++)
        {
            Sleep(500);
            cout<<".";
        }
        cout<<"\nDatagram Sent To Data Link Layer "<<endl;
        system("pause");
        SendingDataLink(data);

        //This Statement is Run Only When All The Functions Return
        if(flag==-1)
            cout<<"SENDING SIDE NETWORK LAYER\n=========================\n\nAcknowledgement Recieved\n";
        else
        {
            cout<<endl<<endl<<endl<<"--TimeOut---"<<endl;
            system("pause");
            SendingNetwork(data);
        }
        return ;
    }
}S;

int main()
{
    string data;
    int ch=1;
    cout<<"\t\t\t\t\tSTOP AND WAIT PROTOCOL"<<endl;
    cout<<string(120,'=')<<endl<<endl<<endl;

    cout<<"CONNECTION ESTABLISHED "<<endl;
    cout<<"====================== ";
    while(ch==1)
    {
        cout<<"\n\n\n\nEnter Data In Packet : ";
        getline(cin,data);
        system("cls");
        cout<<" SENDER SIDE "<<endl;
        cout<<" ==========="<<endl<<endl;
        cout<<"[NETWORK LAYER]"<<endl<<endl;
        cout<<"Making Datagram";
        S.SendingNetwork(data);                                        //Calling Sender Side Transport Layer
        system("pause");
        system("cls");
        cout<<"Press 1 to Send Another Packet : ";
        cin>>ch;
        if(SeqNo==0)
            SeqNo=1;
    }
    cout<<"\nCONNECTION DISABLED"<<endl;
    cout<<"==================="<<endl;
    return 0;
}
