#!/bin/bash

# Nom du programme à exécuter
PROG="./philo"
# Paramètres pour exécuter le programme philo
PARAMS="3 310 103 103"

# Boucle infinie jusqu'à ce que le programme s'arrête de lui-même
while true; do
    # Recompiler le programme
    echo "Recompiling..."
    make re

    # Lancer le programme en arrière-plan
    echo "Executing $PROG $PARAMS"
    $PROG $PARAMS &

    # PID du programme philo
    PROG_PID=$!

	count=$((count + 1))
    
	# Attendre 10 secondes
    sleep 15

    # Vérifier si le programme est toujours en cours d'exécution
    if ps -p $PROG_PID > /dev/null; then
        # Si le programme est toujours en cours, on le tue
        echo "Killing the program (PID $PROG_PID) after 10 seconds..."
        kill $PROG_PID
        wait $PROG_PID 2>/dev/null
    else
        # Si le programme s'est arrêté de lui-même (par exemple, un philosophe est mort)
		echo "Program terminated on its own after $count executions. Exiting loop."
		break
    fi

    # Petite pause pour éviter des redémarrages trop rapides
    sleep 1
done
