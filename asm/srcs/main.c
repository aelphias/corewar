#include "asm.h"

t_crw       *get_asm_data(t_crw *asm_data)
{
    static t_crw *sd;

	if (!sd)
		sd = asm_data;
	return (sd);
}

/*
** проверяем, является ли подаваемый аргумент файлом
*/

int			is_filename(const char *filename, const char *ext)
{
	if (filename && ext && ft_strlen(filename) >= ft_strlen(ext))
		return (!ft_strcmp(ft_strchr(filename, '\0') - ft_strlen(ext), ext));
	else
		return (0);
}

/*
**здесь выводится тип ошибки в случае её выявления
*/

int         call_error(char const *const err)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putendl_fd(err, 2);
	exit(-1);
}

/*
** main function
*/

int         main(int ac, char *av[])
{
    if (ac < 2)
        call_error(ERR_USE);
	else if (ac == 2 && is_filename(*(av + 1), ".s"))
		assembler_mode(*(av + 1));
	else if (ac == 2 && is_filename(*(av + 1), ".cor"))
		disassembler_mode(*(av + 1));
	else
		call_error(ERR_FILE);
    return (0);
}