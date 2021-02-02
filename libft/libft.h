/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:37:07 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/02/02 20:19:02 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wctype.h>
# include <wchar.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <inttypes.h>
# include "libft_structs.h"
# include "ft_printf.h"

# define BUFF_SIZE 1

typedef struct		s_printf
{
	int				printed;
	unsigned short	flag;
	int				width;
	int				prec;
	int				fd;
	va_list			args;
	char			*str;
	int				base;
}					t_printf;

typedef struct		s_dl_lst
{
	char			nbr;
	int				rank;
	char			base;
	struct s_dl_lst	*next;
	struct s_dl_lst	*prev;
}					t_dl_lst;

typedef struct		s_sem
{
	size_t			s;
	size_t			e;
	size_t			m;
	char			base;
}					t_sem;

typedef int			(*t_handler)(t_printf *lstprf);

typedef struct		s_func
{
	t_handler		func;
	char			ch;
}					t_func;

int					get_next_line(const int fd, char **line);
float				ft_fclamp(float n, float min, float max);
long long			ft_atol(const char *str);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, \
								const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
int					ft_atoi(const char *str);
int					ft_lennb(int n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long n);
char				*ft_itoa_base(long long nb, int base, int l);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

int					ft_cmp(int a, int b);
void				ft_foreach(int *tab, int lenght, void (*f)(int));
int					ft_isgraph(int c);
int					ft_ispunct(int c);
void				ft_swap(int *a, int *b);
char				*ft_strndup(const char *s1, size_t n);
int					ft_massize(char **line);
int					ft_min(int a, int b);
void				ft_freesplit(char **split);
int					ft_isempty(char *line);
int					ft_abs(int digit);
unsigned long long	ft_absll(long long n);
void				ft_lstd_pop_front(t_list_a **head);
void				ft_lstd_push_back(t_list_a **head, t_list_a *new);
void				ft_lstd_push_front(t_list_a **head, t_list_a *new);
size_t				ft_putwchar_fd(wchar_t c, int fd);
void				dl_lstdel(t_dl_lst *lst);
char				*ft_strnewc(size_t size, char c);
char				*ft_ulltoa_base(unsigned long long dgt, int base);
int					ft_nbrlen(intmax_t nbr);
size_t				ft_wstrlen_wch(const wchar_t *str);
size_t				ft_wstrlen(unsigned *s);
size_t				ft_putwstrn_fd(wchar_t *str, size_t len, int fd);
char				*ft_strch(const char *str, int ch);
size_t				ft_wcharlens(unsigned str);
void				ft_delcontent(void *content, size_t size);
double				ft_pow(double n, int pow);
int					ft_unbrlen(uintmax_t nbr, int base);
char				*ft_memjoin(void const *src1, void const *src2,
					size_t size1, size_t size2);
char				*ft_strjoin_free_second(char const *s1, char **s2);
size_t				ft_putstr_ptr_fd(const int fd, char const *start,
								char const *finish);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_forward_list		*ft_lstappend_frwd(t_forward_list *head,
							t_forward_list *new);
void				ft_lstappend(t_list **alst, t_list *new);

# define STANDART_PRECISION 6
# define TYPE_NUM	12
# define F_MINUS	(1 << 0)
# define F_PLUS		(1 << 1)
# define F_SPACE	(1 << 2)
# define F_ZERO		(1 << 3)
# define F_HASH		(1 << 4)
# define L_HH		(1 << 5)
# define L_H		(1 << 6)
# define L_L		(1 << 7)
# define L_LL		(1 << 8)
# define L_BIGL		(1 << 9)
# define F_PREC		(1 << 10)
# define F_UP		(1 << 11)

# define FCOLOR_BLACK    "\x1b[30m"
# define FCOLOR_RED      "\x1b[31m"
# define FCOLOR_GREEN    "\x1b[32m"
# define FCOLOR_YELLOW   "\x1b[33m"
# define FCOLOR_BLUE     "\x1b[34m"
# define FCOLOR_MAGENTA  "\x1b[35m"
# define FCOLOR_CYAN     "\x1b[36m"
# define FCOLOR_WHITE    "\x1b[37m"
# define FCOLOR_BOLD_ON  "\x1b[1m"
# define FCOLOR_BOLD_OFF "\x1b[21m"

# define BCOLOR_BLACK    "\x1b[40m"
# define BCOLOR_RED      "\x1b[41m"
# define BCOLOR_GREEN    "\x1b[42m"
# define BCOLOR_YELLOW   "\x1b[43m"
# define BCOLOR_BLUE     "\x1b[44m"
# define BCOLOR_MAGENTA	"\x1b[45m"
# define BCOLOR_CYAN	"\x1b[46m"
# define BCOLOR_WHITE	"\x1b[47m"

# define COLOR_RESET	"\x1b[0m"

#endif
