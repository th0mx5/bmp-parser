#include <stdio.h>

typedef struct Bmp Bmp;
struct Bmp
{
	int width;
	int height;
	int data_offset;
	char *data;
};

static Bmp get_data_from_file(Bmp img, FILE *file)
{
	int c;
	int i;

	i = 0;
	while ((c = getc(file)) != EOF && i < 10)
	{
		i++;
	}
	img.data_offset = (int)c;
	i++;
	while ((c = getc(file)) != EOF && i < 18)
	{
		i++;
	}
	img.width = (int)c;
	i++;
	while ((c = getc(file)) != EOF && i < 22)
	{
		i++;
	}
	img.height = (int)c;
	i++;
	while ((c = getc(file)) != EOF && i < img.data_offset - 1)
	{
		i++;
	}
	while ((c = getc(file)) != EOF)
	{
		printf("%d", c);
	}
	return (img);
}

int	main(int ac, char **av)
{
	int		c;
	int		i;
	Bmp		img;
	FILE 	*file;

	i = 0;
	file = fopen(av[1], "r");
	if (file) {
		img = get_data_from_file(img, file);
		fclose(file);
	}
	printf("-------------\n");
	printf("width = %d\n", img.width);
	printf("height = %d\n", img.height);
	printf("data_offset = %d\n", img.data_offset);
	return (0);
}