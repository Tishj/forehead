/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_enum.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 12:59:09 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/07 16:05:23 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ENUM_H
# define CUB3D_ENUM_H

enum	e_id
{
	INVALID = -2,
	EMPTY,
	NORTH,
	SOUTH,
	WEST,
	EAST,
	RES,
	MAP,
	FLOOR,
	CEILING,
	SPRITE,
};

enum	e_states
{
	MOV_F,
	MOV_B,
	MOV_R,
	MOV_L,
	ROT_R,
	ROT_L,
};

enum	e_dir
{
	DIR_N = 90,
	DIR_E = 0,
	DIR_S = 270,
	DIR_W = 180,
};

enum	e_state
{
	OFF,
	ON,
};

enum	e_errors
{
	ERR_ARG = 1,
	ERR_TYPE,
	ERR_FILE,
	ERR_MEM,
	ERR_ORDER,
	ERR_TEXSOUTH,
	ERR_TEXNORTH,
	ERR_TEXEAST,
	ERR_TEXWEST,
	ERR_ID,
};

typedef enum		e_event_code
{
	MOUSE_PRESS_CODE = 4,
	MOUSE_MOVE_CODE = 6,
	KEY_PRESS_CODE = 2,
	KEY_RELEASE_CODE = 3,
	RED_BUTTON_CODE = 17,
}					t_event_code;

typedef enum		e_ft_mlx_hooks
{
	NO_EVENT_HOOK = 0,
	MOUSE_PRESS_HOOK = 1,
	MOUSE_MOVE_HOOK = 2,
	KEY_PRESS_HOOK = 4,
	RED_BUTTON_HOOK = 8,
}					t_ft_mlx_hooks;

typedef enum		e_mouse_code
{
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5,
}					t_mouse_code;

# ifdef LINUX

typedef enum		e_key_code_linux
{
	A = 97,
	D = 100,
	S = 115,
	W = 119,
	ESCAPE = 65307,
	LEFT_ARROW = 65361,
	RIGHT_ARROW = 65363,
	H = 104,
	Z = 6,
	X = 7,
	ZOOM_IN = 69,
	ZOOM_OUT = 78,
	U = 32,
	J = 38,
	K = 107,
	N = 45,
	M = 46,
	SPACE = 49,
	NUM_LOCK_9 = 92,
	NUM_LOCK_8 = 91,
	NUM_LOCK_7 = 89,
	NUM_LOCK_6 = 88,
	NUM_LOCK_5 = 87,
	NUM_LOCK_4 = 86,
	NUM_LOCK_3 = 85,
	NUM_LOCK_2 = 84,
	NUM_LOCK_1 = 83,
	NUM_LOCK_0 = 82,
	UP_ARROW = 126,
	DOWN_ARROW = 125,
}					t_key_code_linux;
# endif
# ifndef LINUX

typedef enum		e_key_code_mac
{
	A = 0,
	S = 1,
	D = 2,
	H = 4,
	Z = 6,
	X = 7,
	W = 13,
	ZOOM_IN = 69,
	ZOOM_OUT = 78,
	U = 32,
	J = 38,
	K = 40,
	N = 45,
	M = 46,
	SPACE = 49,
	ESCAPE = 53,
	NUM_LOCK_9 = 92,
	NUM_LOCK_8 = 91,
	NUM_LOCK_7 = 89,
	NUM_LOCK_6 = 88,
	NUM_LOCK_5 = 87,
	NUM_LOCK_4 = 86,
	NUM_LOCK_3 = 85,
	NUM_LOCK_2 = 84,
	NUM_LOCK_1 = 83,
	NUM_LOCK_0 = 82,
	RIGHT_ARROW = 124,
	LEFT_ARROW = 123,
	UP_ARROW = 126,
	DOWN_ARROW = 125,
}					t_key_code_mac;

# endif
#endif
