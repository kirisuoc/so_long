/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:48:08 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/07 13:43:09 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stddef.h>
#include <stdlib.h>
#include <X11/keysym.h>

int close_window(void *param)
{
    (void)param;
    exit(0); // Termina el programa
}

int close_on_esc(int keycode, void *param)
{
    if (keycode == XK_Escape) // Verifica si la tecla presionada es ESC
    {
        exit(0); // Sale del programa
    }
    return (0);
}

int main()
{
    // Inicializar conexión a X
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 1366, 768, "Imagen");
	void *win2 = mlx_new_window(mlx, 1366, 768, "Imagen");

    // Crear una imagen en memoria de 800x600
	void *img = mlx_new_image(mlx, 1366, 768);

	   // Declarar variables para almacenar la información de la imagen
    int bpp;         // Bits por píxel
    int size_line;   // Longitud de cada línea de la imagen en bytes
    int endian;      // Orden de bytes: 0 para Little Endian, 1 para Big Endian


	char *data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

     // Dibujar en la imagen (rellenar con un color, por ejemplo)
    for (int y = 200; y < 600; y++)
    {
        for (int x = 0; x < 800; x++)
        {
            int pixel = (y * size_line) + (x * (bpp / 8));
            data[pixel] = 255;    // Azul
            data[pixel + 1] = 0;  // Verde
            data[pixel + 2] = 0;  // Rojo
        }
    }


	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win2, img, 0, 0);

	// Captura el evento de cerrar la ventana
    mlx_hook(win, 17, 0, close_window, NULL);
	mlx_hook(win2, 17, 0, close_window, NULL);

    mlx_key_hook(win, close_on_esc, NULL);

    // Esperar y mantener la ventana abierta
    mlx_loop(mlx);
    return (0);
}
