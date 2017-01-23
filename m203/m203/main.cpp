//
//  main.cpp
//  m203
//
//  Created by mike on 15/9/28.
//  Copyright © 2015年 mike. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
float triple[50][3];
float L[50][3];
float D[50]={0};

int numnode=0;
int numPath=0;

int startNode=0,endNode=0;

void dij()
{
    int min=1000;
    int W=0;
    int V=0;
    int mark=0,snum=1;
    int C[50]={0};
    int C1[50]={0};
    int S[50]={0};
    S[0]=startNode;
    int cNum=0,cnum1=0;
    bool state=true;
    
    for(int i=0;i<numPath;i++)
    {
        if(L[i][0]==startNode)
        {
            W=L[i][1];
            C[cNum]=W;
            cNum++;
            D[W]=L[i][2];
            
        }
        if(L[i][1]==startNode)
        {
            W=L[i][0];
            C[cNum]=W;
            cNum++;
            D[W]=L[i][2];
        }
    }
    while(state==true)
    {
    for(int k=0;k<cNum;k++)
    {
        
         for(int j=0;j<cNum;j++)//work out the index of the minimum D[v] not yet selected
         {
             if(D[C[j]]<min&&D[C[j]]!=0)
             {
                 min=D[C[j]];
                 V=C[j];
                 mark=j;
             }
         }
 
        S[snum]=C[mark];//put it into S array
        snum++;//S array counter
        C[mark]=0;//delete from C array
        min=1000;
        
        for(int i=0;i<numPath;i++)
        {
            if(L[i][0]==V)
            {
                W=L[i][1];
                if(D[W]==0)
                {
                    D[W]=D[V]+L[i][2];
                    C1[cnum1]=W;
                    cnum1++;
                }
                else
                {
                if(D[W]>D[V]+L[i][2])
                    D[W]=D[V]+L[i][2];
                }
                //C1[cnum1]=W;
                //cnum1++;
            }
            if(L[i][1]==V)
            {
                W=L[i][0];
                if(D[W]==0)
                {
                    D[W]=D[V]+L[i][2];
                    C1[cnum1]=W;
                    cnum1++;
                }
                else
                {
                    if(D[W]>D[V]+L[i][2])
                        D[W]=D[V]+L[i][2];
                }
                //C1[cnum1]=W;
                //cnum1++;
            }
        }
    }
        D[startNode]=0;
        
        for(int i=0;i<snum;i++)
        {
            if(S[i]==endNode)
            {
                int fake=endNode;
                int path[50];
                int pathnum=0;
            cout<<"The length of the shortest path from solution 1: "<<D[endNode]<<endl;
                while(fake!=startNode)
                {
                    for(int k=0;k<numPath;k++)
                    {
                        if(L[k][0]==fake)
                        {
                            int a=L[k][1];
                                if((D[a]+L[k][2])==D[fake])
                                {
                                    path[pathnum]=a;
                                    pathnum++;
                                    fake=a;
                                }
                            
                        }
                        if(L[k][1]==fake)
                        {
                            int a=L[k][0];
                            if((D[a]+L[k][2])==D[fake])
                            {
                                path[pathnum]=a;
                                pathnum++;
                                fake=a;
                            }
                            
                        }
                    }
                    
                }
            cout<<"The Path (list of nodes) from solution 1: ";
                for(int i=pathnum-1;i>-1;i--)
                {
                    cout<<path[i]<<" -> ";
                }
                cout<<endNode<<endl;
                
            cout<<"The number of additional nodes in the solution tree for solution 1: "<<snum-pathnum<<endl;
            state=false;
            break;
            }
        }
        cNum=cnum1;
        for(int i=0;i<cnum1;i++)
        {
            
                C[i]=C1[i];
        }
        cnum1=0;
        
    }
    
}
 
void a()
{
    
    float a=(triple[startNode-1][2]-triple[endNode-1][2])/(triple[startNode-1][1]-triple[endNode-1][1]);
    float b=triple[startNode-1][2]-a*triple[startNode-1][2];
    int nearNode[50]={0};
    int nNode=0;
    int nNum=0;
    float lenth=0;
    int anode=0;
    float smally=1000;
    int start=startNode;
    int start1=startNode;
    int end=endNode;
    int alnum=0;
    while(1){
    for(int i=0;i<numPath;i++)
    {
        if(L[i][0]==start1)
        {
            
            anode=L[i][1];
            //cout<<triple[startNode-1][1]<<endl;
            
            if(triple[anode-1][1]>triple[start1-1][1]&&triple[anode-1][1]<triple[endNode-1][1])
            {
                alnum++;
                int y=a*triple[anode-1][1]+b;//work out the value of the Y coordinate of the line between start node and end node
                if(triple[anode-1][2]>y)
                    if(triple[anode-1][2]-y<smally)
                    {
                        smally=triple[anode-1][2]-y;
                        nNode=anode;
                        
                    }
                if(triple[anode-1][2]<y)
                    if(y-triple[anode-1][2]<smally)
                    {
                        
                        smally=y-triple[anode-1][2];
                        nNode=anode;
                        
                    }
            }
            if(L[i][1]==endNode)
            {
                for(int i=0;i<nNum;i++)
                {
                    for(int j=0;j<numPath;j++)
                    {
                        if(L[j][0]==start&&L[j][1]==nearNode[i])
                        {
                            start=nearNode[i];
                            lenth+=L[j][2];
                        }
                        if(L[j][1]==start&&L[j][0]==nearNode[i])
                        {
                            start=nearNode[i];
                            lenth+=L[j][2];
                        }
                    
                    }
                
                }
                for(int j=0;j<numPath;j++)
                {
                    if(L[j][0]==start&&L[j][1]==end)
                    {
                        lenth+=L[j][2];
                    }
                    if(L[j][1]==start&&L[j][0]==end)
                    {
                        lenth+=L[j][2];
                    }
                    
                }
                cout<<"The length of the shortest path from solution 2: "<<lenth<<endl;
                return;
            
            }
            
        }
        if(L[i][1]==start1)
        {
            
            anode=L[i][0];
            if(triple[anode-1][1]>triple[start1-1][1]&&triple[anode-1][1]<triple[endNode-1][1])
            {
                alnum++;
                
                int y=a*triple[anode-1][1]+b;//work out the value of the Y coordinate of the line between start node and end node
                if(triple[anode-1][2]>y)
                    if(triple[anode-1][2]-y<smally)
                    {
                        smally=triple[anode-1][2]-y;
                        nNode=anode;
                        
                    }
                if(triple[anode-1][2]<y)
                    if(y-triple[anode-1][2]<smally)
                    {
                        
                        smally=y-triple[anode-1][2];
                        nNode=anode;
                        
                    }
            }
            if(L[i][0]==endNode)
            {
                for(int i=0;i<nNum;i++)
                {
                    for(int j=0;j<numPath;j++)
                    {
                        if(L[j][0]==start&&L[j][1]==nearNode[i])
                        {
                            start=nearNode[i];
                            lenth+=L[j][2];
                            
                        }
                        if(L[j][1]==start&&L[j][0]==nearNode[i])
                        {
                            start=nearNode[i];
                            lenth+=L[j][2];
                            
                        }
                        
                    }
                    
                }
               
                for(int j=0;j<numPath;j++)
                {
                    if(L[j][0]==start&&L[j][1]==end)
                    {
                        lenth+=L[j][2];
                    }
                    if(L[j][1]==start&&L[j][0]==end)
                    {
                        lenth+=L[j][2];
                    }
                    
                }
                cout<<"The length of the shortest path from solution 2: "<<lenth<<endl;
                cout<<"The Path (list of nodes) from solution 2: "<<startNode<<" -> ";
                for(int i=0;i<nNum;i++)
                {
                    cout<<nearNode[i]<<" -> ";
                
                }
                cout<<endNode<<endl;
                cout<<"The number of additional nodes in the solution tree for solution2(those not in the shortestpath) "<<alnum-nNode<<endl;
                return;
            }

        
        }
        
    }
    nearNode[nNum]=nNode;
    nNum++;
    start1=nNode;
        smally=1000;
    //cout<<nNode<<endl;
    
    }
}

void pia()//in this algorithm, i find the node they meet, then use Diskstra's algorithm to find the path from startnode to this node and endnode to this node, like use solution 1 two times(from startnode to meetnode and from endnode to meetnode)
{
    
    int C[50]={0},C1[50]={0};
//    int D[50]={0},D1[50]={0};
    int cnum=1,c1num=1;
    float state=true;
    int tmp=1;
    C[0]=startNode;
    C1[0]=endNode;
    int totalnum=0;
    while(state==true)
    {
        int snum=cnum;
        int s1num=c1num;
        
        for(int k=0;k<snum;k++)
        {
            //cout<<snum<<endl;
            //cout<<"here"<<endl;
            for(int i=0;i<numPath;i++)
            {
                    if(L[i][0]==C[k])
                    {
                        for(int j=0;j<cnum;j++)
                        {
                            if(C[j]==L[i][1])
                                tmp=0;
                        }
                        if(tmp==1)
                        {
                            C[cnum]=L[i][1];
                            cnum++;
                        }
                    }
                
                
                
                    if(L[i][1]==C[k])
                    {
                        for(int j=0;j<cnum;j++)
                        {
                            if(C[j]==L[i][0])
                                tmp=0;
                        }
                        if(tmp==1)
                        {
                            C[cnum]=L[i][0];
                            //cout<<C[cnum]<<" "<<cnum<<endl;
                            cnum++;
                        }
                    }
                tmp=1;
            }
        }
        
        for(int k=0;k<s1num;k++)
        {
            for(int i=0;i<numPath;i++)
            {
                if(L[i][0]==C1[k])
                {
                    for(int j=0;j<c1num;j++)
                    {
                        if(C1[j]==L[i][1])
                            tmp=0;
                    }
                    if(tmp==1)
                    {
                        C1[c1num]=L[i][1];
                        //cout<<C1[c1num]<<endl;
                        c1num++;
                        
                    }
                }
                
                
                
                if(L[i][1]==C1[k])
                {
                    for(int j=0;j<c1num;j++)
                    {
                        if(C[j]==L[i][0])
                            tmp=0;
                    }
                    if(tmp==1)
                    {
                        C1[c1num]=L[i][0];
                        c1num++;
                    }
                }
                tmp=1;
            }
        }
        totalnum=cnum+c1num;
        for(int i=0;i<cnum;i++)
        {
            
            for(int j=0;j<c1num;j++)
            {
                
                if(C[i]==C1[j])
                {
                    int end=endNode;
                    endNode=C[i];
                    float lenth=0;
                    int p[50]={0};
                    int pnum=0;
//=======================================>1 time
                    
                    int min=1000;
                    int W=0;
                    int V=0;
                    int mark=0,snum=1;
                    int C[50]={0};
                    int C1[50]={0};
                    int S[50]={0};
//                    int smark=0;
                    S[0]=startNode;
                    int cNum=0,cnum1=0;
                    bool state=true;
                    
                    for(int i=0;i<numPath;i++)
                    {
                        if(L[i][0]==startNode)
                        {
                            W=L[i][1];
                            C[cNum]=W;
                            cNum++;
                            D[W]=L[i][2];
                            
                        }
                        if(L[i][1]==startNode)
                        {
                            W=L[i][0];
                            C[cNum]=W;
                            cNum++;
                            D[W]=L[i][2];
                        }
                    }
                    while(state==true)
                    {
                        for(int k=0;k<cNum;k++)
                        {
                            
                            for(int j=0;j<cNum;j++)//work out the index of the minimum D[v] not yet selected
                            {
                                if(D[C[j]]<min&&D[C[j]]!=0)
                                {
                                    min=D[C[j]];
                                    V=C[j];
                                    mark=j;
                                }
                            }
                            
                            S[snum]=C[mark];//put it into S array
                            snum++;//S array counter
                            C[mark]=0;//delete from C array
                            min=1000;
                            
                            for(int i=0;i<numPath;i++)
                            {
                                if(L[i][0]==V)
                                {
                                    W=L[i][1];
                                    if(D[W]==0)
                                    {
                                        D[W]=D[V]+L[i][2];
                                        C1[cnum1]=W;
                                        cnum1++;
                                    }
                                    else
                                    {
                                        if(D[W]>D[V]+L[i][2])
                                            D[W]=D[V]+L[i][2];
                                    }
                                    //C1[cnum1]=W;
                                    //cnum1++;
                                }
                                if(L[i][1]==V)
                                {
                                    W=L[i][0];
                                    if(D[W]==0)
                                    {
                                        D[W]=D[V]+L[i][2];
                                        C1[cnum1]=W;
                                        cnum1++;
                                    }
                                    else
                                    {
                                        if(D[W]>D[V]+L[i][2])
                                            D[W]=D[V]+L[i][2];
                                    }
                                    //C1[cnum1]=W;
                                    //cnum1++;
                                }
                            }
                        }
                        D[startNode]=0;
                        
                        for(int i=0;i<snum;i++)
                        {
                            if(S[i]==endNode)
                            {
                                int fake=endNode;
                                int path[50];
                                int pathnum=0;
                                
                                while(fake!=startNode)
                                {
                                    for(int k=0;k<numPath;k++)
                                    {
                                        if(L[k][0]==fake)
                                        {
                                            int a=L[k][1];
                                            if((D[a]+L[k][2])==D[fake])
                                            {
                                                path[pathnum]=a;
                                                pathnum++;
                                                fake=a;
                                            }
                                            
                                        }
                                        if(L[k][1]==fake)
                                        {
                                            int a=L[k][0];
                                            if((D[a]+L[k][2])==D[fake])
                                            {
                                                path[pathnum]=a;
                                                pathnum++;
                                                fake=a;
                                            }
                                            
                                        }
                                    }
                                    
                                }
                                lenth=D[endNode];
                                
                                for(int i=pathnum-1;i>-1;i--)
                                {
                                    p[pnum]=path[i];
                                    pnum++;
                                }
                                
                                state=false;
                                break;
                                 
                            }
                        }
                        cNum=cnum1;
                        for(int i=0;i<cnum1;i++)
                        {
                            
                            C[i]=C1[i];
                        }
                        cnum1=0;
                        
                    }

                    startNode=end;
                    
                   
                    //--------------------------------------------------->2
                    
                     min=1000;
                     W=0;
                     V=0;
                     mark=0;
                   
                    for(int i=0;i<cNum;i++)
                        C[i]=0;
                    for(int i=0;i<cnum1;i++)
                        C1[i]=0;
                    for(int i=0;i<snum;i++)
                        S[i]=0;
                    for(int i=0;i<50;i++)
                        D[i]=0;
                    //                    int smark=0;
                    S[0]=startNode;
                    cNum=0;
                    cnum1=0;
                    snum=1;
                     state=true;
                    
                    for(int i=0;i<numPath;i++)
                    {
                        if(L[i][0]==startNode)
                        {
                            W=L[i][1];
                            C[cNum]=W;
                            cNum++;
                            D[W]=L[i][2];
                            
                        }
                        if(L[i][1]==startNode)
                        {
                            W=L[i][0];
                            C[cNum]=W;
                            cNum++;
                            D[W]=L[i][2];
                        }
                    }
                    while(state==true)
                    {
                        for(int k=0;k<cNum;k++)
                        {
                            
                            for(int j=0;j<cNum;j++)//work out the index of the minimum D[v] not yet selected
                            {
                                if(D[C[j]]<min&&D[C[j]]!=0)
                                {
                                    min=D[C[j]];
                                    V=C[j];
                                    mark=j;
                                }
                            }
                            
                            S[snum]=C[mark];//put it into S array
                            snum++;//S array counter
                            C[mark]=0;//delete from C array
                            min=1000;
                            
                            for(int i=0;i<numPath;i++)
                            {
                                if(L[i][0]==V)
                                {
                                    W=L[i][1];
                                    if(D[W]==0)
                                    {
                                        D[W]=D[V]+L[i][2];
                                        C1[cnum1]=W;
                                        cnum1++;
                                    }
                                    else
                                    {
                                        if(D[W]>D[V]+L[i][2])
                                            D[W]=D[V]+L[i][2];
                                    }
                                    //C1[cnum1]=W;
                                    //cnum1++;
                                }
                                if(L[i][1]==V)
                                {
                                    W=L[i][0];
                                    if(D[W]==0)
                                    {
                                        D[W]=D[V]+L[i][2];
                                        C1[cnum1]=W;
                                        cnum1++;
                                    }
                                    else
                                    {
                                        if(D[W]>D[V]+L[i][2])
                                            D[W]=D[V]+L[i][2];
                                    }
                                    //C1[cnum1]=W;
                                    //cnum1++;
                                }
                            }
                        }
                        D[startNode]=0;
                        
                        for(int i=0;i<snum;i++)
                        {
                            if(S[i]==endNode)
                            {
                                int fake=endNode;
                                int path[50];
                                int pathnum=0;
                                
                                while(fake!=startNode)
                                {
                                    for(int k=0;k<numPath;k++)
                                    {
                                        if(L[k][0]==fake)
                                        {
                                            int a=L[k][1];
                                            if((D[a]+L[k][2])==D[fake])
                                            {
                                                path[pathnum]=a;
                                                pathnum++;
                                                fake=a;
                                            }
                                            
                                        }
                                        if(L[k][1]==fake)
                                        {
                                            int a=L[k][0];
                                            if((D[a]+L[k][2])==D[fake])
                                            {
                                                path[pathnum]=a;
                                                pathnum++;
                                                fake=a;
                                               
                                            }
                                            
                                        }
                                    }
                                    
                                }
                                cout<<"The length of the shortest path from solution 3: "<<lenth+D[endNode]<<endl;
                                cout<<"The Path (list of nodes) from solution 3: ";
                                for(int i=0;i<pnum;i++)
                                {
                                    cout<<p[i]<<" -> ";
                                }
                                cout<<endNode<<" -> "<<endl;
                                for(int i=0;i<pathnum;i++)
                                 {
                                 cout<<path[i];
                                     if(i!=pathnum-1)
                                         cout<<" -> ";
                                 }
                                cout<<endl;
                                
                                cout<<"The number of additional nodes in the solution tree for solution 3: "<<snum<<endl;
                                state=false;
                                break;
                                
                            }
                        }
                        cNum=cnum1;
                        for(int i=0;i<cnum1;i++)
                        {
                            
                            C[i]=C1[i];
                        }
                        cnum1=0;
                        
                    }
                    
                    
                    state=false;
                    return;
                }
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    ifstream ins;
    cout<<"plz input the filename"<<endl;
    //char a[100];
    //cin>>a;
    ins.open("/Users/mike/Desktop/new/123/m203/m203/1.txt");
    
    
    while(ins.good())
    {
        ins>>numnode;
        for(int k=0;k<numnode;k++)
            ins>>triple[k][0]>>triple[k][1]>>triple[k][2];
        ins>>numPath;
        for(int k=0;k<numPath;k++)
            ins>>L[k][0]>>L[k][1]>>L[k][2];
        ins>>startNode>>endNode;
        
    }
    dij();//modified Diskstra's algorithm
    a();//variant
    pia();//proposed improved algorithm

    return 0;
}
