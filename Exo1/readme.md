```
# TP 5 - exercice 1

## Question 1

*Que se passe-t-il si le processus père envoie le signal SIGSTOP au lieu de SIGUSR1 ? La situation est-elle différente avec le signal SIGINT ?*

Comme le programme ne définit pas de fonction par défaut pour la signal `SIGSTOP`. Il va se mettre en pause. Avec le signal `SIGINT`, il va s'interrompre.

## Question 2

*Comment améliorer le programme pour que le processus père ne soit pas interrompu lorsque l’on tape un CTRL-C ?*

Pour ce faire, nous devons définir une fonction par défaut pour le signal `SIGTERM` afin qu'il ne mette pas fin à l'éxécution.
```