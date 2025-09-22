#include "../include/minishell.h"

int is_operator(char c) 
{
    return (c == '|' || c == '<' || c == '>');
}

char *extract_quoted_content(char *input, size_t *i)
{
    char *content;
    char quote_type;    
    size_t start = ++(*i);       // Saltar comilla inicial

    quote_type = input[*i];
    while (input[*i] != '\0' && input[*i] != quote_type)
        (*i)++;

    if (input[*i] == '\0') 
    {
        fprintf(stderr, "Error: Falta comilla de cierre\n");
        return NULL; // Manejar error de comillas no cerradas
    }
    content = strndup(input + start, *i - start); // Copiar contenido entre comillas
    (*i)++; // Saltar la comilla de cierre
    return content;
}

char **ft_tokenize(char *input)
{
    char **tokens = malloc(sizeof(char *) * MAX_TOKENS);
    size_t i = 0, token_count = 0;
    size_t start = 0;

    while (input[i] != '\0')
    {
        // Saltar espacios en blanco
        while (isspace(input[i]))
            i++;

        if (input[i] == '\0')
            break; // Fin de la entrada
        // Marcar inicio del token
        start = i;
        if (is_operator(input[i])) 
        {
            if (input[i] == '>' && input[i + 1] == '>') 
            {
                tokens[token_count++] = strndup(input + i, 2); // ">>"
                i += 2;
            }
            else if (input[i] == '<' && input[i + 1] == '<')
            {
                tokens[token_count++] = strndup(input + i, 2); // "<<"
                i += 2;
            } 
            else 
            {
                tokens[token_count++] = strndup(input + i, 1); // "|", "<", ">"
                i++;
            }
        }
        // Manejar comillas
        else if (input[i] == '"' || input[i] == '\'')
        {
            char *quoted = extract_quoted_content(input, &i);
            if (quoted)
                tokens[token_count++] = quoted;
        }
        // Manejar palabras
        else
        {
            while (input[i] != '\0' && !isspace(input[i]) && !is_operator(input[i]))
                i++;
            tokens[token_count++] = strndup(input + start, i - start);
        }
    }
    tokens[token_count] = NULL; // Terminar la lista de tokens
    return (tokens);
}