#ifndef EXEC_H
#define EXEC_H

void reap_children(int pipefds[], int pipe_count, pid_t children[], int command_count);
void execute_pipeline(int pipefds[], int pipe_count, int pipe_flag, char *line, char ***cmd_start, pid_t children[]);
void cmd_run(char **tokens, char *line, int pipe_flag);
void builtin_run(int *builtin_flag, char **tokens);
void execute(char **tokens, char *line, int pipe_flag);
void create_pipes(int *pipefds, int pipe_count, char *line, char **tokens);
void close_pipes(int pipefds[], int pipes_num);

#endif
