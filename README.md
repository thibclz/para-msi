


Résultats : 

| suffix fichier output | nombre de clockcycles | acceleration multiplier | Comment   | Corresponding commit name |
| --------------------- | --------------------- | ----------------------- | ----------------------------------------------------------------------- | ------|
| default               | 1,2998E+10            | 1,00                    |     baseline | init repo                                                                    | 
| 1                     | 9846958328            | 1,32                    | seulement light paralléllisé pour i et j   |    para only light                            |                 |
| 2                     | 8705508849            | 1,49                    | i et j inversées dans light                                             |
| 3                     | 4220873359            | 3,08                    | i et j inversées dans toutes les fonctions                              | para all
| 4                     | 3072097614            | 4,23                    | pour copier on utiliser une fonction de string.h pour copier directement le bloc mémoire dans copy | standard function for copy |
| 5                     | 2152776366            | 6,04                    | parallélisation de curve                                                |
| 6                     | 1896110610            | 6,85                    | on retire i et j et on remplace avec un seul index i qui va jusque w\*h | single loop |
| 7                     | 1892932140            | 6,87                    | on retire des variables inutiles  | ajout des fichiers d'outputs et de l'explication des résultats                                                                 |
| 8                     | 973927334            | 13,35 | on met toutes les instructions dans la même fonction et on optimise les types | 8.everything in one function |


