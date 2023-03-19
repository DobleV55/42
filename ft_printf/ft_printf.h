/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valenvila <vvila@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:02:58 by valenvila         #+#    #+#             */
/*   Updated: 2023/03/18 14:34:00 by valenvila        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s, int order);
int		ft_putaddress(unsigned long num);
int		ft_putunbr(unsigned int num);
int		ft_puthexnbr_upper(unsigned int num);
int		ft_puthexnbr_lower(unsigned int num);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);

#endif
