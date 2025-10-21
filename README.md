# fract-ol

[![42 School project](https://img.shields.io/badge/42-Project-blue)](https://42.fr)
[![Score](https://img.shields.io/badge/Score-125%2F125-success)](https://github.com/yourusername/fractol)
[![Language](https://img.shields.io/badge/Language-C-orange)](https://en.wikipedia.org/wiki/C_(programming_language))

My own vision of beautiful fractal rendering created as part of my 42 School experience. This project explores the fascinating world of fractals through interactive visualization using the MiniLibX graphics library.

![Fractol Demo](https://via.placeholder.com/800x400.png?text=Fractol+Demo)

- [What is Fract-ol?](#about)
- [Features](#features)
- [Supported Fractals](#supported-fractals)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Project Structure](#project-structure)
- [Technical Details](#technical-details)
- [Bonus Features](#bonus-features)
- [Acknowledgments](#acknowledgments)
- [Tips to Try](#tips)

## What is Fract-ol?

**Fract-ol** is a 42 School project that introduces students to the world of fractals (infinitely complex patterns that are self-similar across different scales). The program renders various types of fractals in real-time, allowing users to explore infinite mathematical beauty through zooming, panning, and parameter manipulation.

## Features

### Mandatory:
- Real-time fractal rendering
- **Mandelbrot set** visualization
- **Julia set** with customizable parameters
- Smooth zooming with mouse wheel
- Window management (minimize, close)
- ESC key to exit
- Clean error handling

### Bonus:
- **Additional fractals**: Burning Ship and Spider fractals
- Real-time fractal parameter modification with mouse
- 3+ different color schemes
- Arrow keys for panning
- **Iteration control**: +/- keys to adjust detail level
- **Mouse lock feature**: Toggle parameter tracking
- Smooth zoom towards mouse cursor position
- Auto-adjust quality based on zoom level

## Supported Fractals

### 1. Mandelbrot Set
The classic fractal discovered by Benoit Mandelbrot. Visualizes the set of complex numbers that don't diverge when iterated.

```bash
./fractol mandelbrot
```

### 2. Julia Set
A family of fractals closely related to the Mandelbrot set. This set is named after the French mathematician Gaston Julia. Each Julia set corresponds to a different complex constant.

```bash
./fractol julia                    
./fractol julia -0.7 0.27015      
./fractol julia 0.285 0.01        
```

### 3. Spider Fractal (Bonus)
A variant of the Julia set that creates web-like patterns.

```bash
./fractol spider                 
./fractol spider -0.7 0.27015     
```

### 4. Burning Ship (Bonus)
A fractal that resembles a ship in flames, created using absolute values in the iteration.

```bash
./fractol burning_ship
```

## Installation

### Prerequisites

- Linux operating system (tested on Ubuntu/Debian)
- GCC compiler
- Make
- X11 development libraries
- MiniLibX library

### Installing Dependencies

```bash
# Ubuntu/Debian
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev

# Fedora
sudo dnf install gcc make libXext-devel libXrandr-devel libX11-devel

# Arch Linux
sudo pacman -S gcc make libx11 libxext
```

### Building the Project

```bash
# clone the repository
git clone https://github.com/TinyaPetrova/fractol.git
cd fractol

# compile mandatory version
make

# compile bonus version
make bonus

# clean object files
make clean

# clean everything
make fclean

# recompile
make re
```

## Usage

### Basic Syntax

```bash
./fractol [fractal_type] [parameters (optional)]
```

### Examples

```bash
# Mandelbrot set
./fractol mandelbrot

# Julia set with default parameters
./fractol julia

# Julia set with custom parameters (range: -2.0 to 2.0)
./fractol julia -0.4 0.6
./fractol julia 0.285 0.01
./fractol julia -0.7 0.27015
./fractol julia -0.835 -0.2321
./fractol julia -0.8 0.156

# Spider fractal (bonus)
./fractol spider
./fractol spider -0.7 0.27015

# Burning Ship (bonus)
./fractol burning_ship
```

### Invalid Usage

The program will display usage instructions if arguments are incorrect:

```bash
./fractol                          # missing arguments
./fractol invalid                  # unknown fractal type
./fractol julia 3.0 0.5           # parameters out of range
./fractol mandelbrot 0.5 0.5      # extra parameters
```

## Controls

### Mouse Controls

| Control | Action |
|---------|--------|
| **Scroll Up** | Zoom in towards cursor |
| **Scroll Down** | Zoom out from cursor |
| **Move Mouse** | Change fractal parameters (Julia/Spider/Ship)* |
| **Move Mouse** | Pan view (Mandelbrot)** |

\* *when mouse lock is disabled*  
\** *bonus feature*

### Keyboard Controls

| Key | Action |
|-----|--------|
| **ESC** | Exit program |
| **↑ / W** | Move up |
| **↓ / S** | Move down |
| **← / A** | Move left |
| **→ / D** | Move right |
| **+ / =** | Increase iterations (more detail) |
| **- / _** | Decrease iterations (less detail) |
| **C** | Cycle through color palettes |
| **L** | Lock/unlock mouse parameter control |

### Tips 

1. **Finding interesting areas**: Use small zoom increments and explore edges
2. **Julia set parameters**: Try values between -1.0 and 1.0 for both real and imaginary parts
3. **Performance**: If rendering is slow, decrease iterations with the minus key
4. **Color schemes**: Press 'C' to change the palette
5. **Spiral patterns**: In Mandelbrot, zoom into the connection points between bulbs

## Project Structure

```
fractol/
├── Makefile
├── README.md
├── fractol.h                      # header file
├── minilibx-linux/                # MiniLibX graphics library
│
├── Mandatory files
├── main_mandatory.c               # entry point (mandatory)
├── draw_mandatory.c               # rendering functions
├── handlers_mandatory.c           # event handlers
├── colorizer_mandatory.c          # color algorithms
├── utils_init_mandatory.c         # initialization utilities
├── utils_print_mandatory.c        # usage/help messages
├── validator_mandatory.c          # input validation
│
├── Bonus files
├── main_bonus.c                   # entry point (bonus)
├── draw_bonus.c                   # enhanced rendering
├── draw_preview_bonus.c           # fast preview rendering
├── handlers_bonus.c               # enhanced event handlers
├── handlers_key_bonus.c           # keyboard event handling
├── handlers_motion_bonus.c        # mouse motion handling
├── handlers_zoom_bonus.c          # zoom calculations
├── colorizer_bonus.c              # multiple color palettes
├── utils_init_bonus.c             # extended initialization
├── utils_print_bonus.c            # enhanced help messages
├── validator_bonus.c              # extended input validation
│
├── Fractal algorithms
├── mandelbrot.c                   # calculation of Mandelbrot set
├── julia.c                        # calculation of Julia set 
├── spider.c                       # calculation of Spider fractal 
├── burning_ship.c                 # calculation of Burning Ship 
│
└── Utilities
    ├── utils.c                    # general utilities (atof, map)
    ├── utils_lib.c                # string/math functions
```

## Technical Details

### Compilation

```makefile
# compiler flags
CFLAGS = -Wall -Wextra -Werror -O3

# libraries
-lmlx -lXext -lX11 -lm
```

### Graphics Settings

```c
#define WIDTH 1500          // window width
#define HEIGHT 1500         // window height
#define MAX_ITER 100        // initial iteration count
```

### Algorithm Overview

The program uses the **escape time algorithm** to determine if a point belongs to a fractal set:

1. For each pixel, map screen coordinates to complex plane
2. Iterate the fractal formula until:
   - point escapes (magnitude > 2)
   - maximum iterations reached
3. Color pixel based on iteration count
4. Display the complete image

### Performance Optimizations

- Efficient pixel buffer manipulation
- Adaptive iteration counts based on zoom level
- Preview rendering for smooth interactions
- Optimized mathematical operations

## Bonus Features

### 1. Multiple Color Palettes

Three color schemes are available:
- **Palette 1**: Classic gradient
- **Palette 2**: Wave-based colors
- **Palette 3**: "Fire" colors

### 2. Mouse Parameter Control

For Julia and Spider fractals, moving the mouse changes the constant parameters in real-time, creating a morphing effect.

### 3. Adaptive Iterations

The program automatically adjusts iteration count based on zoom level:
- Zoom 1-5: 100 iterations
- Zoom 5-20: 120 iterations
- Zoom 20-100: 150 iterations
- Zoom 100-500: 200 iterations
- Zoom 500-1000: 250 iterations
- Zoom 1000+: 300 iterations

### 4. Advanced Navigation

- Arrow keys for precise panning
- Zoom centered on mouse cursor
- Smooth zoom with proper coordinate transformation

## Tips to Try

### Visually Cool Julia Set Parameters 

```bash
./fractol julia -0.4 0.6          # Dendrite fractal
./fractol julia 0.285 0.01        # Douady's rabbit
./fractol julia -0.7 0.27015      # Dragon-like structure
./fractol julia -0.835 -0.2321    # Swirls and tendrils
./fractol julia -0.8 0.156        # Lightning pattern
./fractol julia 0.3 0.5           # Fuzzy spiral
./fractol julia -0.4 -0.59        # Seahorse valley
./fractol julia 0.28 0.008        # Feathery pattern
```

### Zoom Exploration Tips

1. **Mandelbrot "Seahorse Valley"**: Zoom into the connection between the main body and the circular bulb on the left
2. **Mini Mandelbrots**: Keep zooming into spiral areas to find tiny copies of the main set
3. **Julia Connection**: Points inside the Mandelbrot set correspond to connected Julia sets
4. **Burning Ship Mast**: Zoom into the "mast" of the ship for incredible detail
