DOCUMENTACION 


	1.	Configuración inicial
	•	1.1 Configurar el Makefile con las reglas básicas (NAME, all, clean, fclean, re).
	•	1.2 Crear los archivos iniciales (minishell.c, utils.c, signals.c, etc.) y la estructura de directorios si es necesario.
	•	1.3 Configurar las librerías obligatorias, como readline, e integrar libft si se necesita.
	2.	Loop principal del shell
	•	2.1 Implementar el bucle interactivo:
	•	Mostrar un prompt.
	•	Leer la entrada del usuario utilizando readline.
	•	Almacenar los comandos en el historial con add_history.
	3.	Manejo de señales
	•	3.1 Configurar ctrl-C, ctrl-D y ctrl-\ usando sigaction o signal.
	•	3.2 Implementar una variable global para manejar señales sin romper la normativa.
	4.	Parsing (robusto y modular)
	•	4.1 Diseñar un tokenizer para separar comandos, argumentos y operadores (|, <, >, >>, <<).
	•	4.2 Manejar las comillas (' y `”) para proteger metacaracteres.
	•	4.3 Implementar un parser que convierta los tokens en una estructura organizada:
	•	Comandos con argumentos.
	•	Redirecciones.
	•	Pipelines.
	5.	Ejecución de comandos básicos
	•	5.1 Implementar la búsqueda de ejecutables en el PATH o rutas relativas/absolutas.
	•	5.2 Usar execve para ejecutar comandos externos.
	6.	Implementación de built-ins Implementar los comandos internos en este orden, ya que algunos son interdependientes:
	•	6.1 echo con -n.
	•	6.2 cd para cambiar de directorio.
	•	6.3 pwd para mostrar el directorio actual.
	•	6.4 export para añadir variables de entorno.
	•	6.5 unset para eliminarlas.
	•	6.6 env para mostrar las variables de entorno actuales.
	•	6.7 exit para terminar el shell.
	7.	Gestión de redirecciones
	•	7.1 Implementar redirección de entrada (<) y salida (>).
	•	7.2 Implementar append (>>) y heredoc (<<).
	8.	Implementación de pipes
	•	8.1 Crear pipes para conectar el output de un comando al input de otro.
	•	8.2 Manejar múltiples pipes en una misma línea.
	9.	Variables de entorno y expansión
	•	Mostrar el estado de salida del último comando ejecutado.
	10.	Manejo avanzado
	•	10.1 Gestionar errores comunes (comillas sin cerrar, comandos inválidos, etc.).
	•	10.2 Optimizar el uso de memoria, liberando recursos al salir o al reejecutar el bucle.
	11.	Validaciones finales
	•	11.1 Probar con casos interactivos y no interactivos.
	•	11.2 Comparar el comportamiento con Bash.

Jerarquía de redirecciones en Bash

Bash procesa las redirecciones y pipes de acuerdo con estas reglas:
	1.	Pipes (|): Conectan la salida estándar de un comando con la entrada estándar del siguiente.
	2.	Redirección de archivos (< y >): Redirigen entradas o salidas estándar a archivos (o comandos).
	3.	Orden de evaluación: Bash evalúa de izquierda a derecha. Sin embargo, si hay conflictos (por ejemplo, múltiples redirecciones de entrada estándar), el comando falla.


Logica Organizacion Archivos :

minishell/
.
├── include
│   └── minishell.h
├── libft
│   ├── ft_atoi.c
│   ├── ft_bzero.c
│   ├── ft_calloc.c
│   ├── ft_isalnum.c
│   ├── ft_isalpha.c
│   ├── ft_isascii.c
│   ├── ft_isdigit.c
│   ├── ft_isprint.c
│   ├── ft_itoa.c
│   ├── ft_lstadd_back_bonus.c
│   ├── ft_lstadd_front_bonus.c
│   ├── ft_lstclear_bonus.c
│   ├── ft_lstdelone_bonus.c
│   ├── ft_lstiter_bonus.c
│   ├── ft_lstlast_bonus.c
│   ├── ft_lstmap_bonus.c
│   ├── ft_lstnew_bonus.c
│   ├── ft_lstsize_bonus.c
│   ├── ft_memchr.c
│   ├── ft_memcmp.c
│   ├── ft_memcpy.c
│   ├── ft_memmove.c
│   ├── ft_memset.c
│   ├── ft_putchar_fd.c
│   ├── ft_putendl_fd.c
│   ├── ft_putnbr_fd.c
│   ├── ft_putstr_fd.c
│   ├── ft_split.c
│   ├── ft_strcat.c
│   ├── ft_strchr.c
│   ├── ft_strcmp.c
│   ├── ft_strdup.c
│   ├── ft_striteri.c
│   ├── ft_strjoin.c
│   ├── ft_strlcat.c
│   ├── ft_strlcpy.c
│   ├── ft_strlen.c
│   ├── ft_strmapi.c
│   ├── ft_strncmp.c
│   ├── ft_strnstr.c
│   ├── ft_strrchr.c
│   ├── ft_strtrim.c
│   ├── ft_substr.c
│   ├── ft_tolower.c
│   ├── ft_toupper.c
│   ├── libft.a
│   ├── libft.h
│   └── Makefile
├── Makefile
├── minishell
├── README.MD
├── src
│   ├── L0_Sig.c
│   ├── L1_Exp.c
│   ├── L2_Token.c
│   ├── L3_Parse.c
│   ├── L4_Redir.c
│   ├── L5_Exec.c
│   ├── L6_BuiltIns.c
│   ├── L6_Utils.c
│   ├── L9_EC.c
│   └── main.c
└── test
    └── func.c

5 directories, 63 files
