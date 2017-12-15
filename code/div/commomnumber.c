#include<stdio.h>

int getCommonNumber(int *a,int n)
{
    int candiate=a[0];
    int count=1;
    for(int i=1;i<n;i++){
        if (a[i]==candiate){
            count++;
        }
        else{
            count--;
            if(count==0){
                i+=2;
                candiate=a[i];
            }
        }
    }
    return candiate;
}

int main(){
    int a[17]={1,1,5,9,9,2,2,2,1,1,1,1,5,1,1,1,5};
    int ans=getCommonNumber(a,17);
    printf("%d",ans);
}