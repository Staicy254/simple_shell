#include "my_shell.h"

/**
 * my_env_get_key - function that gets the value of env vars.
 * @key: variable representing the environment variable of interest.
 * @data: variable representing the struct of the program data.
 * Return: (pointer to variable value) Success or (NULL) when not present.
 */
char *my_env_get_key(char *key, data_of_program *data)
{
int q, key_length = 0;

/*arguments validation */
if (key == NULL || data->env == NULL)
return (NULL);

/* variable length requested */
key_length = my_str_length(key);

for (q = 0; data->env[q]; q++)
{/* checking coincidence of variable name */
if (my_str_compare(key, data->env[q], key_length) &&
data->env[q][key_length] == '=')
{/* return key NAME=  when found*/
return (data->env[q] + key_length + 1);
}
}
/* return NULL when not found*/
return (NULL);
}
