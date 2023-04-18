// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include "MLX42/include/MLX42/MLX42.h"

mlx_image_t* image;

#define WIDTH 512
#define HEIGHT 512


// -----------------------------------------------------------------------------

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 15;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 15;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 15;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 15;
}

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(0);
}

int main(void)
{
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
        error();

	// Create a new image
	image = mlx_new_image(mlx, 32, 32);
	if (!image)
		error();

	// Set every pixel to white
	memset(image->pixels, 255, image->width * image->height * sizeof(int32_t));

	// Display an instance of the image
	if (mlx_image_to_window(mlx, image, 0, 0) < 0)
        error();
	mlx_loop_hook(mlx, &ft_hook, mlx);
	mlx_loop(mlx);

	// Optional, terminate will clean up any left overs, this is just to demonstrate.
	mlx_delete_image(mlx, image);
	mlx_terminate(mlx);
	return (1);
}
