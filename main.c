/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** main
*/

#include "navy.h"   

void handler(__attribute__((unused))int __sig, \
__attribute__((unused)) sighandler_t handler)
{
    // quand on recupere le signal avec ce handler on met la variable connected a 1
}

void init_player(void) {
    // set les valeurs de la structure player a 0
}

void display_pid(void) {
    // affiche le pid du process
}

void player_one(void) {
    display_pid();
    printf("waiting for enemy connection...\n");
    player.pid_j2 = get_j2_pid();

    // on envoie un signal au player 2 pour lui dire qu'on a bien recu son pid et que la connection est etablie (voir fonction permisse dans le navy)
}

void player_two(char *pid) {
    display_pid();
    player.pid_j2 = my_getnbr(pid);

    // on envoie un signal au player 1 pour lui dire qu'on veux se connecté puis l'on attend de recevoir le signal de confirmation (voir fonction permisse dans le navy)
    if (player.connected == 1) {
        printf("successfully connected\n\n");
    } else {
        printf("Bad connection\n");
    }

}

int main(int argc, char **argv) {
    init_player();
    // on set un handler pour le signal SIGUSR1

    // Si on a pas de parametre on lance le player 1 sinon on lance le player 2 avec le pid du player 1 en parametre
    if (argc == 1) {
        player_one();
    } else if (argc == 2) {
        player_two(argv[1]);
    } else {
        return 84;
    }
}
