#include <iostream>

using namespace std;


int main()
{
    long int a,b,acarreo,result,tmpa,tmpb,last,i;
	while(1){
		cin >> a;
		cin >> b;
		if(a==0 && b==0)
			break;
		result=0;acarreo=0;
		for(i=1;i<=10;i++){
			tmpa=a%10;
			tmpb=b%10;
			last=tmpa+tmpb+acarreo;
			if(last>9){
				result++;
				acarreo=1;
			}
			else
				acarreo=0;
			a=a/10;
			b=b/10;
		}
		if(result==0)
			cout << "No carry operation.\n";
		else if(result==1)
		    cout << result << " carry operation.\n";
	    else
			cout << result << " carry operations.\n";

	}
	return 0;
}
