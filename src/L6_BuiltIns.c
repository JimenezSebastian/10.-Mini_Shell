#include "../include/minishell.h"

/*
** 6.1. echo [-n]
** Imprime argumentos, maneja la opción -n (sin salto de línea).
*/
int ft_echo(char **args)
{
    int i = 1;
    int newline = 1;

    // Manejar banderas -n consecutivas (opcional, depende normativa)
    while (args[i] && strcmp(args[i], "-n") == 0)
    {
        newline = 0;
        i++;
    }
    // Imprimir el resto de argumentos
    while (args[i])
    {
        printf("%s", args[i]);
        if (args[i + 1])
            printf(" "); // Separador
        i++;
    }
    // Si hay que hacer salto de línea
    if (newline)
        printf("\n");
    return (0);
}

/*
** 6.2. cd [ruta]
** Cambia el directorio actual a 'ruta' o $HOME si no se pasa arg.
** Actualiza variables PWD y OLDPWD si quieres mantener consistencia.
*/
int ft_cd(char **args, char ***env)
{
    char *path;
    // Buffer para getcwd
    char cwd[1024]; // PATH_MAX puede ser 4096 en Linux, pero ajusta según quieras

    // Si no hay args[1], usar HOME
    if (!args[1])
    {
        // Búscate una función que obtenga "HOME" de env
        path = getenv_from_env(*env, "HOME"); 
        if (!path)
        {
            fprintf(stderr, "cd: HOME not set\n");
            return (1);
        }
    }
    else
        path = args[1];

    // Guardar directorio actual en OLDPWD (opcional)
    if (getcwd(cwd, sizeof(cwd)))
        setenv_in_env(env, "OLDPWD", cwd); // tu función para setear

    // Cambiar de directorio
    if (chdir(path) != 0)
    {
        perror("cd");
        return (1);
    }

    // Actualizar PWD
    if (getcwd(cwd, sizeof(cwd)))
        setenv_in_env(env, "PWD", cwd);

    return (0);
}

/*
** 6.3. pwd
** Imprime el directorio actual.
*/
int ft_pwd(void)
{
    char cwd[1024];
    if (!getcwd(cwd, sizeof(cwd)))
    {
        perror("pwd");
        return (1);
    }
    printf("%s\n", cwd);
    return (0);
}

/*
** 6.4. export VAR=VAL
** Crea o actualiza una variable de entorno en env.
*/
int ft_export(char **args, char ***env)
{
    int i = 1;
    // Si no hay argumentos, podrías mostrar las variables en formato `declare -x ...`
    if (!args[1])
    {
        print_env_export(*env); // Imprime con "declare -x " o como te pida la normativa
        return (0);
    }
    // Recorrer argumentos
    while (args[i])
    {
        // Buscar '='
        char *equal_sign = strchr(args[i], '=');
        if (equal_sign)
        {
            // Separar var y value
            *equal_sign = '\0';
            char *var_name = args[i];
            char *var_value = equal_sign + 1;

            // Ver si var_name es válido
            if (!is_valid_identifier(var_name))
            {
                fprintf(stderr, "export: `%s': not a valid identifier\n", args[i]);
                // Decide si sigues o devuelves error
            }
            else
                setenv_in_env(env, var_name, var_value);
        }
        else
        {
            // Puede que sea un "export VAR" sin valor
            if (!is_valid_identifier(args[i]))
            {
                fprintf(stderr, "export: `%s': not a valid identifier\n", args[i]);
            }
            else
            {
                // Crea la variable vacía, o no hagas nada (depende normativa)
                setenv_in_env(env, args[i], "");
            }
        }
        i++;
    }
    return (0);
}

/*
** 6.5. unset VAR
** Elimina una variable del entorno.
*/
int ft_unset(char **args, char ***env)
{
    int i = 1;

    if (!args[1])
        return (0);

    while (args[i])
    {
        if (!is_valid_identifier(args[i]))
        {
            fprintf(stderr, "unset: `%s': not a valid identifier\n", args[i]);
        }
        else
        {
            unsetenv_in_env(env, args[i]);
        }
        i++;
    }
    return (0);
}

/*
** 6.6. env
** Muestra todas las variables de entorno en formato VAR=valor
*/
int ft_env(char **args, char **env)
{
    // Si hay argumentos extra, depende la normativa (en Bash se usan para otros propósitos).
    if (args[1])
    {
        // Podrías ignorarlo o imprimir error
        fprintf(stderr, "env: too many arguments\n");
        return (1);
    }
    // Imprime todas las variables
    for (int i = 0; env[i]; i++)
        printf("%s\n", env[i]);
    return (0);
}

/*
** 6.7. exit [status]
** Termina la shell con un código de salida (0 o el que se pase).
*/
int ft_exit(char **args)
{
    // Puedes imprimir "exit\n" según la normativa de 42
    printf("exit\n");

    if (!args[1])
        exit(0);

    // Validar que args[1] sea numérico
    for (int i = 0; args[1][i]; i++)
    {
        if ((i == 0 && (args[1][i] == '-' || args[1][i] == '+')) 
            || (args[1][i] >= '0' && args[1][i] <= '9'))
            continue;
        else
        {
            fprintf(stderr, "minishell: exit: %s: numeric argument required\n", args[1]);
            exit(2);
        }
    }
    // Manejar múltiples argumentos -> "too many arguments" en bash
    if (args[2])
    {
        fprintf(stderr, "minishell: exit: too many arguments\n");
        return (1); 
        // O decide si sales de una
    }
    int status = atoi(args[1]);
    exit(status);
    return (0); // no se ejecuta realmente
}

int ft_builtin_verify(t_command *cmd, char ***envp)
{
    if (!cmd->argv[0])
        return (0);

    if (strcmp(cmd->argv[0], "echo") == 0)
        return ft_echo(cmd->argv);
    else if (strcmp(cmd->argv[0], "cd") == 0)
        return ft_cd(cmd->argv, envp);
    else if (strcmp(cmd->argv[0], "pwd") == 0)
        return ft_pwd();
    else if (strcmp(cmd->argv[0], "export") == 0)
        return ft_export(cmd->argv, envp);
    else if (strcmp(cmd->argv[0], "unset") == 0)
        return ft_unset(cmd->argv, envp);
    else if (strcmp(cmd->argv[0], "env") == 0)
        return ft_env(cmd->argv, *envp);
    else if (strcmp(cmd->argv[0], "exit") == 0)
        return ft_exit(cmd->argv);
    else
        return (1);
}