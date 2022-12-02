#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char * returnBill(char *str ,char *newWord , char *oldWord){
    char *generatedBill;
    int i,count=0;
    int oldWordLength=strlen(oldWord);
    int newWordLength=strlen(newWord);
    for(i=0;*(str+i)!='\0';i++){
        if(strstr(&str[i],oldWord)==&str[i]){
            count++;
            i+=oldWordLength;
        }
    }
    generatedBill=(char *)malloc(i+ count * (newWordLength-oldWordLength) + 1);  
    i=0;  
    while(*str){
        if(strstr(str,oldWord)==str){
            strcpy(&generatedBill[i],newWord);
            i+=newWordLength;
            str+= oldWordLength;
        }
        else{
            generatedBill[i]=*str;
            i++;
            str+=1;
        }
    }
generatedBill[i]='\0';
return generatedBill;
}
int main(){
    FILE *ptr =NULL;
    char *newString;
    ptr=fopen("bill.txt","r");
    char str[200];
    fgets(str,200,ptr);
    newString= returnBill(str,"Ads Group","{{outlet}}");
    newString = returnBill(newString,"Divyansh","{{name}}");
    newString = returnBill(newString,"10000","{{price}}");
    newString = returnBill(newString,"Cooler","{{item}}");
    printf("%s\n",newString);
   fclose(ptr);
    return 0;
}
