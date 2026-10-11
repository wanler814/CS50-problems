#include "helpers.h"
#include<math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            int a=image[i][j].rgbtBlue;
            int b=image[i][j].rgbtRed;
            int c=image[i][j].rgbtGreen;
            int d=round((a+b+c)/3.0);
            image[i][j].rgbtBlue=d;
            image[i][j].rgbtRed=d;
            image[i][j].rgbtGreen=d;
        }
    }return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            int a=round(0.393*image[i][j].rgbtRed+0.769*image[i][j].rgbtGreen+0.189*image[i][j].rgbtBlue);
            int b=round(0.349*image[i][j].rgbtRed+0.686*image[i][j].rgbtGreen+0.168*image[i][j].rgbtBlue);
            int c=round(0.272*image[i][j].rgbtRed+0.534*image[i][j].rgbtGreen+0.131*image[i][j].rgbtBlue);
            if(a<=255){
            image[i][j].rgbtRed=a;
            }
            else{
                image[i][j].rgbtRed=255;
            }
            if(b<=255){
            image[i][j].rgbtGreen=b;
            }
            else{
                image[i][j].rgbtGreen=255;
            }
            if(c<=255){
            image[i][j].rgbtBlue=c;
            }
            else{
                image[i][j].rgbtBlue=255;
            }

        }
    }return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++){
        for(int j=0;j<=width/2;j++){
            RGBTRIPLE temp=image[i][j];
            image[i][j]=image[i][width-j-1];
            image[i][width-1-j]=temp;
        }
    }return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{    int Gx[3][3]={
    {-1,0,1},
    {-2,0,2},
    {-1,0,1}
};
    int Gy[3][3]={
        {-1,-2,-1},
        {0,0,0},
        {1,2,1}
    };
    RGBTRIPLE copy[height][width];
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            copy[i][j]=image[i][j];
            }
        }for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                    float a=0.0;
                    float b=0.0;
                    float c=0.0;
                    float d=0.0;
                    float e=0.0;
                    float f=0.0;
                    for(int k=i-1;k<=i+1;k++){
            if(k>=0&&k<=height-1){
            for(int m=j-1;m<=j+1;m++){
                if(m>=0&&m<=width-1){
                    a+=copy[k][m].rgbtBlue*Gx[k-i+1][m-j+1];
                    b+=copy[k][m].rgbtGreen*Gx[k-i+1][m-j+1];
                    c+=copy[k][m].rgbtRed*Gx[k-i+1][m-j+1];
                    d+=copy[k][m].rgbtBlue*Gy[k-i+1][m-j+1];
                    e+=copy[k][m].rgbtGreen*Gy[k-i+1][m-j+1];
                    f+=copy[k][m].rgbtRed*Gy[k-i+1][m-j+1];

                }
            }

        }
    }   if((a^2+d^2)^(1/2)<=255){
     image[i][j].rgbtBlue=round((a^2+d^2)^(1/2));}
     else{
        image[i][j].rgbtBlue=255;
     }if((b^2+e^2)^(1/2)<=255){
     image[i][j].rgbtGreen=round((b^2+e^2)^(1/2));}
     else{
        image[i][j].rgbtGreen=255;
     }if((c^2+f^2)^(1/2)<=255){
     image[i][j].rgbtRed=round((c^2+f^2)^(1/2));}
     else{
        image[i][j].rgbtRed=255;
     }

            }
        }
       return;
}
