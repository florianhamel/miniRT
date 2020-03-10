int	main(int ac, char **av)
{
	if (ac == 2)
		miniRT(av[1]);
	else
		ft_printf("Please select a file with \".rt\" extention.");
	return (0);
}

int	miniRT(char *file)
{
	int		fd;
	t_data	*data;

	fd = open("./file", O_RDONLY);
	init_data(data);
	if (parsing(fd, data) == -1)
		return (-1);
	close(fd);
}

void	init_data(t_data *data)
{
	data->R = NULL;
	data->A = NULL;
	data->cameras = NULL;
	data->lights = NULL;
	data->objects = NULL;
}
