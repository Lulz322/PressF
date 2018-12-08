//
// Created by Ihor RUBAN on 12/8/18.
//

void prntnum_lower(unsigned int num, char sign , int base)
{

    int i = 12;
    int j = 0;
    char outbuf[255];

    do{
        outbuf[i] = "0123456789abcdef"[num % base];
        i--;
        num = num/base;
    }while( num > 0);

    if(sign != ' '){
        outbuf[0] = sign;
        ++j;
    }

    while( ++i < 13){
        outbuf[j++] = outbuf[i];
    }

    outbuf[j] = 0;
    printf("%s\n", outbuf);

}

void prntnum_upper(unsigned int num, char sign , int base)
{

    int i = 12;
    int j = 0;
    char outbuf[255];

    do{
        outbuf[i] = "0123456789ABCDEF"[num % base];
        i--;
        num = num/base;
    }while( num > 0);

    if(sign != ' '){
        outbuf[0] = sign;
        ++j;
    }

    while( ++i < 13){
        outbuf[j++] = outbuf[i];
    }

    outbuf[j] = 0;
    printf("%s\n", outbuf);

}