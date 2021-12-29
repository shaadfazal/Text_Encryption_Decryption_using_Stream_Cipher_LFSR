//
//  main.c
//  Correctionstopandgo
//
//  Created by Shaad Fazal on 18/05/20.
//  Copyright © 2020 Shaad Fazal. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main() {
    
    int a[8],b,k,l[8],m[8],z,c,y,x,s=0,w,op[1000],inp_lf1=100,inp_lf2=102,inp_lf3=103,i,encrypt[1000],decrypt[1000],j; //Initialization of arrays and variables to be used
    int val,arr[8],lmt=0,msg[1000],n=0,count=0,num=0;
    FILE *fp,*fpe;
    fp=fopen("/Users/ShaadFazal/Desktop/Mini Project/ma.txt","w+");
    fpe=fopen("/Users/ShaadFazal/Desktop/Mini Project/ea.txt","w+");
    if(fp == NULL)
    {
        printf("h");
    }
    if(fpe==NULL)
    {
        printf("Ok then");
    }
    fprintf(fp,"I am\nnot bad\ni am not\n I am just stupid,okay! ");        // Text to be encrypted
    fclose(fp);
    fp=fopen("/Users/ShaadFazal/Desktop/Mini Project/ma.txt","r+");
    val=fgetc(fp);
    while(val!=EOF)
    {
        while(val>0)
        {
            for(lmt=0;lmt<8;lmt++)
            {
                arr[lmt]=val%2;                                     // Reading file character-wise and converting to binary equivalent from ASCII number
                val=val/2;
            }
            
        }
        val=fgetc(fp);
        lmt=0;
        while(lmt<8)
        {
            msg[n++]=arr[lmt++];                                    // Populating the input bitstream array
            
        }
        
        
        
    }
    
    for(lmt=0;lmt<n;lmt++)
    {
        count=count+1;                                          // Calculating number of bits
    }
    printf("\n%d",count);
    fclose(fp);
    

    
    while(inp_lf3>0)
    {
        for(i=0;i<8;i++)
        {
            a[7-i] = (inp_lf3)%2;                           // Intializing input linear feedback shift registers
            inp_lf3= (inp_lf3)/2;
        }
        
    }
    while(inp_lf2>0)
    {
        for(i=0;i<8;i++)
        {
            l[7-i] = (inp_lf2)%2;
            inp_lf2= (inp_lf2)/2;
        }
        
    }
    while(inp_lf1>0)
    {
        for(i=0;i<8;i++)
        {
            m[7-i] = (inp_lf1)%2;
            inp_lf1= (inp_lf1)/2;
        }
        
    }

    
      while(1)
    {
        
        
        
            x=m[0]; //LSB as output for initialization of LFSR 1
            z=l[0];//LSB as output for initialization of LFSR 2
            y=a[0];//LSB as output for initialization of LFSR 3


            k=(m[7]^m[3]^m[2]^m[1]);
            if(x==1)
            {
                z=l[0]; //Output from LFSR 2
                c=(l[7]^l[3]^l[2]^l[1]);
                for(b=7;b>0;b--)
                {
                    l[b-1]=l[b];
                }
                l[7]=c;
                
            }
            if(x==0)
            {
                y=a[0];
                w=(a[7]^a[3]^a[2]^a[1]);
                for(b=7;b>0;b--)                // Encryption Algorithm
                {
                    a[b-1]=a[b];
                }
                a[7]=w;
                
            }
            op[s]=(z^y);
            s++;
            for(b=7;b>0;b--)
            {
                m[b-1]=m[b];
            }
            m[7]=k;
            if(s==n)
            {
                break;
            }
            
        
    }
    for(i=0;i<n+1;i++)
    {
        encrypt[i]=(msg[i]^op[i]);              // Encryption
    }
    for(i=0;i<n+1;i++)
    {
        decrypt[i]=(encrypt[i]^op[i]);          // Decryption
    }
    i=0;
    while(i<n+1)
    {
        num=0;
        for(j=i;j<i+8;j++)
        {
            num = num+(pow(2,(j-i))*encrypt[j]);        // Conversion to encrypted ASCII characters
        }
        fprintf(fpe,"%c",num);
        i=i+8;
        
        
    }
    fprintf(fpe,"\n");
    num=0;
    i=0;
    while(i<n+1)
    {
        num=0;
        for(j=i;j<i+8;j++)
        {
            num = num+(pow(2,(j-i))*decrypt[j]);        // Conversion to decrypted characters
        }
        
        fprintf(fpe,"%c",num);
        i=i+8;
        
        
    }
    fclose(fpe);
    
return 0;
}
