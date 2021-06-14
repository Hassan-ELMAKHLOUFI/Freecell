#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>

typedef struct Carte{
    char *type;
    char *coleur;
    int numero;
}Carte;

typedef struct ElementColonne {
    Carte *c;
    struct ElementColonne  *next ;
}ElementColonne;

typedef struct Zone{
    ElementColonne **Pile ;
}Zone;


void PUSH (Carte *c, ElementColonne **Pile ){
    ElementColonne *e;
    e=(ElementColonne *) malloc(sizeof(ElementColonne));
    e->c=c;
     e->next=NULL;
    if(*Pile==NULL){
        e->next=NULL;
        *Pile=e;
        return;
    }
    e->next=(*Pile);
    *Pile=e;
}

void POP (ElementColonne **Pile){
    ElementColonne *tmp;
    
    if(*Pile==NULL){
        return;
    }
    tmp=(*Pile);
    (*Pile)=(*Pile)->next;
    free(tmp);
    }

Carte *PEEK(ElementColonne *Pile){
    if (Pile==NULL){
        return NULL;
    }
        
    
    return Pile->c;
}





Carte * numToCarte(int num){
    
    Carte *c=(Carte *)malloc (sizeof(Carte));
    
    if (num >=1 && num <=13){
        c->type="carreaux";
        c->coleur="Rouge";
        c->numero=num;
    }
    
    
    if (num >=14 && num <=26){
        c->type="piques";
        c->coleur="Noire";
        c->numero=num-13;
    }
    
    if (num >=27 && num <=39){
        c->type="cœurs";
        c->coleur="rouge";
        c->numero=num-26;
    }
    
    
    if (num >=40 && num <=52){
        c->type="trefles";
        c->coleur="Noire";
        c->numero=num-39;
    }
    
    return c;
}

Zone * initialiser(){
    int r,indice =52,tmp;
      int T[52];
    Zone *zone1;
    Zone *zone ;
    zone=(Zone*)malloc(sizeof(Zone)*3);
    Carte *c;
    
    zone[0].Pile=(ElementColonne**)malloc(sizeof(ElementColonne)*8);
    
    for(int i=0;i<8;i++){
        zone[0].Pile[i]=NULL;
    }
  
    for (int i=0;i<52;i++){
        T[i]=i+1;
    }
 
    
    //initialisation
    for(int j=0;j<=6;j++){
        r= rand()%indice;
        srand(time(0));
        tmp=T[r];
       
        
        for (int i=r+1;i<=indice;i++){
            T[i-1]=T[i];
        }
         indice--;
       
        c=numToCarte(tmp);
                
                PUSH(c,&zone[0].Pile[0]);
            }
    

    
    
    for(int j=0;j<=6;j++){
        r= rand()%indice;
         srand(time(0));
        tmp=T[r];
       
        
        for (int i=r+1;i<=indice;i++){
            T[i-1]=T[i];
        }
         indice--;
       
        c=numToCarte(tmp);
                
                PUSH(c,&zone[0].Pile[1]);
            }
        
       
    
    for(int j=0;j<=6;j++){
        r= rand()%indice;
         srand(time(0));
        tmp=T[r];
       
        
        for (int i=r+1;i<=indice;i++){
            T[i-1]=T[i];
        }
         indice--;
       
        c=numToCarte(tmp);
                
                PUSH(c,&zone[0].Pile[2]);
            }
        
    
    
    
    for(int j=0;j<=6;j++){
        r= rand()%indice;
        srand(time(0));

        tmp=T[r];
       
        
        for (int i=r+1;i<=indice;i++){
            T[i-1]=T[i];
        }
         indice--;
       
        c=numToCarte(tmp);
                
                PUSH(c,&zone[0].Pile[3]);
            }
    
    
    
    for(int j=0;j<=5;j++){
        r= rand()%indice;
        srand(time(0));

        tmp=T[r];
       
        
        for (int i=r+1;i<=indice;i++){
            T[i-1]=T[i];
        }
         indice--;
       
        c=numToCarte(tmp);
                
                PUSH(c,&zone[0].Pile[4]);
            }
    
    
    for(int j=0;j<=5;j++){
        r= rand()%indice;
        srand(time(0));

        tmp=T[r];
       
        
        for (int i=r+1;i<=indice;i++){
            T[i-1]=T[i];
        }
         indice--;
       
        c=numToCarte(tmp);
                
                PUSH(c,&zone[0].Pile[5]);
            }
    
    
    for(int j=0;j<=5;j++){
        r= rand()%indice;
        srand(time(0));

        tmp=T[r];
       
        
        for (int i=r+1;i<=indice;i++){
            T[i-1]=T[i];
        }
         indice--;
       
        c=numToCarte(tmp);
                
                PUSH(c,&zone[0].Pile[6]);
            }
        
        

    for(int j=0;j<=5;j++){
        srand((unsigned) time(0));

        r= rand()%indice;
        tmp=T[r];


        for (int i=r+1;i<=indice;i++){
            T[i-1]=T[i];
        }
         indice--;

        c=numToCarte(tmp);

                PUSH(c,&zone[0].Pile[7]);
            }

    return zone;
}


void afficheCol(ElementColonne *col){
    
//    while (col!=NULL){
//        printf("%d\t",PEEK(col)->numero);
//        printf("%s\t",PEEK(col)->coleur);
//        printf("%s\t",PEEK(col)->type);
//        POP(&col);
//        printf("\n");
//    }
    
    for (ElementColonne * e=col;e!=NULL;e=e->next){
        printf("%d\t",e->c->numero);
        printf("%s\t",e->c->coleur);
        printf("%s\t",e->c->type);
        printf("\n");
    }
}




void deplace (Zone *z,int   zSource, int  zDestination ,int colSource, int colDestination  ){
    
    Zone zSrc, zDes;
    Carte *carteSrc,*carteDes;
    
    for (int i=0;i<3;i++){
        if (zSource==i){
            zSrc=z[i];
          }
      }
    
    for (int i=0;i<3;i++){
        if (zDestination==i){
            zDes=z[i];
          }
      }
    
    carteSrc= PEEK(zSrc.Pile[colSource]);
    carteDes=PEEK(zDes.Pile[colDestination]);
    
    if (zDestination==0){

            
            if(carteDes->numero==carteSrc->numero+1 && strcmp(carteSrc->coleur, carteDes->coleur)!=0){
                POP(&zSrc.Pile[colSource]);
                PUSH(carteSrc,&zDes.Pile[colDestination]);
                printf("\n bine deplacer \n");
            }else{
                printf("\n vous nous pouvez pas deplacer \n");
            }
    }
    
    if(zDestination==2){
            
        if(carteDes->numero+1==carteSrc->numero && strcmp(carteSrc->type, carteDes->type)!=0){
             POP(&zSrc.Pile[colSource]);
             PUSH(carteSrc,&zDes.Pile[colDestination]);
         }
    }
    
    if(zDestination==1){
            
        if(!carteDes){
            
             PUSH(carteSrc,&zDes.Pile[colDestination]);
         }
    }
    
    
    
    
    
    

}

void afficheZone (Zone *zone){
    
    for (int i=0;i<8;i++){
        printf("\n********************\n");
        afficheCol(zone[0].Pile[i]);
        
        
    }
}



int main() {

    Zone *z;
    int   zSource, zDestination ,colSource, colDestination;

    int test;
    
    z=initialiser();
    afficheZone(z);
    
    do{
        
        printf("\n Donnez le numero de la zone Source  \n ");
        scanf("%d",&zSource);
        
        printf("\n Donnez le numero de la colonne Source  \n ");
        scanf("%d",&colSource);
        
        printf("\n Donnez le numero de la zone Destination  \n ");
        scanf("%d",&zDestination);
        

        printf("\n Donnez le numero de la colonne Destination \n ");
        scanf("%d",&colDestination);
        deplace (z,zSource,zDestination ,colSource,colDestination);
         afficheZone(z);
        printf ("taper 0 pour quitter \n ");
        printf ("taper 1 pour continuer\n");
        scanf("%d",&test);
        
        
    }while(test);
}
