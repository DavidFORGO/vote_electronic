#include <stdlib.h>
#include <stdio.h>
#define MAX 5 // nombre total des votants pouvant etre defini par l'utilisateur

void Interfaceuniv(){

system("clear");
printf("************************************************************************************************************** *\n");
printf("* ************************************************************************************************************ *\n");
printf("* * UNIVERSITE VIRTUELLE                                                                  GENIE LOGICIEL (L1) * *\n");
printf("* *    DU BURKINA FASO                                                                                                       * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                          BIENVENUE DANS LE PROGRAMME DE VOTE ELECTRONIQUE                                * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                PROJET TUTORE EN C                                                        * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                          2020 - 2021                                                     * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                       ==============================                                     * *\n");
printf("* *                                                NOM & PRENOM                                              * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                               - FORGO David                                              * *\n");
printf("* *                                               - RABO Abdourahim                                          * *\n");
printf("* *                                       ==============================                                     * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                                                                                          * *\n");
printf("* ************************************************************************************************************ *\n");
printf("************************************************************************************************************** *\n");
}

void Jevote(){

	int tab[MAX];
	char id[MAX],mdp[MAX];
	int i;
	
	printf("==============================================================\n");

			printf("=CHOISIR UN NUMERO POUR MATERIALISER VOTRE VOTE              =\n");
			printf("=                                                            =\n");
			printf("=		1:AMidr                                              =\n");
			printf("=                                                            =\n");
			printf("=		2:Razbande                                           =\n");
			printf("=                                                            =\n");
			printf("=		3:bulletin null                                      =\n");
			printf("=                                                            =\n");
	
			printf("==============================================================\n");
	
	//saisie des choix
		for(i=0;i<MAX;i++){
			printf("Entrer votre identifiant:\t");
			scanf("%s",&id[i]);
			printf("Entrer votre mot de passe:\t");
			scanf("%s",&mdp[i]);  
			printf("Entrer votre choix:\t");
			scanf("%d",&tab[i]); 
		}
		
	//affichage du tableau
		for(i=0;i<MAX;i++){
			printf("%d\t",tab[i]);
		}
	//appel de la fonction decompte
	Decompte(tab);
}

void Decompte(int *tabvoix){ //fonction qui pointe sur le tableau des choix dans la fonction je vote
	int i;
	int voixcandi1,voixcandi2,bullnul;
	bullnul=0;
	voixcandi1=0;
	voixcandi2=0;
	for(i=0;i<MAX;i++){
		if(tabvoix[i]==1){
			voixcandi1=voixcandi1 + 1;
		}
		if (tabvoix[i]==2){
			voixcandi2=voixcandi2 +1;
		}
		if(tabvoix[i]==3){
			bullnul=bullnul+1;
		}
	}
	printf("\nle candidat n°1 a eu:%d voix\n",voixcandi1);
	printf("le candidat n°2 a eu:%d voix\n",voixcandi2);
	printf("le nombre de bulletin null est de:%d\n\n",bullnul);
	
	//appel de la fonction resultat_final()
	resultat_final(voixcandi1,voixcandi2);

}

void resultat_final(int a, int b){
	if(a>b){
		printf("Le gagnant est le candidat 1  avec %d %% des voix\n\n",(int)(a*100)/MAX);
		printf("Et le candidat 2 a eu %d %% des voix\n",(int)(b*100)/MAX );
	}
	else if(b>a){
		printf("Le gagnant est le candidat 2  avec %d %% des voix\n\n",(int)(b*100)/MAX);
		printf("Et le candidat 1 a eu %d %% des voix\n",(int)(a*100)/MAX );
	}
	else{
		printf("les candidats sont à egalités");
	}
}

int main(){
	
	char ch;
	Interfaceuniv();
	printf ("appuyer sur une touche pour passer de l'interface et faire un vote\n");
	ch=getchar();
	
		Jevote();
return (0);	
}
