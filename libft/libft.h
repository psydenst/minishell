/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:39:56 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/19 11:56:48 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef UINT_MAX
#  define UINT_MAX 4294967295
# endif

/*
 * -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
 *									INCLUDES
 */

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/*
 * -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
 *							   STRUCT DECLARATION
 */

typedef struct s_list
{
	void			*content;
	int				value;
	struct s_list	*next;
}	t_list;

/*
 * -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
 *							   ENUM DECLARATION
 */

typedef enum e_specs
{
	SPEC_CHAR = 'c',
	SPEC_STR = 's',
	SPEC_PTR = 'p',
	SPEC_DEC = 'd',
	SPEC_INT = 'i',
	SPEC_UDEC = 'u',
	SPEC_HEXLOW = 'x',
	SPEC_HEXUP = 'X',
	SPEC_PERCENT = '%'
}	t_specs;

/*
 * -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
 *							  FUNCTION DECLARATIONS
 */

/*
 *	IS FUNCTIONS						  		
 */

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

/*
 *	MEM FUNCTIONS
 */

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

/*
 *	STR FUNCTIONS
 */

char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*
 *	TO FUNCTIONS
 */

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_tolower(int c);
int		ft_toupper(int c);

/*
 *	PUT FUNCTIONS
 */

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*
 *	LST FUNCTIONS
 */

t_list	*ft_lstnew(void *content, int value);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)());
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
 *	GNL FUNCTIONS
 */

char	*get_next_line(int fd);
char	*build_line(char *buffer);
char	*append_line(char *line, char *buffer);
size_t	valid_buffer_len(char *buffer);
size_t	is_line_ready(char *line);
size_t	write_buffer(char *buffer, int fd);
void	offset_buffer(char *buffer);

/*
 *	PRINTF FUNCTIONS
 */

int		ft_printf(const char *s, ...);
int		ft_putchar_n(char s, int fd);
int		ft_putstr_n(const char *s, int fd);
int		ft_putnbr_n(int n, int fd);	
int		ft_putunbr_n(unsigned int n, int fd);
int		ft_putptr_n(void *ptr, int fd);
int		ft_puthexlowlong_n(unsigned long n, int fd);
int		ft_puthexlow_n(unsigned int n, int fd);
int		ft_puthexup_n(unsigned int n, int fd);

/*
 *	EXTRA FUNCTIONS
 */

char	*ft_ctoa(char c);
int		ft_clean(void *ptr, int ret);
void	ft_throw_error(char *msg, int error_code);
void	ft_striter(char **array, void (*f)());
void	ft_nfree_arr(int n, ...);
void	ft_nfree(int n, ...);
int		ft_isescape(int c);
int		ft_isquote(int c);
char	*ft_strcombine(int n, ...);
char	**ft_strarr_expand(char **array, char *new);
char	**ft_strarr_remove(char **array, char *target);
size_t	ft_strarr_size(char **array);
void	ft_free_arr(void **arr);
char	**ft_strarr_dup(char **arr);
size_t	ft_strdiff(char *src, char sep);
char	*ft_strinsert(char	*dst, char *graft, unsigned int start);
char	*ft_str_detach(char	*str, int start, int end);
char	*ft_straddchar(char *src, char c);

#endif
