# <center>Forehead</center>

Have you ever worked on your project, stopped to test and be met with the following:

```bash
error: implicit declaration of function 'ft_not_in_header'
```

Well, look no further! Forehead has got you covered :wink:
***

## Introduction

Forehead was made to make your life as easy as possible.

It will take your source files and prototype all the functions for you!

You don't even have to worry about [norminette](norme.en.pdf) :rocket:
***

## Quickstart

### Install

```bash
git clone https://github.com/Tishj/forehead ~/forehead
make -C ~/forehead release
echo 'alias forehead="~/forehead/forehead"' >> ~/.zshrc
```

### usage

```bash
forehead SOURCEFILES -o HEADERFILE
```

## Features

* Detect and update indentation
* Remove concurrent empty lines
* Makes prototypes fit within a 80 character line:

```c
void                ft_mlx_pixel_to_img(t_data *data, int x, int y,
                    t_col color);
```
