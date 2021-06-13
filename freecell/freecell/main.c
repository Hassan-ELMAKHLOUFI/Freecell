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
    Carte *c;
    zone1=(Zone*)malloc(sizeof(Zone));
    zone1->Pile=(ElementColonne**)malloc(sizeof(ElementColonne)*8);
    
    for(int i=0;i<8;i++){
        zone1->Pile[i]=NULL;
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
                
                PUSH(c,&zone1->Pile[0]);
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
                
                PUSH(c,&zone1->Pile[1]);
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
                
                PUSH(c,&zone1->Pile[2]);
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
                
                PUSH(c,&zone1->Pile[3]);
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
                
                PUSH(c,&zone1->Pile[4]);
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
                
                PUSH(c,&zone1->Pile[5]);
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
                
                PUSH(c,&zone1->Pile[6]);
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

                PUSH(c,&zone1->Pile[7]);
            }

    return zone1;
}


void afficheCol(ElementColonne *col){
    
    while (col!=NULL){
        printf("%d\t",PEEK(col)->numero);
        printf("%s\t",PEEK(col)->coleur);
        printf("%s\t",PEEK(col)->type);
        POP(&col);
        printf("\n");
    }
}


void afficheZone (Zone *zone){
    
    
    for (int i=0;i<8;i++){
        afficheCol(zone->Pile[i]);
        
        
    }
}
int main() {

    Zone *z;
    z=initialiser();
    afficheZone(z);
}
