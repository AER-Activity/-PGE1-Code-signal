/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** connection
*/

#include "navy.h"

void handle_usr1(__attribute__((unused))int signal, \
__attribute__((unused))siginfo_t *siginfo, \
__attribute__((unused))void *context)
{
    player.connected = 1;
}

void sig_handler(int signal, siginfo_t *siginfo, \
__attribute__((unused))void *context)
{
    player.pid_j2 = siginfo->si_pid;
    kill(player.pid_j2, SIGUSR1);
    signal++;
}

pid_t get_j2_pid(void)
{
    struct sigaction act;

    act.sa_sigaction = &sig_handler;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    sigaction(SIGUSR1, &act, NULL);
    while (player.pid_j2 == 0);
    printf("enemy connected\n\n");
    act.sa_sigaction = &handle_usr1;
    sigaction(SIGUSR1, &act, NULL);
    return (player.pid_j2);
}
