#include<iostream>
using namespace std;
int GetMax(int d[],int N){
    int max=d[0];
    for(int i=0;i<N;i++){
        if(d[i]>max){
            max=d[i];
        }
    }
    return max;
}
void CountSort(int d[],int N,int pos){
      int output[N];
      int count[10]={0};
      int i;

      for(i=0;i<N;i++){
        count[(d[i] / pos) % 10]++;

      }
      for(i=1;i<10;i++){
        count[i]=count[i]+count[i-1];
      }

      for(i=N-1;i>=0;i--){
        output[--count[(d[i]/pos)%10]]=d[i];
      }

      for(i=0;i<N;i++){
        d[i]=output[i];
      }
}
void Radix_Sort(int d[],int N){
      int max=GetMax(d,N);

      for(int pos=1;max/pos>0;pos=pos*10){
        CountSort(d,N,pos);
      }

     
}
int main(){
    int N;
    cin>>N;
    int data[N];

    for(int i=0;i<N;i++){
        cin>>data[i];
    }

   Radix_Sort(data,N);

   cout<<"after sorting:"<<endl;
   for(int i=0;i<N;i++){
    cout<<data[i]<<" ";
   }
}