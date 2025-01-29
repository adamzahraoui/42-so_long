/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:46:11 by adzahrao          #+#    #+#             */
/*   Updated: 2025/01/28 12:08:20 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    int fd;
    char *str;

    if(argc == 2)
    {
        if(check_map(argv[1]) == 0)
            printf("error map invaled\n");
        else
            printf("ok");
    }
    else
        printf("Error: select one map\n");
}