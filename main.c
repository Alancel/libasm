/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alancel <alancel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:19:07 by ncolomer          #+#    #+#             */
/*   Updated: 2021/04/19 18:06:04 by alancel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>


int		ft_strlen(char const *str);

int		ft_strcmp(char const *s1, char const *s2);

char	*ft_strcpy(char *dst, char const *src);

ssize_t	ft_write(int fd, void const *buf, size_t nbyte);

ssize_t	ft_read(int fd, void *buf, size_t nbyte);

char	*ft_strdup(char const *s1);

int		main(void)
{
	char *buf;
	char *buf1; 
	char *str = "Veeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeery long string";
	char *str1 = "welcome to the jungle";
	
	buf = (char*)malloc(sizeof(char) * 237);
	buf1 = (char*)malloc(sizeof(char) * 23);
	printf("Test ft_strlen\n");
	printf("Std string\norig: %lu\nmine: %d\n", strlen(str1), ft_strlen(str1));
	printf("Empty string\norig: %lu\nmine: %d\n", strlen(""), ft_strlen(""));
	printf("Long string\norig: %lu\nmine: %d\n", strlen(str), ft_strlen(str));
	
	printf("Test ft_strcpy\n");
	printf("Std string\norig: %s\nmine: %s\n", strcpy(buf1, str1), ft_strcpy(buf1, str1));
	printf("Empty string\norig: %s\nmine: %s\n", strcpy(buf1, ""), ft_strcpy(buf1, ""));
	printf("Long string\norig: %s\nmine: %s\n", strcpy(buf, str), ft_strcpy(buf, str));
	
	printf("Test ft_strcmp\n");
	printf("Std string\norig: %d\nmine: %d\n", strcmp("abc", "abc"), ft_strcmp("abc", "abc"));
	printf("orig: %d\nmine: %d\n", strcmp("cba", "abc"), ft_strcmp("cba", "abc"));
	printf("orig: %d\nmine: %d\n", strcmp("abc", "cba"), ft_strcmp("abc", "cba"));
	printf("Empty strings\nEmpty first arg\norig: %d\nmine: %d\n", strcmp("", "abc"), ft_strcmp("", "abc"));
	printf("Empty second arg\norig: %d\nmine: %d\n", strcmp("abc", ""), ft_strcmp("abc", ""));
	printf("Empty both args\norig: %d\nmine: %d\n", strcmp("", ""), ft_strcmp("", ""));
	
	printf("Test ft_write\n");
	printf("Stdout returns\norig: %zd\nmine: %zd\n", write(STDOUT_FILENO, "abc\n", 4), ft_write(STDOUT_FILENO, "abc\n", 4));
	printf("Open fd returns\norig: %zd\nmine: %zd\n", write(1, "abc\n", 4), ft_write(1, "abc\n", 4));
	printf("Wrong fd returns\norig: %zd\nmine: %zd\n", write(255, "abc\n", 4), ft_write(255, "abc\n", 4));

	printf("Test ft_read\n");
	printf("Stdout returns\norig: %zd\nmine: %zd\n", read(STDIN_FILENO, buf, 10), ft_read(STDIN_FILENO, buf, 10));
	printf("Open fd returns\norig: %zd\nmine: %zd\n", read(1, buf, 10), ft_read(1, buf, 10));
	printf("Wrong fd returns\norig: %zd\nmine: %zd\n", read(255, buf, 10), ft_read(255, buf, 10));

	printf("Test ft_strdup\n");
	printf("Std string\norig: %s\nmine: %s\n", strdup(str1), ft_strdup(str1));
	printf("Empty string\norig: %s\nmine: %s\n", strdup(""), ft_strdup(""));
	printf("Long string\norig: %s\nmine: %s\n", strdup(str), ft_strdup(str));
	
	free(buf);
	free(buf1);
}