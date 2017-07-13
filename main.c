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


    for ( i = 1; i < m; i++){
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

int main(){
    printf("\nA distancia de ediçao por Força Bruta: %d",count2("arthur","artur",0,0));
    printf("\nA distancia de ediçao por Programaçao Dinamica: %d\n",count1("arthur","artur"));

    return 0;
}
