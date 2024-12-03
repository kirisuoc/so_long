# So Long

**So Long** es un juego 2D creado en C utilizando la librería **MiniLibX**. El objetivo del juego es guiar a un jugador a través de un mapa lleno de paredes, objetos coleccionables y una salida. El jugador debe recoger todos los objetos y salir del mapa eligiendo el camino más corto posible.

## Características
- **Movimiento del jugador**: Usando las teclas **W**, **A**, **S** y **D**.
- **Interacción con el mapa**: El mapa está compuesto por 5 caracteres (`0` para espacio vacío, `1` para muro, `C` para coleccionables, `E` para la salida y `P` para la posición inicial del jugador).
- **Ventana gráfica**: Utiliza la **MiniLibX** para manejar la ventana y los gráficos.
- **Contador de movimientos**: El número real de movimientos se muestra en el terminal.
- **Verificación del mapa**: Asegura que el mapa sea válido, rectangular y cerrado con muros.

## Instrucciones de uso

### Compilación

1. **Compilar el proyecto**: 
   - Ejecuta `make` para compilar el proyecto.
   - Asegúrate de tener la librería **MiniLibX** instalada.
   
2. **Ejecutar el juego**:
   - El programa toma como primer argumento un archivo de mapa `.ber`.
   - Ejecuta el juego con: 
     ```bash
     ./so_long <map_file>.ber
     ```

### Controles
- **W**: Mover hacia arriba.
- **A**: Mover hacia la izquierda.
- **S**: Mover hacia abajo.
- **D**: Mover hacia la derecha.
- **Esc**: Cerrar la ventana y salir del juego.

### Estructura del Mapa
El mapa debe estar formado por los siguientes caracteres:
- `0` - Espacio vacío.
- `1` - Pared.
- `C` - Objeto coleccionable.
- `E` - Salida.
- `P` - Posición inicial del jugador.

**Ejemplo de un mapa válido**:  
1111111111111  
10010000000C1  
1000011111001  
1P0011E000001  
1111111111111  

### Requisitos
- **MiniLibX**: Se debe utilizar la librería **MiniLibX** para manejar gráficos y eventos.
- **Norma**: El proyecto debe seguir la norma de codificación.
- **Makefile**: Se incluye un **Makefile** que compila el proyecto.

### Funcionalidades adicionales (Bonus)
- Puedes agregar características adicionales, como enemigos, animaciones de sprites o un contador de tiempo.

## Licencia
Este proyecto está bajo la licencia [MIT](LICENSE).
