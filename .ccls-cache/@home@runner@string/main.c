// Online C compiler to run C program online
#include <stdio.h>
#define FALSE 0
#define TRUE 1
#define bool unsigned char

typedef char string[15];


unsigned short StringLen(string str)
{
unsigned short count=0;
while (str[count++]);

return count-1;
    
}


short placeOfTav(string str,char tav,unsigned short start)
{

unsigned short count=start,temp=0;
while (count<StringLen(str)&& !temp )
{
    temp=(str[count++]==tav?count:0);
}
return temp-1;
    
}
short amountOfTav(string str,char tav)
{

unsigned short count=0,sum=0;
while (str[count++]==tav?++sum:str[count-1]);

return sum;
    
}

bool isEqaul(string str1,string str2)
{
    unsigned short count=0,temp=0;
    while (str1[count]==str2[count++]?str2[++temp]:0);
    return !(StringLen(str1)-temp+(StringLen(str2)-temp));
    
}
void copyString(string str1, string str2){
    unsigned short index;
    for(index=0;index<StringLen(str1);str2[index]=str1[index],index++);
        str2[index]='\0';

}

void copyRange(string str1, string str2, unsigned short start, unsigned short end)
{
    unsigned short index, place=0;
    for(index=start;index<end;str2[place++]=str1[index++]);
    str2[place]='\0';
}

void addString(string str1, string str2){
    unsigned short index, place1=StringLen(str1), place2=StringLen(str2);
    for(index=0;index<=place2;
str1[place1++]=str2[index++]);


}


void reverseString(string str)
{
  unsigned short count, len = StringLen(str);
  char temp;
  for (count = 0; count < len/2; temp = str[count], str[count] = str[len-count-1], str[len-count-1] = temp, count++);
}

bool isPoly(string str)
{
  unsigned short count, len = StringLen(str),temp=0;
  for (count = 0; count < len/2;str[count]==str[len-count-1]?temp++:(count=len/2), count++);
  return !(temp-len/2);
}





void cut(string str, unsigned short start, unsigned short end)
{

    unsigned short len = StringLen(str);
    string str2,str3;
    copyRange(str,str2,0,start );
    copyRange(str,str3,end ,len);
    addString(str2,str3);
    str2[StringLen(str2)]='\0';
    copyString(str2,str);

}


bool isSubString(string str,string sub)
{
    unsigned short count=0,index=placeOfTav(str,sub[0],count);
    string strTemp;
    unsigned short lenSub = StringLen(sub);
    copyRange(str,strTemp,index,index+lenSub);

    while(isEqaul(strTemp,sub)?FALSE:str[count++])
    {
        index=placeOfTav(str,sub[0],count);
        copyRange(str,strTemp,index,lenSub+index);

    }

return isEqaul(strTemp,sub);
}

short placeOfSubString(string str,string sub)
{
     unsigned short count=0,index=placeOfTav(str,sub[0],count);
    string strTemp;
    unsigned short lenSub = StringLen(sub);
    copyRange(str,strTemp,index,index+lenSub);

    while(isEqaul(strTemp,sub)?FALSE:str[count++])
    {
        index=placeOfTav(str,sub[0],count);
        copyRange(str,strTemp,index,lenSub+index);
    }

return index;
}


unsigned short sumOfSubString(string str,string sub)
{
unsigned short length1, length2, index, flag;
    string temp;
    length1=StringLen(sub);
    length2=StringLen(str);
    flag=0;
    for(index=0;index<length2-length1+1;index++)
    {
        copyRange(str,temp, index, index+length1);
        flag+=isEqaul(sub, temp);
    }
    return flag;
}


void cutSubString(string str,string sub)
{
        unsigned short count=1,p1,p2,lenStr;
    unsigned short lenSub = StringLen(sub);
    while(isSubString(str,sub))
    {
        lenStr=StringLen(str);
        p1=placeOfSubString(str,sub);
        p2=placeOfSubString(str,sub)+lenSub;
        cut(str,p1,p2);
    }
    str[StringLen(str)]='\0';

}
void putSubString(string str,string sub,unsigned short start)
{
     unsigned short lenStr = StringLen(str),lenSub = StringLen(sub);
    string str2,str3;
    copyRange(str,str2,0,start+1);
    copyRange(str,str3,start+lenSub-1,lenStr);
    addString(str2,sub);
    str2[StringLen(str2)+StringLen(sub)]='\0';
    addString(str2,str3);
    str2[StringLen(str2)+StringLen(str3)]='\0';
    copyString(str2,str);
    str[StringLen(str2)]='\0';

}

void makeNumString(string str, unsigned short num){
    unsigned short index=0;
    while(num>0?str[index++]=num%10+'0',num/=10:FALSE);
    str[index]='\0';
    reverseString(str);
    printf("%s",str);

    
}
unsigned short makeStringNum(string str){
    unsigned short index=0,num=0;
    while(str[index] ? num += (str[index++]-'0') , num *=10  
:FALSE);
    printf("%d",num/10);
    return num/10;

    
}
    

int main() {
    // Write C code here
    string g="445",d="2rtfdr";
    // printf("\n %d",sumOfSubString("djddfdfdfid","i"));
    unsigned short num=646;
    makeStringNum(g);


    return 0;
}