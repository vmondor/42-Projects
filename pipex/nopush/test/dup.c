/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:32:28 by vmondor           #+#    #+#             */
/*   Updated: 2024/03/01 15:49:33 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/pipex.h"

int main() {
  int fd = open("../../outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Redirige STDOUT vers fd
    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("dup2");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Maintenant, tout ce qui est écrit sur STDOUT ira dans "output.txt"
    printf("Ce texte est redirigé dans output.txt\n");

    close(fd); // Fermer le fichier original après la redirection
}