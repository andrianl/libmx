/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:10:46 by yfuks             #+#    #+#             */
/*   Updated: 2014/11/10 17:45:16 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmx.h"

char *mx_trjoin(char const *s1, char const *s2)
{
    char *s3;

    if (!s1 && !s2)
        return (NULL);
    if (!s1)
        return (mx_strdup(s2));
    if (!s2)
        return (mx_strdup(s1));
    if (!(s3 = mx_strnew(mx_strlen(s1) + mx_strlen(s2))))
        return (NULL);
    mx_strcpy(s3, s1);
    mx_strcat(s3, s2);
    return (s3);
    return (NULL);
}
