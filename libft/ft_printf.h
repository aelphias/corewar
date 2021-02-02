/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:35:33 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 13:35:34 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include "libft.h"
# define USI				unsigned short int
# define ULI				unsigned long int
# define LLI				long long int
# define BASE_8 			"01234567"
# define BASE_10			"0123456789"
# define BASE_16U			"0123456789ABCDEF"
# define BASE_16L			"0123456789abcdef"
# define LOG2				0.3010299956639812
# define BASE_NBR_LEN		25
# define DEFAULT_PRECISION	6
# define RED				"\e[31m"
# define GREEN				"\e[32m"
# define YELLOW				"\e[33m"
# define BLUE				"\e[34m"
# define MAGENTA			"\e[35m"
# define CYAN				"\e[36m"
# define RESET				"\e[00m"

typedef struct		s_flag
{
	unsigned char	minus;
	unsigned char	plus;
	unsigned char	space;
	unsigned char	zero;
	unsigned char	hash;
}					t_flag;

typedef struct		s_param
{
	char			*str;
	int				line_size;
	int				precision;
	char			type;
	unsigned char	length;
	char			sign;
	t_flag			flag;
	va_list			ap;
	int				width;
}					t_param;

typedef struct		s_date
{
	char			sep;
	char			error;
	unsigned char	day;
	unsigned char	month;
	int				year;

}					t_date;

int					ft_printf(const char *format, ...);
int					ft_printf_fd(const int fd, const char *format, ...);
int					get_param(t_param *new_param, char **str);
int					get_item(t_param *param);
int					ft_itoa_u(uintmax_t nbr, t_param *param);
int					ft_itoa_p(intmax_t nbr, t_param *param);
int					ft_itoa_b(uintmax_t nbr, char *base_list, t_param *param);
int					ft_getstr(char *str, t_param *param);
int					ft_getchar(char c, t_param *param);
int					string_convertation(t_param *param);
int					ten_base_int(t_param *param);
int					hex_base_int(t_param *param);
int					other_base_int(t_param *p);
int					double_convertation(t_param *param);
int					ft_apply_flags(t_param *param);
int					raw_string(char *string, t_param *param);
int					get_flag(const char *str, t_flag *flag);
int					get_width(char **str, t_param *param);
int					get_precision(char **str, t_param *param);
int					shift_string(char *str, int max_len);
int					date_to_string(t_date *date, t_param *param);
void				division_two_e(char *str, int max_len);
void				add_exponent(t_param *param, int power);
void				multiply_two(char *str, int max_len);
void				division_two(char *str, int max_len, int i);
size_t				ft_putstring(const int fd, char *string, size_t size);
unsigned char		get_length(const char *str);
char				get_type(const char *str);
t_date				*string_to_date(char *str);

#endif
