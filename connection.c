/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** connection
*/

#include "navy.h"

void sig_handler(int signal, siginfo_t *siginfo, \
__attribute__((unused))void *context)
{
    // dans la structure siginfo on a le pid du process qui a envoyé le signal
    // utiliser cette sturcture pour recuperer le pid du process qui a envoyé le signal
    // puis renvoyer le signal au process qui a envoyé le signal pour lui dire qu'on a bien recu son pid
    signal++;
}

pid_t get_j2_pid(void)
{
    struct sigaction act;

    act.sa_sigaction = &sig_handler;
    act.sa_flags = SA_SIGINFO;

    // grace a la structure sigaction on peut modifier le comportement du signal SIGUSR1 pour utiliser notre sig_handler et la structure siginfo_t
    // (man sigaction, man sigemptyset)
    while (player.pid_j2 == 0);
    printf("enemy connected\n\n");
    return (player.pid_j2);
}
