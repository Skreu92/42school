---README_FILLIT---

•°•Vision Hugo•°•

Nous avons un fichier d'entrée contenant les tetriminos.

1ere étape : File -> Main -> Filechecker
A chaque tetriminos valide -> on envoie le tetriminos dans un element de liste chainée
if (filechecker != valid)
on free la list.

2eme étape : chaque tetriminos est contenu dans un element de liste chainée sous la forme d'une grille. 
example[x][y] :  {0, 0, 0, 0}
                           {0, 1, 1, 1}
                           {0, 0, 0, 1}
                           {0, 0, 0, 0}
Nous avons donc 4 cases que l'on peut disposer en ajoutant x ou y a chaque case. Dans le cas de cette example : x + x + x + y
D'ailleurs, chaque tetriminos devra etre identifie par une lettre, de a a z, en respectant l'ordre d'entree de chacun.

3eme etape : Nous construisons une grille qui sera le format de sortie. Pour commencer il conviendra de construire la grille la plus petite possible donc : 2 * 2  * le nombre de tetriminos.

4eme etape : Il faut maintenant ranger les tetriminos dans la grille en commancant donc par la case[0][0]
Si la case est vide on place la premiere coordonee et ainsi de suite jusqu'a avoir poser l'ensemble du tetriminos. Si le placement n'est pas possible, on avance d'un element dans la liste chainee et on recommence. Si a la fin, il reste des tetriminos, on agrandit la grille et on recommence. Dans un soucis d'efficacite, nous utiliserons la recursivite.
Astuce a trouver : il faut pouvoir supprimer le tetriminos de la liste pour ne pas a avoir a le replacer. Cependant si la grille est trop petite il faudra bien retrouver ce tetriminos. Peut etre un lstcpy ?

5eme etape : Une fois la grille remplie, ne pas oublier de free notre liste chainee. il ne reste plus qu'a afficher la grille sur la sortie standard. Bien joue les copains!
