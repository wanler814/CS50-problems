#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string a=get_string("TEXT:\n");
    for(int i=0;i<strlen(a)-1;i++){
        print_bulb(a[i]);


    }
}

void print_bulb(int bit)
{   int b[8]={0,0,0,0,0,0,0,0};
    int j=7;
    while(bit>0){
        b[j]=bit%2;
        bit/2;
        j--;
    }
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
