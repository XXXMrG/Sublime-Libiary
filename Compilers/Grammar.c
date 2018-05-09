//
// Created by 高建 on 2018/4/13.
//

#include "compilint_02.h"


char token[20], token1[40]; 		//to save the id and name
extern char Scanout[300];			//the lexical result
FILE *fp;


//grammar ana

int TESTparse(){
    int es = 0;
    if ((fp = fopen(Scanout, "r")) == NULL){
        printf("open file error fuck it !!!\n");
        es = 10;
    }

    if(es == 0)
        es = program();

    printf("the result of the grammar\n");
    switch(es){
        case 0 :
            printf("success !!\n");
            break;
        case 1 :
            printf("open failed !\n");
            break;
        case 2 :
            printf("missing { \n");
            break;
        case 3 :
            printf("missing } \n");
            break;
        case 4 :
            printf("missing id\n");
            break;
        case 5 :
            printf("missing ; \n");
            break;




    }

    fclose(fp);
    return(es);
}

//program -> <declaration_list><statement_list>

int program(){
    int es = 0;
    fscanf(fp, "%s %s\n", token, token1);
    printf("%s %s\n",token, token1 );

    if(strcmp(token, "{")) {
        es = 1;
        return es;
    }

    fscanf(fp, "%s %s\n", token, token1);
    printf("%s %s\n",token, token1 );

    es = declaration_list();
    if(es > 0)
        return es;
    //es = statement_list();
    //if(es > 0)
    //    return es;

    if(strcmp(token, "}")){
        es = 2;
        return es;
    }

    return es;

}


//declaration_list -> {declaration_stat}
int declaration_list(){
    int es = 0;
    while(strcmp(token, "int") == 0){
        es = declaration_stat();
        if(es > 0)
            return es;
    }
    return es;
}

//declaration_stat -> int ID;
int declaration_stat(){
    int es = 0;
    fscanf(fp, "%s %s\n", token, token1);
    printf("%s %s\n",token, token1 );
    if(strcmp(token, "ID"))
        return es = 3;
    fscanf(fp, "%s %s\n", token, token1);
    printf("%s %s\n",token, token1 );
    if(strcmp(token, ";"))
        return es = 4;
    fscanf(fp, "%s %s\n", token, token1);
    printf("%s %s\n",token, token1 );

    return es;

}














