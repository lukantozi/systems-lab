#ifndef PARSER_H
#define PARSER_H

int pipeline_split(char **, size_t, char ***, int *);
char *get_line(void);
char **tokenize(char **, char *, size_t *);

#endif
