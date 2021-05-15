#include <iostream>
#include <algorithm> 
#include <iomanip> 
#include <queue>
#include <string.h>
using namespace std;

struct process {
    int processid;
    int artime;
    int brstime;
    int strtime;
    int completetime;
    int tat;
    int wt;
    int rt;
};

bool compare(process p1, process p2) 
{ 
    return p1.artime < p2.artime;
}

bool compareid(process p1, process p2) 
{  
    return p1.processid < p2.processid;
}

bool comparerr(process p1,process p2)
{
    return p1.artime < p2.artime;
}

bool comparedidrr(process p1,process p2)
{
    return p1.processid< p2.processid;
}

bool comparesjf(process p1,process p2)
{
    return p1.artime < p2.artime;
}

bool comparesjfid(process p1,process p2)
{
    return p2.processid < p2.processid;
}
int main() {

    int n;
    int quantumtime;
    struct process p[100];
    int total_tat = 0;
    int total_wt = 0;
    int total_rt = 0;
    int total_idle_time = 0;
    int burstrem[100];
    int idx;
    int isitfinished[100];

    cout << setprecision(2) << fixed;

    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"Enter time quantum-";
    cin>>quantumtime;

    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].artime;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].brstime;
        burstrem[i]=p[i].brstime;
        p[i].processid = i+1;
        cout<<endl;
    }
    
    sort(p,p+n,comparesjf);
    
    int currenttimesjf=0;
    int completeddsjf=0;
    int prev=0;
    memset(isitfinished,0,sizeof(isitfinished));
    
    while(completeddsjf!=n) {
        int idx=-1;
        int mn = 10000000;
        for(int i=0; i<n; i++){
            if(p[i].artime<=currenttimesjf && isitfinished[i]==0){
                if(p[i].brstime<mn){
                    mn=p[i].brstime;
                    idx=i;
                }
                if(p[i].brstime==mn){
                    if(p[i].artime < p[idx].artime){
                        mn=p[i].brstime;
                        idx=i;
                    }
                }
            }
        }
        if(idx!=-1){
            p[idx].strtime=currenttimesjf;
            p[idx].completetime=p[idx].strtime+p[idx].brstime;
            p[idx].tat=p[idx].completetime-p[idx].artime;
            p[idx].wt=p[idx].tat-p[idx].brstime;
            p[idx].rt=p[idx].strtime-p[idx].artime;
            
            total_tat+=p[idx].tat;
            total_wt+=p[idx].wt;
            total_rt+=p[idx].rt;
            total_idle_time+=p[idx].strtime-prev;
            
            isitfinished[idx]=1;
            completeddsjf++;
            currenttimesjf=p[idx].completetime;
            prev=currenttimesjf;
        }
        else{
            currenttimesjf++;
        }
    }
    

    sort(p,p+n,comparerr);
    
    queue<int> q;
    int currenttime=0;
    q.push(0);
    int completedd=0;
    int mark[100];
    memset(mark,0,sizeof(mark));
    mark[0] = 1;
    
    while(completedd!=n){
        idx=q.front();
        q.pop();
        
        if(burstrem[idx]==p[idx].brstime){
            p[idx].strtime = max(currenttime,p[idx].artime);
            total_idle_time+=p[idx].strtime - currenttime;
            currenttime = p[idx].strtime;
        }
        if(burstrem[idx] - quantumtime > 0){
            burstrem[idx] -= quantumtime;
            currenttime += quantumtime;
        }
        else{
            currenttime += burstrem[idx];
            burstrem[idx] = 0;
            completedd++;
            
            p[idx].completetime = currenttime;
            p[idx].tat = p[idx].completetime - p[idx].artime;
            p[idx].wt = p[idx].tat - p[idx].brstime;
            p[idx].rt= p[idx].strtime - p[idx].artime;
            
            total_tat += p[idx].tat;
            total_wt += p[idx].wt;
            total_rt += p[idx].rt;
        }
         for(int i = 1; i < n; i++) {
            if(burstrem[i] > 0 && p[i].artime <= currenttime && mark[i] == 0) {
                q.push(i);
                mark[i] = 1;
            }
        }
        if(burstrem[idx] > 0) {
            q.push(idx);
        }

        if(q.empty()) {
            for(int i = 1; i < n; i++) {
                if(burstrem[i] > 0) {
                    q.push(i);
                    mark[i] = 1;
                    break;
                }
        }
}
    sort(p,p+n,compare);

    for(int i = 0; i < n; i++) {
        p[i].strtime = (i == 0)?p[i].artime:max(p[i-1].completetime,p[i].artime);
        p[i].completetime = p[i].strtime + p[i].brstime;
        p[i].tat = p[i].completetime - p[i].artime;
        p[i].wt = p[i].tat - p[i].brstime;
        p[i].rt = p[i].strtime - p[i].artime;

        total_tat += p[i].tat;
        total_wt += p[i].wt;
        total_rt += p[i].rt;
        total_idle_time += (i == 0)?(p[i].artime):(p[i].strtime - p[i-1].completetime);
    }

    sort(p,p+n,compareid);

    cout<<endl;
    cout<<"#P\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<p[i].processid<<"\t"<<p[i].artime<<"\t"<<p[i].brstime<<"\t"<<p[i].strtime<<"\t"<<p[i].completetime<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t"<<"\n"<<endl;
    }
  
    sort(p,p+n,comparedidrr);
    
    cout<<endl;
    cout<<"#Processid\t"<<"ATrr\t"<<"BTrr\t"<<"STrr\t"<<"CTrr\t"<<"TATrr\t"<<"WTrr\t"<<"RTrr\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<p[i].processid<<"\t"<<p[i].artime<<"\t"<<p[i].brstime<<"\t"<<p[i].strtime<<"\t"<<p[i].completetime<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t"<<"\n"<<endl;
    }
   
    sort(p,p+n,comparesjfid);
    
    cout<<endl;
    cout<<"#Processid\t"<<"ATsjf\t"<<"BTsjf\t"<<"STsjf\t"<<"CTsjf\t"<<"TATsjf\t"<<"WTsjf\t"<<"RTsjf\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<p[i].processid<<"\t"<<p[i].artime<<"\t"<<p[i].brstime<<"\t"<<p[i].strtime<<"\t"<<p[i].completetime<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t"<<"\n"<<endl;
    }
   
    
}
}












