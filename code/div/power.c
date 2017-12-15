#include<stdio.h>
#include<time.h>

static int power(int x,int n);
static int count=0;
static int power(int x,int n){
    switch(n)
    {
        case 0:
            return 1;
            break;
        case 1:
            return (x);
            break;
        case 2:
            count++;
            return (x*x);
            break;
        default:
            break;
    }
    if (0==n%3){
        count+=2;
        return power(x*x*x,n/3);
    }
    if (1==n%3){
        count+=3;
        return power(x*x*x,n/3)*x;
    }
    if (2==n%3){float start=clock();
        count+=4;
        return power(x*x*x,n/3)*x*x;
    }
}

int main(){
    int x=2;
    int n=10;
    for (int i=0;i<9;i++){
        double average=0;
        for(int j=0;j<1000000;j++){
            clock_t start=clock();
            int ans=power(x,n);
            clock_t end=clock();
            average+=(double)(end-start);
        }
        average/=100000;
        printf("%d的%d次幂耗时：%f\n",x,n,average);
        n*=10;
    }

}