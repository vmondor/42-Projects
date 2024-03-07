/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:07:36 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/29 12:24:57 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/pipex.h"

// int execve_cmd() {
//     // Chemin vers l'exécutable `ls`
//     const char *path = "/bin/ls";

//     // Arguments à passer à `ls`
//     // Notez que le premier argument est traditionnellement le nom du programme
//     char *const args[] = {"ls", "-l", "./", NULL};

//     // Appel à `execve`
//     // Remplace le processus actuel par `/bin/ls -l /home`
//     if (execve(path, args, NULL) == -1) {
//         perror("execve");
//         exit(EXIT_FAILURE);
//     }

//     // `execve` ne retourne qu'en cas d'erreur
//     return 0; // Cette ligne n'est jamais atteinte si `execve` réussit
// }

int main(void)
{
        printf("HERE OR NOT");
    const char *path = "/bin/hostname";

	char *const args[] = {"hostname", NULL, NULL};

    if (execve(path, args, NULL) == -1) {
        perror("execve");
        exit(EXIT_FAILURE);
    }
    return 0;
}