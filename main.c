#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int v1, int v2) {
    return v1 < v2 ? v1 : v2;
}

int count2(char* s1, char* s2, int m, int n)
{
	if (n == strlen(s2))
        return strlen(s1)-m;
	if (m == strlen(s1))
        return strlen(s2)-n;
	if (s1[m] == s2[n])
        return count2(s1,s2,m+1,n+1);
	if (s1[m] != s2[n]) {
		return 1+min(min(count2(s1,s2,m,n+1), count2(s1,s2,m+1,n)), count2(s1,s2,m+1,n+1));
	}
}

int count1(char* s1, char* s2){

    int m = strlen(s1) +1;
    int n = strlen(s2) +1;
    int i;
    int j;
    int v[m][n];

    for(i = 0; i< m; i++){
        for(j = 0; j< n; j++){
            v[i][j] = 0;
        }
    }

    for(j = 0; j< n; j++){
        v[0][j] = j;
    }
    for(i = 0; i< m; i++){
        v[i][0] = i;
    }


    for ( i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            if (s1[i-1] == s2[j-1]) {
                v[i][j] = min(min(v[i][j-1],v[i-1][j]),v[i-1][j-1]);
            } else {
                v[i][j] = 1 + min(min(v[i][j-1],v[i-1][j]),v[i-1][j-1]);
            }
        }
    }

    return v[m-1][n-1];

}

int main()
{

    int resp;
    int teste;
    char s1[100];
    char s2[100];

    do{
        printf("\n1 - Programaçao Dinamica: ");
        printf("\n2 - Bruta Força: ");
        printf("\n3 - Sair\n\n");
        teste = scanf("%d", &resp);


        switch(resp){
        case 1:
            system("clear");

            printf("\nDigite a primeira string(100): ");
            fflush(stdin);
            fgets(s1,100,stdin);

            printf("\nDigite a primeira string(100): ");
            fflush(stdin);
            fgets(s2,100,stdin);

            printf("A distancia de ediçao entre %s e %s é: %d",s1,s2,count1(s1,s2));
            break;
        case 2:
            system("clear");

            printf("\nDigite a primeira string(100): ");
            fflush(stdin);
            fgets(s1,100,stdin);

            printf("\nDigite a primeira string(100): ");
            fflush(stdin);
            fgets(s2,100,stdin);

            printf("A distancia de ediçao entre %s e %s é: %d",s1,s2,count2(s1,s2,0,0));
            break;
        default:
            break;
        }
        system("clear");


    }while(resp != 0);

    return 0;
}
