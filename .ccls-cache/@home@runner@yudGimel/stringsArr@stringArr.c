// Online C compiler to run C program online
#include <stdio.h>
#define NUMOFLETTERS 26
#define BIGGER(x,y)(x>y)?x:y
#define FALSE 0
#define TRUE 1
#define bool unsigned char

typedef char string[12];



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
    

void frequencyOfLetters(string str,unsigned short mone[] )
{
    unsigned short count, len;
    len=StringLen(str);
    mone[NUMOFLETTERS]=0;
    for(count=0;count<len;mone[str[count++]-'a']++);
}




unsigned short StringAmountInVector(string arr[],string str,unsigned short N)
{
  unsigned short count,sum=0;

  for(count=0;count<N;isEqaul(arr[count++],str)?sum++:0);
    return sum;
}

void commonStringInVector(string arr[], string str,unsigned short N)
{
    unsigned short count=0;
    unsigned short max=StringAmountInVector(arr,arr[0],N);
    string maxString;
    copyString(arr[0],maxString);
    for(count=1;count<N;count++)
    {
        if ( max<StringAmountInVector(arr,arr[count],N))
        {
            max=StringAmountInVector(arr,arr[count],N);
            copyString(arr[count],maxString);
        }
    }
    copyString(maxString,str);
}

void caesar( string str1,string str2,unsigned short offset)
{
    unsigned short count,len;
    len=StringLen(str1);
    offset%=NUMOFLETTERS;
    for (count=0;count<len;count++)
    {
        str2[count] = 'z' >= (str1[count] + offset)?
        str1[count] + offset:
        str1[count] + offset- NUMOFLETTERS;
    }
    str2[count]='\0';
}

void criptedpilandrom(string s, string pil)
{
	unsigned short offset, length = StringLen(s);
	for (offset = 0; offset < length; pil[offset] = ('z' - (s[offset] - 'a')), offset++);
	pil[offset] = 0;
}

unsigned short biggestSeq(string str){
    unsigned short index, count, higher, length;
    index=0;
    count=1;
    higher=0;
    length=StringLen(str);
    for(index=0;index<length;index++)
    {
        count+=(str[index]==str[index+1])?1:-count+1;
        higher=BIGGER(count, higher);
    }
    return higher;
}
unsigned short maxAmountOfSeq(string arr[], unsigned short size){
    unsigned short index, placeHigher, higher;
    index=0;
    placeHigher=0;
    higher=biggestSeq(arr[index]);
    for(index=1;index<size;biggestSeq(arr[index])>higher?higher=biggestSeq(arr[index]),
    placeHigher=index++:index++);
    return placeHigher;
}
bool isSubOfOther(string str1,string str2)
{
   unsigned short len1=StringLen(str1) ,len2=StringLen(str2);
    return len1<len2?isSubString(str2,str1):isSubString(str1,str2);
}

void deleteDup(string str, string result) {
	copyString( str,result);
	unsigned short offset = 0,index=0;
	string temp;
	string temp1;
	while(result[0])
	{
	    copyRange(result,temp1,0,1);
	    amountOfTav(result, result[0]) > 0 ? temp[index++]=result[0], cutSubString( result , temp1 ) : 0;
	    cutSubString( result , temp1 ) ;

	}
	temp[index]='\0';
	copyString( temp,result);
}
void frequencyOfLettersInput(string str)
{
    
    unsigned short mone[NUMOFLETTERS]={0};
    frequencyOfLetters(str,mone);
    deleteDup(str,str);
    unsigned short index,length=StringLen(str);
    for(index=0;index<length;printf("%c %d \n",str[index],mone[str[index]-'a']),index++);
}


	



// int main() {
//     // Write C code here
//     string g="abc",d="ddfyydgddrgd";
//     string arr[]={"fsdf","fdfsdfsd","gfdfff","fdfd","dfdddd"};
//     // printf("%d",isSubOfOther ("arnrafy","arr"));
//     frequencyOfLettersInput(d);
//     // cutSubString(d,"d");
//     // cut(g,0,1);
//     // placeOfSubString(g,d);
//     // cut(d,3,4);
//     // cut(d,4,5);
//     // deleteDup(d,g);
//     // printf(" %s",g);

//     return 0;
// }