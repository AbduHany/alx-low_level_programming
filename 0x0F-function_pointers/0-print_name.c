/**
 * print_name - prints a name
 * @name: pointer to name string.
 * @f: pointer to function to be called.
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
