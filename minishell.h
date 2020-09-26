/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 10:51:49 by rlucas        #+#    #+#                 */
/*   Updated: 2020/09/26 12:03:17 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# include <libft_types.h>
# include <vector.h>
# include <termios.h>

typedef struct s_lexer	t_lexer;
typedef struct s_tok	t_tok;
typedef struct s_cmd	t_cmd;
typedef struct s_var	t_var;

typedef struct			s_coord
{
	int					row;
	int					col;
}						t_coord;

typedef struct			s_line
{
	char				*prompt;
	size_t				promptlen;
	char				*multiline_prompt;
	size_t				multiline_len;
	t_vecstr			cmd;
	size_t				inputrow;
	t_coord				max;
	t_coord				cursor;
	size_t				total_rows;
	int					escmode;
	char				*termtype;
	char				cap_table[2048];
	struct termios		term;
}						t_line;

typedef	struct			s_msh
{
	t_vec				file_arr;
	t_vec				argtypes;
	t_vec				args;
	t_cmd				*commands;
	int					exit_status;
	char				**envp;
	t_var				*env;
	t_line				line;
	size_t				argc;
}						t_msh;

enum					e_error
{
	MEM_FAIL,
	TERM_FAIL,
	CAP_FAIL
};

enum					e_stages
{
	PRE_ENV,
	IN_ENV,
	IN_TERM,
	IN_INPUT
};

t_vec					g_pid;
char					*g_prompt;
int						g_siggy;
int						g_total_lines;
int						g_current_line;

/*
** Utility functions in utils.c
*/

size_t					ft_no_ansi_strlen(const char *str);
char					*ft_strsdup(char *str, char *set);
size_t					ft_str2len(char **str);
char					**ft_str2clear(char **str);
void					ft_str2print(char **str);
long long				ft_str2cmpstr(const char **str2, char *str);
char					*ft_str3join(const char *s1, const char *s2,
								const char *s3);

/*
** Functions to free all allocated memory before exiting - erroneously or
** normally.
*/

char					*error_lookup(int err);
void					error_exit(t_msh *prog, int err);
void					std_exit(t_msh *prog, int n);

/*
** Functions to read input and handle line-editing. In read_input.c,
** handle_input.c, and input*.c.
*/

int						get_endstate(t_vecstr *line);
char					*prompt(t_msh *prog, t_line *line);
int						handle_input(t_line *line, char buf[6]);
int						initialize_line_editor(t_line *line);
void					refresh_cursor(t_line *line);
int						read_input(t_msh *prog);

/*
** Signal functions.
*/

void					sighandler(int signal);

/*
** Troubleshooting
*/

void					debug_commands(t_cmd *commands);
void					print_state(int c, t_lexer lex);
void					print_tokens(t_tok *tokens);

#endif
