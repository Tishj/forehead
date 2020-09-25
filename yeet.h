/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   yeet.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 16:04:18 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/09/25 12:07:31 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef YEET_H
# define YEET_H

int	vec_getref(t_vec *vector, void **buffer, size_t index);
int	vec_destroy(t_vec *vector, void (*del)(void *));
int	vec_add(t_vec *vector, void *buffer);
size_t	ft_strslen(char *str, char *set);
char	*ft_str3join(const char *s1, const char *s2, const char *s3);
void	ft_str2print(char **str);
size_t	ft_str2len(char **str);
long long	ft_str2cmpstr(const char **str2, char *str);
char	**ft_str2clear(char **str);
size_t	ft_no_ansi_strlen(const char *str);
char	*env_val_get(const char *name, t_var *env, size_t len);
void	update_lexer(char *line, t_lexer *lex);
void	execute(t_msh *prog, t_cmd *cmd);
void	print_state(int c, t_lexer lex);
t_var	*env_val_set(const char *name, t_var **env, const char *val);
int	check_last(const char *name, t_var *iter, const char *val);
void	env_update(t_msh *prog);
char	*prompt(t_msh *prog, t_line *line);
t_var	*env_new(const char *name, const char *val);
int	run_builtin(t_msh *prog, t_cmd *cmd, int id);
int	add_char(t_line *line, char c);
int	env_init(t_msh *prog);
int	set_redirection(t_cmd *command, char **args, int *types, t_vec *fd_arr);
int	modify_shlvl(t_var *env);
int	env_clear(t_var *env, void);
void	env_print(t_var *env);
int	clear_commands(t_cmd *commands);
void	print_tokens(t_tok *tokens);
void	close_ifnot(t_vec *fd_arr, int *iostream);
int	ft_export(t_msh *prog, int argc, char **argv);
void	refresh_cursor(t_line *line);
void	env_current_process(t_lexer *lex, t_vecstr *line, t_msh *prog);
int	ft_exit(t_msh *prog, int argc, char **argv);
void	close_all(t_vec *fd_arr);
int	parse_error(char c);
char	**env_convert(t_var *env);
char	*get_cwd(void);
void	run_program(t_msh *prog, t_cmd *cmd, char *abspath);
void	cursor_move_word(t_line *line, int c);
void	env_exitstatus(t_lexer *lex, t_vecstr *line, t_msh *prog);
int	get_commands(t_msh *prog, t_tok *tokens, size_t totaltokens);
int	vec_get(t_vec *vector, void *buffer, size_t index);
int	builtin_error(char **argv);
void	debug_commands(t_cmd *commands);
t_cmd	*push_command(t_cmd **commands, t_cmd *new);
int	pwd_set(t_var **env);
int	ft_cd(t_msh *prog, int argc, char **argv);
void	env_unset(t_var **env, char *name);
char	*get_program(char **args, int *types);
int	ft_pwd(t_msh *prog, int argc, char **argv);
char	*ft_strsdup(char *str, char *set);
int	ft_echo(t_msh *prog, int argc, char **argv);
int	ft_unset(t_msh *prog, int argc, char **argv);
int	backspace(t_line *line, char buf[6]);
int	ft_env(t_msh *prog, int argc, char **argv);
int	conv_tokens(t_msh *prog, t_tok *tokens, size_t totaltokens);
void	env_del(t_var *delete);
int	run_commands(t_msh *prog, t_cmd *commands);
int	handle_input(t_line *line, char buf[6]);
int	initialize_line_editor(t_line *line);
int	tokenizer(t_msh *prog, t_vecstr *line);
int	delete_char(t_line *line);
int	read_input(t_msh *prog);
int	special_command(t_line *line, char buf[6]);
int	char_input(t_line *line, char buf[6]);
void	cursor_home(t_line *line);
void	cursor_left(t_line *line);
int	cursor_move(t_line *line, int c);
void	cursor_move_row(t_line *line, int c);
void	cursor_right(t_line *line);
int	send_input(t_line *line, char buf[6]);
t_cmd	*new_command(char **argstart, int *types, t_vec *fd_arr);
void	evaluate_env(t_lexer *lex, t_vecstr *line, t_msh *prog);
void	close_iostream(int *iostream);
int	gen_tokens(t_tok **tokens, t_vecstr *line, t_msh *prog);
int	vec_new(t_vec *vector, size_t type_size);
int	in_out_redirection(t_msh *prog, t_cmd *command);
void	get_abspath(char *program, char **abspath_to_exe, t_var *env);
void	quote_toks(t_tok **tokens, t_lexer *lex, t_vecstr *line, t_msh *prog);
void	init_readline(t_msh *prog);
int	check_esc_char(t_vecstr *line, t_lexer *lex, int gen_true);
void	create_token(t_tok *token, t_lexer *lex);
void	termcmd(char *command, int p1, int p2, int lines_affected);
int	get_endstate(t_vecstr *line);
int	delete_word(t_line *line);
void	env_zero(t_lexer *lex, t_vecstr *line, t_msh *prog);
int	clear_input(t_line *line, char buf[6]);
void	init_lexer(t_lexer *lex);
int	send_eof(t_line *line, char buf[6]);
void	cursor_end(t_line *line);
size_t	env_strclen(char *line);
int	clear_screen(t_line *line, char buf[6]);
int	lex_checkstate(int c, t_lexer lex);

#endif
