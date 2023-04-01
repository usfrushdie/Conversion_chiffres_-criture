#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <locale.h>
#include <malloc.h>
#include "chaine2.h"


	char all[1000];
	
	void ent_reel(char T[], char P1[], char P2[])
		{
			int N= strlen(T);
			int i=0;
			for(i=0;i<strlen(T);i++)
				{
					if(T[i]=='.')	break;
					P1[i]=T[i];
				}
			P2[i-1]='\0';
			if(strlen(T)==i)
				{
					P2[0]='0';
					return;
				}
			int j;
			i++;
			for(j=i;j<N;j++)	{	P2[j-i]=T[j];	}	P2[j]='\0';
			
		}


	
	void lecture_chaine (char T[])
		{
			//L'insertion du numéro:
			int i;
			printf("Donnez votre numéro : ");
			scanf("%s",T);	
		}
	
	void affichage_chaine (char P1[], char P2[])
		{
			int i,l=0;
			//Test d'affichage:
			printf("\t La partie entière de votre numéro est : %s \n",P1);
			for(i=strlen(P2)-1;i>=0;i--)
					{
						if(P2[i]!='0')	break;
						else l++;
					}
			printf("\t La partie réelle de votre numéro est : ");	
			for(i=0; i<strlen(P2)-l; i++)		printf("%c",P2[i]);	printf("\n");
		}
		

	void num_block_b (int i, int N)
		{
			if(N==0)	return;
			if(i==6)	strcat(all,"Mille ");
			
			else if(i==9)	
				{	if (N==1)	strcat(all,"Million ");
					else	strcat(all,"Millions ");	}
					
			else if(i==12)
				{
					if (N==1)	strcat(all,"Milliard ");
					else 	strcat(all,"Milliards ");
				}
			
		}
	
	void char_to_num (char T[])
		{
			int i=0,X,Y,A;
			char b[40];
			int K=strlen(T)%3;
			//Cas de 0
			int C=0;
			for(i=0;i<strlen(T);i++)
				{
					if(T[i]=='0')	C++;	
				}
			if(C==strlen(T))
				{
					strcat(all,"Zero");
					return;
				}
			//Le premier block
			if(K!=0)
				{
				X=0;
				for(i=0;i<K;i++)
					{
						X=X+(T[i]-'0')*pow(10,K-1-i);
					}
				num_to_car_x (X);
				num_block_b (strlen(T)-K+3,X);
				}
			//Le reste des blocks
			for(i=K; i<=strlen(T)-1; i=i+3)
				{	int F=strlen(T)-i;
					if(F==3)
						{
							if((T[i]==0)&&(T[i+1]==0))	strcat(all," et ");
						}
					if(i+2>strlen(T)-1)	break;
					Y= T[i]-'0';
					num_to_car_y (Y);
					X=(T[i+2]-'0') + (T[i+1]-'0')*10;
					num_to_car_x (X);
					num_block_b (strlen(T)-i,Y*100+X);
				}
		}
		

	char * SaisirChaineClavier()
	{
	     unsigned int c, nbc = 0 ;
	     char * ch = NULL ;
	
	     while((c = getchar()) != '\n')
	     {
	        ch = realloc(ch, (nbc+1)*sizeof(char));
	        ch[nbc++] = c ;
	     }
	     ch = realloc(ch, (nbc+1)*sizeof(char));
	     ch[nbc] = '\0' ;
	
	     return ch ;
	}
	
	char * SaisirLigneFichier(FILE * pf)
	{
	    unsigned int c, nbc = 0 ;
	    char * ch = NULL ;
	
	    while(((c = fgetc(pf)) != '\n') && (c != EOF))
	    {
	        ch = realloc(ch, (nbc+1)*sizeof(char));
	        ch[nbc++] = c ;
	    }
	    if((nbc > 0) || (c == '\n'))
	    {
	        ch = realloc(ch, (nbc+1)*sizeof(char));
	        ch[nbc] = '\0' ;
	        return ch ;
	    }
	
	    return NULL ;
	}

	char ** CreerVecteurNombres(char *nf , unsigned int * taille)
	{
	    FILE * pf = fopen(nf, "r") ;
	    char * str = NULL ;
	    unsigned int i = 0 ;
	    char ** VN = NULL ;
	
	    if(pf == NULL)
	    {
	        printf("\n probleme lors de l ouverture du fichier %s\n", nf) ;
	        fclose(pf) ;
	        *taille = 0 ;
	        return NULL ;
	    }
	
	    while((str = SaisirLigneFichier(pf)) != NULL)
	    {
	        VN = realloc(VN, (i+1)*sizeof(char*)) ;
	        VN[i++] = str ;
	    }
	
	    fclose(pf) ;
	    *taille = i ;
	    return VN ;
	}
	
	void num_to_car_x (int X)
	{
	    unsigned int i, nbc, chiffre ;
	    char ** TC = CreerVecteurNombres("Nombres.txt" , &nbc) ;
	    setlocale(LC_CTYPE,"") ;   
		chiffre = X;
		strcat(TC[chiffre]," ") ;
	    strcat(all,TC[chiffre]) ;
	
	}
	
	void num_to_car_v (int X)
	{
	    unsigned int i, nbc, chiffre ;
	    char ** TC = CreerVecteurNombres("Chiffres.txt" , &nbc) ;
	    setlocale(LC_CTYPE,"") ;   
		chiffre = X;
		strcat(TC[chiffre]," ") ;
	    strcat(all,TC[chiffre]) ;
	
	}
	
	void num_to_car_y (int Y)
	{
	    unsigned int i, nbc, chiffre ;
	    char ** TC = CreerVecteurNombres("Centaines.txt" , &nbc) ;
	    setlocale(LC_CTYPE,"") ;   
		chiffre = Y;
		strcat(TC[chiffre]," ") ;
	    strcat(all,TC[chiffre]) ;
	
	}
	void char_to_num_v (char P2[])
	{
		if(strlen(P2)>0)
			{	int K=0,i;
				for(i=0;i<strlen(P2);i++)
					{
						if(P2[i]=='0')	K++;
					}
				if(K==strlen(P2))	return;
				int l=0;
//				int C=CheckApresVirgule(P2,&C);
//				if(C==1)	return;
				strcat(all," Virgule: ");
				for(i=strlen(P2)-1;i>=0;i--)
					{
						if(P2[i]!=0)	break;
						else l++;
					}
				for(i=0;i<strlen(P2)-l;i++)
						{
							num_to_car_v(P2[i]-'0');
						}
			}
	}

