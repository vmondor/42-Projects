/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:32:28 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/20 14:24:16 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main() {
    int fd2 = open("file2.txt", O_WRONLY, 0644);
    if (fd2 < 0) {
        perror("open");
        return 1;
    }

    // Duplique le descripteur de fichier vers la sortie standard (stdout)
    int dupFd = dup(fd2);
    if (dupFd < 0) {
        perror("dup");
        close(fd2);
        return 1;
    }

    // Maintenant, tout ce qui est écrit sur stdout ira dans "file2.txt"
    write(dupFd, "Hello, Valentin!\n", 17);

    // Ferme les descripteurs de fichier
    close(fd2);
    close(dupFd);

    return 0;
}