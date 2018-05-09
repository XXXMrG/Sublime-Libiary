//
// Created by 高建 on 2018/4/6.
//
#include "compiling_01.h"


// the num of the keyword

/*
 * 词法分析程序
 * 13 keyword
 * for & do/while & if/else & switch/case
 * integer var&let
 * read & write
 * identifier -> alpha + digit
 *
 *
 *
 *
 *
 * */


char *keyword[keywordSum] = {
        "if", "else", "for", "while", "do", "int", "read", "write", "switch", "case", "let",
        "break", "default"
};



// defined the singleWord

char singleword[50] = "+-*(){};,:";
char doubleword[10] = "><=!";

extern char Scanin[300], Scanout[300];
extern FILE *fin, *fout;

int TESTscan (){
    char ch, token[40];
    int es = 0;
    int j, n;

    printf("in put your file name :\n");
    scanf("%s", &Scanin);
    printf("input your out file name :\n");
    scanf("%s", &Scanout);
    // check the file
    if ((fin = fopen(Scanin, "r")) == NULL){
        printf("open file error\n");
        return 1;
    }

    if ((fout = fopen(Scanout, "w")) == NULL){
        printf("write file error\n");
        return 2;
    }

    ch = getc(fin);

    while(ch != EOF){
        // jump the space
        while (ch == ' ' || ch == '\n' || ch == '\t' )
            ch = getc(fin);
        // check the ID
        if (isalpha(ch)){
            token[0] = ch;
            j = 1;
            ch = getc(fin);
            while (isalnum(ch)){
                token[j++] = ch;
                ch = getc(fin);

            }

            token[j] = '\0';
            n = 0;
            // find the keyword
            while ((n < keywordSum) && strcmp(token,keyword[n]))
                n ++;
            if (n >= keywordSum)
                fprintf(fout, "%s\t%s\n", "ID", token);
            else
                fprintf(fout, "%s\t%s\n", token, token);

        }else if (isdigit(ch)){             // deal with digit
            token[0] = ch;
            j = 1;
            ch = getc(fin);
            // combie the digit
            while( isdigit(ch) ){
                token[j++] = ch;
                ch = getc(fin);
            }

            token[j] = '\0';

            fprintf(fout, "%s\t%s\n", "NUM",token);

        }else if (strchr(singleword,ch) > 0){            // deal with the singleword
            token[0] = ch;
            token[1] = '\0';
            ch = getc(fin);
            fprintf(fout, "%s\t%s\n", token, token);
        }else if (strchr(doubleword,ch) > 0){            // deal with the doubleword
            token[0] = ch;
            ch = getc(fin);
            if(ch == '='){
                token[1] = ch;
                token[2] = '\0';
                ch = getc(fin);
            }
            else
                token[1] = '\0';
            fprintf(fout, "%s\t%s\n", token, token);
        }else if (ch == '/'){                        // notice the '/' between / and annotation
            ch = getc(fin);
            // deal with the /**/ annotation
            if(ch == '*'){
                char ch1;
                do{
                    ch = ch1;
                    ch1 = getc(fin);

                }while((ch != '*' || ch1 != '/') && ch1 != EOF);    // delete the annotation

                ch = getc(fin);
            }
            // deal with the // annotation
            else if(ch == '/'){
                char ch1;
                do{
                    ch = ch1;
                    ch1 = getc(fin);
                }while ( (ch != '\n') && ch1 != EOF);
            }
            // deal with the '/'
            else{
                token[0] = '/';
                token[1] = '\0';
                fprintf(fout, "%s\t%s\n", token, token);
            }
        }
        // deal with error
        else{
            token[0] = ch;
            token[1] = '\0';
            ch = getc(fin);
            es = 3;
            fprintf(fout, "%s\t%s\n", "Error!", token);
        }
    }

    fclose(fin);
    fclose(fout);
    return es;
}