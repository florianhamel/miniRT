int	main()
{
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
