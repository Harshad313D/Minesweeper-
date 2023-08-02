#include<stdio.h>
#include<string.h>
#define MAX(x,y) ( (x) >= (y) ? (x) : (y) )
char str1[10000],str2[10000],str3[10000];
char a[10000],b[10000];
bool bigger(char t1[],char t2[]){
	int len1=strlen(t1);
	int len2=strlen(t2);
	if(len1>len2)
		return true;
	else if(len1<len2)
		return false;
	else{
		for(int i=0;i<len1;i++)
			if(t1[i]>t2[i])
				return true;
			else if(t1[i]<t2[i])
				return false;
		return true;
	}
}
bool contain(char str[]){
	if(bigger(str,a)&&bigger(b,str))
		return true;
	else
		return false;
}
void plus(char str1[],char str2[],char str3[]){
	int len1=strlen(str1);
	int len2=strlen(str2);
	int len3=MAX(len1,len2)+1;
	int i,j,k,temp,carry;
	str3[len3]='\0';
	for(i=len1-1,j=len2-1,k=len3-1,carry=0;i>=0||j>=0;){
		if(i>=0&&j>=0)
			temp=str1[i--]-'0'+str2[j--]-'0'+carry;
		else if(i>=0)
			temp=str1[i--]-'0'+carry;
		else
			temp=str2[j--]-'0'+carry;
		carry=temp/10;
		temp%=10;
		str3[k--]='0'+temp;
	}
	str3[k]='0'+carry;
	if(str3[0]=='0')
		memmove(str3,str3+1,sizeof(char)*len3);
}
int main(){
	while(scanf("%s%s",a,b)==2){
		if(a[0]=='0'&&b[0]=='0')
			break;
		str1[0]='1',str1[1]='\0';
		str2[0]='2',str2[1]='\0';

		int count=0;
		if(contain(str1))
			count++;
		if(contain(str2))
			count++;
		while(!bigger(str2,b)){
			plus(str1,str2,str3);
			if(contain(str3))
				count++;
			memmove(str1,str2,sizeof(str1));
			memmove(str2,str3,sizeof(str2));
		}
		printf("%d\n",count);
	}
	return 0;
}
