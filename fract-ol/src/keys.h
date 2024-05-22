/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:10:13 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/11 21:19:11 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __APPLE__

#  define ESC_KEY 53
#  define LEFT_KEY 123
#  define RIGHT_KEY 124
#  define UP_KEY 126
#  define DOWN_KEY 125
#  define PLUS_KEY 24
#  define MINUS_KEY 27
#  define SHIFT_LEFT 257
#  define SHIFT_RIGHT 258
#  define O_KEY 31
#  define P_KEY 35
#  define NUM_1 18
#  define NUM_2 19
#  define NUM_3 20
#  define NUM_4 21
#  define NUM_5 23

# elif defined(__linux__)

#  define ESC_KEY 65307
#  define LEFT_KEY 65361
#  define RIGHT_KEY 65363
#  define UP_KEY 65362
#  define DOWN_KEY 65364
#  define PLUS_KEY 65451
#  define MINUS_KEY 65453
#  define SHIFT_LEFT 65505
#  define SHIFT_RIGHT 65506
#  define O_KEY 111
#  define P_KEY 112
#  define NUM_1 49
#  define NUM_2 50
#  define NUM_3 51
#  define NUM_4 52
#  define NUM_5 53

# else

#  error "Unsupported operating system"

# endif

#endif
