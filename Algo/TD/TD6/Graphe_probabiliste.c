immunisé (I)
malade (M)
non immunisé (S)

I -> I 90%
I -> S 10%

S -> S 50%
S -> M 50%

M -> M 20%
M -> I 80%

Matrice de transition :

   |I		M		S
---|-------------------------
I  |0.9		0		0.1
M  |0.8		0.2		0
S  |0		0.5		0.5

	  "1mois"		"2mois"
I  M  S -> I   M   S   -> 	...
1  0  0	   0.9 0  0.1


"12mois" -> 0.754	0.094	0.151
