#include <stdio.h>
#include <stdlib.h>

int main()
{
    int prim,div,verd;
    prim=3;
   while(prim<=332){
    verd=0;
    while(!verd){
        for(div=2;div<prim;div++){
            if(prim%div==0){

                prim++;
                div=2;
             }else{
                 verd=1;

             }

        }
       printf("%d \n",prim);
    }
    prim++;
    }
    return 0;
}
