#include "../include/minishell.h"

 size_t env_count(char **env)
{
    size_t i = 0;
    while (env && env[i])
        i++;
    return i;
}

/**
 * Duplica el entorno 'env' en un nuevo array 'my_env' terminado en NULL.
 */
char **ft_duplicate_env(char **env)
{
    if (!env)
        return (NULL);
    size_t count = env_count(env);
    // Reservamos array de punteros de tamaño count + 1
    // (+1 para terminar en NULL)
    char **my_env = malloc(sizeof(char *) * (count + 1));
    if (!my_env)
        return NULL;

    size_t i = 0;
    while (i < count)
    {
        // strdup cada variable (o tu ft_strdup)
        my_env[i] = strdup(env[i]);
        if (!my_env[i])
        {
            // Manejo de error: si falla, liberar todo
            while (i > 0)
                free(my_env[--i]);
            free(my_env);
            return NULL;
        }
        i++;
    }
    my_env[i] = NULL; // Termina el array
    return my_env;
}

/**
 * Busca 'var' en 'my_env'.
 * - 'var' es un nombre de variable (ej: "HOME")
 * - Devuelve un puntero al valor de la variable (después del '=') si existe.
 * - Devuelve NULL si no existe.
 */
char *getenv_from_env(char **my_env, const char *var)
{
    if (!my_env || !var)
        return NULL;

    size_t var_len = strlen(var);

    // Recorremos cada línea 'VAR=VAL'
    for (size_t i = 0; my_env[i]; i++)
    {
        // Compara primero var_len caracteres y verifica que justo después haya '='
        if (strncmp(my_env[i], var, var_len) == 0 && my_env[i][var_len] == '=')
        {
            // Retorna el puntero al valor (después del '=')
            return my_env[i] + var_len + 1;
        }
    }
    return NULL;
}

/**
 * Crea o actualiza la variable 'var' con el valor 'value' en *my_env.
 * - Se asume que var y value son strings válidos (sin espacios ni '=').
 * - Si var ya existe, reemplaza el valor.
 * - Si var no existe, se realoca el array para añadirla.
 */
int setenv_in_env(char ***my_env, const char *var, const char *value)
{
    if (!my_env || !*my_env || !var)
        return -1;

    // Preparamos la nueva cadena "VAR=VAL"
    size_t var_len = strlen(var);
    size_t val_len = (value) ? strlen(value) : 0;
    char *new_entry = malloc(var_len + val_len + 2); // 1 para '=' y 1 para '\0'
    if (!new_entry)
        return -1;
    // Construir la cadena
    sprintf(new_entry, "%s=%s", var, (value) ? value : "");

    // 1) Ver si ya existe en my_env
    for (size_t i = 0; (*my_env)[i]; i++)
    {
        if (strncmp((*my_env)[i], var, var_len) == 0 && (*my_env)[i][var_len] == '=')
        {
            // Existe, sustituimos
            free((*my_env)[i]);
            (*my_env)[i] = new_entry;
            return 0;
        }
    }

    // 2) Si no existe, la añadimos al final
    // Primero contamos cuántos elementos hay
    size_t count = 0;
    while ((*my_env)[count])
        count++;

    // Creamos un nuevo array con espacio para (count + 2)
    // (la nueva variable y el NULL final)
    char **new_envp = malloc(sizeof(char *) * (count + 2));
    if (!new_envp)
    {
        free(new_entry);
        return -1;
    }

    // Copiamos los punteros antiguos
    for (size_t i = 0; i < count; i++)
        new_envp[i] = (*my_env)[i];

    // Añadimos la nueva variable y el NULL final
    new_envp[count] = new_entry;
    new_envp[count + 1] = NULL;

    // Liberamos el array antiguo (pero no sus strings) y reasignamos
    free(*my_env);
    *my_env = new_envp;

    return 0;
}

/**
 * Elimina la variable 'var' de *my_env si existe.
 * - Retorna 0 aunque no exista, porque no es un "error".
 */
int unsetenv_in_env(char ***my_env, const char *var)
{
    if (!my_env || !*my_env || !var)
        return -1;

    size_t var_len = strlen(var);
    size_t i = 0;

    while ((*my_env)[i])
    {
        if (strncmp((*my_env)[i], var, var_len) == 0 && (*my_env)[i][var_len] == '=')
        {
            // La encontramos, liberamos la cadena
            free((*my_env)[i]);

            // Desplazar el resto una posición
            while ((*my_env)[i + 1])
            {
                (*my_env)[i] = (*my_env)[i + 1];
                i++;
            }
            // Ahora i apunta al último elemento no-NULL
            (*my_env)[i] = NULL;
            return 0;
        }
        i++;
    }
    return 0; // No la encontró, pero no es error
}

/**
 * Libera cada string del entorno y luego libera el propio array.
 */
void free_env(char **my_env)
{
    if (!my_env)
        return;

    size_t i = 0;
    while (my_env[i])
    {
        free(my_env[i]);
        i++;
    }
    free(my_env);
}

void print_env_export(char **env)
{
    int i = 0;

    while (env && env[i])
    {
        // env[i] es algo como "FOO=BAR"
        char *equal_sign = ft_strchr(env[i], '=');
        if (equal_sign)
        {
            // Separamos var y value
            // var = lo que hay antes del '='
            // value = lo que hay después
            // Ejemplo con ft_substr (función de la libft)
            char *var_name = ft_substr(env[i], 0, equal_sign - env[i]);
            char *var_value = ft_substr(env[i], (equal_sign - env[i]) + 1,
                                        ft_strlen(env[i]) - (equal_sign - env[i] + 1));

            // Imprimir con comillas
            printf("declare -x %s=\"%s\"\n", var_name, var_value);

            free(var_name);
            free(var_value);
        }
        else
        {
            // No hay '=', solo imprime 'declare -x VAR'
            // (caso de variable sin valor)
            printf("declare -x %s\n", env[i]);
        }
        i++;
    }
}

int is_valid_identifier(const char *str)
{
    int i;

    if (!str || !str[0])
        return (0);
    if (!ft_isalpha(str[0]) && str[0] != '_')
        return (0);
    i = 1;
    // Verificar el resto
    while (str[i])
    {
        if (!ft_isalnum(str[i]) && str[i] != '_')
            return (0);
        i++;
    }
    return (1);
}

int ft_strcmp(const char *s1, const char *s2)
{
    int n;

    n = 0;
    while(s1[n])
    {
        if (s1[n] == s2[n])
            ++n;
        else 
            return(1);
    }
    return (0);
}