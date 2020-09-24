/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   yeet.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 16:04:18 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/09/24 19:17:22 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef YEET_H
# define YEET_H

int	vec_add(t_vec *vector, void *buffer);
int	vec_destroy(t_vec *vector, void (*del)(void *));
int	vec_get(t_vec *vector, void *buffer, size_t index);
int	vec_getref(t_vec *vector, void **buffer, size_t index);
int	vec_new(t_vec *vector, size_t type_size);

int	builtin_error(char **argv);
int	ft_cd(t_msh *prog, int argc, char **argv);
int	ft_echo(t_msh *prog, int argc, char **argv);
int	ft_env(t_msh *prog, int argc, char **argv);
int	ft_exit(t_msh *prog, int argc, char **argv);
int	ft_export(t_msh *prog, int argc, char **argv);
int	ft_pwd(t_msh *prog, int argc, char **argv);
int	ft_unset(t_msh *prog, int argc, char **argv);
char	*get_cwd(void);
int	clear_commands(t_cmd *commands);
int	get_commands(t_msh *prog, t_tok *tokens, size_t totaltokens);
t_cmd	*new_command(char **argstart, int *types, t_vec *fd_arr);
t_cmd	*push_command(t_cmd **commands, t_cmd *new);
int	run_commands(t_msh *prog, t_cmd *commands);
void	debug_commands(t_cmd *commands);
void	print_state(int c, t_lexer lex);
void	print_tokens(t_tok *tokens);
int	env_clear(t_var *env, void);
char	**env_convert(t_var *env);
void	env_del(t_var *delete);
int	modify_shlvl(t_var *env);
int	env_init(t_msh *prog);
t_var	*env_new(const char *name, const char *val);
void	env_print(t_var *env);
void	env_unset(t_var **env, char *name);
void	env_update(t_msh *prog);
char	*env_val_get(const char *name, t_var *env, size_t len);
int	check_last(const char *name, t_var *iter, const char *val);
t_var	*env_val_set(const char *name, t_var **env, const char *val);
int	pwd_set(t_var **env);
void	execute(t_msh *prog, t_cmd *cmd);
void	get_abspath(char *program, char **abspath_to_exe, t_var *env);
char	*get_program(char **args, int *types);
int	run_builtin(t_msh *prog, t_cmd *cmd, int id);
void	run_program(t_msh *prog, t_cmd *cmd, char *abspath);
int	get_endstate(t_vecstr *line);
int	handle_input(t_line *line, char buf[6]);
int	initialize_line_editor(t_line *line);
char	*prompt(t_msh *prog, t_line *line);
int	read_input(t_msh *prog);
int	read_input(t_msh *prog);
void	refresh_cursor(t_line *line);
int	backspace(t_line *line, char buf[6]);
int	char_input(t_line *line, char buf[6]);
void	cursor_end(t_line *line);
void	cursor_home(t_line *line);
void	cursor_left(t_line *line);
int	cursor_move(t_line *line, int c);
void	cursor_move_row(t_line *line, int c);
void	cursor_move_word(t_line *line, int c);
void	cursor_right(t_line *line);
int	send_eof(t_line *line, char buf[6]);
int	send_input(t_line *line, char buf[6]);
int	special_command(t_line *line, char buf[6]);
void	close_all(t_vec *fd_arr);
void	close_ifnot(t_vec *fd_arr, int *iostream);
void	close_iostream(int *iostream);
int	in_out_redirection(t_msh *prog, t_cmd *command);
int	set_redirection(t_cmd *command, char **args, int *types, t_vec *fd_arr);
int	add_char(t_line *line, char c);
int	clear_input(t_line *line, char buf[6]);
int	clear_screen(t_line *line, char buf[6]);
int	delete_char(t_line *line);
int	delete_word(t_line *line);
void	init_readline(t_msh *prog);
void	init_readline(t_msh *prog);
void	termcmd(char *command, int p1, int p2, int lines_affected);
int	check_esc_char(t_vecstr *line, t_lexer *lex, int gen_true);
int	conv_tokens(t_msh *prog, t_tok *tokens, size_t totaltokens);
void	create_token(t_tok *token, t_lexer *lex);
void	env_current_process(t_lexer *lex, t_vecstr *line, t_msh *prog);
void	env_zero(t_lexer *lex, t_vecstr *line, t_msh *prog);
void	env_exitstatus(t_lexer *lex, t_vecstr *line, t_msh *prog);
size_t	env_strclen(char *line);
void	evaluate_env(t_lexer *lex, t_vecstr *line, t_msh *prog);
void	evaluate_env(t_lexer *lex, t_vecstr *line, t_msh *prog);
int	gen_tokens(t_tok **tokens, t_vecstr *line, t_msh *prog);
int	gen_tokens(t_tok **tokens, t_vecstr *line, t_msh *prog);
void	init_lexer(t_lexer *lex);
int	lex_checkstate(int c, t_lexer lex);
int	parse_error(char c);
void	quote_toks(t_tok **tokens, t_lexer *lex, t_vecstr *line, t_msh *prog);
void	quote_toks(t_tok **tokens, t_lexer *lex, t_vecstr *line, t_msh *prog);
int	tokenizer(t_msh *prog, t_vecstr *line);
void	update_lexer(char *line, t_lexer *lex);
size_t	ft_no_ansi_strlen(const char *str);
char	**ft_str2clear(char **str);
long long	ft_str2cmpstr(const char **str2, char *str);
size_t	ft_str2len(char **str);
void	ft_str2print(char **str);
char	*ft_str3join(const char *s1, const char *s2, const char *s3);
size_t	ft_strslen(char *str, char *set);
char	*ft_strsdup(char *str, char *set);

#endif
