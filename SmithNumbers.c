#include <stdio.h>
#include <math.h>
#define max 46400

int p[max+1];
int a[6000];
int prime(){
	int k = 0
	int j,i;
	for( i = 1; i < max; i++)
		p[i]=1;
	for(i = 2 ; i <= sqrt(max);){
		for(j = i + i; j <= max; j += i) p[j]=0;
		for(i++; !p[i];i++);
	}
	for(i = 1;i <= max; i++)
		if(p[i]) a[k++]=i;  
	return 0;
}

int main(){
	long int i,j,n,a1,k,sum1,m,s;
	long int fl=0;
	prime();
	scanf("%ld",&n);
	for(i = 0; i < n; i++){
		scanf("%ld",&a1);
	for(j = a1 + 1;;j++){
		sum1 = 0;
		k=0;
	  for(m = j;m != 0; m /= 10)
		  sum1 += (m%10);
	  m = j;
	  s = (long int)sqrt(m);
	  long int o;
	  for(o = 1; a[o] <=s && k<=sum1;o++){
		 if(m%a[o]==0){
			  long int ds=0;
              for(long int dm = a[o]; dm! = 0; dm/=10) ds+=(dm%10); 
			  while(m%a[o]==0){
			        k+=ds;
			        m=m/a[o];
			  }
		  }
	  }
	  if(m!=1 && k!=0){
		   for (long int dm=m;m!=0;m/=10)
			                   k+=(m%10);
	  }
	  if(sum1==k)
		  break;
	}
	printf("%ld\n",j);
  }
  return 0;
}
